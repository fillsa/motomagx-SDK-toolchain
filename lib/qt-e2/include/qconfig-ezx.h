/****************************************************************************
** $Id: qt/src/tools/qconfig-large.h   2.3.6   edited 2002-07-25 $
**
** Qt/Embedded "large" configuration definition.
**
** Copyright (C) 2000-2002 Trolltech AS.  All rights reserved.
**
** This file is part of the tools module of the Qt GUI Toolkit.
**
** This file may be distributed and/or modified under the terms of the
** GNU General Public License version 2 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.
**
** Licensees holding valid Qt Enterprise Edition or Qt Professional Edition
** licenses may use this file in accordance with the Qt Commercial License
** Agreement provided with the Software.
**
** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
**
** See http://www.trolltech.com/pricing.html or email sales@trolltech.com for
**   information about Qt Commercial License Agreements.
** See http://www.trolltech.com/gpl/ for GPL licensing information.
**
** Contact info@trolltech.com if any conditions of this licensing are
** not clear to you.
**
**********************************************************************/

/*
 * Modifed for EZX by samr7 of MotorolaFans.com
 * This was originally qconfig-large.h.  Modifications were chosen by
 * building QT-Embedded 2.3.6 and comparing the symbol table of the
 * produced binary with the EZX version.
 *
 * The compiler inlining decisions seem to differ greatly between the
 * generally available GPL sources for GCC 3.2 and whatever was used
 * to build the EZX version, and it shows in the set of functions that
 * make it into the shared library.
 */

#ifndef QT_H
#endif // QT_H
//#ifndef QT_NO_CODECS
//#define QT_NO_CODECS
//#endif
#define QT_NO_UNICODETABLES
#define QT_NO_IMAGEIO_BMP
#define QT_NO_IMAGEIO_PPM
//#define QT_NO_ASYNC_IO
//#define QT_NO_ASYNC_IMAGE_IO
#define QT_NO_FREETYPE
#define QT_NO_BDF
//#define QT_NO_FONTDATABASE
//#define QT_NO_TRANSLATION
//#define QT_NO_DRAGANDDROP
//#define QT_NO_CLIPBOARD
#define QT_NO_SOUND
//#define QT_NO_PROPERTIES
//#define QT_NO_DNS
//#define QT_NO_NETWORKPROTOCOL
#define QT_NO_COLORNAMES
//#define QT_NO_TRANSFORMATIONS
#define QT_NO_PRINTER
#define QT_NO_PICTURE
//#define QT_NO_ICONVIEW
#define QT_NO_DIAL
#define QT_NO_WORKSPACE
//#define QT_NO_TABLE
//#define QT_NO_ACTION
#define QT_NO_STYLE_MOTIF
#define QT_NO_STYLE_PLATINUM
//#define QT_NO_FILEDIALOG
#define QT_NO_FONTDIALOG
#define QT_NO_PRINTDIALOG
#define QT_NO_COLORDIALOG
#define QT_NO_INPUTDIALOG
//#define QT_NO_MESSAGEBOX
#define QT_NO_PROGRESSDIALOG
//#define QT_NO_TABDIALOG
#define QT_NO_WIZARD
//#define QT_NO_EFFECTS

#define QT_NO_QWS_IM
#define QT_NO_LCDNUMBER
#define QT_NO_MESSAGEBOX
#define QT_NO_SIZEGRIP
#define QT_NO_SPINBOX
#define QT_NO_TABBAR
#define QT_NO_TABDIALOG
#define QT_NO_TABWIDGET
#define QT_NO_QWS_BEOS_WM_STYLE
#define QT_NO_QWS_HYDRO_WM_STYLE
#define QT_NO_QWS_KDE_WM_STYLE
#define QT_NO_QWS_WINDOWS_WM_STYLE
#define QT_NO_QWS_SAVEFONTS
#define QT_NO_RTLCODEC
#define QT_NO_JISCODEC
#define QT_NO_SJISCODEC
#define QT_NO_TSCIICODEC
#define QT_NO_EUCJPCODEC
#define QT_NO_EUCKRCODEC
#define QT_NO_IMAGE_TEXT
#define QT_EZX_MUNGE
#define QT_EZX_CLIPBOARD
#define QWS_CUSTOMTOUCHPANEL

/* Enabling VFB, we assume that you don't want the EZX input removals */
#ifdef QT_NO_QWS_VFB
#define QT_EZX_INPUT
#endif

/*
 * The line used to invoke the base QT build was:
 * configure -no-g++-exceptions -thread -xplatform linux-arm-g++ -depths 8,16 -gif -no-qvfb -qconfig ezx
 */
