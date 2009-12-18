/*
# Revision History:
# 
#    date         coreid  description
# ---------------------------------------------------------------------------
#    02-Jun-2008  BeZ     changed return type for functions:
#                            ZSingleCaptureDlg::getLineEdit()
*/

#ifndef _ZSINGLECAPTUREDLG_H
#define _ZSINGLECAPTUREDLG_H

#include <ZPopup.h>
//
#include <ZLineEdit.h>
#include <ZMultiLineEdit.h>

/* Size:216=54*4 */

#define TypeLineEdit normal

class ZSingleCaptureDlg : public ZPopup
{
	Q_OBJECT
	unsigned int data[55 - sizeof(ZPopup)/4];
public: 
    enum CaptureDlgType
    {
        normal,         // text field,     use ZLineEdit widget
        TypeLineEditPasswd,   // password field, use ZLineEdit widget

        TypeTextField,        // text field,     use ZMultiLineEdit widget
        TypePasswdField,      // password field, use ZMultiLineEdit widget

        TypeCustom            // custom type, for extend use
    };
	    ZSingleCaptureDlg(const QString& strDlgTitle,
                      const QString& strInstructText,
                      CaptureDlgType type,
                      QWidget* parent = NULL,
                      const char* name = 0,
                      bool modal = TRUE,
                      WFlags f = 0,
                      int auto_dismiss_time = 0);
                      
    ZSingleCaptureDlg(QWidget* parent = NULL,
                      const char* name = 0,
                      bool modal = TRUE,
                      WFlags f = 0);
                      
	virtual ~ZSingleCaptureDlg();

    ZMultiLineEdit* getMultiLineEdit();
    ZLineEdit* getLineEdit();
    CaptureDlgType getDialogType();
    QString getResultText();
    bool setEditWidget(ZWidget* pEditWidget);
    ZWidget* getEditWidget();
    
protected slots:
    virtual void slotResizeAllChild(int);
    
private:
    void initialize(CaptureDlgType type);

public slots:
	virtual void  slotLSKClicked();
	virtual void  slotRSKClicked();

};

#endif
