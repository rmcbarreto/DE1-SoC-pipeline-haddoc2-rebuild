#ifndef _ALTERA_HPS_0_H_
#define _ALTERA_HPS_0_H_

/*
 * This file was automatically generated by the swinfo2header utility.
 * 
 * Created from SOPC Builder system 'cnn_hps_system' in
 * file '/home/ricardo/Programs/haddoc2_tiny_lenet_8bit_newnetwork3/example/quartus/hps_system/cnn_hps_system.sopcinfo'.
 */

/*
 * This file contains macros for module 'hps_0' and devices
 * connected to the following masters:
 *   h2f_axi_master
 *   h2f_lw_axi_master
 * 
 * Do not include this header file and another header file created for a
 * different module or master group at the same time.
 * Doing so may result in duplicate macro names.
 * Instead, use the system header file which has macros with unique names.
 */

/*
 * Macros for device 'in_data', class 'altera_avalon_pio'
 * The macros are prefixed with 'IN_DATA_'.
 * The prefix is the slave descriptor.
 */
#define IN_DATA_COMPONENT_TYPE altera_avalon_pio
#define IN_DATA_COMPONENT_NAME in_data
#define IN_DATA_BASE 0x0
#define IN_DATA_SPAN 32
#define IN_DATA_END 0x1f
#define IN_DATA_BIT_CLEARING_EDGE_REGISTER 0
#define IN_DATA_BIT_MODIFYING_OUTPUT_REGISTER 0
#define IN_DATA_CAPTURE 0
#define IN_DATA_DATA_WIDTH 8
#define IN_DATA_DO_TEST_BENCH_WIRING 0
#define IN_DATA_DRIVEN_SIM_VALUE 0
#define IN_DATA_EDGE_TYPE NONE
#define IN_DATA_FREQ 50000000
#define IN_DATA_HAS_IN 0
#define IN_DATA_HAS_OUT 1
#define IN_DATA_HAS_TRI 0
#define IN_DATA_IRQ_TYPE NONE
#define IN_DATA_RESET_VALUE 0

/*
 * Macros for device 'dma_0', class 'altera_avalon_dma'
 * The macros are prefixed with 'DMA_0_'.
 * The prefix is the slave descriptor.
 */
#define DMA_0_COMPONENT_TYPE altera_avalon_dma
#define DMA_0_COMPONENT_NAME dma_0
#define DMA_0_BASE 0x0
#define DMA_0_SPAN 64
#define DMA_0_END 0x3f
#define DMA_0_ALLOW_BYTE_TRANSACTIONS 1
#define DMA_0_ALLOW_DOUBLEWORD_TRANSACTIONS 1
#define DMA_0_ALLOW_HW_TRANSACTIONS 1
#define DMA_0_ALLOW_QUADWORD_TRANSACTIONS 1
#define DMA_0_ALLOW_WORD_TRANSACTIONS 1
#define DMA_0_LENGTHWIDTH 32
#define DMA_0_MAX_BURST_SIZE 128

/*
 * Macros for device 'hps_0_bridges', class 'hps_bridge_avalon'
 * Path to the device is from the master group 'dma_0_read_master'.
 * The macros are prefixed with 'DMA_0_READ_MASTER_HPS_0_BRIDGES_'.
 * The prefix is the master group descriptor and the slave descriptor.
 */
#define DMA_0_READ_MASTER_HPS_0_BRIDGES_COMPONENT_TYPE hps_bridge_avalon
#define DMA_0_READ_MASTER_HPS_0_BRIDGES_COMPONENT_NAME hps_0_bridges
#define DMA_0_READ_MASTER_HPS_0_BRIDGES_BASE 0x0
#define DMA_0_READ_MASTER_HPS_0_BRIDGES_SPAN 0x0
#define DMA_0_READ_MASTER_HPS_0_BRIDGES_END 0xffffffff

/*
 * Macros for device 'onchip_memory2_0', class 'altera_avalon_onchip_memory2'
 * Path to the device is from the master group 'dma_0_write_master'.
 * The macros are prefixed with 'DMA_0_WRITE_MASTER_ONCHIP_MEMORY2_0_'.
 * The prefix is the master group descriptor and the slave descriptor.
 */
#define DMA_0_WRITE_MASTER_ONCHIP_MEMORY2_0_COMPONENT_TYPE altera_avalon_onchip_memory2
#define DMA_0_WRITE_MASTER_ONCHIP_MEMORY2_0_COMPONENT_NAME onchip_memory2_0
#define DMA_0_WRITE_MASTER_ONCHIP_MEMORY2_0_BASE 0x0
#define DMA_0_WRITE_MASTER_ONCHIP_MEMORY2_0_SPAN 131072
#define DMA_0_WRITE_MASTER_ONCHIP_MEMORY2_0_END 0x1ffff
#define DMA_0_WRITE_MASTER_ONCHIP_MEMORY2_0_ALLOW_IN_SYSTEM_MEMORY_CONTENT_EDITOR 0
#define DMA_0_WRITE_MASTER_ONCHIP_MEMORY2_0_ALLOW_MRAM_SIM_CONTENTS_ONLY_FILE 0
#define DMA_0_WRITE_MASTER_ONCHIP_MEMORY2_0_CONTENTS_INFO ""
#define DMA_0_WRITE_MASTER_ONCHIP_MEMORY2_0_DUAL_PORT 1
#define DMA_0_WRITE_MASTER_ONCHIP_MEMORY2_0_GUI_RAM_BLOCK_TYPE AUTO
#define DMA_0_WRITE_MASTER_ONCHIP_MEMORY2_0_INIT_CONTENTS_FILE cnn_hps_system_onchip_memory2_0
#define DMA_0_WRITE_MASTER_ONCHIP_MEMORY2_0_INIT_MEM_CONTENT 1
#define DMA_0_WRITE_MASTER_ONCHIP_MEMORY2_0_INSTANCE_ID NONE
#define DMA_0_WRITE_MASTER_ONCHIP_MEMORY2_0_NON_DEFAULT_INIT_FILE_ENABLED 0
#define DMA_0_WRITE_MASTER_ONCHIP_MEMORY2_0_RAM_BLOCK_TYPE AUTO
#define DMA_0_WRITE_MASTER_ONCHIP_MEMORY2_0_READ_DURING_WRITE_MODE DONT_CARE
#define DMA_0_WRITE_MASTER_ONCHIP_MEMORY2_0_SINGLE_CLOCK_OP 0
#define DMA_0_WRITE_MASTER_ONCHIP_MEMORY2_0_SIZE_MULTIPLE 1
#define DMA_0_WRITE_MASTER_ONCHIP_MEMORY2_0_SIZE_VALUE 131072
#define DMA_0_WRITE_MASTER_ONCHIP_MEMORY2_0_WRITABLE 1
#define DMA_0_WRITE_MASTER_ONCHIP_MEMORY2_0_MEMORY_INFO_DAT_SYM_INSTALL_DIR SIM_DIR
#define DMA_0_WRITE_MASTER_ONCHIP_MEMORY2_0_MEMORY_INFO_GENERATE_DAT_SYM 1
#define DMA_0_WRITE_MASTER_ONCHIP_MEMORY2_0_MEMORY_INFO_GENERATE_HEX 1
#define DMA_0_WRITE_MASTER_ONCHIP_MEMORY2_0_MEMORY_INFO_HAS_BYTE_LANE 0
#define DMA_0_WRITE_MASTER_ONCHIP_MEMORY2_0_MEMORY_INFO_HEX_INSTALL_DIR QPF_DIR
#define DMA_0_WRITE_MASTER_ONCHIP_MEMORY2_0_MEMORY_INFO_MEM_INIT_DATA_WIDTH 32
#define DMA_0_WRITE_MASTER_ONCHIP_MEMORY2_0_MEMORY_INFO_MEM_INIT_FILENAME cnn_hps_system_onchip_memory2_0

/*
 * Macros for device 'enable', class 'altera_avalon_pio'
 * The macros are prefixed with 'ENABLE_'.
 * The prefix is the slave descriptor.
 */
#define ENABLE_COMPONENT_TYPE altera_avalon_pio
#define ENABLE_COMPONENT_NAME enable
#define ENABLE_BASE 0x10
#define ENABLE_SPAN 32
#define ENABLE_END 0x2f
#define ENABLE_BIT_CLEARING_EDGE_REGISTER 0
#define ENABLE_BIT_MODIFYING_OUTPUT_REGISTER 0
#define ENABLE_CAPTURE 0
#define ENABLE_DATA_WIDTH 1
#define ENABLE_DO_TEST_BENCH_WIRING 0
#define ENABLE_DRIVEN_SIM_VALUE 0
#define ENABLE_EDGE_TYPE NONE
#define ENABLE_FREQ 50000000
#define ENABLE_HAS_IN 0
#define ENABLE_HAS_OUT 1
#define ENABLE_HAS_TRI 0
#define ENABLE_IRQ_TYPE NONE
#define ENABLE_RESET_VALUE 0

/*
 * Macros for device 'out_data', class 'altera_avalon_pio'
 * The macros are prefixed with 'OUT_DATA_'.
 * The prefix is the slave descriptor.
 */
#define OUT_DATA_COMPONENT_TYPE altera_avalon_pio
#define OUT_DATA_COMPONENT_NAME out_data
#define OUT_DATA_BASE 0x20
#define OUT_DATA_SPAN 32
#define OUT_DATA_END 0x3f
#define OUT_DATA_BIT_CLEARING_EDGE_REGISTER 0
#define OUT_DATA_BIT_MODIFYING_OUTPUT_REGISTER 0
#define OUT_DATA_CAPTURE 0
#define OUT_DATA_DATA_WIDTH 8
#define OUT_DATA_DO_TEST_BENCH_WIRING 0
#define OUT_DATA_DRIVEN_SIM_VALUE 0
#define OUT_DATA_EDGE_TYPE NONE
#define OUT_DATA_FREQ 50000000
#define OUT_DATA_HAS_IN 1
#define OUT_DATA_HAS_OUT 0
#define OUT_DATA_HAS_TRI 0
#define OUT_DATA_IRQ_TYPE NONE
#define OUT_DATA_RESET_VALUE 0

/*
 * Macros for device 'dma_1', class 'altera_avalon_dma'
 * The macros are prefixed with 'DMA_1_'.
 * The prefix is the slave descriptor.
 */
#define DMA_1_COMPONENT_TYPE altera_avalon_dma
#define DMA_1_COMPONENT_NAME dma_1
#define DMA_1_BASE 0x20
#define DMA_1_SPAN 64
#define DMA_1_END 0x5f
#define DMA_1_ALLOW_BYTE_TRANSACTIONS 1
#define DMA_1_ALLOW_DOUBLEWORD_TRANSACTIONS 1
#define DMA_1_ALLOW_HW_TRANSACTIONS 1
#define DMA_1_ALLOW_QUADWORD_TRANSACTIONS 1
#define DMA_1_ALLOW_WORD_TRANSACTIONS 1
#define DMA_1_LENGTHWIDTH 32
#define DMA_1_MAX_BURST_SIZE 128

/*
 * Macros for device 'onchip_memory2_1', class 'altera_avalon_onchip_memory2'
 * Path to the device is from the master group 'dma_1_read_master'.
 * The macros are prefixed with 'DMA_1_READ_MASTER_ONCHIP_MEMORY2_1_'.
 * The prefix is the master group descriptor and the slave descriptor.
 */
#define DMA_1_READ_MASTER_ONCHIP_MEMORY2_1_COMPONENT_TYPE altera_avalon_onchip_memory2
#define DMA_1_READ_MASTER_ONCHIP_MEMORY2_1_COMPONENT_NAME onchip_memory2_1
#define DMA_1_READ_MASTER_ONCHIP_MEMORY2_1_BASE 0x0
#define DMA_1_READ_MASTER_ONCHIP_MEMORY2_1_SPAN 131072
#define DMA_1_READ_MASTER_ONCHIP_MEMORY2_1_END 0x1ffff
#define DMA_1_READ_MASTER_ONCHIP_MEMORY2_1_ALLOW_IN_SYSTEM_MEMORY_CONTENT_EDITOR 0
#define DMA_1_READ_MASTER_ONCHIP_MEMORY2_1_ALLOW_MRAM_SIM_CONTENTS_ONLY_FILE 0
#define DMA_1_READ_MASTER_ONCHIP_MEMORY2_1_CONTENTS_INFO ""
#define DMA_1_READ_MASTER_ONCHIP_MEMORY2_1_DUAL_PORT 1
#define DMA_1_READ_MASTER_ONCHIP_MEMORY2_1_GUI_RAM_BLOCK_TYPE AUTO
#define DMA_1_READ_MASTER_ONCHIP_MEMORY2_1_INIT_CONTENTS_FILE cnn_hps_system_onchip_memory2_1
#define DMA_1_READ_MASTER_ONCHIP_MEMORY2_1_INIT_MEM_CONTENT 1
#define DMA_1_READ_MASTER_ONCHIP_MEMORY2_1_INSTANCE_ID NONE
#define DMA_1_READ_MASTER_ONCHIP_MEMORY2_1_NON_DEFAULT_INIT_FILE_ENABLED 0
#define DMA_1_READ_MASTER_ONCHIP_MEMORY2_1_RAM_BLOCK_TYPE AUTO
#define DMA_1_READ_MASTER_ONCHIP_MEMORY2_1_READ_DURING_WRITE_MODE DONT_CARE
#define DMA_1_READ_MASTER_ONCHIP_MEMORY2_1_SINGLE_CLOCK_OP 0
#define DMA_1_READ_MASTER_ONCHIP_MEMORY2_1_SIZE_MULTIPLE 1
#define DMA_1_READ_MASTER_ONCHIP_MEMORY2_1_SIZE_VALUE 131072
#define DMA_1_READ_MASTER_ONCHIP_MEMORY2_1_WRITABLE 1
#define DMA_1_READ_MASTER_ONCHIP_MEMORY2_1_MEMORY_INFO_DAT_SYM_INSTALL_DIR SIM_DIR
#define DMA_1_READ_MASTER_ONCHIP_MEMORY2_1_MEMORY_INFO_GENERATE_DAT_SYM 1
#define DMA_1_READ_MASTER_ONCHIP_MEMORY2_1_MEMORY_INFO_GENERATE_HEX 1
#define DMA_1_READ_MASTER_ONCHIP_MEMORY2_1_MEMORY_INFO_HAS_BYTE_LANE 0
#define DMA_1_READ_MASTER_ONCHIP_MEMORY2_1_MEMORY_INFO_HEX_INSTALL_DIR QPF_DIR
#define DMA_1_READ_MASTER_ONCHIP_MEMORY2_1_MEMORY_INFO_MEM_INIT_DATA_WIDTH 32
#define DMA_1_READ_MASTER_ONCHIP_MEMORY2_1_MEMORY_INFO_MEM_INIT_FILENAME cnn_hps_system_onchip_memory2_1

/*
 * Macros for device 'hps_0_bridges', class 'hps_bridge_avalon'
 * Path to the device is from the master group 'dma_1_write_master'.
 * The macros are prefixed with 'DMA_1_WRITE_MASTER_HPS_0_BRIDGES_'.
 * The prefix is the master group descriptor and the slave descriptor.
 */
#define DMA_1_WRITE_MASTER_HPS_0_BRIDGES_COMPONENT_TYPE hps_bridge_avalon
#define DMA_1_WRITE_MASTER_HPS_0_BRIDGES_COMPONENT_NAME hps_0_bridges
#define DMA_1_WRITE_MASTER_HPS_0_BRIDGES_BASE 0x0
#define DMA_1_WRITE_MASTER_HPS_0_BRIDGES_SPAN 0x0
#define DMA_1_WRITE_MASTER_HPS_0_BRIDGES_END 0xffffffff

/*
 * Macros for device 'leds2', class 'altera_avalon_pio'
 * The macros are prefixed with 'LEDS2_'.
 * The prefix is the slave descriptor.
 */
#define LEDS2_COMPONENT_TYPE altera_avalon_pio
#define LEDS2_COMPONENT_NAME leds2
#define LEDS2_BASE 0x30
#define LEDS2_SPAN 32
#define LEDS2_END 0x4f
#define LEDS2_BIT_CLEARING_EDGE_REGISTER 0
#define LEDS2_BIT_MODIFYING_OUTPUT_REGISTER 0
#define LEDS2_CAPTURE 0
#define LEDS2_DATA_WIDTH 2
#define LEDS2_DO_TEST_BENCH_WIRING 0
#define LEDS2_DRIVEN_SIM_VALUE 0
#define LEDS2_EDGE_TYPE NONE
#define LEDS2_FREQ 50000000
#define LEDS2_HAS_IN 0
#define LEDS2_HAS_OUT 1
#define LEDS2_HAS_TRI 0
#define LEDS2_IRQ_TYPE NONE
#define LEDS2_RESET_VALUE 0

/*
 * Macros for device 'switches2', class 'altera_avalon_pio'
 * The macros are prefixed with 'SWITCHES2_'.
 * The prefix is the slave descriptor.
 */
#define SWITCHES2_COMPONENT_TYPE altera_avalon_pio
#define SWITCHES2_COMPONENT_NAME switches2
#define SWITCHES2_BASE 0x40
#define SWITCHES2_SPAN 32
#define SWITCHES2_END 0x5f
#define SWITCHES2_BIT_CLEARING_EDGE_REGISTER 0
#define SWITCHES2_BIT_MODIFYING_OUTPUT_REGISTER 0
#define SWITCHES2_CAPTURE 0
#define SWITCHES2_DATA_WIDTH 2
#define SWITCHES2_DO_TEST_BENCH_WIRING 0
#define SWITCHES2_DRIVEN_SIM_VALUE 0
#define SWITCHES2_EDGE_TYPE NONE
#define SWITCHES2_FREQ 50000000
#define SWITCHES2_HAS_IN 1
#define SWITCHES2_HAS_OUT 0
#define SWITCHES2_HAS_TRI 0
#define SWITCHES2_IRQ_TYPE NONE
#define SWITCHES2_RESET_VALUE 0

/*
 * Macros for device 'image_sent_ocm', class 'altera_avalon_pio'
 * The macros are prefixed with 'IMAGE_SENT_OCM_'.
 * The prefix is the slave descriptor.
 */
#define IMAGE_SENT_OCM_COMPONENT_TYPE altera_avalon_pio
#define IMAGE_SENT_OCM_COMPONENT_NAME image_sent_ocm
#define IMAGE_SENT_OCM_BASE 0x40
#define IMAGE_SENT_OCM_SPAN 32
#define IMAGE_SENT_OCM_END 0x5f
#define IMAGE_SENT_OCM_BIT_CLEARING_EDGE_REGISTER 0
#define IMAGE_SENT_OCM_BIT_MODIFYING_OUTPUT_REGISTER 0
#define IMAGE_SENT_OCM_CAPTURE 0
#define IMAGE_SENT_OCM_DATA_WIDTH 1
#define IMAGE_SENT_OCM_DO_TEST_BENCH_WIRING 0
#define IMAGE_SENT_OCM_DRIVEN_SIM_VALUE 0
#define IMAGE_SENT_OCM_EDGE_TYPE NONE
#define IMAGE_SENT_OCM_FREQ 50000000
#define IMAGE_SENT_OCM_HAS_IN 0
#define IMAGE_SENT_OCM_HAS_OUT 1
#define IMAGE_SENT_OCM_HAS_TRI 0
#define IMAGE_SENT_OCM_IRQ_TYPE NONE
#define IMAGE_SENT_OCM_RESET_VALUE 0

/*
 * Macros for device 'in_dv', class 'altera_avalon_pio'
 * The macros are prefixed with 'IN_DV_'.
 * The prefix is the slave descriptor.
 */
#define IN_DV_COMPONENT_TYPE altera_avalon_pio
#define IN_DV_COMPONENT_NAME in_dv
#define IN_DV_BASE 0x50
#define IN_DV_SPAN 32
#define IN_DV_END 0x6f
#define IN_DV_BIT_CLEARING_EDGE_REGISTER 0
#define IN_DV_BIT_MODIFYING_OUTPUT_REGISTER 0
#define IN_DV_CAPTURE 0
#define IN_DV_DATA_WIDTH 1
#define IN_DV_DO_TEST_BENCH_WIRING 0
#define IN_DV_DRIVEN_SIM_VALUE 0
#define IN_DV_EDGE_TYPE NONE
#define IN_DV_FREQ 50000000
#define IN_DV_HAS_IN 0
#define IN_DV_HAS_OUT 1
#define IN_DV_HAS_TRI 0
#define IN_DV_IRQ_TYPE NONE
#define IN_DV_RESET_VALUE 0

/*
 * Macros for device 'in_fv', class 'altera_avalon_pio'
 * The macros are prefixed with 'IN_FV_'.
 * The prefix is the slave descriptor.
 */
#define IN_FV_COMPONENT_TYPE altera_avalon_pio
#define IN_FV_COMPONENT_NAME in_fv
#define IN_FV_BASE 0x60
#define IN_FV_SPAN 32
#define IN_FV_END 0x7f
#define IN_FV_BIT_CLEARING_EDGE_REGISTER 0
#define IN_FV_BIT_MODIFYING_OUTPUT_REGISTER 0
#define IN_FV_CAPTURE 0
#define IN_FV_DATA_WIDTH 1
#define IN_FV_DO_TEST_BENCH_WIRING 0
#define IN_FV_DRIVEN_SIM_VALUE 0
#define IN_FV_EDGE_TYPE NONE
#define IN_FV_FREQ 50000000
#define IN_FV_HAS_IN 0
#define IN_FV_HAS_OUT 1
#define IN_FV_HAS_TRI 0
#define IN_FV_IRQ_TYPE NONE
#define IN_FV_RESET_VALUE 0

/*
 * Macros for device 'select_i', class 'altera_avalon_pio'
 * The macros are prefixed with 'SELECT_I_'.
 * The prefix is the slave descriptor.
 */
#define SELECT_I_COMPONENT_TYPE altera_avalon_pio
#define SELECT_I_COMPONENT_NAME select_i
#define SELECT_I_BASE 0x70
#define SELECT_I_SPAN 32
#define SELECT_I_END 0x8f
#define SELECT_I_BIT_CLEARING_EDGE_REGISTER 0
#define SELECT_I_BIT_MODIFYING_OUTPUT_REGISTER 0
#define SELECT_I_CAPTURE 0
#define SELECT_I_DATA_WIDTH 32
#define SELECT_I_DO_TEST_BENCH_WIRING 0
#define SELECT_I_DRIVEN_SIM_VALUE 0
#define SELECT_I_EDGE_TYPE NONE
#define SELECT_I_FREQ 50000000
#define SELECT_I_HAS_IN 0
#define SELECT_I_HAS_OUT 1
#define SELECT_I_HAS_TRI 0
#define SELECT_I_IRQ_TYPE NONE
#define SELECT_I_RESET_VALUE 0

/*
 * Macros for device 'clock_cnn', class 'altera_avalon_pio'
 * The macros are prefixed with 'CLOCK_CNN_'.
 * The prefix is the slave descriptor.
 */
#define CLOCK_CNN_COMPONENT_TYPE altera_avalon_pio
#define CLOCK_CNN_COMPONENT_NAME clock_cnn
#define CLOCK_CNN_BASE 0x80
#define CLOCK_CNN_SPAN 32
#define CLOCK_CNN_END 0x9f
#define CLOCK_CNN_BIT_CLEARING_EDGE_REGISTER 0
#define CLOCK_CNN_BIT_MODIFYING_OUTPUT_REGISTER 0
#define CLOCK_CNN_CAPTURE 0
#define CLOCK_CNN_DATA_WIDTH 1
#define CLOCK_CNN_DO_TEST_BENCH_WIRING 0
#define CLOCK_CNN_DRIVEN_SIM_VALUE 0
#define CLOCK_CNN_EDGE_TYPE NONE
#define CLOCK_CNN_FREQ 50000000
#define CLOCK_CNN_HAS_IN 1
#define CLOCK_CNN_HAS_OUT 0
#define CLOCK_CNN_HAS_TRI 0
#define CLOCK_CNN_IRQ_TYPE NONE
#define CLOCK_CNN_RESET_VALUE 0

/*
 * Macros for device 'out_dv', class 'altera_avalon_pio'
 * The macros are prefixed with 'OUT_DV_'.
 * The prefix is the slave descriptor.
 */
#define OUT_DV_COMPONENT_TYPE altera_avalon_pio
#define OUT_DV_COMPONENT_NAME out_dv
#define OUT_DV_BASE 0x90
#define OUT_DV_SPAN 32
#define OUT_DV_END 0xaf
#define OUT_DV_BIT_CLEARING_EDGE_REGISTER 0
#define OUT_DV_BIT_MODIFYING_OUTPUT_REGISTER 0
#define OUT_DV_CAPTURE 0
#define OUT_DV_DATA_WIDTH 1
#define OUT_DV_DO_TEST_BENCH_WIRING 0
#define OUT_DV_DRIVEN_SIM_VALUE 0
#define OUT_DV_EDGE_TYPE NONE
#define OUT_DV_FREQ 50000000
#define OUT_DV_HAS_IN 1
#define OUT_DV_HAS_OUT 0
#define OUT_DV_HAS_TRI 0
#define OUT_DV_IRQ_TYPE NONE
#define OUT_DV_RESET_VALUE 0

/*
 * Macros for device 'out_fv', class 'altera_avalon_pio'
 * The macros are prefixed with 'OUT_FV_'.
 * The prefix is the slave descriptor.
 */
#define OUT_FV_COMPONENT_TYPE altera_avalon_pio
#define OUT_FV_COMPONENT_NAME out_fv
#define OUT_FV_BASE 0x100
#define OUT_FV_SPAN 32
#define OUT_FV_END 0x11f
#define OUT_FV_BIT_CLEARING_EDGE_REGISTER 0
#define OUT_FV_BIT_MODIFYING_OUTPUT_REGISTER 0
#define OUT_FV_CAPTURE 0
#define OUT_FV_DATA_WIDTH 1
#define OUT_FV_DO_TEST_BENCH_WIRING 0
#define OUT_FV_DRIVEN_SIM_VALUE 0
#define OUT_FV_EDGE_TYPE NONE
#define OUT_FV_FREQ 50000000
#define OUT_FV_HAS_IN 1
#define OUT_FV_HAS_OUT 0
#define OUT_FV_HAS_TRI 0
#define OUT_FV_IRQ_TYPE NONE
#define OUT_FV_RESET_VALUE 0

/*
 * Macros for device 'sent_new_pixel', class 'altera_avalon_pio'
 * The macros are prefixed with 'SENT_NEW_PIXEL_'.
 * The prefix is the slave descriptor.
 */
#define SENT_NEW_PIXEL_COMPONENT_TYPE altera_avalon_pio
#define SENT_NEW_PIXEL_COMPONENT_NAME sent_new_pixel
#define SENT_NEW_PIXEL_BASE 0x110
#define SENT_NEW_PIXEL_SPAN 32
#define SENT_NEW_PIXEL_END 0x12f
#define SENT_NEW_PIXEL_BIT_CLEARING_EDGE_REGISTER 0
#define SENT_NEW_PIXEL_BIT_MODIFYING_OUTPUT_REGISTER 0
#define SENT_NEW_PIXEL_CAPTURE 0
#define SENT_NEW_PIXEL_DATA_WIDTH 1
#define SENT_NEW_PIXEL_DO_TEST_BENCH_WIRING 0
#define SENT_NEW_PIXEL_DRIVEN_SIM_VALUE 0
#define SENT_NEW_PIXEL_EDGE_TYPE NONE
#define SENT_NEW_PIXEL_FREQ 50000000
#define SENT_NEW_PIXEL_HAS_IN 0
#define SENT_NEW_PIXEL_HAS_OUT 1
#define SENT_NEW_PIXEL_HAS_TRI 0
#define SENT_NEW_PIXEL_IRQ_TYPE NONE
#define SENT_NEW_PIXEL_RESET_VALUE 0

/*
 * Macros for device 'receive_new_pixel', class 'altera_avalon_pio'
 * The macros are prefixed with 'RECEIVE_NEW_PIXEL_'.
 * The prefix is the slave descriptor.
 */
#define RECEIVE_NEW_PIXEL_COMPONENT_TYPE altera_avalon_pio
#define RECEIVE_NEW_PIXEL_COMPONENT_NAME receive_new_pixel
#define RECEIVE_NEW_PIXEL_BASE 0x120
#define RECEIVE_NEW_PIXEL_SPAN 32
#define RECEIVE_NEW_PIXEL_END 0x13f
#define RECEIVE_NEW_PIXEL_BIT_CLEARING_EDGE_REGISTER 0
#define RECEIVE_NEW_PIXEL_BIT_MODIFYING_OUTPUT_REGISTER 0
#define RECEIVE_NEW_PIXEL_CAPTURE 0
#define RECEIVE_NEW_PIXEL_DATA_WIDTH 1
#define RECEIVE_NEW_PIXEL_DO_TEST_BENCH_WIRING 0
#define RECEIVE_NEW_PIXEL_DRIVEN_SIM_VALUE 0
#define RECEIVE_NEW_PIXEL_EDGE_TYPE NONE
#define RECEIVE_NEW_PIXEL_FREQ 50000000
#define RECEIVE_NEW_PIXEL_HAS_IN 1
#define RECEIVE_NEW_PIXEL_HAS_OUT 0
#define RECEIVE_NEW_PIXEL_HAS_TRI 0
#define RECEIVE_NEW_PIXEL_IRQ_TYPE NONE
#define RECEIVE_NEW_PIXEL_RESET_VALUE 0

/*
 * Macros for device 'idle_pixel', class 'altera_avalon_pio'
 * The macros are prefixed with 'IDLE_PIXEL_'.
 * The prefix is the slave descriptor.
 */
#define IDLE_PIXEL_COMPONENT_TYPE altera_avalon_pio
#define IDLE_PIXEL_COMPONENT_NAME idle_pixel
#define IDLE_PIXEL_BASE 0x130
#define IDLE_PIXEL_SPAN 32
#define IDLE_PIXEL_END 0x14f
#define IDLE_PIXEL_BIT_CLEARING_EDGE_REGISTER 0
#define IDLE_PIXEL_BIT_MODIFYING_OUTPUT_REGISTER 0
#define IDLE_PIXEL_CAPTURE 0
#define IDLE_PIXEL_DATA_WIDTH 1
#define IDLE_PIXEL_DO_TEST_BENCH_WIRING 0
#define IDLE_PIXEL_DRIVEN_SIM_VALUE 0
#define IDLE_PIXEL_EDGE_TYPE NONE
#define IDLE_PIXEL_FREQ 50000000
#define IDLE_PIXEL_HAS_IN 0
#define IDLE_PIXEL_HAS_OUT 1
#define IDLE_PIXEL_HAS_TRI 0
#define IDLE_PIXEL_IRQ_TYPE NONE
#define IDLE_PIXEL_RESET_VALUE 0


#endif /* _ALTERA_HPS_0_H_ */
