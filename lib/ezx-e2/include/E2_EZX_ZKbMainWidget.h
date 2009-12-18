//This file is create by lasly
//u can use it to create e2 native program
//and u can find my blog in http://my.opera.com/Lasly
// e2_ezx_sdk_0.01

// ZKbMainWidget 下面凡是以？开头的注释都是猜测的用途，没有经过测试

// _ZN13ZKbMainWidgetC4EN7ZHeader11HEADER_TYPEEP7QWidgetPKcj
// _ZN13ZKbMainWidgetC4EP7QWidgetPKcj
// _ZN13ZKbMainWidgetC4ERK7QStringP7QWidgetPKcj
// _ZN13ZKbMainWidgetD4Ev

#ifndef _E2_EZX_ZKBMAINWIDGET_H
#define _E2_EZX_ZKBMAINWIDGET_H

#include <qstring.h>
#include <qwidget.h>
#include <E2_EZX_ZHeader.h>
#include <qevent.h>
#include <qobject.h>
#include <E2_EZX_ZAppInfoArea.h>
#include <qcstring.h>
#include <qarray.h>
#include <E2_EZX_ZSoftKey.h>
#include <E2_EZX_ZMainWidget.h>

class ZKbMainWidget : public ZMainWidget
{
	Q_OBJECT
	char tmp[4096];
public:
	ZKbMainWidget(QString const&, QWidget*, char const*, unsigned);
	ZKbMainWidget(QWidget*, char const*, unsigned);
	ZKbMainWidget(ZHeader::HEADER_TYPE, QWidget*, char const*, unsigned);
	~ZKbMainWidget();
	void clearKeyClicked();	
	virtual bool event(QEvent*);
	bool eventFilter(QObject*, QEvent*);
	ZAppInfoArea* getAppInfoArea();
	QString getAppTitle();
	int getLRSBaseIndex();
	QString getMainWidgetTitle();
	ZSoftKey* getSoftKey(bool);
	int headerSize();
	int init(ZHeader::HEADER_TYPE);
	bool isTitleTruncEnable();
	virtual void keyPressEvent(QKeyEvent*);
	void setAppInfoArea(ZAppInfoArea*);
	void setAppTitle(QString const&);
	void setHeaderType(ZHeader::HEADER_TYPE);
	void setMainWidgetTitle(QString const&);
	void setSoftKey(ZSoftKey*);
	void setTitleTruncEnable(bool);

public slots:
	virtual void slotAppMessage(QCString const&, QArray<char> const&);
	virtual void slotFullScreenModeChanged(bool);
	virtual void slotKbStateChanged(int, bool);
public:
	void updateHeader();
};
#endif
