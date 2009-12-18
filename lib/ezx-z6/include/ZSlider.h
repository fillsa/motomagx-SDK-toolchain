#ifndef _ZSLIDER_H
#define _ZSLIDER_H

#include <ZWidget.h>
#include <ZSkinBase.h>


/* Size: 364=91*4 */

class ZSlider : public ZWidget
{
	Q_OBJECT
	unsigned int data[91-sizeof(ZWidget)/4];
public:
	virtual int setOrientation(Qt::Orientation);
        virtual int setValue(int);
        virtual int valueChange();
        virtual int rangeChange();
        virtual int paintSlider(QPainter*, QRect const&);

	enum Indicator {
		NULL_MINMAX,
        TEXT,
        ICON,
	    NONE = 0
	};

  ZSlider(QWidget*, char const*, ZSkinService::WidgetClsID = ZSkinService::clsZSliderModule);
  ZSlider(ZSlider::Indicator, Qt::Orientation, QWidget*, char const*, ZSkinService::WidgetClsID = ZSkinService::clsZSliderModule);
  ZSlider(int, int, int, int, ZSlider::Indicator, Qt::Orientation, QWidget*, char const*, ZSkinService::WidgetClsID = ZSkinService::clsZSliderModule);
	~ZSlider();

	void addStep();
	void autoResize() const;
	void focusInEvent(QFocusEvent*);
	void focusOutEvent(QFocusEvent*);
	void isZDisabled();
	void isZEnabled();
	void keyPressEvent(QKeyEvent*);
	void keyReleaseEvent(QKeyEvent*);
	void lineStep() const;
	void maxValue() const;
	void minValue() const;
	QSize minimumSizeHint() const;
	void pageStep() const;
	void paintEvent(QPaintEvent*);
	void reset();
	void resizeEvent(QResizeEvent*);
	void setAutoResize(bool);
	void setEnabled(bool);
	void setLineStep(int);
	void setMaxValue(int);
	void setMinValue(int);
	void setPageStep(int);
	void setPalette(QPalette const&);
	void setPixmap(QPixmap, QPixmap);
	void setSelectionState(ZSkinBase::SelectionState);
	void setThickness(int);
	void showThumb(bool);
	void signalSelect();
	QSize sizeHint() const;
	QSize sliderSizeChange();
	void subtractStep();
	void thickness() const;
	void updateSkin(bool);
	void updateState();
	int value() const;
	int valueChanged(int);
};

/* Size 284=71*4 */

class ZSliderModule : public ZWidget
{
	Q_OBJECT
	unsigned int data[71-sizeof(ZWidget)/4];
public:
	enum Alignment {
	};

	ZSliderModule(ZSlider::Indicator, QWidget*, char const*, ZSkinService::WidgetClsID);
	ZSliderModule(QWidget*, char const*, ZSkinService::WidgetClsID);
	ZSliderModule(int, int, int, int, ZSlider::Indicator, QWidget*, char const*, ZSkinService::WidgetClsID);
	~ZSliderModule();

	void paintEvent(QPaintEvent*);
	void setPalette(QPalette const&);
	void updateSkin(bool);
	void resizeEvent(QResizeEvent*);
	void updateLabel(QString);
	void updateLabel();
	void updateValue();
	void focusInEvent(QFocusEvent*);
	void setAlignment(Alignment);
	void setSpacingV1(short);
	void setThickness(int);
	void keyPressEvent(QKeyEvent*);
	void setAutoResize(bool);
	void setOrientation(Qt::Orientation);
	void resizeAll();
	void autoResize() const;
	QSize minimumSizeHint() const;
	QSize sizeHint() const;
	void getSlider() const;
};



#endif

