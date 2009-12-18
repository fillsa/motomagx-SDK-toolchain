/*
 * include/asm-arm/arch-mxc/board-scma11phone.h - hardware defines for
 *                                                Motorola's SCM-A11-based
 *                                                phones.
 * 
 * Copyright 2005 Freescale Semiconductor, Inc. All Rights Reserved.
 * Copyright 2006-2007 Motorola, Inc.
 */

/*
 * The code contained herein is licensed under the GNU General Public
 * License. You may obtain a copy of the GNU General Public License
 * Version 2 or later at the following locations:
 *
 * http://www.opensource.org/licenses/gpl-license.html
 * http://www.gnu.org/copyleft/gpl.html
 *
 * Date     Author    Comment
 * 10/2006  Motorola  Added board specific definitions for Motorola products.
 * 01/2007  Motorola  Added support for dynamic IPU memory pool config.
 */

#ifndef __ASM_ARM_ARCH_BOARD_SCMA11PHONE_H_
#define __ASM_ARM_ARCH_BOARD_SCMA11PHONE_H_

/*
 * Include Files
 */
#include <linux/config.h>
#include <asm/arch/board.h>

/* Start of physical RAM */
#define PHYS_OFFSET	        (0x90000000UL)

/* I2C configuration */
/*!
 * This defines the number of I2C modules in the MXC platform
 * Defined as 1, as MC13783 on ADS uses the other pins
 */
#define I2C_NR                  1
/*!
 * This define specifies the frequency divider value to be written into
 * the I2C \b IFDR register.
 */
#define I2C1_FRQ_DIV            0x07

/*!
 * @name MXC UART board level configurations
 */
/*! @{ */
/*!
 * Specify the max baudrate for the MXC UARTs for your board, do not specify a max
 * baudrate greater than 1500000. This is used while specifying the UART Power
 * management constraints.
 */
#ifdef CONFIG_MOT_FEAT_BT_MAXUARTBAUDRATE
#define MAX_UART_BAUDRATE       3000000
#else
#define MAX_UART_BAUDRATE       1500000
#endif /* CONFIG_MOT_FEAT_BT_MAXUARTBAUDRATE */
/*!
 * Specifies if the Irda transmit path is inverting
 */
#define MXC_IRDA_TX_INV         MXC_UARTUCR3_INVT
/*!
 * Specifies if the Irda receive path is inverting
 */
#define MXC_IRDA_RX_INV         0
/* UART 1 configuration */
/*!
 * This define specifies if the UART port is configured to be in DTE or
 * DCE mode. There exists a define like this for each UART port. Valid
 * values that can be used are \b MODE_DTE or \b MODE_DCE.
 */
#define UART1_MODE              MODE_DCE
/*!
 * This define specifies if the UART is to be used for IRDA. There exists a
 * define like this for each UART port. Valid values that can be used are
 * \b IRDA or \b NO_IRDA.
 */
#define UART1_IR                NO_IRDA

/*!
 * This define is used to enable or disable a particular UART port. If
 * disabled, the UART will not be registered in the file system and the user
 * will not be able to access it. There exists a define like this for each UART
 * port. Specify a value of 1 to enable the UART and 0 to disable it.
 */
#define UART1_ENABLED           1
/*! @} */
/* UART 2 configuration */
#define UART2_MODE              MODE_DCE
#define UART2_IR                NO_IRDA
#define UART2_ENABLED           1
/* UART 3 configuration */
#define UART3_MODE              MODE_DCE
#define UART3_IR                NO_IRDA
#define UART3_ENABLED           1

#define MXC_LL_UART_PADDR	UART2_BASE_ADDR
#define MXC_LL_UART_VADDR	AIPS1_IO_ADDRESS(UART2_BASE_ADDR)
#undef  MXC_LL_EXT_UART_16BIT_BUS

/*!
 * @name Memory Size parameters
 */
/*! @{ */
/*!
 * Size of SDRAM memory
 */
#define SDRAM_MEM_SIZE          SZ_64M
/*!
 * Size of IPU buffer memory
 * Note: Currently the (MXCIPU_MEM_SIZE)MB of memory is located in
 * SDRAM right after the memory allocated for kernel.
 * Need to allocate 5MB to support 2MP camera
 */
#ifndef CONFIG_MOT_FEAT_IPU_MEM_ADDR
#define MXCIPU_MEM_SIZE         (SZ_4M + SZ_1M)
#endif /* CONFIG_MOT_FEAT_IPU_MEM_ADDR */
/*!
 * Size of DSP image in SDRAM 
 */
#define DSP_MEM_SIZE		SZ_4M
/*!
 * Size of memory available to kernel
 * This is unused when we pass in the mem= parameter via the command line.
 * Changing the dsp memory size, ipu memory size, and sdram memory size
 * in this case has no effect.
 */
#ifdef CONFIG_MOT_FEAT_IPU_MEM_ADDR
/* MEM_SIZE is only used when the "mem=" boot cmdline option is missing,
 * but CONFIG_MOT_FEAT_IPU_MEM_ADDR won't work if "mem=" is not specified.
 * Thus the value of the following MEM_SIZE has no meaning in normal working
 * conditions.
 */
#define MEM_SIZE                (SDRAM_MEM_SIZE - DSP_MEM_SIZE)
#else
#define MEM_SIZE                (SDRAM_MEM_SIZE - DSP_MEM_SIZE - MXCIPU_MEM_SIZE)
#endif
/*!
 * Size and physical start address of IPU buffer memory
 * 5MB is a safe value for 2 MP camera support. 
 * The exact size depends on the hardware configuration.
 */
#if !defined(CONFIG_MOT_FEAT_IPU_MEM_ADDR)
#define MXCIPU_MEM_ADDRESS      (PHYS_OFFSET + MEM_SIZE)
#endif
/*! @} */

/*!
 * @name Keypad Configurations FIXME
 */
/*! @{ */
/*!
 * Maximum number of rows (0 to 7)
 */
#define MAXROW                  8
/*!
 * Maximum number of columns (0 to 7)
 */
#define MAXCOL                  8
/*! @} */

#define MXC_PMIC_INT_LINE	INT_EXT_INT5

/*
 * Board specific REF, AHB and IPG frequencies
 */
#define AHB_FREQ                133000000
#define IPG_FREQ                66500000

/*
 * Globals used for IPC channel assignment over SDMA
 */
#define IPC_RX_CHANNEL 1
#define IPC_TX_CHANNEL 2

#endif				/* __ASM_ARM_ARCH_BOARD_SCMA11PHONE_H_ */
