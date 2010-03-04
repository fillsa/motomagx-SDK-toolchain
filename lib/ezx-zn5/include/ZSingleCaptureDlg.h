//Fix for Motorola ZN5 by Ant-ON, 2009

// Copyright (c) 27-Apr-07 - 2008 Motorola, Inc. All rights reserved.

#ifndef _ZSINGLECAPTUREDLG_H
#define _ZSINGLECAPTUREDLG_H

#include <ZPopup.h>
#include <ZLineEdit.h>

/* Size:216=54*4 */

//For compobility on Z6
#define normal2 TypeTextField
#define normal3 TypePasswdField
//

class ZSingleCaptureDlg : public ZPopup
{
	Q_OBJECT
	unsigned int data[54 - sizeof(ZPopup)/4];
public: 
	/*
	enum CaptureDlgType
	{
		normal, secret, normal2, secret2
	};
	*/
	
    enum CaptureDlgType
    {
        TypeLineEdit,         // text field,     use ZLineEdit widget
        TypeLineEditPasswd,   // password field, use ZLineEdit widget

        TypeTextField,        // text field,     use ZMultiLineEdit widget
        TypePasswdField,      // password field, use ZMultiLineEdit widget

        TypeCustom            // custom type, for extend use
    };
    
	//ZSingleCaptureDlg(QString const&, QString const&, ZSingleCaptureDlg::CaptureDlgType, QWidget*, char const*, bool, unsigned int, int);
	//ZSingleCaptureDlg(QWidget*, char const*, bool, unsigned int);
	
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
	~ZSingleCaptureDlg();

	void initialize(ZSingleCaptureDlg::CaptureDlgType);
	ZLineEdit* getLineEdit();
	void getDialogType();
	void getEditWidget();
	QString getResultText();
	void setEditWidget(ZWidget*);
	ZMultiLineEdit* getMultiLineEdit();

public slots:
	void slotLSKClicked();
	void slotRSKClicked();
	void slotResizeAllChild(int);
};

#endif
