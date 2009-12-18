/*
 * motfb.h
 *
 * Copyright 2006-2007 Motorola, Inc.
 *
 * This library is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation; either version 2.1 of the License,
 * or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place, Suite 330,
 * Boston, MA 02111-1307 USA
 *
 * Date     Author    Comment
 * 10/2006  Motorola  Initial version.  Added Motorola specific IOCTL
 *                    interfaces and type definitions for both the MXCFB and
 *                    MXCFB_HVGA framebuffer drivers.
 */

#ifndef __LINUX_MOTFB_H__
#define __LINUX_MOTFB_H__

/* Panic text on display */
#if !defined(__KERNEL__) || defined(CONFIG_MOT_FEAT_FB_PANIC_TEXT)
#define PANIC_MAX_STR_LEN       24
#define FBIOPANICTEXT		_IOW('M', 0xb3, char *)
#endif

#if !defined(__KERNEL__) || defined(CONFIG_MOT_FEAT_IPU_IOCTL)

typedef enum bklight_state {
	BKLIGHT_OFF,
	BKLIGHT_ON,
} bklight_state_t;

#define MIN_BRIGHTNESS		0
#define MAX_BRIGHTNESS		100
#define DEFAULT_BRIGHTNESS	MAX_BRIGHTNESS

struct backlight_brightness_range {
	unsigned long min;
	unsigned long max;
};

/* Mask for ON/OFF of the MAIN and CLI panels */
typedef enum panel {
	PANEL_OFF = 0,
	MAIN_PANEL = 1,
	CLI_PANEL = 2,
} panel_t;

/* Returns the type of display with respect to backlight brightness requirement i.e.,
 * TRANSMISSIVE : A TRANSMISSIVE display cannot be seen without backlight
 * TRANSFLECTIVE : A TRANSFLECTIVE display can still be seen without backlight
 * */
typedef enum {
        TRANSMISSIVE_DISPLAY,
        TRANSFLECTIVE_DISPLAY,
} display_type_t;

/* added for backlight control */
#define FBIOSETBKLIGHT          _IOW('M', 0xb4, size_t)
#define FBIOGETBKLIGHT          _IOR('M', 0xb5, size_t)
#define FBIOSETBRIGHTNESS       _IOW('M', 0xb6, __u8)
#define FBIOGETBRIGHTNESS       _IOR('M', 0xb7, __u8)
#define FBIOSET_BRIGHTNESSRANGE _IOW('M', 0xb8, struct backlight_brightness_range)

#endif				/* !defined(__KERNEL__) || defined(CONFIG_MOT_FEAT_IPU_IOCTL) */

#if !defined(__KERNEL__) || defined(CONFIG_MOT_FEAT_IPU_IOCTL_EZX_COMPAT)
#include <linux/fb.h>		/* needed for struct fb_fix_screeninfo definition */

struct fb_ovl2_mapinfo {
	unsigned long ovl2_offset;
	unsigned long ovl2_size;
	unsigned long ovl2_priv;
	unsigned long ovl2_framelen;
	unsigned long aylen;
	unsigned long acblen;
	unsigned long acrlen;
};
#define FBIOENABLE2BFS          _IO( 'M', 0xb9)
#define FBIODISABLE2BFS         _IO( 'M', 0xba)
#define FBIOCHECK2BFS           _IOR('M', 0xbb, unsigned long)
#define FBIOCKMAINVALIDFB       _IO( 'M', 0xbc)
#define FBIOENABLEOVL2          _IOR('M', 0xbd, __u8)
#define FBIODISABLEOVL2         _IOR('M', 0xbe, __u8)
#define FBIOGET_OVL2_MAPINFO    _IOR('M', 0xbf, struct fb_ovl2_mapinfo)
#define FBIOGET_OVL2FIX		_IOR('M', 0xc0, struct fb_fix_screeninfo)
#define FBIOGET_OVL2VAR	        _IOR('M', 0xc1, struct fb_var_screeninfo)
#define FBIOPUT_OVL2VAR	        _IOW('M', 0xc2, struct fb_var_screeninfo)
#define FBIOPAN_DISPLAY_OVL2    _IOW('M', 0xc3, struct fb_var_screeninfo)
#define FBIOADJUST_TRANS	_IOW('M', 0xc4, unsigned short)
#if !defined(__KERNEL__) || defined(CONFIG_MOT_FEAT_EMULATED_CLI)
#define FBIOSMARTUPDATE         _IO( 'M', 0xd0)
#define FBIOENTERCLIPWRSAVE     _IO( 'M', 0xd1)
#define FBIOEXITCLIPWRSAVE      _IO( 'M', 0xd2)
#endif /* !defined(__KERNEL__) || defined(CONFIG_MOT_FEAT_EMULATED_CLI) */
#endif /* !defined(__KERNEL__) || defined(CONFIG_MOT_FEAT_IPU_IOCTL_EZX_COMPAT) */
#if !defined(__KERNEL__) || defined(CONFIG_MOT_FEAT_EMULATED_CLI)
#define FBIOENABLE_EMULATEDCLI  _IO( 'M', 0xd3)
#define FBIODISABLE_EMULATEDCLI _IO( 'M', 0xd4)
#endif
#if !defined(__KERNEL__) || defined(CONFIG_MOT_FEAT_IPU_IOCTL)
#define FBIO_QUERY_DISPLAY_TYPE _IOR('M', 0xd5, display_type_t)
#endif

#if !defined(__KERNEL__) || defined(CONFIG_FB_MXC_HVGA_PANEL)

/* color depth : high or low color mode */
typedef enum {
	low_power_monochrome, /* monochrome color mode for power-savings */
	low_power_color, /* low color mode for power-savings */
	full_color, /* normal full color */
} color_depth_t;

/* 
 * Partial mode coordinates. On the HVGA TMD display, the start_x and 
 * end_x values are ignored. 
 */
struct partial_mode_info {
	uint32_t start_x;
	uint32_t start_y;
	uint32_t end_x;
	uint32_t end_y;
};

/* 
 * Static-mode state. When static mode is ENABLED, DMA transfer to the 
 * particular panel is DISABLED. When static mode is DISABLED, pixel data 
 * is once again sent to the panel. This mode is intended for use on SMART 
 * displays where the panel will refresh the pixels using its internal 
 * memory and oscillator.
 */
typedef enum {
	ENTER_STATIC_MODE,
	EXIT_STATIC_MODE,
	UPDATE_STATIC_IMAGE,
} static_state_t;

#define FBIOSET_OVERLAY_PANEL   _IOW('M', 0xe0, panel_t)
#define FBIOGET_CURRENT_PANEL   _IOR('M', 0xe1, unsigned long)
#define FBIOSWAP_BUFFERS        _IO('M', 0xe2)

#define FBIOPARTIALMODE         _IOW('M', 0xe6, struct partial_mode_info)
#define FBIOSTATICIMAGE         _IOW('M', 0xea, static_state_t)
#define FBIOSET_COLOR_DEPTH     _IOW('M', 0xef, color_depth_t)
#endif

#if defined(__KERNEL__)

#if defined(CONFIG_MOT_FEAT_IPU_IOCTL_EZX_COMPAT)
#define DBUFFER_ENABLED  	true
#define DBUFFER_DISABLED	false
#endif

#if defined(CONFIG_MOT_FEAT_IPU_IOCTL)

/* Masks for brightness setting */
#define BACKLIGHT_ON		0x1
#define DISPLAY_ON    		0x2

#if defined(CONFIG_FB_MXC_HVGA_PANEL)
/* 
 * Mask for defining the refresh mode. While in full refresh mode, data will be
 * continuously sent to the display at refresh_rate times per second.  This state
 * is used when reconfiguring the DMA channel to decide which DMA mode we are in.
 *
 * Possible DMA modes are:
 *   1. Full HVGA DMA of both MAIN and CLI pixel data. 
 *   2. QVGA DMA of the MAIN pixel data. The CLI is either OFF or in STATIC mode.
 *   3. QVGA DMA of the CLI pixel data. The MAIN is either OFF or in STATIC mode.
 *   4. No active DMA. 
 *  
 * While in (1) full HVGA refresh, the MAIN panel's pixel data is sent first, 
 * followed by the CLI pixel data.
 */
typedef enum {
	REFRESH_OFF = 0x00,
	MAIN_FULL_REFRESH = 0x01,
	CLI_FULL_REFRESH = 0x02,
} refresh_mode_t;

typedef enum {
	NO_STATIC_MODE,
	MAIN_STATIC_MODE,
	CLI_STATIC_MODE,
} static_image_mode_state_t;


/*
 * Pixel data can be DMA'd to the display either through an 18-bit parallel
 * interface or serially through a SPI interface.  The HVGA design current supports
 * DMA only over the parallel interface, and the SPI line is used exclusively to send 
 * commands to the panel.  However, in the future we may support MODE_SPI, which 
 * would DMA data to the panel over SPI.
 */
typedef enum disp_intf_mode {
        MODE_RGB,
        MODE_SPI,
} disp_intf_mode_t;
#endif

/* Holds global information about the state of the panel */
struct global_state {
	struct semaphore g_sem; /* This mutex must be held whenever modifying global_state */
	uint32_t brightness; /* Current brightness setting of the display */
	bklight_state_t backlight_state; /* Backlight ON/OFF state */
	struct backlight_brightness_range bklight_range; /* MIN and MAX backlight brightness levels */
#if defined(CONFIG_FB_MXC_HVGA_PANEL)
	panel_t panel_state; /* The panel ON/OFF state. This says nothing about DMA */
	panel_t overlay_panel; /* The panel the overlay is currently enabled on */
	refresh_mode_t refresh_mode; /* The current DMA mode */
	static_image_mode_state_t static_image_mode_state; /* Maintains static image mode for both main and CLI */
	disp_intf_mode_t disp_intf; /* The display interface, either RGB or SPI */
	color_depth_t curr_color_depth; /* Full 18-bit color or low-power 8-bit color */
	color_depth_t main_color_depth; /* Full 18-bit color or low-power 8-bit color */
	color_depth_t cli_color_depth; /* Full 18-bit color or low-power 8-bit color */
	struct partial_mode_info main_partial_coords; /* Main panel's partial mode coordinates */
	struct partial_mode_info cli_partial_coords; /* CLI panel's partial mode coordinates */
	unsigned long buffers_swapped; /* True if MAIN and CLI images are swapped */
#endif
#if defined(CONFIG_MOT_FEAT_IPU_IOCTL_EZX_COMPAT)
	unsigned char dbuffer_enabled; /* True if Double Buffering is enabled */
#endif
};

#endif				/* defined(CONFIG_MOT_FEAT_IPU_IOCTL) */
#endif				/* defined(__KERNEL__) */
#endif				/* __LINUX_MOTFB_H__ */
