//This file is create by lasly
//u can use it to create e2 native program
//and u can find my blog in http://my.opera.com/Lasly
// e2_ezx_sdk_0.01

// ZAppInfoArea 下面凡是以？开头的注释都是猜测的用途，没有经过测试

// _ZN12ZAppInfoAreaC4EP7QWidgetPKcjN12ZSkinService11WidgetClsIDE
// _ZN12ZAppInfoAreaD4Ev

#ifndef _E2_EZX_ZAPPINFOAREA_H
#define _E2_EZX_ZAPPINFOAREA_H

#include <qstring.h>
#include <qwidget.h>
#include <qpixmap.h>
#include <qpainter.h>
#include <qrect.h>
#include <qevent.h>

#include <E2_EZX_ZAppend.h>
#include <E2_EZX_ZFmwArea.h>
#include <E2_EZX_ZFmwItem.h>

class ZAppInfoArea : public QWidget
{
	Q_OBJECT
	char tmp[4096];
public:
	enum AREA_IDX
	{
		NONE_IDX
	};
	enum ACTIVITY_MODE
	{
		NONE_MODE
	};
	enum METER_STYLE
	{
		NONE_STYLE
	};
	enum COUNTER_MODE
	{
		NONE_COUNTER_MODE
	};
	enum COUNTERICON_ALIGN
	{
		NONE_ALIGN
	};
	enum COUNTER_V
	{
		NONE_V
	};

	ZAppInfoArea(QWidget*, char const*, unsigned, ZSkinService::WidgetClsID);
	~ZAppInfoArea();
	
	void appendAnimation(ZAppInfoArea::AREA_IDX, QString const&, QString const&);
	void appendIcon(ZAppInfoArea::AREA_IDX, QPixmap const&, QString const&);
	void appendIcon(ZAppInfoArea::AREA_IDX, QString const&, QPixmap const&, QString const&);
	void appendIcon(ZAppInfoArea::AREA_IDX, QString const&, QString const&);
	void appendText(ZAppInfoArea::AREA_IDX, QString const&, QString const&);
	void appendWidget(ZAppInfoArea::AREA_IDX, QWidget*, QString const&);
	
	void createIconItem(QPixmap const&, QString const&);
	void createIconItem(QString const&, QString const&);
	void createTextItem(QString const&);
	void createTextItem(QString const&, QString const&);
	void createWidgetItem(QWidget*, QString const&);
	
	void cropWidgetFromArea(ZAppInfoArea::AREA_IDX, int&);
	void deleteArea(ZAppInfoArea::AREA_IDX, int&);
		
	void drawActivityArea(QPainter*);
	void drawArea(ZFmwArea*, QPainter*, QRect const&);
	void drawCounterArea(QPainter*);
	void drawInputArea(QPainter*);
	void drawStorageArea(QPainter*);
	void enableOutlineText(bool);
	
	// -------------note----------------------have not finished
	int getActMeter();
	const int getAreaHeight(ZFmwArea*); 
	const int getAreaWidth(ZFmwArea*); 
	int getAreaWidthExceptStorage();
	const int getContentHeight();
	int getInitAreaWidth(ZFmwArea*);
	const int getInternalSpacing();
	const int getItemHeight(ZFmwItem*);
	int getMeterStyle();
	const int getOutlineColor();
	const int getPadding(int);
	QRect getRect();
	const int getSpacing();
	int getTotalItemNum();
	int getWidgetHeight(); const
	int getWidgetRect();
	int getWidth(ZAppInfoArea::AREA_IDX);
		
	void insertAnimation(ZAppInfoArea::AREA_IDX, int, QString const&, QString const&);
	void insertIcon(ZAppInfoArea::AREA_IDX, int, QPixmap const&, QString const&);
	void insertIcon(ZAppInfoArea::AREA_IDX, int, QString const&, QString const&);
	void insertText(ZAppInfoArea::AREA_IDX, int, QString const&, QString const&);
	void insertWidget(ZAppInfoArea::AREA_IDX, int, QWidget*, QString const&);
	bool isAreaCouldInsertItem(ZAppInfoArea::AREA_IDX);
	bool isHasNewWordIcon();
	bool isOutlineText();
	bool isRemoveIconFromArea(ZAppInfoArea::AREA_IDX, ZFmwItem*);
	bool isRemoveNewWordFromInput(ZAppInfoArea::AREA_IDX, ZFmwItem*);
	bool isValidArea(ZAppInfoArea::AREA_IDX);
	bool isZEnable();
	
	void itemNum(int);
	void paint(QPainter*);
	void paintBackground(QPainter*);
	void paintBorder(QPainter*);
	void paintEvent(QPaintEvent*);
	void paintFrame(QPainter*);
	void printArea(ZAppInfoArea::AREA_IDX);
	void removeArea(ZAppInfoArea::AREA_IDX);
	void removeCounterIcon();
	void removeIconFromArea(ZAppInfoArea::AREA_IDX, int&, bool (ZAppInfoArea::*)(ZAppInfoArea::AREA_IDX, ZFmwItem*));
	void removeItem(ZAppInfoArea::AREA_IDX, QString const&);
	void removeItem(ZAppInfoArea::AREA_IDX, int);
	void resizeWidget();
	void restoreArea();
	void scaleArea();
	
	void setActArea(ZAppInfoArea::ACTIVITY_MODE);
	void setAllAreaWidth();
	void setCounterArea(ZAppInfoArea::COUNTER_MODE);
	void setCounterIcon(ZAppInfoArea::COUNTERICON_ALIGN, QPixmap const&);
	void setCounterIcon(ZAppInfoArea::COUNTERICON_ALIGN, QString const&);
	void setCounterIcon(ZAppInfoArea::COUNTERICON_ALIGN, QString const&, QPixmap const&);
	void setCounterQualifier(QString const&);
	void setCounterVariable(ZAppInfoArea::COUNTER_V, QString const&);
	void setIcon(ZAppInfoArea::AREA_IDX, QString const&, QPixmap const&);
	void setIcon(ZAppInfoArea::AREA_IDX, QString const&, QString const&);
	void setIcon(ZAppInfoArea::AREA_IDX, int, QPixmap const&);
	void setIcon(ZAppInfoArea::AREA_IDX, int, QString const&);
	void setInputArea();
	
	void setMeterStyle(ZAppInfoArea::METER_STYLE);
	void setPalette(QPalette const&);
	void setStorage(QString const&, QPixmap const&);
	void setStorageIcon(QPixmap const&);
	void setStorageIcon(QString const&);
	void setText(ZAppInfoArea::AREA_IDX, QString const&, QString const&);
	void setText(ZAppInfoArea::AREA_IDX, int, QString const&);
	void setWidget(ZAppInfoArea::AREA_IDX, QString const&, QWidget*);
	void setWidget(ZAppInfoArea::AREA_IDX, int, QWidget*);
	const int sizeHint();
	void slotHideIconOfInputArea();
	
	int truncateTextFromArea(ZAppInfoArea::AREA_IDX, int&);
};

#endif
