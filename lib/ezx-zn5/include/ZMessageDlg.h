//Fix for Motorola ZN5 by Ant-ON, 2009
//Fix for ZN5/U9 by Ant-ON, 25-10-2010

// Copyright (c) 27-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef _ZMESSAGEDLG_H_
#define _ZMESSAGEDLG_H_

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "ZPopup.h"

#include "qstring.h"
#include "qobjectdefs.h"
#include "qwidget.h"
#include "qnamespace.h"
#include "qevent.h"
#include "qobject.h"

struct ZMessageDlgPrivate;

class ZMessageDlg : public ZPopup
{
    Q_OBJECT

public:

    enum MessageDlgType
    {
        TypeChoose,        
        TypeConfirm,       
        TypeOK,            
        TypeCustom,
        TypeNotice         
    };

	#if !defined(yes_no) || !defined(just_ok)
	#define yes_no TypeConfirm
	#define just_ok TypeOK
	#endif

public:

    ZMessageDlg(QWidget* parent = NULL,
                const char* name = 0,
                bool modal = TRUE,
                WFlags f = 0);

    ZMessageDlg(const QString& strDlgTitle,
                const QString& strInstructText,
                MessageDlgType type,
                int auto_dismiss_time = 0,
                QWidget* parent = NULL,
                const char* name = 0,
                bool modal = TRUE,
                WFlags f = 0);

    virtual ~ZMessageDlg();

    void setMessage(const QString& strText) { setInstructText(strText); }

    void setType(MessageDlgType type);

    void setMsgIcon(const QString& /*strIcon*/) {};

protected:

    virtual void keyReleaseEvent(QKeyEvent*);
    virtual void keyPressEvent(QKeyEvent*);

private:

    void initialize();

private:

    ZMessageDlgPrivate* mpData;

};

#endif	

