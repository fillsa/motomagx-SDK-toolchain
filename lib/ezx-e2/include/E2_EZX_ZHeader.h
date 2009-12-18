//This file is create by lasly
//u can use it to create e2 native program
//and u can find my blog in http://my.opera.com/Lasly
// e2_ezx_sdk_0.01

// ZHeader 下面凡是以？开头的注释都是猜测的用途，没有经过测试

// _ZN7ZHeader15AppStatusInfo_SC4Ev
// _ZN7ZHeader15AppStatusInfo_SD4Ev
// _ZN7ZHeaderC4ENS_11HEADER_TYPEEP7QWidgetPKcj
// _ZN7ZHeaderC4EP7QWidgetPKcj
// _ZN7ZHeaderD4Ev

#ifndef _E2_EZX_ZHEADER_H
#define _E2_EZX_ZHEADER_H

#include <qstring.h>
#include <qwidget.h>
#include <qevent.h>
#include <qpalette.h>

class ZHeader : public QWidget
{
public:
	class AppStatusInfo_S
	{
	public:
		AppStatusInfo_S();
		~AppStatusInfo_S();
	};

	enum HEADER_TYPE
	{
		NORMAL_TYPE,
		TIME_TYPE,
		TINY_TYPE,
		FULL_TYPE
	};

	enum HEADER_STATUS
	{
		NONE_STATUS
	};

	ZHeader(QWidget*, char const*, unsigned);
	ZHeader(ZHeader::HEADER_TYPE, QWidget*, char const*, unsigned);
	~ZHeader();
		
	int alignment();
	void changeStatus(ZHeader::HEADER_STATUS, int);
		
	QString getPrimTitle();
	QString getSecondTitle();
	
	void initStatus(ZHeader::HEADER_TYPE);
	bool isTruncEnable();
	bool isZEnable();
	virtual void paintEvent(QPaintEvent*);
	virtual void primTitleChanged(QString const&);
	void registerInfo(ZHeader::AppStatusInfo_S const&);
	virtual void resizeEvent(QResizeEvent*);
	virtual void secondTitleChanged(QString const&);
	void setAlignment(int);
	void setPalette(QPalette const&);
	void setPrimTitle(QString const&);
	void setSecondTitle(QString const&);
	void setTimeString();
	void setTruncEnable(bool);
	
	virtual void slotChangePrimTitle(QString const&);
	virtual void slotChangeSecondTitle(QString const&);
	virtual void slotDisplayTime();
	virtual void slotGetIcon(int);
	virtual void slotPaletteChanged();
	
	void switchHeader(ZHeader::HEADER_TYPE);
		
	void unregisterInfo(ZHeader::HEADER_STATUS);
	void updateArea(int);
};

#endif
