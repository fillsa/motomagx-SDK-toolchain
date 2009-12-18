//This file is create by lasly
//u can use it to create e2 native program
//and u can find my blog in http://my.opera.com/Lasly
// e2_ezx_sdk_0.01

// ZWIDGET 下面凡是以？开头的注释都是猜测的用途，没有经过测试
// 完全新添加的类，

// _ZN7ZWidgetC4EP7QWidgetPKcjN12ZSkinService11WidgetClsIDE
// _ZN7ZWidgetD4Ev

#ifndef _E2_EZX_ZWIDGET_H
#define _E2_EZX_ZWIDGET_H

#include <qwidget.h>
#include <qcstring.h>
#include <qpainter.h>
#include <qpixmap.h>
#include <qstring.h>

#include <E2_EZX_ZAppend.h>
class ZWidget : public QWidget
{
	Q_OBJECT
public:
	ZWidget(QWidget* parent = NULL , char const* str = NULL , unsigned type = 0, ZSkinService::WidgetClsID cls = ZSkinService::NONE);
	~ZWidget();
	const int autoAdjustWidthInPanel(); 
	void cacheTransparentBgImage(bool);
	void drawBackground(QPainter&, QRect const*, bool);
	void drawBackgroundAndBorder(QPainter&, QRect const*);
	void drawBorder(QPainter&, QRect const*);
	void getBgImageForTransparent(bool&);
	const QPixmap* getCachedBgPixmap(); 
	
	int getScreenFSBA();
	int getScreenSkinService();
	const bool isInternalWidget(); 
	const int scrolledInPanel(); 
	void setAutoAdjustWidthInPanel(bool);
	void setInternalWidget(bool);
	void setScreenFSBA(QPixmap&, int, PIXMAP_STRETCH_POLICY_E);
	void setScreenSkinFile(QString);
	void setScrolledInPanel(bool);
	const QPixmap* transparentBgImageCached();
	void updateSkin(bool);
};
#endif
