/*
 *
 *  BlueZ - Bluetooth(R) protocol stack for Linux
 *
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
 *  $Id: rfcomm.h,v 1.15 2005/04/27 10:49:43 holtmann Exp $
 *
 *
 *  Copyright (C) 2005-2006 - Motorola
 *
 *  Date         Author           Comment
 *  -----------  --------------   --------------------------------
 *  2005-Oct-26  Motorola         changes structs to __attribute__((packed)) to work around ABI issues
 *  2006-Jan-17  Motorola         Added __PACKED__ macro to pack structures only for arm
 *  2006-Apr-05	 Motorola         adds the RFCOMM_FLOW_ON_TTY_OPEN sockopt()
 *  2006-Nov-02  Motorola         changes to enhance RFCOMM channel establishment
 *
 */


#ifndef __RFCOMM_H
#define __RFCOMM_H

#ifdef __arm__
# define __PACKED__ __attribute__ ((packed))
#else
# define __PACKED__
#endif

#ifdef __cplusplus
extern "C" {
#endif

#include <sys/socket.h>

/* RFCOMM defaults */
#define RFCOMM_DEFAULT_MTU	127

#define RFCOMM_PSM 3

#define RFCOMM_CONN_TIMEOUT	(HZ * 30)
#define RFCOMM_DISC_TIMEOUT	(HZ * 20)

/* RFCOMM socket address */
struct sockaddr_rc {
	sa_family_t	rc_family;
	bdaddr_t	rc_bdaddr;
	uint8_t		rc_channel;
} __PACKED__;

/* RFCOMM socket options */
#define RFCOMM_CONNINFO	0x02
struct rfcomm_conninfo {
	uint16_t	hci_handle;
	uint8_t		dev_class[3];
} __PACKED__;

#define RFCOMM_LM	0x03
#define RFCOMM_LM_MASTER        0x0001
#define RFCOMM_LM_AUTHENTICATE  0x0002
#define RFCOMM_LM_ENCRYPT       0x0004
#define RFCOMM_LM_TRUSTED       0x0008
#define RFCOMM_LM_RELIABLE      0x0010
#define RFCOMM_LM_SECURE        0x0020
#define RFCOMM_LM_AUTHORIZE     0x0040

#define RFCOMM_FLOW_ON_TTY_OPEN 0x04
    
/* RFCOMM TTY support */
#define RFCOMM_MAX_DEV	256

#define RFCOMMCREATEDEV         _IOW('R', 200, int)
#define RFCOMMRELEASEDEV        _IOW('R', 201, int)
#define RFCOMMGETDEVLIST        _IOR('R', 210, int)
#define RFCOMMGETDEVINFO        _IOR('R', 211, int)
#define RFCOMMSETAUTHORIZATION  _IOW('R', 230, int)

struct rfcomm_dev_req {
	int16_t		dev_id;
	uint32_t	flags;
	bdaddr_t	src;
	bdaddr_t	dst;
	uint8_t	channel;
} __PACKED__;
#define RFCOMM_REUSE_DLC	0
#define RFCOMM_RELEASE_ONHUP	1
#define RFCOMM_HANGUP_NOW	2
#define RFCOMM_TTY_ATTACHED	3

struct rfcomm_dev_info {
	int16_t		id;
	uint32_t	flags;
	uint16_t	state;
	bdaddr_t	src;
	bdaddr_t	dst;
	uint8_t		channel;
} __PACKED__;

struct rfcomm_dev_list_req {
	uint16_t	dev_num;
	struct rfcomm_dev_info dev_info[0];
} __PACKED__;

#ifdef __cplusplus
}
#endif

#endif /* __RFCOMM_H */
