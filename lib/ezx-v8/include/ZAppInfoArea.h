#ifndef _ZAPPINFOAREA_H
#define _ZAPPINFOAREA_H

#include <ZWidget.h>

class ZFmwItem;
class ZFmwArea;

/* Size: 312=78*4 */

class ZAppInfoArea : public ZWidget
{
	Q_OBJECT

	unsigned int data[79-sizeof(QWidget)/4];

public:
	enum AREA_IDX {
    input, 
    activity, 
    counter, 
    storage , 
    area_num
	};
	enum ACTIVITY_MODE 
  {
    progress_meter, 
    no_progress_meter 
	};
	enum COUNTER_MODE {
    two_variable_qualifier, 
    one_variable_qualifier, 
    one_variable, 
    free
	};
	enum COUNTERICON_ALIGN {
    left, 
    right, 
    invalid_align
	};
	enum COUNTER_V {
    left_v, 
    right_v
	};
	enum METER_STYLE {
	};

  ZAppInfoArea(QWidget*, char const* = 0, unsigned int = 0, ZSkinService::WidgetClsID = ZSkinService::clsZAppInfoArea);
	~ZAppInfoArea();

	void appendAnimation(AREA_IDX, QString const&, QString const&);
	void appendIcon(AREA_IDX, QPixmap const&, QString const&);
	void appendIcon(AREA_IDX, QString const&, QPixmap const&, QString const&);
	void appendIcon(AREA_IDX, QString const&, QString const&);
	void appendText(AREA_IDX, QString const&, QString const&);
	void appendWidget(AREA_IDX, QWidget*, QString const&);
	void createIconItem(QPixmap const&, QString const&);
	void createIconItem(QString const&, QString const&);
	void createTextItem(QString const&);
	void createTextItem(QString const&, QString const&);
	void createWidgetItem(QWidget*, QString const&);
	void cropWidgetFromArea(AREA_IDX, int&);
	void deleteArea(AREA_IDX, int&);
	void drawActivityArea(QPainter*);
	void drawArea(ZFmwArea*, QPainter*, QRect const&);
	void drawCounterArea(QPainter*);
	void drawInputArea(QPainter*);
	void drawStorageArea(QPainter*);
	void enableOutlineText(bool);
	void getActMeter();
	QSize getAreaHeight(ZFmwArea*) const;
	QSize getAreaWidth(ZFmwArea*) const;
	void getAreaWidthExceptStorage();
	QSize getContentHeight() const;
	QSize getInitAreaWidth(ZFmwArea*);
	void getInternalSpacing() const;
	QSize getItemHeight(ZFmwItem*) const;
	void getMeterStyle();
	void getOutlineColor() const;
	void getPadding(int) const;
	QRect getRect();
	void getSpacing() const;
	void getTotalItemNum();
	QSize getWidgetHeight() const;
	QRect getWidgetRect();
	int getWidth(AREA_IDX);
	void insertAnimation(AREA_IDX, int, QString const&, QString const&);
	void insertIcon(AREA_IDX, int, QPixmap const&, QString const&);
	void insertIcon(AREA_IDX, int, QString const&, QString const&);
	void insertText(AREA_IDX, int, QString const&, QString const&);
	void insertWidget(AREA_IDX, int, QWidget*, QString const&);
	bool isAreaCouldInsertItem(AREA_IDX);
	bool isHasNewWordIcon();
	bool isOutlineText();
	bool isRemoveIconFromArea(AREA_IDX, ZFmwItem*);
	bool isRemoveNewWordFromInput(AREA_IDX, ZFmwItem*);
	bool isValidArea(AREA_IDX);
	bool isZEnable();
	void itemNum(int);
	void paint(QPainter*);
	void paintBackground(QPainter*);
	void paintBorder(QPainter*);
	void paintEvent(QPaintEvent*);
	void paintFrame(QPainter*);
	void printArea(AREA_IDX);
	void removeArea(AREA_IDX);
	void removeCounterIcon();
	void removeIconFromArea(AREA_IDX, int&, bool (*)(AREA_IDX, ZFmwItem*));
	void removeItem(AREA_IDX, QString const&);
	void removeItem(AREA_IDX, int);
	void resizeWidget();
	void restoreArea();
	void scaleArea();
	void setActArea(ACTIVITY_MODE);
	void setAllAreaWidth();
	void setCounterArea(COUNTER_MODE);
	void setCounterIcon(COUNTERICON_ALIGN, QPixmap const&);
	void setCounterIcon(COUNTERICON_ALIGN, QString const&);
	void setCounterIcon(COUNTERICON_ALIGN, QString const&, QPixmap const&);
	void setCounterQualifier(QString const&);
	void setCounterVariable(COUNTER_V, QString const&);
	void setIcon(AREA_IDX, QString const&, QPixmap const&);
	void setIcon(AREA_IDX, QString const&, QString const&);
	void setIcon(AREA_IDX, int, QPixmap const&);
	void setIcon(AREA_IDX, int, QString const&);
	void setInputArea();
	void setMeterStyle(METER_STYLE);
	void setPalette(QPalette const&);
	void setStorage(QString const&, QPixmap const&);
	void setStorageIcon(QPixmap const&);
	void setStorageIcon(QString const&);
	void setText(AREA_IDX, QString const&, QString const&);
	void setText(AREA_IDX, int, QString const&);
	void setWidget(AREA_IDX, QString const&, QWidget*);
	void setWidget(AREA_IDX, int, QWidget*);
	void truncateTextFromArea(AREA_IDX, int&);

public slots:
	void slotHideIconOfInputArea();
};

#endif
