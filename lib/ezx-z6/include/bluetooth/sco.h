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
 *  $Id: sco.h,v 1.5 2005/01/29 03:08:20 holtmann Exp $
 *
 *
 *  Copyright (C) 2005-2006 - Motorola
 *
 *  Date         Author           Comment
 *  -----------  --------------   --------------------------------
 *  2005-Oct-26  Motorola         changes structs to __attribute__((packed)) to work around ABI issues
 *  2006-Jan-17  Motorola         Added __PACKED__ macro to pack structures only for arm
 *
 */


#ifndef __SCO_H
#define __SCO_H

#ifdef __arm__
# define __PACKED__ __attribute__ ((packed))
#else
# define __PACKED__
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* SCO defaults */
#define SCO_DEFAULT_MTU		500
#define SCO_DEFAULT_FLUSH_TO	0xFFFF

#define SCO_CONN_TIMEOUT	(HZ * 40)
#define SCO_DISCONN_TIMEOUT	(HZ * 2)
#define SCO_CONN_IDLE_TIMEOUT	(HZ * 60)

/* SCO socket address */
struct sockaddr_sco {
	sa_family_t	sco_family;
	bdaddr_t	sco_bdaddr;
} __PACKED__;

/* set/get sockopt defines */
#define SCO_OPTIONS	0x01
struct sco_options {
	uint16_t	mtu;
} __PACKED__;

#define SCO_CONNINFO	0x02
struct sco_conninfo {
	uint16_t	hci_handle;
	uint8_t		dev_class[3];
} __PACKED__;

#ifdef __cplusplus
}
#endif

#endif /* __SCO_H */
