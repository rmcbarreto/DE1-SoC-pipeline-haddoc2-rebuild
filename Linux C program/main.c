// https://shanetully.com/2014/12/translating-virtual-addresses-to-physcial-addresses-in-user-space/

//http://www.linuxforums.org/forum/programming-scripting/202000-dev-mem-access-c-program.html
//https://stackoverflow.com/questions/10733816/read-and-write-process-memory-through-dev-mem-text-segment-works-but-data-seg
//https://github.com/hackndev/tools/blob/master/devmem2.c
// https://cboard.cprogramming.com/c-programming/176305-reading-writing-dev-mem.html

//=============================================================================================
// To run this program, first reserve a portion of memory only for FPGA (in u-boot limitate the meory of the Linux)
// Then change the physical address to read and write from the physycal memory.
// 
// This program read a image and then writes it in the physical memory.
// Then activates the DMA controller in the FPGA to copy the image from one address to another.
// From Linux, the program will read the image from the second address and save the image. 
//=============================================================================================

#define DEBUG 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <errno.h>
#include <fcntl.h>
#include <stdint.h>

#include "hwlib.h"
#include "socal/socal.h"
#include "socal/hps.h"
#include "socal/alt_gpio.h"

#include "hps_0.h"

//#include "sgdma.h"	// Scatter-Gather DMA
#include "dma.h"		// DMA
//=============================================================================================
#define STB_IMAGE_IMPLEMENTATION
#include "../../stb-master/stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "../../stb-master/stb_image_write.h"
//=============================================================================================
// settings for the lightweight HPS-to-FPGA bridge
// The ALT_STM_OFST starts at 0xfc000000 and the HW_REGS_SPAN of 0x04000000 occupies all the physical space until the end
// The lightweight HPS-to-FPGA bridge starts at 0xff200000 -> ALT_LWFPGASLVS_OFST
#define HW_REGS_BASE ( ALT_STM_OFST )
#define HW_REGS_SPAN ( 0x04000000 ) //64 MB with 32 bit adress space this is 256 MB
#define HW_REGS_MASK ( HW_REGS_SPAN - 1 )
//=============================================================================================
//setting for the HPS2FPGA AXI Bridge
#define ALT_AXI_FPGASLVS_OFST (0xC0000000) // axi_master
#define HW_FPGA_AXI_SPAN (0x40000000) // Bridge span 1GB
#define HW_FPGA_AXI_MASK ( HW_FPGA_AXI_SPAN - 1 )
//=============================================================================================
// Activate the FPGA-to-SDRAM bridge
//SDRAMC beginning address
// Manual CycloneV page 833-834
#define SDRAMC_REGS_BASE	0xFFC20000	// From hps.h file it is the ALT_SDR_OFST = 0xFFC20000
#define SDRAMC_REGS_SPAN	0x00100000
#define SDRAMC_REGS_MASK	( SDRAMC_REGS_SPAN - 1 )
//Offset of FPGA-to-SDRAMC ports reset register from the beginning of SDRAMC
#define FPGAPORTRST 		0x00005080

//Remove FPGA-to-SDRAMC ports from reset so FPGA can access SDRAM through them
//*((unsigned int *)(SDRAMC_REGS + FPGAPORTRST)) = 0xFFFF;
//=============================================================================================

void* create_buffer(size_t buf_size);
int open_memory(void);

int main(int argc, char *argv[]) {

	// Check inputs
	if (argc < 2){
		printf("Usage: <program> <image filename>\n");
		return 0;
	}

	printf("Running. To exit, press Ctrl+C.\n\n");

	unsigned long physical_addr1 = 0x20000000;
	unsigned long physical_addr2 = 0x21000000;

	//===================================  Read Image =============================================
	int width, height, channels;
	// Read in RGB mode
	//unsigned char *image_data = stbi_load(argv[1], &width, &height, &channels, 3);

	// Read in GreyScale Mode (the image can be in rgb)
	if(DEBUG) printf("Reading Image...\n");
	unsigned char *image_data = stbi_load(argv[1], &width, &height, &channels, 1);

	if(DEBUG) printf("Image read successfully\n");
	if(DEBUG) printf("Image width = %d; height = %d\n", width, height);

	//=============================================================================================

	int image_size = width*height;
	size_t size = image_size * sizeof(unsigned char); // size is the same size as image_size
	//=============================================================================================
	int MAP_SIZE = 131072;
	//=============================================================================================
	// Map the first physical address, to copy the image to it
	int mem_fd1 = open_memory();

	void *map_base1;
	map_base1 = mmap(0, MAP_SIZE, PROT_READ|PROT_WRITE, MAP_SHARED, mem_fd1, physical_addr1);

	if(map_base1 == MAP_FAILED){
		printf("Can't mmap\n");
		return 1;
	}

	// Coloca a zero, so para testar e ter a certez que estava a copiar a imagem corretamente
	memset(map_base1, 0, MAP_SIZE);

	// Add the image to the mapped memory place
	for(int i = 0; i < image_size; i++){
		*((unsigned char *)map_base1+i) = image_data[i];
	}

	//=============================================================================================
	// Map the second physical address, to clean its memory
	int mem_fd2 = open_memory();

	void *map_base2;
	map_base2 = mmap(0, MAP_SIZE, PROT_READ|PROT_WRITE, MAP_SHARED, mem_fd2, physical_addr2);

	if(map_base2 == MAP_FAILED){
		printf("Can't mmap\n");
		return 1;
	}

	// Coloca a zero, so para testar e ter a certez que estava a copiar a imagem corretamente
	memset(map_base2, 0, MAP_SIZE);

	//=============================================================================================
	int fd = open_memory();
	//=============================================================================================
	// Activate the FPGA-to-SDRAM bridge
	// FPGA-to-SDRAM bridge
	
	void *fpga_sdram_virtual_base;
	fpga_sdram_virtual_base = mmap( NULL, SDRAMC_REGS_SPAN, ( PROT_READ | PROT_WRITE ), MAP_SHARED, fd, SDRAMC_REGS_BASE );

	if( fpga_sdram_virtual_base == MAP_FAILED ) {
		printf( "ERROR: axi mmap() fpga_sdram_virtual_base failed...\n" );
		close( fd );
		return( 1 );
	}

	// See cyclone V manual page 833
	// Activates the FPGA-to-SDRAM bridge
	void *f2sdram = NULL;
	f2sdram = fpga_sdram_virtual_base + ( ( unsigned long  )( 0x0 + FPGAPORTRST ) & ( unsigned long)( SDRAMC_REGS_MASK ) );

	*((unsigned int *)(f2sdram)) = 0xFFF;
	
	//=============================================================================================
	// DMA Controller

	printf( "\n\n\n-----------DMA SDRAM to SDRAM-------------\n\n" );

	//lightweight HPS-to-FPGA bridge
	void *virtual_base;
	virtual_base = mmap( NULL, HW_REGS_SPAN, ( PROT_READ | PROT_WRITE ), MAP_SHARED, fd, HW_REGS_BASE );

	if( virtual_base == MAP_FAILED ) {
		printf( "ERROR: mmap() virtual_base failed...\n" );
		close( fd );
		return( 1 );
	}

	//create a pointer to the DMA controller base
	void *h2p_lw_dma_addr0 = NULL;
	h2p_lw_dma_addr0 = virtual_base + ( ( unsigned long  )( ALT_LWFPGASLVS_OFST + DMA_0_BASE ) & ( unsigned long)( HW_REGS_MASK ) );

	// clear the DMA control and status
	clearDMAcontrol(h2p_lw_dma_addr0);
	_DMA_REG_STATUS(h2p_lw_dma_addr0) = 0;

	printf("\n");
	printf("Before start DMA\n");
	debugPrintDMARegister(h2p_lw_dma_addr0);
	printf("\n");
	debugPrintDMAStatus(h2p_lw_dma_addr0);

	// Make a reset to the DMA
	// Se fizer um reset, precisa de ter um usleep de 10000 micro segundos no meio, e outro no fim.
	// Estes usleeps têm OBRIGATORIAMENTE de estar AQUI!!! Se não NÃO FUNCIONA!!!!!!! PORQUÊ? não sei...
	/*
	_DMA_REG_CONTROL(h2p_lw_dma_addr0) = _DMA_CTR_SOFTWARERESET;
	usleep(100000);
	_DMA_REG_CONTROL(h2p_lw_dma_addr0) = _DMA_CTR_SOFTWARERESET;
	usleep(100000);
	*/

	// Este usleep tem OBRIGATORIAMENTE de estar AQUI!!! Se não NÃO FUNCIONA!!!!!!! PORQUÊ? não sei...
	// Correçao, funcionou sem este usleep
	//usleep(2*100000);
	
	_DMA_REG_STATUS(h2p_lw_dma_addr0) = 0;
	_DMA_REG_READ_ADDR(h2p_lw_dma_addr0)  = physical_addr1;  // read from F2SDRAM_0
	_DMA_REG_WRITE_ADDR(h2p_lw_dma_addr0) = 0;  // write to F2SDRAM_1
	_DMA_REG_LENGTH(h2p_lw_dma_addr0) = image_size;			//write 100x 4bytes since we have a 32 bit system

	//start the transfer
	_DMA_REG_CONTROL(h2p_lw_dma_addr0) = _DMA_CTR_BYTE | _DMA_CTR_GO | _DMA_CTR_LEEN;
	


	// wait for DMA to be finished
	waitDMAFinish(h2p_lw_dma_addr0);
	printf("finished transfer from SDRAM to OCM\nStarting the OCM to SDRAM tranasfer\n");

	printf("DMA 0 STATUS:\n");
	debugPrintDMAStatus(h2p_lw_dma_addr0);
	printf("\n");

	printf("\n");
	printf("End of DMA\n");

	// clear the DMA control and status
	clearDMAcontrol(h2p_lw_dma_addr0);
	_DMA_REG_STATUS(h2p_lw_dma_addr0) = 0;


	// O ponteiro que liga ao PIO que vai ativar a leitura da imagem para o haddoc correr
	void *start_haddoc = NULL;
	start_haddoc = virtual_base + ( ( unsigned long  )( ALT_LWFPGASLVS_OFST + IMAGE_SENT_OCM_BASE ) & ( unsigned long)( HW_REGS_MASK ) );
	*((uint32_t *)start_haddoc+0) = 1;


	printf("Espera 2 segundos até desativar o haddoc (todo o processo do haddoc e automatico)\n");

	usleep(2*1000000);

	*((uint32_t *)start_haddoc+0) = 0;


	// Read the values from counters from memory 
	// Copy the information from the OCM to the SDRAM using the DMA controller

	//create a pointer to the DMA controller base
	void *h2p_lw_dma_addr1 = NULL;
	h2p_lw_dma_addr1 = virtual_base + ( ( unsigned long  )( ALT_LWFPGASLVS_OFST + DMA_1_BASE ) & ( unsigned long)( HW_REGS_MASK ) );

	// clear the DMA control and status
	clearDMAcontrol(h2p_lw_dma_addr1);
	_DMA_REG_STATUS(h2p_lw_dma_addr1) = 0;

	_DMA_REG_STATUS(h2p_lw_dma_addr1) = 0;
	_DMA_REG_READ_ADDR(h2p_lw_dma_addr1)  = 0;  				// read from OCM
	_DMA_REG_WRITE_ADDR(h2p_lw_dma_addr1) = physical_addr2;  	// write to SDRAM (DDR3)
	_DMA_REG_LENGTH(h2p_lw_dma_addr1) = 4000;					// number of elements in bytes

	//start the transfer
	_DMA_REG_CONTROL(h2p_lw_dma_addr1) = _DMA_CTR_BYTE | _DMA_CTR_GO | _DMA_CTR_LEEN;

	// wait for DMA to be finished
	waitDMAFinish(h2p_lw_dma_addr1);
	printf("finished transfer from SDRAM to OCM\nStarting the OCM to SDRAM tranasfer");

	printf("DMA 0 STATUS:\n");
	debugPrintDMAStatus(h2p_lw_dma_addr1);
	printf("\n");

	printf("\n");
	printf("End of DMA\n");

	int range = 50;
	int addr = 0;
	for(int i = addr; i < addr+range; i++){
		printf("pixel%d = %d\n", i-addr, *((unsigned char *)map_base2+i));
	}
	printf("\n");


	//=============================================================================================
	// Copy the image from the physical address 2 to a buffer (it's not necessary, I can use the map_base2 to have direct acess to the image)
	/*
	unsigned char *aux = create_buffer(size);

	for(int i = 0; i < image_size; i++){
		aux[i] = *((unsigned char *)map_base2+i);
	}
	*/

	//=================================================================================================================
	// SAVE IMAGE
	
	/*
	if(stbi_write_jpg("out_grey.jpg", 28, 20, 1, (unsigned char *)map_base2, 100) == 0){
		printf("ERROR!!\n");
	}
	*/
	

	/*
	if(stbi_write_png("out_grey.png", 4, 40, 1, (unsigned char *)map_base2, 0 ) == 0){
		printf("ERROR!!\n");
	}
	*/
	
	
	
	// Used to get multiple 3x3 kernels from image (to test neighborhood extract in haddoc2)
	
	
	char str[14];
	int num_outputs = 10;
	int pixels_per_output = 16;

	for(int i = 0; i < num_outputs; i++){
		sprintf(str, "out_pixl%d.png", (unsigned char)i);
		if(stbi_write_png(str, 4, 4, 1, ((unsigned char *)map_base2+(i*pixels_per_output)), 0 ) == 0){
			printf("ERROR!!\n");
		}
	}
	
	
	

	/*
	if(stbi_write_png("out_grey.png", 24, 24, 1, image_data, 0 ) == 0){
		printf("ERROR!!\n");
	}
	*/
	

	
	
	//stbi_write_png(char const *filename, int w, int h, int comp, const void *data, int stride_in_bytes);
	//stbi_write_png("out_grey.png", width, height, 1, image_output, 0 )
	//stbi_write_jpg(char const *filename, int w, int h, int comp, const void *data, int quality); // 0 < quality <=100

	//stbi_image_free(image_data);
	//free(image_output);
	//=============================================================================================
	// CLEAN MMORY AND UNMAP AND FREE POINTERS

	//memset(map_base1, 0, size);
	//memset(map_base2, 0, size);
	
	if(munmap(map_base1, MAP_SIZE) == -1){
		printf("Can't munmap\n");
		return 1;
	}

	if(munmap(map_base2, MAP_SIZE) == -1){
		printf("Can't munmap\n");
		return 1;
	}

	close(mem_fd1);
	close(mem_fd2);
	
	//=================================================================================================================

	return 0;
}

void* create_buffer(size_t buf_size) {
	//size_t buf_size = strlen(size) + 1; // Add 1 for the final characer

	if(DEBUG) printf("size buffer = %d\n", buf_size);

	// Allocate some memory to manipulate
	void *buffer = malloc(buf_size);
	//void *buffer = calloc(buf_size, sizeof(unsigned char));
	if(buffer == NULL) {
		fprintf(stderr, "Failed to allocate memory for buffer\n");
		exit(1);
	}

	// Lock the page in memory
	// Do this before writing data to the buffer so that any copy-on-write
	// mechanisms will give us our own page locked in memory
	if(mlock(buffer, buf_size) == -1) {
		fprintf(stderr, "Failed to lock page in memory: %s\n", strerror(errno));
		exit(1);
	}

	return buffer;
}

int open_memory(void) {
	// Open the memory (must be root for this)
	int fd = open("/dev/mem", ( O_RDWR | O_SYNC ));

	if(fd == -1) {
		fprintf(stderr, "Error opening /dev/mem: %s\n", strerror(errno));
		exit(1);
	}

	return fd;
}
