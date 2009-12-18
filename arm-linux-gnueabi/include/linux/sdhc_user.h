/*
 * Copyright © 2005-2006, Motorola, All Rights Reserved.
 *
 * This program is licensed under a BSD license with the following terms:
 *
 * Redistribution and use in source and binary forms, with or without modification, are permitted
 * provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice, this list of conditions
 *   and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright notice, this list of
 *   conditions and the following disclaimer in the documentation and/or other materials provided
 *   with the distribution.
 * - Neither the name of Motorola nor the names of its contributors may be used to endorse or
 *   promote products derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
 * FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
 * OF SUCH DAMAGE.
 *
 * Motorola 2006-Aug-16 - Add R7 response define
 * Motorola 2005-Oct-26 - Initial Creation
 */

#ifndef __SDHC_USER_H__
#define __SDHC_USER_H__

/*!
 * @file sdhc_user.h
 *
 * @ingroup sdhc
 *
 * @brief Contains user mode SDHC interface information (types, enums, macros, functions, etc.)
 */

#include <linux/ioctl.h>
#include <stdbool.h>

/*! @brief The major number of the user mode SDHC driver. */
#define MOTO_SDHC_DRIVER_MAJOR_NUM 223
/*! @brief The name of the user mode SDHC driver. */
#define MOTO_SDHC_DRIVER_DEV_NAME  "sdhc_user"

/*!
 * @name SDIO card responses
 *
 * The value for the "format of reponse" bits in the CMD_DAT_CONT register.
 * Please see the SCMA11 spec section 78.3.3.4 for more information.
 */
/*! @{ */
#define MOTO_SDHC_NO_RESP    0   /* No response for current command */
#define MOTO_SDHC_R1_RESP    1   /* 48-bit response with CRC7 */
#define MOTO_SDHC_R2_RESP    2   /* 136-bit, CSD/CID read response */
#define MOTO_SDHC_R3_RESP    3   /* 48-bit response without CRC check */
#define MOTO_SDHC_R6_RESP    1   /* 48-bit response with CRC7 */
#define MOTO_SDHC_R7_RESP    1   /* 48-bit response with CRC7 */
/*! @} */

/*!
 * @brief Get the SDHC parameters and place in the pointer to MOTO_SDHC_PARAMETER_T.
 *
 * Read the SDHC parameters from the kernel SDHC device driver and copy the data
 * to the user provided pointer.  If the module select entry contains
 * MOTO_SDHC_MS__END then the SDHC parameters have not yet been initialized.
 * In this case the other entries are not valid.
 *
 * @return -EFAULT upon an error copying the data to user space.<BR>
 *         0 upon success.
 *
 * @note See MOTO_SDHC_PARAMETER_T for more information on the data copied.
 */
#define MOTO_SDHC_IOCTL_GET_SDHC_PARAMS \
    _IOR(MOTO_SDHC_DRIVER_MAJOR_NUM, 0x00, MOTO_SDHC_PARAMETER_T *)

/*!
 * @brief Set the SDHC parameters provided by a pointer to MOTO_SDHC_PARAMETER_T.
 *
 * Sets the kernel SDHC parameters provided by the pointer to
 * MOTO_SDHC_PARAMETER_T.  The module select entry must contain a value less
 * than MOTO_SDHC_MS__END (see MOTO_SDHC_MS_T) or the data will not be set.
 *
 * @return -EFAULT upon an error copying the data to user space.<BR>
 *         -EINVAL for invalid module select.<BR>
 *         0 upon success.
 *
 * @note See MOTO_SDHC_PARAMETER_T for more information on the data copied.
 */
#define MOTO_SDHC_IOCTL_SET_SDHC_PARAMS \
    _IOW(MOTO_SDHC_DRIVER_MAJOR_NUM, 0x01, MOTO_SDHC_PARAMETER_T *)

/*!
 * @brief Sends commands over the SDHC.
 *
 * Sends commands provided by the caller via the SDHC.  Reads and writes should
 * not use this IOCTL - please use MOTO_SDHC_IOCTL_DATA.
 *
 * The response can be transfered from kernel memory to user memory.
 * This is provided for cases when a user application must copy data
 * directly into kernel structures.  (For example if the user space app
 * is used as a helper to the user block device (usr_blk_dev).
 *
 * @return -ENOTCONN if the parameters have yet to be setup.<BR>
 *         -EFAULT if an error happens when copying to user space.<BR>
 *         0 upon success.
 */
#define MOTO_SDHC_IOCTL_CMD \
    _IOW(MOTO_SDHC_DRIVER_MAJOR_NUM, 0x02, MOTO_SDHC_COMMAND_T *)

/*!
 * @brief Allows for reads and writes over the SDHC.
 *
 * Commands should not use this IOCTL - please use MOTO_SDHC_IOCTL_CMD.
 *
 * The responses and reads can be transfered from kernel memory to user memory.
 * In addition, write data can be transfered from user memory to kernel memory.
 * This is provided for cases when a user application must copy data
 * directly into kernel structures.  (For example if the user space app
 * is used as a helper to the user block device (usr_blk_dev).  If the data
 * is from user space it will be copied into some scratch buffers for
 * transmission by the kernel SDHC driver.
 *
 * @return -ENOTCONN if the parameters have yet to be setup.<BR>
 *         -EFAULT if an error happens when copying to or from user space.<BR>
 *         -ENOMEM if no memory is available for a data buffer.<BR>
 *         0 upon success.
 */
#define MOTO_SDHC_IOCTL_DATA \
    _IOW(MOTO_SDHC_DRIVER_MAJOR_NUM, 0x03, MOTO_SDHC_TRANSCEIVE_T *)

/*!
 * @brief Indicates the beginning or end of a sequence of commands.
 *
 * This should be called at the beginning and end of a sequence of commands.
 * If necessary, the low level driver will perform additional work.
 *
 * @return 0 upon success.
 */
#define MOTO_SDHC_IOCTL_SEQ \
    _IOW(MOTO_SDHC_DRIVER_MAJOR_NUM, 0x04, MOTO_SDHC_SEQ_T)

/*!
 * @brief Allows user space to reset the SDHC modules
 *
 * This should be called when the SDHC hardware is either locked up, or needed
 * to get back into a known state.
 *
 * @return 0 upon success.
 */
#define MOTO_SDHC_IOCTL_RESET \
    _IOW(MOTO_SDHC_DRIVER_MAJOR_NUM, 0x05, MOTO_SDHC_MS_T)

/*! @brief Command sequence begin/end enumeration. */
typedef enum
{
    /*! @brief Informs the driver this is the beginning of a sequence. */
    MOTO_SDHC_SEQ_BEGIN,
    /*! @brief Informs the driver this is the end of a sequence. */
    MOTO_SDHC_SEQ_END
} MOTO_SDHC_SEQ_T;

/*! @brief The list of module selects which can be accessed from user space. */
typedef enum
{
    /*! @brief The module select for the trans flash is SDHC1. */
    MOTO_SDHC_MS_TFLASH,
    /*!
     * @brief The last entry in the enumeration, it does not correspond to any
     *        module select.  All new values must be placed above this entry.
     */
    MOTO_SDHC_MS__END
} MOTO_SDHC_MS_T;

/*!
 * @brief Holds the user selectable parameters for SDHC transmissions.
 *
 * This contains the subset of the kernel SDHC driver parameters which are
 * allowed to be set by user space applications.  This is done for both
 * security reasons and to keep the kernel SDHC driver header file private
 * to the kernel.
 */
typedef struct
{
    /*! @brief The module select which the data will be send out on. */
    MOTO_SDHC_MS_T ms;

    /*! @brief Specifies the width of the data bus.  False = 1-bit, True = 4-bit. */
    unsigned int four_bit_bus:1;

    /*!
     * @brief Controls if an additional 80 clock cycle prefix will happen before sending a
     * command.  False = disable, True = enable.
     */
    unsigned int clk_prefix:1;

    /*! @brief Specifies the length of the data blocks. */
    uint16_t blk_len;

    /*!
     * @brief Speed for the transceive.
     *
     * The value to be set in the CLK_RATE register.
     */
    uint16_t speed;
} MOTO_SDHC_PARAMETER_T;

/*! @brief Structure holding information about a SDIO command transfer */
typedef struct
{
    /*! @brief Command to be sent to the card. */
    uint8_t command;

    /*! @brief Argument to be sent to the card. */
    uint32_t argument;

    /*!
     * @brief Sets the response format for the command.
     *
     * 00 = No response for command
     * 01 = R1/R6 (48-bit response with CRC7)
     * 10 = R2 (136-bit, CSD/CID read response)
     * 11 = R3 (48-bit response without CRC check)
     *
     * When setting this variable, please use the SDIO card response
     * defines which are found near the top of this file.
     */
    unsigned int format_of_response:2;

    /*! @brief 1 if resp pointer is a kernel-space pointer, 0 for user space. */
    unsigned int resp_is_kernel_space:1;

    /*!
     * @brief Pointer to where received response should be placed
     *
     * This can be in either kernel space or user space based on the value
     * of resp_is_kernel_space.  If the pointer is NULL, then the received
     * response (if any) will be placed in a scratch buffer and discarded.
     */
    void *resp;
} MOTO_SDHC_COMMAND_T;

/*! @brief Structure holding information about a SDIO data transfer */
typedef struct
{
    /*! @brief Command to be sent to the card. */
    uint8_t command;

    /*! @brief Argument to be sent to the card. */
    uint32_t argument;

    /*! @brief Number of blocks of data to transmit/receive. */
    uint16_t nob;

    /*!
     * @brief Specifies whether the data transfer of the current command is a write or read
     * operation.  0=read, 1=write
     */
    unsigned int is_write:1;

    /*! @brief 1 if resp pointer is a kernel-space pointer, 0 for user space. */
    unsigned int resp_is_kernel_space:1;

    /*! @brief 1 if data pointer is a kernel-space pointer, 0 for user space. */
    unsigned int data_is_kernel_space:1;

    /*!
     * @brief Pointer to where received response should be placed
     *
     * This can be in either kernel space or user space based on the value
     * of resp_is_kernel_space.  If the pointer is NULL, then the received
     * response (if any) will be placed in a scratch buffer and discarded.
     */
    void *resp;

    /*!
     * @brief Pointer to data to transmit (writes) or place received data (reads).
     *
     * The data can be in either user space or kernel space, depending on the value
     * of data_is_kernel_space. This can be NULL if this is not a data command
     */
    void *data;
} MOTO_SDHC_TRANSCEIVE_T;

#endif /* __SDHC_USER_H__ */
