//This file is create by lasly
//u can use it to create e2 native program
//and u can find my blog in http://my.opera.com/Lasly
// e2_ezx_sdk_0.01

// ZLabel ÏÂÃæ·²ÊÇÒÔ£¿¿ªÍ·µÄ×¢ÊÍ¶ŒÊÇ²Â²âµÄÓÃÍŸ£¬Ã»ÓÐŸ­¹ý²âÊÔ


// _ZN6ZLabelC4EP7QWidgetPKcjN12ZSkinService11WidgetClsIDE
// _ZN6ZLabelC4ERK7QStringP7QWidgetPKcjN12ZSkinService11WidgetClsIDE
// _ZN6ZLabelD4Ev

#ifndef _E2_EZX_ZLABEL_H
#define _E2_EZX_ZLABEL_H

#include <qwidget.h>
#include <qcstring.h>
#include <qpainter.h>
#include <qpixmap.h>
#include <qstring.h>

#include <E2_EZX_ZWidget.h>

class ZLabel : public ZWidget
{ 
	Q_OBJECT
	char tmp[4096];
public:
    ZLabel( QWidget *parent, const char *name=0, WFlags f=0,
            const ZSkinService::WidgetClsID clsId = ZSkinService::clsTotal );
    ZLabel( const QString &text, QWidget *parent, const char *name=0,
           WFlags f=0, const ZSkinService::WidgetClsID clsId = ZSkinService::clsTotal);
	~ZLabel();
	void adjustHeightBySetting(int);
	void setAutoResize(bool);
	void setGeometry(int, int, int, int);
	void setNumLines(int);
	void clear() ;
	void setPreferredWidth(int);
	int heightForWidth(int) const;
	void setEnabled(bool);
	void setText(QString const&);
/*	int drawOutlineText(QPainter*, QColor, QColor, int, int, int, int, int, QString const&, int, QRect*, char**);
 	int fontChange(QFont const&)
	int fontColor() const
	int getContentNumLines()
	int getContentRect()
	int getFrameWidth(int&, int&, int&, int&) const
	int getTrancatestr(QString const&)
	int heightForWidth(int) const
	int initMetaObject()
	int isParentBackground()
	int isZDisabled()
	int isZEnabled()
	int leading() const
	int marqueeDirection() const
	int marqueePause()
	int marqueePlay()
	int marqueeRepetition() const
	int marqueeSpeed() const
	int marqueeState() const
	int marqueeStep() const
	int numLines() const
	int paintEvent(QPaintEvent*)
	int preferredWidth() const
	int setAlignment(Qt::AlignmentFlags)
	int setEnabled(bool)
	int setFontColor(QColor const&)
	int setGeometry(QRect const&)
	int setGeometry(int, int, int, int)
	int setLeading(int)
	int setMarqueeDirection(ZLabel::MarqueeDirection)
	int setMarqueeRepetition(int)
	int setMarqueeSpeed(int)
	int setMarqueeState(ZLabel::MarqueeState)
	int setMarqueeStep(int)
	int setNumLines(int)
	int setOutline(bool, QColor, QColor)
	int setPadding(ZWidgetPaddingInfo const&)
	int setPalette(QPalette const&)
	int setParentBackground(bool)
	int setText(QString const&)
	int setTextDirection(ZLabel::TextDirection)
	int setTruncateNum(int)
	int setTruncateStat(unsigned char)
	int setTruncateString(QString const&)
	int setWrapPolicy(ZWrapLine::WrapPolicy)
	int showEvent(QShowEvent*)
	int sizeHint() const
	int staticMetaObject()
	int textDirection() const
	int tr(char const*)
	int tr(char const*, char const*)
	int truncateNum() const
	int truncateStat() const
	int truncateString() const
	int wrapPolicy() const */
};

#endif
