/*
 *
 *  BlueZ - Bluetooth(R) protocol stack for Linux
 *
 *  Copyright (C) 2000-2001  Qualcomm Incorporated
 *  Copyright (C) 2002-2003  Maxim Krasnyansky <maxk@qualcomm.com>
 *  Copyright (C) 2002-2005  Marcel Holtmann <marcel@holtmann.org>
 *
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as
 *  published by the Free Software Foundation;
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 *  OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT OF THIRD PARTY RIGHTS.
 *  IN NO EVENT SHALL THE COPYRIGHT HOLDER(S) AND AUTHOR(S) BE LIABLE FOR ANY
 *  CLAIM, OR ANY SPECIAL INDIRECT OR CONSEQUENTIAL DAMAGES, OR ANY DAMAGES 
 *  WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN 
 *  ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF 
 *  OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 *
 *  ALL LIABILITY, INCLUDING LIABILITY FOR INFRINGEMENT OF ANY PATENTS, 
 *  COPYRIGHTS, TRADEMARKS OR OTHER RIGHTS, RELATING TO USE OF THIS 
 *  SOFTWARE IS DISCLAIMED.
 *
 *
 *  $Id: l2cap.h,v 1.12 2005/04/27 10:49:43 holtmann Exp $
 *
 *
 *  Copyright (C) 2005-2006 - Motorola
 *
 *  Date         Author           Comment
 *  -----------  --------------   --------------------------------
 *  2005-Jun-16  Motorola         Adding fix for packing one of the socket structure since its size 
 *				  is different between user space/kernel space
 *  2005-Oct-26  Motorola         changes structs to __attribute__((packed)) to work around ABI issues
 *  2006-Jan-17  Motorola         Added __PACKED__ macro to pack structures only for arm
 *  2006-Feb-12	 Motorola	  Changes to add the l2cap device driver functionality
 *       			  1. Define L2CAPCREATEDEV
 *      			  2. Define L2CAPRELASEDEV
 *  2006-Dec-14	 Motorola	      Added l2cap_echo_data structure
 *
 *
 */


#ifndef __L2CAP_H
#define __L2CAP_H

#ifdef __arm__
# define __PACKED__ __attribute__ ((packed))
#else
# define __PACKED__
#endif

#ifdef __cplusplus
extern "C" {
#endif

#include <sys/socket.h>

/* L2CAP defaults */
#define L2CAP_DEFAULT_MTU	672
#define L2CAP_DEFAULT_FLUSH_TO	0xFFFF

#define L2CAP_CONN_TIMEOUT	(HZ * 40)

/* L2CAP socket address */
struct sockaddr_l2 {
	sa_family_t	l2_family;
	unsigned short	l2_psm;
	bdaddr_t	l2_bdaddr;
} __PACKED__;

/* L2CAP socket options */
#define L2CAP_OPTIONS	0x01
struct l2cap_options {
	uint16_t	omtu;
	uint16_t	imtu;
	uint16_t	flush_to;
	uint8_t		mode;
} __PACKED__;

#define L2CAP_CONNINFO	0x02
struct l2cap_conninfo {
	uint16_t	hci_handle;
	uint8_t		dev_class[3];
} __PACKED__;

#define L2CAP_LM	0x03
#define L2CAP_LM_MASTER		0x0001
#define L2CAP_LM_AUTH		0x0002
#define L2CAP_LM_ENCRYPT	0x0004
#define L2CAP_LM_TRUSTED	0x0008
#define L2CAP_LM_RELIABLE	0x0010
#define L2CAP_LM_SECURE		0x0020

/* L2CAP command codes */
#define L2CAP_COMMAND_REJ	0x01
#define L2CAP_CONN_REQ		0x02
#define L2CAP_CONN_RSP		0x03
#define L2CAP_CONF_REQ		0x04
#define L2CAP_CONF_RSP		0x05
#define L2CAP_DISCONN_REQ	0x06
#define L2CAP_DISCONN_RSP	0x07
#define L2CAP_ECHO_REQ		0x08
#define L2CAP_ECHO_RSP		0x09
#define L2CAP_INFO_REQ		0x0a
#define L2CAP_INFO_RSP		0x0b

/* L2CAP structures */
typedef struct {
	uint16_t	len;
	uint16_t	cid;
} __attribute__ ((packed)) l2cap_hdr;
#define L2CAP_HDR_SIZE 4

typedef struct {
	uint8_t		code;
	uint8_t		ident;
	uint16_t	len;
} __attribute__ ((packed)) l2cap_cmd_hdr;
#define L2CAP_CMD_HDR_SIZE 4

typedef struct {
	uint16_t	reason;
} __attribute__ ((packed)) l2cap_cmd_rej;
#define L2CAP_CMD_REJ_SIZE 2

typedef struct {
	uint16_t	psm;
	uint16_t	scid;
} __attribute__ ((packed)) l2cap_conn_req;
#define L2CAP_CONN_REQ_SIZE 4

typedef struct {
	uint16_t	dcid;
	uint16_t	scid;
	uint16_t	result;
	uint16_t	status;
} __attribute__ ((packed)) l2cap_conn_rsp;
#define L2CAP_CONN_RSP_SIZE 8

/* connect result */
#define L2CAP_CR_SUCCESS	0x0000
#define L2CAP_CR_PEND		0x0001
#define L2CAP_CR_BAD_PSM	0x0002
#define L2CAP_CR_SEC_BLOCK	0x0003
#define L2CAP_CR_NO_MEM		0x0004

/* connect status */
#define L2CAP_CS_NO_INFO	0x0000
#define L2CAP_CS_AUTHEN_PEND	0x0001
#define L2CAP_CS_AUTHOR_PEND	0x0002

typedef struct {
	uint16_t	dcid;
	uint16_t	flags;
	uint8_t		data[0];
} __attribute__ ((packed)) l2cap_conf_req;
#define L2CAP_CONF_REQ_SIZE 4

typedef struct {
	uint16_t	scid;
	uint16_t	flags;
	uint16_t	result;
	uint8_t		data[0];
} __attribute__ ((packed)) l2cap_conf_rsp;
#define L2CAP_CONF_RSP_SIZE 6

#define L2CAP_CONF_SUCCESS	0x0000
#define L2CAP_CONF_UNACCEPT	0x0001
#define L2CAP_CONF_REJECT	0x0002
#define L2CAP_CONF_UNKNOWN	0x0003

typedef struct {
	uint8_t		type;
	uint8_t		len;
	uint8_t		val[0];
} __attribute__ ((packed)) l2cap_conf_opt;
#define L2CAP_CONF_OPT_SIZE 2

#define L2CAP_CONF_MTU		0x01
#define L2CAP_CONF_FLUSH_TO	0x02
#define L2CAP_CONF_QOS		0x03
#define L2CAP_CONF_RFC		0x04
#define L2CAP_CONF_RFC_MODE	0x04

#define L2CAP_CONF_MAX_SIZE	22

typedef struct {
	uint16_t	dcid;
	uint16_t	scid;
} __attribute__ ((packed)) l2cap_disconn_req;
#define L2CAP_DISCONN_REQ_SIZE 4

typedef struct {
	uint16_t	dcid;
	uint16_t	scid;
} __attribute__ ((packed)) l2cap_disconn_rsp;
#define L2CAP_DISCONN_RSP_SIZE 4

typedef struct {
	uint16_t	type;
	uint8_t		data[0];
} __attribute__ ((packed)) l2cap_info_req;
#define L2CAP_INFO_REQ_SIZE 2

typedef struct {
	uint16_t	type;
	uint16_t	result;
	uint8_t		data[0];
} __attribute__ ((packed)) l2cap_info_rsp;
#define L2CAP_INFO_RSP_SIZE 4

/* info type */
#define L2CAP_IT_CL_MTU		0x0001
#define L2CAP_IT_FEAT_MASK	0x0002

/* info result */
#define L2CAP_IR_SUCCESS	0x0000
#define L2CAP_IR_NOTSUPP	0x0001

/*  ----- L2cap device driver support ------*/
#define L2CAPCREATEDEV  _IOW('R',300,int)
#define L2CAPRELEASEDEV _IOW('R',301,int)
#define L2CAPECHO       _IOW('R',302,int)

struct l2cap_echo_data { 
	uint16_t dlen; 
	uint8_t data[0]; 
} __PACKED__;

#ifdef __cplusplus
}
#endif

#endif /* __L2CAP_H */
