//This file is create by lasly
//u can use it to create e2 native program
//and u can find my blog in http://my.opera.com/Lasly
// e2_ezx_sdk_0.01

// ZMessageDlg 新增类，与ZMessageBox类似

// _ZN11ZMessageDlgC4EP7QWidgetPKcbj
// _ZN11ZMessageDlgC4ERK7QStringS2_NS_14MessageDlgTypeEiP7QWidgetPKcbj
// _ZN11ZMessageDlgD4Ev

#ifndef _E2_EZX_ZMESSAGEDLG_H
#define _E2_EZX_ZMESSAGEDLG_H

#include <qwidget.h>
#include <qstring.h>
#include <qevent.h>
#include <ZPopup.h>


class ZMessageDlg : public ZPopup
{
Q_OBJECT
public:
	char tmp[256];
	enum MessageDlgType
	{
		ok_cancel, //choose
  yes_no, //confirm
  just_ok, //ok
  NONE = 0 //custom
	};
	void initialize();
	void setMsgIcon(QString const&);
	virtual void keyReleaseEvent(QKeyEvent*);
	void setType(ZMessageDlg::MessageDlgType);
	ZMessageDlg(QWidget*, char const*, bool, unsigned);
	ZMessageDlg(QString const&, QString const&, ZMessageDlg::MessageDlgType, int, QWidget*, char const*, bool, unsigned);
	~ZMessageDlg();
};
#endif
