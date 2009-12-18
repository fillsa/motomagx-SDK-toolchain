#ifndef _SCOLLBAR_H_
#define _SCOLLBAR_H_ 1

#include <ZWidget.h>

/* Size 316=79*4 */

class ZScrollBar : public ZWidget
{
    Q_OBJECT
    unsigned int data[80 - sizeof(ZWidget)/4];

public:
    virtual int setOrientation(Qt::Orientation);
    virtual int setTracking(bool);
    virtual int valueChange();
    virtual int stepChange();
    virtual int rangeChange();

	ZScrollBar(QWidget*, char const*);
	ZScrollBar(int, int, int, int, int, Qt::Orientation, QWidget*, char const*);
	~ZScrollBar();

        void paintEvent(QPaintEvent*);
        void setPalette(QPalette const&);
        void wheelEvent(QWheelEvent*);
        void resizeEvent(QResizeEvent*);
        void setLineStep(int);
        void setMaxValue(int);
        void setMinValue(int);
        void setPageStep(int);
        void sliderMoved(int);
        void styleChange(QStyle&);
        void doAutoRepeat();
        void valueChanged(int);
        void keyPressEvent(QKeyEvent*);
        void sliderPressed();
        void mouseMoveEvent(QMouseEvent*);
        void sliderReleased();
        void stopAutoRepeat();
        void mousePressEvent(QMouseEvent*);
        void startAutoRepeat();
        void mouseReleaseEvent(QMouseEvent*);
        void positionSliderFromValue();
        void init();
        void action(QStyle::ScrollControl);
        void nextLine();
        void nextPage();
        void prevLine();
        void prevPage();
        void setValue(int);
        QSizePolicy sizePolicy() const;
        void sliderRect() const;
        void drawControls(unsigned int, unsigned int) const;
        void drawControls(unsigned int, unsigned int, QPainter*) const;
        void sliderMinMax(int&, int&) const;
        void draggingSlider() const;
        void rangeValueToSliderPos(int) const;
        void sliderPosToRangeValue(int) const;
        void calculateValueFromSlider() const;
        void value() const;
        void metrics(int&, int&, int&, int&) const;
        void lineStep() const;
        void maxValue() const;
        void minValue() const;
        void pageStep() const;
        QSize sizeHint() const;
        void pointOver(QPoint const&) const;

};

#endif
