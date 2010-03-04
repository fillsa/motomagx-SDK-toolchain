//Fix for ZN5/U9 by Ant-ON, 25-10-2010

// Copyright (c) 27-Apr-07 - 2008 Motorola, Inc. All rights reserved.

#ifndef _ZMULTISELECTDLG_H_
#define _ZMULTISELECTDLG_H_

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include <ZListBox.h>

#include "qstring.h"
#include "qobjectdefs.h"
#include "qwidget.h"
#include "qnamespace.h"
#include "qevent.h"
#include "qobject.h"
#include "qglobal.h"


struct ZMultiSelectDlgPrivate;

class ZMultiSelectDlg : public ZPopup
{
    Q_OBJECT

public:
    enum MENU_INDEX_E
    {
        SelectAll,
        UnSelectAll,
        Cancel,
    };
    ZMultiSelectDlg(QWidget* parent = NULL,
                    const char* name = 0,
                    bool modal = TRUE,
                    WFlags f = 0);
    ZMultiSelectDlg(const QString& strDlgTitle,
                    const QString& strInstructText,
                    QWidget* parent = NULL,
                    const char* name = 0,
                    bool modal = TRUE,
                    WFlags f = 0,
                    int auto_dismiss_time = 0);
    virtual ~ZMultiSelectDlg();
    ZListBox* getListBox();
    void setRightBtnPrompt( const QString& str );
    void setMenuSlot(MENU_INDEX_E idx, const QObject* receiver, const char* memberFunc, bool bSet = true);
    void enableMenuItem(MENU_INDEX_E idx, bool bEnable);
    void enableRSKdefaultBehavior(bool bEnalbe);
    void updateUIinfo();
    void addItemsList(QStringList&);

protected:
    virtual bool eventFilter( QObject*, QEvent* );
    virtual void showEvent(QShowEvent*);

protected slots:
    virtual void slotRSKClicked(); 
    virtual void slotResizeAllChild(int);

//private slots:
//    void slotMenuItemClick(int nMenuId);
//    void slotItemStateChanged();


private:
    int getCheckedItemCount();
    
    //void initialize();
    //void initBodyArea();
    //void initSoftKeyArea();
    //void checkAllListBoxItem( bool bSelect );
    //void updateUI();
    //void initAIAinfo();
    //void updateAppInfoArea(int nSelCount);

private:

    ZMultiSelectDlgPrivate* mpData;

};


#endif	//_ZMULTISELECTDLG_H_


