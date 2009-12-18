#ifndef QWALLPAPER_H
#define QWALLPAPER_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

//---------------------------------------------------------------------------
//                                                                    
//   Header Name: qwallpaper.h
//   General Description: functions get/set the qt wallpaper
//
//---------------------------------------------------------------------------
//
//                   Motorola Confidential Proprietary
//        Template ID and version: IL93-TMP-01-0107  Version 1.10
//         (c) Copyright Motorola 2002-2003, All Rights Reserved
//
// Revision History:
//                             Modification     Tracking
//---------------------------------------------------------------------------
// Author (core ID)                Date          Number     Changes
//
// Peter McDermott (w20027)      01/25/2004    
//
//---------------------------------------------------------------------------
//                              INCLUDE FILES
//---------------------------------------------------------------------------

#include <qpixmap.h>

//---------------------------------------------------------------------------

class QWallpaper {

public:
   
    // 
    // set/get the system wallpaper
    //
    // By default, the system wallpaper points to NULL.  This has the 
    // effect of turning off wallpaper blending for all applications
    //
    
    static void setSysWallpaper(const QPixmap*);
    static QPixmap* sysWallpaper();

    //
    // enabling the system wallpaper will enable blending the system
    // wallpaper with application data
    //
    
    static void setSysWallpaperEnabled(bool enable);
    static bool sysWallpaperEnabled();

    //
    // set/get the application wallpaper
    //
    // By default, the application wallpaper points to NULL, which means
    // no wallpaper when you call setAppWallpaperMode(UseAppWallpaper). So
    // call setAppWallpaper() with your favorite pixmap and then call
    // setAppWallpaperMode(UseAppWallpaper)
    //
   
    static void setAppWallpaper(const QPixmap*);
    static QPixmap* appWallpaper();
    
    // 
    // set the wallpaper mode for your application.  
    //
    // default is UseSysWallpaper
    //

    enum Mode
    {
        UseSysWallpaper,
        UseAppWallpaper,
        Off
    };
    
    static void setAppWallpaperMode(Mode mode);
    static Mode appWallpaperMode();

    //
    // get the current wallpaper. 
    //
    // Returns a pointer to the current wallpaper, whether system or 
    // application.  It returns NULL if the wallpaper is either NULL or
    // set to Off.
    //

    static QPixmap* wallpaper(); 
    
};

#endif // QWALLPAPER_H

