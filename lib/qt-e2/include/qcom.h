/****************************************************************************
 ** $Id:  qt/qlibrary.h	  3.0.0	  edited Sep 20 19:46 $
 **
 ** Definition of QLibrary class
 **
 ** Created : 2000-01-01
 **
 ** Copyright (C) 2000 Trolltech AS.  All rights reserved.
 **
 ** This file is part of the kernel module of the Qt GUI Toolkit.
 **
 ** This file may be distributed under the terms of the Q Public License
 ** as defined by Trolltech AS of Norway and appearing in the file
 ** LICENSE.QPL included in the packaging of this file.
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
 **	  information about Qt Commercial License Agreements.
 ** See http://www.trolltech.com/qpl/ for QPL licensing information.
 ** See http://www.trolltech.com/gpl/ for GPL licensing information.
 **
 ** Contact info@trolltech.com if any conditions of this licensing are
 ** not clear to you.
 **
 **	Modified by BJDC, Motorola 
 **
 **********************************************************************/
 
#ifndef QCOM_H
#define QCOM_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "quuid.h"


#define QRESULT     unsigned long
#define QS_OK       (QRESULT)0x00000000
#define QS_FALSE    (QRESULT)0x00000001

#define QE_NOTIMPL      (QRESULT)0x80000001
#define QE_OUTOFMEMORY  (QRESULT)0x80000002
#define QE_INVALIDARG   (QRESULT)0x80000003
#define QE_NOINTERFACE  (QRESULT)0x80000004
#define QE_NOCOMPONENT  (QRESULT)0x80000005


/**
 * internal class that wraps an initialized ulong
 */
struct QtULong
{
    QtULong() : ref( 0 ) { }
    operator unsigned long () const { return ref; }
    unsigned long& operator++() { return ++ref; }
    unsigned long operator++( int ) { return ref++; }
    unsigned long& operator--() { return --ref; }
    unsigned long operator--( int ) { return ref--; }

    unsigned long ref;
};

/**
 * Default implementation of ref counting.
 * A variable "ulong ref" has to be a member
*/
#define Q_REFCOUNT \
private:       \
    QtULong qtrefcount;   \
public:        \
    ulong addRef() {return qtrefcount++;} \
    ulong release() {if(!--qtrefcount){delete this;return 0;}return qtrefcount;}

#ifndef Q_EXTERN_C
#define Q_EXTERN_C  extern "C"
#endif


// {1D8518CD-E8F5-4366-99E8-879FD7E482DE}
#ifndef IID_QUnknown
#define IID_QUnknown QUuid(0x1d8518cd, 0xe8f5, 0x4366, 0x99, 0xe8, 0x87, 0x9f, 0xd7, 0xe4, 0x82, 0xde)
#endif

struct QUnknownInterface
{
    virtual QRESULT queryInterface( const QUuid&, QUnknownInterface** ) = 0;
    virtual ulong   addRef() = 0;
    virtual ulong   release() = 0;
};

// {5F3968A5-F451-45b1-96FB-061AD98F926E}
#ifndef IID_QComponentInformation
#define IID_QComponentInformation QUuid(0x5f3968a5, 0xf451, 0x45b1, 0x96, 0xfb, 0x6, 0x1a, 0xd9, 0x8f, 0x92, 0x6e)
#endif

struct QComponentInformationInterface : public QUnknownInterface
{
    virtual QString name() const = 0;
    virtual QString description() const = 0;
    virtual QString author() const = 0;
    virtual QString version() const = 0;
};

// {B5FEB5DE-E0CD-4E37-B0EB-8A812499A0C1}
#ifndef IID_QComponentRegistration
#define IID_QComponentRegistration QUuid( 0xb5feb5de, 0xe0cd, 0x4e37, 0xb0, 0xeb, 0x8a, 0x81, 0x24, 0x99, 0xa0, 0xc1)
#endif

struct QComponentRegistrationInterface : public QUnknownInterface
{
    virtual bool    registerComponents( const QString &filepath ) const = 0;
    virtual bool    unregisterComponents() const = 0;
};

#ifndef IID_QLibrary
#define IID_QLibrary QUuid( 0xd16111d4, 0xe1e7, 0x4c47, 0x85, 0x99, 0x24, 0x48, 0x3d, 0xae, 0x2e, 0x07)
#endif
 
struct Q_EXPORT QLibraryInterface : public QUnknownInterface
{
    virtual bool    init() = 0;
    virtual void    cleanup() = 0;
    virtual bool    canUnload() const = 0;
};

#define Q_CREATE_INSTANCE( IMPLEMENTATION )              \
{                                                        \
    IMPLEMENTATION *i = new IMPLEMENTATION;          \
    QUnknownInterface* iface = 0;                    \
    QRESULT rt;                                      \
    rt = i->queryInterface( IID_QUnknown, &iface );  \
        if(rt == QS_OK)                                  \
           return iface;                                 \
        delete i;                                        \
        return NULL;                                     \
}

#define Q_EXPORT_INTERFACE() extern "C" QUnknownInterface* ucm_instantiate()

#define EZX_CREATE_INSTANCE( IMPLEMENTATION ) Q_CREATE_INSTANCE( IMPLEMENTATION )
#define EZX_EXPORT_INTERFACE()  Q_EXPORT_INTERFACE()

#endif //QCOM_H
