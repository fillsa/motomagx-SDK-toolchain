/*
 *  camera.h
 *
 *  Camera Interface driver.
 *
 *  Copyright (C) 2006-2007 Motorola Inc.
 *
 *  Author: Motorola Inc.
 * 
 *  This library is free software; you can redistribute it and/or modify it
 *  under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation; either version 2.1 of the License, or (at 
 *  your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful, but 
 *  WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY 
 *  or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public 
 *  License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License 
 *  along with this library; if not, write to the Free Software Foundation, 
 *  Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 *
 
Revision History:
                   Modification     
Author                 Date        Description of Changes
----------------   ------------    -------------------------
Motorola            12/07/2006     Created
Motorola            01/04/2007     OSS code changes
*/

/*=============================================================================
                                 INCLUDE FILES
=============================================================================*/
#ifndef __CAMERA_H__ 
#define __CAMERA_H__ 

/*!
 *  General description of the Motorola video device driver:
 *
 *  The video device driver has a "character special" file named /dev/video0. 
 *  Developers can access the video device via the file operator interfaces.
 *  Six file operator interfaces are supported:
 *     open
 *     ioctl
 *     mmap
 *     poll/select
 *     read
 *     close
 *  For information on using these fuctions, please refer to the standard linux
 *  development documents.
 *  
 *  These following ioctl interfaces are important for getting the video 
 *  device to work properly.
 * 
 */

/*!
 * WCAM_VIDIOCGSNAME Gets the name of the camera sensor.
 *
 * The following code gets the name of the camera sensor:
 *
 *   char name[32];
 *   //dev is the video device handle 
 *   ioctl(dev, WCAM_VIDIOCGSNAME, name);
 *   printf("The sensor name is %s\n", name);
 *
 */
#define WCAM_VIDIOCGSNAME       200

/*!
 * WCAM_VIDIOCGMINMAX Gets minimum and maximum dimensions for sensor.
 *
 * The following code gets the min/max information:
 *
 *   min_max_t cap;
 *   //dev is the video device handle 
 *   ioctl(dev, WCAM_VIDIOCGMINMAX, &cap);
 *   printf("max width is %d, max height is %d\n", cap.max_width, cap.max_height);
 *   printf("min width is %d, min height is %d\n", cap.min_width, cap.min_height);
 *
 */
#define WCAM_VIDIOCGMINMAX      201

typedef struct min_max_s
{
    int max_width;
    int max_height;
    int min_width;
    int min_height;
} min_max_t;

/*!
 * WCAM_VIDIOCGBUFINFO Gets image frame buffer info.
 *
 * The following code gets the image frame buffer info:
 *
 *   buf_info_t buf;
 *   //dev is the video device handle 
 *   ioctl(dev, WCAM_VIDIOCGBUFINFO, &buf);
 *   printf("buffer size is %d, number of frames is %d\n", buf.buf_size, 
 *          buf.num_frames);
 *
 */
#define WCAM_VIDIOCGBUFINFO     202

typedef struct buf_info_s
{
    int buf_size;
    int num_frames;
} buf_info_t;

/*!
 * WCAM_VIDIOCSPIXFORMAT Sets video and still mode formats.
 *
 * The following formats are supported:
 *
 *   PIX_FORMAT_RAW8
 *   PIX_FORMAT_RGB444
 *   PIX_FORMAT_RGB565
 *   PIX_FORMAT_RGB666_PACKED
 *   PIX_FORMAT_RGB666_PLANAR
 *   PIX_FORMAT_RGB888_PACKED
 *   PIX_FORMAT_RGB888_PLANAR
 *   PIX_FORMAT_YCBCR422_PACKED
 *   PIX_FORMAT_YCBCR422_PLANAR
 *   PIX_FORMAT_YCBCR444_PACKED
 *   PIX_FORMAT_YCBCR444_PLANAR
 *   PIX_FORMAT_JPEG
 *   PIX_FORMAT_JPEG_SENSOR
 *
 * The following code sets the formats to YUV422 PACKED:
 *
 *   pix_format_t format;
 *   format.vid_in_format = PIX_FORMAT_YCBCR422_PACKED;
 *   format.vid_out_format = PIX_FORMAT_YCBCR422_PACKED;
 *   format.still_in_format = PIX_FORMAT_YCBCR422_PACKED;
 *   format.still_out_format = PIX_FORMAT_YCBCR422_PACKED;
 *   //dev is the video device handle 
 *   ioctl(dev, WCAM_VIDIOCSPIXFORMAT, &format);
 *
 */
#define WCAM_VIDIOCSPIXFORMAT   203

typedef struct pix_format_s
{
    int vid_in_format;
    int vid_out_format;
    int still_in_format;
    int still_out_format;
} pix_format_t;

/*!
 *Image format definitions
 */
#define PIX_FORMAT_RAW8                1
#define PIX_FORMAT_RGB444              2
#define PIX_FORMAT_RGB555              3
#define PIX_FORMAT_RGB565              4
#define PIX_FORMAT_RGB666_PACKED       5
#define PIX_FORMAT_RGB666_PLANAR       6
#define PIX_FORMAT_RGB888_PACKED       7
#define PIX_FORMAT_RGB888_PLANAR       8
#define PIX_FORMAT_YCBCR422_PACKED     9
#define PIX_FORMAT_YCBCR422_PLANAR    10
#define PIX_FORMAT_YCBCR444_PACKED    11
#define PIX_FORMAT_YCBCR444_PLANAR    12
#define PIX_FORMAT_JPEG               13
#define PIX_FORMAT_JPEG_SENSOR        14
#define PIX_FORMAT_RGBT888_0          15  //RGB+Transparent bit 0
#define PIX_FORMAT_RGBT888_1          16  //RGB+Transparent bit 1
#define PIX_FORMAT_MAX                PIX_FORMAT_RGBT888_1



/*!
 * WCAM_VIDIOCSTARTSTOP Starts/stops the video capture.
 *
 * The following values are supported:
 *
 *   RETURN_VIDEO       Return to video capture after still image capture
 *   STILL_IMAGE        Still image capture
 *   VIDEO_START        Starts video capture
 *   VIDEO_STOP         Stops video capture
 *
 * The following code segment demonstrates how to start the video:
 *
 *   ioctl(dev, WCAM_VIDIOCSTARTSTOP, VIDEO_START);
 *
 */
#define WCAM_VIDIOCSTARTSTOP    204

/*!
 * WCAM_VIDIOCSTARTSTOP arguments
 */
#define RETURN_VIDEO    2
#define STILL_IMAGE     1
#define VIDEO_START     0
#define VIDEO_STOP      -1

/*! 
 *  WCAM_VIDIOCSI2CREG Sets camera register through I2C bus
 *
 *   The following code sets the register 0x3000 to value 0x1234 for a sensor 
 *   that uses word values:
 *
 *   camera_i2c_register_t reg;
 *   reg.addr = 0x3000;
 *   reg.value.w = 0x1234;
 *   //dev is the video device handle 
 *   ioctl(dev, WCAM_VIDIOCSI2CREG, &reg);
 *
 *   The following code sets the register 0x3000 to value 0x12 for a sensor 
 *   that uses byte values:
 *
 *   camera_i2c_register_t reg;
 *   reg.addr = 0x3000;
 *   reg.value.b = 0x12;
 *   //dev is the video device handle 
 *   ioctl(dev, WCAM_VIDIOCSI2CREG, &reg);
 *
 */
#define WCAM_VIDIOCSI2CREG      205

/*! 
 *  WCAM_VIDIOCGI2CREG Gets camera register through I2C bus
 *
 *   The following code gets the value at register 0x3000 for a sensor that 
 *   uses word values:
 *
 *   camera_i2c_register_t reg;
 *   reg.addr = 0x3000;
 *   //dev is the video device handle 
 *   ioctl(dev, WCAM_VIDIOCGI2CREG, &reg);
 *   printf("The register value at %x is %x\n", reg.addr, reg.value.w);
 *
 */
#define WCAM_VIDIOCGI2CREG      206

typedef struct window_size_s
{
    unsigned short w, h;
} window_size_t;

/*! 
 *  WCAM_VIDIOCSSSIZE Sets the sensor window size
 *
 *   The following code sets the sensor size to 640 X 480:
 *
 *   window_size_t sensor_size;
 *   sensor_size.w = 640;
 *   sensor_size.h = 480;
 *   //dev is the video device handle 
 *   ioctl(dev, WCAM_VIDIOCSSSIZE, &sensor_size);
 *
 *  Remarks:
 *    The sensor size is restricted by the video device capability. 
 *    The sensor size must be an even of multiple of 8. If not, the driver 
 *    changes the sensor size to a multiple of 8.
 */
#define WCAM_VIDIOCSSSIZE       217

/*!
 * WCAM_VIDIOCSOSIZE Sets output size of the video device
 *
 *   The following code segment shows how to set the output size to 240 X 320:
 *
 *   window_size_t out_size;
 *   out_size.w = 240;
 *   out_size.h = 320;
 *   //dev is the video device handle 
 *   ioctl(dev, WCAM_VIDIOCSOSIZE, &out_size);
 *
 *  Remarks:
 *   In video mode, the output size must be less than 240X320. However, in 
 *   still mode, the output size is restricted by the video device capability 
 *   and the sensor size. The output size must always be less than the sensor 
 *   size, so if the developer changes the output size to be greater than the 
 *   sensor size, the video device driver may work abnormally. 
 *   The width and height must also be a multiple of 8. If it is not, the 
 *   driver changes the width and height size to a multiple of 8. 
 *   The developer can modify the sensor size and the output size to create a 
 *   digital zoom. 
 */
#define WCAM_VIDIOCSOSIZE       218

/*!
 * WCAM_VIDIOCGSSIZE Gets the current sensor size.
 * 
 * The following code segment shows how to use this function:
 *
 *   window_size_t sensor_size;
 *   //dev is the video device handle 
 *   ioctl(dev, WCAM_VIDIOCGSSIZE, &sensor_size); 
 *   printf("sensor width is %d, sensor_height is %d\n", sensor_size.w, 
 *          sensor_size.h);
 *
 */
#define WCAM_VIDIOCGSSIZE       219

/*!
 * WCAM_VIDIOCGOSIZE Gets the current output size.
 * 
 * The following code segment shows how to use this function:
 *
 *   window_size_t out_size;
 *   //dev is the video device handle 
 *   ioctl(dev, WCAM_VIDIOCGOSIZE, &out_size); 
 *   printf("output width is %d, output height is %d\n", out_size.w, 
 *          out_size.h);
 *
 */
#define WCAM_VIDIOCGOSIZE       220

/*!
 * WCAM_VIDIOCSFPS Sets the output frame rate (fps - frames per second) of the 
 * video device
 *
 * The following code segment shows how to use this function:
 *
 *   fps_max_min_t fps;
 *   fps.maxfps  = 15;
 *   fps.minfps  = 12;
 *   ioctl(dev, WCAM_VIDIOCSFPS, &fps);
 *
 * Remarks:
 *   The minimum value of maxfps is 1; the maximum value is 15.  minfps must 
 *   not exceed maxfps. 
 *   The default value of fps is [15, 10].
 *   minfps and maxfps only suggest a fps range. The video device driver will 
 *   select an appropriate value automatically. The actual fps depends on 
 *   environmental circumstances such as brightness, illumination, etc. 
 *   
 */
#define WCAM_VIDIOCSFPS         221

typedef struct fps_max_min_s
{
    int maxfps, minfps;
} fps_max_min_t;

/*!
 * WCAM_VIDIOCSNIGHTMODE Sets the video device capture mode. 
 *
 * The capture mode can use the following values
 *
 *   NM_AUTO     Auto mode(default value)
 *   NM_NIGHT    Night mode
 *   NM_ACTION   Action mode
 *  
 * The following code segment shows how to set the video device to night mode 
 * with max exposure time to 100 ms:
 *
 *   EXPO_MODE_PARAM_T night_mode;
 *   night_mode.mode = NM_NIGHT;
 *   night_mode.maxexpotime  = 100000;
 *   ioctl(dev, WCAM_VIDIOCSNIGHTMODE, &night_mode);
 *
 * Remarks:
 *   Different capture modes represent different sensor exposure times. Night 
 *   mode represents a longer exposure time. Setting the video device to night 
 *   mode can capture high quality image data in low light environments. 
 *   Action mode represents a shorter exposure time. This is used for capture 
 *   moving objects. When working in auto mode, the video device will select 
 *   an appropriate exposure time automatically.
 *
 *   Not all camera modules support this interface. Developers can also use 
 *   WCAM_VIDIOCSFPS to achieve similar results.
 *   Smaller minfps represent longer exposure times.
 *
 */
#define WCAM_VIDIOCSNIGHTMODE   222

typedef enum NIGHT_MODE_S
{
   NM_AUTO,
   NM_NIGHT,
   NM_ACTION
} NIGHT_MODE_T;

typedef struct EXPO_MODE_PARAM_S
{
    NIGHT_MODE_T mode;
    unsigned int maxexpotime;
} EXPO_MODE_PARAM_T;

/*
 * WCAM_VIDIOCSVFPARAM Sets camera viewfinder offset and size
 *
 * The following code segment shows how to use this function:
 *
 * VF_PARAM vfparam;
 * vf.xoffset  = xoffset_to_fb_upleft_corner;
 * vf.yoffset  = yoffset_to_fb_upleft_corner;
 * vf.width    = viewfinder_width;
 * vf.height   = viewfinder_height;
 * vf.rotation = rotation_to_csi_data
 * ioctl(dev, WCAM_VIDIOCSVFPARAM, &vfparam);
 *
 * The viewfinder size must be smaller than the overlay frame buffer size and
 * vf.width + vf.xoffset must less than overlay frame buffer width
 * vf.height + vf.yoffset must less than overlay frame buffer height
 *
 */
#define WCAM_VIDIOCSVFPARAM     223

typedef struct VF_PARAM_STRUCT
{
  unsigned int xoffset;
  unsigned int yoffset;
  unsigned int width;
  unsigned int height;
  unsigned int rotation;
} VF_PARAM;


/*!
 * WCAM_VIDIOCSSTYLE Sets the image style.
 *
 * The following styles are supported:
 *
 *   STYLE_NORMAL        Normal (default value)
 *   STYLE_BLACK_WHITE   Black and white 
 *   STYLE_SEPIA         Sepia
 *   STYLE_SOLARIZE      Solarized (not supported by all camera modules)
 *   STYLE_NEG_ART       Negative (not supported by all camera modules)
 *
 * The following code segment demonstrates how to set the image style to black 
 * and white:
 *
 *   ioctl(dev, WCAM_VIDIOCSSTYLE, STYLE_BLACK_WHITE);
 *
 */
#define WCAM_VIDIOCSSTYLE       250

typedef enum PIC_STYLE_S
{
   STYLE_NORMAL,
   STYLE_BLACK_WHITE,
   STYLE_SEPIA,
   STYLE_SOLARIZE,
   STYLE_NEG_ART,
   STYLE_BLUISH,
   STYLE_REDDISH,
   STYLE_GREENISH
} PIC_STYLE_T;

/*!
 * WCAM_VIDIOCSLIGHT Sets the image light mode
 * 
 * The following light modes are supported:
 *   WB_AUTO           Auto mode(default)
 *   WB_DIRECT_SUN     Direct sun
 *   WB_INCANDESCENT   Incandescent
 *   WB_FLUORESCENT    Fluorescent
 * 
 * The following code sets the image light mode to incandescent:
 *   ioctl(dev, WCAM_VIDIOCSLIGHT, WB_INCANDESCENT);
 */
#define WCAM_VIDIOCSLIGHT       251

typedef enum PIC_WB_S
{
   WB_AUTO,
   WB_DIRECT_SUN,
   WB_INCANDESCENT,
   WB_FLUORESCENT,
   WB_CLOUDY
} PIC_WB_T;

/*!
 * WCAM_VIDIOCSBRIGHT Sets the brightness of the image (exposure compensation value)
 *  
 *  parameter value      exposure value
 *   -4                     -2.0 EV
 *   -3                     -1.5 EV
 *   -2                     -1.0 EV
 *   -1                     -0.5 EV
 *    0                      0.0 EV(default value)
 *    1                     +0.5 EV
 *    2                     +1.0 EV
 *    3                     +1.5 EV
 *    4                     +2.0 EV
 *
 * The following code segment sets the brightness to 2.0 EV
 *   ioctl(dev, WCAM_VIDIOCSBRIGHT, 4);
 */
#define WCAM_VIDIOCSBRIGHT      252

/*!
 * Sets the frame buffer count for video mode. The default value is 3.
 *
 * The following code segment shows how to use this function:
 *
 *   int bufcount = 4;
 *   ioctl(handle.fd, WCAM_VIDIOCSBUFCOUNT, &bufcount);
 *
 * Remarks:
 * The video device driver maintains some memory for buffering image data in 
 * the kernel space. When working in video mode, there are at least 3 frame 
 * buffers in the driver.  In still mode, there is only 1 frame buffer.
 * This interface is not open to SDK developers.
 * 
 */
#define WCAM_VIDIOCSBUFCOUNT    253

/*!
 * Gets the camera sensor type
 *
 * The following code segment shows how to use this function:
 *
 *  unsigned int sensor_type
 *  ioctl(dev, WCAM_VIDIOCGSTYPE, &sensor_type);
 *  if(sensor_type == CAMERA_TYPE_ADCM_2700)
 *  {
 *     printf("Agilent ADCM2700");
 *  }
 *
 * Remarks:
 *   For all possible values of sensor_type please refer to the sensor definitions below.
 */
#define WCAM_VIDIOCGSTYPE       255 

/*!
 *Sensor type definitions
 */
#define CAMERA_TYPE_ADCM_2650               1
#define CAMERA_TYPE_ADCM_2670               2
#define CAMERA_TYPE_ADCM_2700               3
#define CAMERA_TYPE_OMNIVISION_9640         4
#define CAMERA_TYPE_ADCM3800                6
#define CAMERA_TYPE_OV9650                  7
#define CAMERA_TYPE_SENSOR2M                8
#define CAMERA_TYPE_MAX                     CAMERA_TYPE_SENSOR2M

/*!
 * Sets the flicker frequency(50hz/60hz)
 *
 * The following flicker frequencies are supported:
 *   50                 50 hz
 *   60                 60 hz
 *   other              Auto
 *
 * The following code segment sets the flicker to 50 hz
 *   ioctl(dev, WCAM_VIDIOCSFLICKER, 50);
 */
#define WCAM_VIDIOCSFLICKER     257

/*
 * Gets the camera exposure parameters
 *
 * The following code segment shows how to use this function:
 *
 *   EXPOSURE_PARA_T para;
 *   ioctl(dev, WCAM_VIDIOCGEXPOPARA, &para);
 */
#define WCAM_VIDIOCGEXPOPARA    258

typedef struct EXPOSURE_PARA_S
{
    unsigned int luminance;
    int shutter;
    int ISOSpeed;
    char *reserved[16];
} EXPOSURE_PARA_T;

/*
 * Sets the camera still mode size
 * 
 * The following code segment shows how to use this function:
 *
 *   window_size_t si_size;
 *   si_size.w = 640;
 *   si_size.h = 480;
 *   //dev is the video device handle 
 *   ioctl(dev, WCAM_VIDIOCSCSIZE, &si_size); 
 */
#define WCAM_VIDIOCSCSIZE       259

/*
 * Gets the camera still mode size
 * 
 * The following code segment shows how to use this function:
 *
 *   window_size_t si_size;
 *   //dev is the video device handle 
 *   ioctl(dev, WCAM_VIDIOCGCSIZE, &si_size); 
 *   printf("still image width is %d, still image height is %d\n", si_size.w, 
 *          si_size.h);
 */
#define WCAM_VIDIOCGCSIZE       260

/*
 * Sets the camera capture digital zoom number
 *
 * The following code segment shows how to use this function:
 *
 *   int vzoom = 2;
 *   //dev is the video device handle 
 *   ioctl(dev, WCAM_VIDIOCSZOOM, vzoom); 
 */
#define WCAM_VIDIOCSZOOM        263

/*
 * Gets the camera capture digital zoom number
 *
 * The following code segment shows how to use this function:
 *
 *   int vzoom;
 *   //dev is the video device handle 
 *   ioctl(dev, WCAM_VIDIOCGZOOM, &vzoom); 
 *   printf("video zoom is %d\n", vzoom);
 */
#define WCAM_VIDIOCGZOOM        264

/*
 * Gets the current frame
 *
 * The following code segment shows how to use this function:
 *
 *   IMAGE_FRAME_T frame;
 *   ioctl(dev, WCAM_VIDIOCGRABFRAME, &frame); 
 */
#define WCAM_VIDIOCGRABFRAME    265

typedef struct IMAGE_FRAME_S
{
    int first;
    int last;
    /*! The width of image frame */
    int             width;
    /*! The height of image frame */
    int             height;
    /*! The format of image frame */
    int             format;
    /*! The plane number of image frame */
    int             planeNum;
    /*! The buffer offset of image planes */
    unsigned        planeOffset[3];
    /*! The bytes size of image planes */
    int             planeBytes[3];
} IMAGE_FRAME_T;

/*
 * Move to the next frame
 *
 * The following code segment shows how to use this function:
 *
 *   int moveFrame = 1;
 *   ioctl(dev, WCAM_VIDIOCNEXTFRAME, &moveFrame); 
 */
#define WCAM_VIDIOCNEXTFRAME    266

/*!
 * Gets the frame buffer count for video mode.
 *
 * The following code segment shows how to use this function:
 *
 *   int bufcount;
 *   ioctl(dev, WCAM_VIDIOCGBUFCOUNT, &bufcount); 
 *   printf("buffer count is %d\n", bufcount);
 */
#define WCAM_VIDIOCGBUFCOUNT    267

/*
 * Sets the camera still mode digital zoom number
 *
 * The following code segment shows how to use this function:
 *
 *   int pzoom = 2;
 *   //dev is the video device handle 
 *   ioctl(dev, WCAM_VIDIOCSSZOOM, pzoom); 
 */
#define WCAM_VIDIOCSSZOOM       268

/*
 * Gets the camera still mode digital zoom number
 *
 * The following code segment shows how to use this function:
 *
 *   int pzoom;
 *   //dev is the video device handle 
 *   ioctl(dev, WCAM_VIDIOCGSZOOM, &pzoom); 
 *   printf("still image zoom is %d\n", pzoom);
 */
#define WCAM_VIDIOCGSZOOM       269

/*
 * Sets the camera JPEG quality
 * Not currently used
 */
#define WCAM_VIDIOCSJPEGQUALITY 270

/*
 * Sets the camera horizontally or vertically mirroring
 *
 * The following code segment shows how to use this function:
 *
 *   int mirror = 0;
 *   mirror |= CAMERA_MIRROR_VERTICALLY;
 *   mirror |= CAMERA_MIRROR_HORIZONTALLY;
 *   ioctl(handle.fd, WCAM_VIDIOCSMIRROR, mirror);
 *
 */
#define WCAM_VIDIOCSMIRROR      272

/*
 * Defines for parameter for WCAM_VIDIOCSMIRROR
 */
#define CAMERA_MIRROR_VERTICALLY    0x0001
#define CAMERA_MIRROR_HORIZONTALLY  0x0002

/*
 * Sets the camera strobe flash enable/disable
 *
 * The following code segment shows how to use this function:
 *
 *   int strobe = 1;
 *   ioctl(handle.fd, WCAM_VIDIOCSSTROBEFLASH, strobe);
 */
#define WCAM_VIDIOCSSTROBEFLASH 273


/*
 * Definitions of the camera's i2c device
 */
#define CAMERA_I2C_WRITEW    101
#define CAMERA_I2C_WRITEB    102
#define CAMERA_I2C_READW     103
#define CAMERA_I2C_READB     104
#define CAMERA_I2C_DETECTID  105

typedef struct camera_i2c_register {
    unsigned short  addr;
    union {
        unsigned short w;
        unsigned char b;
    } value __attribute__ (( __aligned__ (4)));
} camera_i2c_register_t;

struct camera_i2c_detectid {
    int buflen;
    char data[256];
};
//End of the camera's i2c device

/* 
 * Define the camera digital zoom level multiple 
 * the zoom value should equal
 *     zoom level x CAMERA_ZOOM_LEVEL_MULTIPLE
*/
#define CAMERA_ZOOM_LEVEL_MULTIPLE  256

/*
 * Maximum number of frames.
 */
#define MAX_FRAMES 32

#endif // __CAMERA_H__ 

