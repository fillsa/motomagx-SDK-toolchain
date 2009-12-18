//This file is create by lasly
//u can use it to create e2 native program
//and u can find my blog in http://my.opera.com/Lasly
// e2_ezx_sdk_0.01

// ZFmwItem 下面凡是以？开头的注释都是猜测的用途，没有经过测试

// _ZN8ZFmwItemC4ENS_4TypeEi
// _ZN8ZFmwItemC4ENS_4TypeERK7QStringi

#ifndef _E2_EZX_ZFMWITEM_H
#define _E2_EZX_ZFMWITEM_H

#include <qstring.h>
#include <qwidget.h>
#include <qfontmetrics.h>
#include <qpixmap.h>

class ZFmwItem
{
public:
	enum Type
	{
		NONE
	};
	ZFmwItem(ZFmwItem::Type, QString const&, int);
	ZFmwItem(ZFmwItem::Type, int);
	int getAlignment();
	QString getIcon();
	int getKey();
	int getSteadyWidth();
	QString getText();
	ZFmwItem::Type getType();
	QWidget* getWidget();
	int getWidth();
	void growToNoTrunc(QFontMetrics*);
	void setAlignment(int);
	void setIcon(QPixmap const&);
	void setIcon(QString const&);
	void setSteadyWidth(int);
	void setText(QString const&);
	void setWidget(QWidget*);
	void setWidth(int);
};
#endif
