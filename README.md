# HPS and FPGA management system - Full pipeline to feed data to the Haddoc2 rebuild

This pipeline can be used for other projects. 

It was used the Quartus II 14.1 version.
The test board was the [Terasic DE1-SoC](https://www.terasic.com.tw/cgi-bin/page/archive.pl?Language=English&No=836) board, running the Ubuntu 14 LXDE that can be downloaded from the Oficial page of the board.

![Full pipeline](/Images/HPS_program_diagram.jpg)

This image shows the full pipeline system. In the HPS side is running a Linux Ubuntu OS that has a C program managing the whole processing stages, described bellow:

1. Receive a image as input;
2. Put the image in memory (SDRAM);
3. Activate the CNN processing on FPGA using the communication bridges;
4. Receive an interrupt from FPGA representing the end of CNN processing;
5. Get the final results from the SDRAM;
6. Sends the data to the broker via MQTT;

![HPS Management System](/Images/HPS-FPGA_memory_flow.jpg)

This image is a closer look to the HPS management system and the interaction with the global memory (SDRAM) and the memories in the FPGA (DMA and On-Chip memory).

![FPGA Management System](/Images/fpga_system.jpg)

This image represent what happens inside the FPGA.


# Tutorial to connect the whole pipeline with the [HADDOC2 Rebuild](https://github.com/rmcbarreto/haddoc2-rebuild) (or any other project)
(This tutorial is in the file [tutorial.txt](./tutorial.txt) in the repository)


Folders:
Linux C program - The software used in the linux in the HPS of the DE1-SoC board. This software read a image and puts it in the memory to be used by the FPGA haddoc2, and at the end, reads the data produced by the network and save it.

FPGA System - This is the pipeline created in the Qsys and the files in the FPGA that comunicates with the Qsys and the CNN in the FPGA. These files are coupled to cnn in fpga.

Programs used:
Ubuntu 18.04
Quartus II 14.1 Subscripted Edition
Intel® SoC FPGA Embedded Development Suite 14.1 (lbraries used in the compilation of the Linux C program)

TUTORIAL:

A - Install the Linux for the board:
* 1\. You need a microSD card. Then install the linux LXDE kernel 4.5 downloaded from the Terasic website
www.terasic.com/downloads/cd-rom/de1-soc/linux_BSP/de1soc_lxde_1604.zip
* 2\. Install this vesion in the microSD card
  * 2.1\. Windows: Use the program Win32DiskImager.exe to create a microSD Card linux image
  * 2.2\. Linux: sudo dd if=Linux_Image.img of=/dev/sdb (never tested this command, but search for "create micros card image linux" in google)
    * 2.2.1\. Change the "Linux_Image.img" and the "/edv/sdb" for the corresponding values 

B - Run the linux on the board. 

C - In the U-Boot, stop the autostart.
* 1\. Change the linux memory access to half the memory, with the following command:
setenv mmcboot "setenv bootargs console=ttyS0,115200 root=${mmcroot} mem=512M rw rootwait;bootz ${loadaddr} - ${fdtaddr}"
  * 1.1\. Save the changes: saveenv
  * 1.2\. Run the linux: run bootcmd
  * 1.3\. Check in linux the ammount of memory available: cat /proc/iomem

D - Run the HADDOC2 REBUILD and create the Quartus project
* 1\. Have the HADDOC2 REBUILD path as environment varialbe (export HADDOC2_ROOT="$HOME/Programs/HADDOC2_REBUILD")
* 2\. Have the Caffe as environment variable (export CAFFE_ROOT="/usr/lib/python3/dist-packages/caffe")
* 3\. Run the HADDOC2 REBUILD makefile example (to run: "make"; to clean: "make clean")
* 4\. Now it has generated a folder named "quartus"
  * 4.1\. Copy the "FPGA_MANAGEMENT_SYSTEM" files to inside the "quartus folder" 
  * 4.2\. Open Quartus
  * 4.3\. Open Qsys -> Open the file "cnn_hps_system.qsys" -> Click "Generate HDL..." (confirm the file path) -> Click "Finish"
  * 4.4\. In Quartus go to "Project" -> "Add/Remove Files in Project..." and add the following files:
    * 4.4.1\.  "cnn_hps_system/synthesis/cnn_hps_system.qip" -> click "Add"
    * 4.4.2\. "hps_system" -> Select "mian.v" "readOCM.v" "writeAuxDtaOCM.v" and "hexto7segment.v"
    * 4.4.3\. Click OK to confirm and exit window
  * 4.5\. Now in Quartus "Project Navigator" go to "Files" and set the "main.v" as "Top-Level Entity"
  * 4.6\. Go to "Assignments" -> "Import Assignments..." and select the file "pin_assignment_custom.txt"
  * 4.7\. Go to "Processing" -> "Start" -> "Start Analysis & Synthesis" and wait until finished
  * 4.8\. Go to "Tools" -> "Tcl Scripts..." and select the "hps_sdram_p0_pin_assignments.tcl" and click "Run"
  * 4.9\. Recompile the whole project.
* 5\. Convert the .sof file and upload it to the board. 
* 6\. Use a program in the Linux to test the CNN. You can use the "HPS_Linux_Software" to test the FPGA program.



# Need any HELP?
If you want any information, feel free to contact me:
rmcbarreto@gmail.com
