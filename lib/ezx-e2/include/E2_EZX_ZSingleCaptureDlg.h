// _ZN17ZSingleCaptureDlgC4EP7QWidgetPKcbj
// _ZN17ZSingleCaptureDlgC4ERK7QStringS2_NS_14CaptureDlgTypeEP7QWidgetPKcbji
// _ZN17ZSingleCaptureDlgD4Ev

#ifndef _E2_EZX_ZSINGLECAPTUREDLG_H
#define _E2_EZX_ZSINGLECAPTUREDLG_H

#include <qstring.h>
#include <qwidget.h>

class ZSingleCaptureDlg : public QWidget
{
	Q_OBJECT
public: 
	char tmp[4096];
	enum CaptureDlgType
	{
		NONE
	};
	ZSingleCaptureDlg(QString const&, QString const&, ZSingleCaptureDlg::CaptureDlgType, QWidget*, char const*, bool, unsigned, int);
	ZSingleCaptureDlg(QWidget*, char const*, bool, unsigned);
	QString getResultText();
/*
	int className() const
	int getDialogType()
	int getEditWidget()
	int getLineEdit()
	int getMultiLineEdit()
	int initMetaObject()
	int initialize(ZSingleCaptureDlg::CaptureDlgType)
	int setEditWidget(ZWidget*)
	int slotLSKClicked()
	int slotRSKClicked()
	int slotResizeAllChild(int)
	int staticMetaObject()
	int tr(char const*)
	int tr(char const*, char const*)
	int ~ZSingleCaptureDlg [in-charge deleting]()
	int ~ZSingleCaptureDlg [in-charge]()
	int ~ZSingleCaptureDlg [not-in-charge]()
*/
};

#endif
