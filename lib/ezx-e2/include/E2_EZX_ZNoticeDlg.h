// _ZN10ZNoticeDlgC4ENS_4TypeEjRK7QStringS3_P7QWidgetPKcbj
// _ZN10ZNoticeDlgC4ENS_4TypeERK7QStringS3_P7QWidgetPKcbjb
// _ZN10ZNoticeDlgD4Ev

#ifndef _E2_EZX_ZNOTICEDLG_H
#define _E2_EZX_ZNOTICEDLG_H

#include <qstring.h>
#include <qwidget.h>

class ZNoticeDlg : public QWidget
{ 
	Q_OBJECT
public: 
	char tmp[512];
	enum Type
	{
		NONE
	};
	ZNoticeDlg(ZNoticeDlg::Type, QString const&, QString const&, QWidget*, char const*, bool, unsigned, bool);
	ZNoticeDlg(ZNoticeDlg::Type, unsigned, QString const&, QString const&, QWidget*, char const*, bool, unsigned);
	~ZNoticeDlg();
/*
	int calculateDismissTime()
	int className() const
	int dismissDlg(ZPopup::PopupCode)
	int dlgDismissed()
	int information(QString const&, QString const&, QString const&, QString const&, QObject const*, char*)
	int initMetaObject()
	int initialize(ZNoticeDlg::Type)
	int keyPressEvent(QKeyEvent*)
	int setAnimate(QString const&)
	int setAutoDismissTime(int)
	int setMessageIcon(QPixmap const&)
	int setMessageText(QString const&)
	int showEvent(QShowEvent*)
	int slotResizeAllChild(int)
	int slotTimeout()
	int startAutoDismissTimer()
	*/
};

#endif
