//Fix for Motorola ZN5 by Ant-ON, 2009

// Copyright (c) 27-Apr-07 - 2008 Motorola, Inc. All rights reserved.

#ifndef PUBLIC_API_WIDGET_ZSCROLLBAR_H
#define PUBLIC_API_WIDGET_ZSCROLLBAR_H

class QTimer;

#ifndef QT_H
#include "qwidget.h"
#include "qrangecontrol.h"
#include "qdrawutil.h" // REMOVE THIS IN 3.0
#endif // QT_H

#include "ZWidget.h"

#ifndef QT_NO_SCROLLBAR

class ZScrollBarPrivate;

/// The widget provides a vertical or horizontal scroll bar.

/// For more information, please refer to /vobs/ezx_qt/code/doc/html/qscrollbar.html

class Q_EXPORT ZScrollBar : public ZWidget, public QRangeControl
{
    Q_OBJECT
public:
    enum Orientation {
        Horizontal,     ///< horizontal scrollbar
        Vertical        ///< vertical scrollbar
    };

    ///
    /// indicate if increment or decrement button is selected.
    ///
    enum INCORDEC {
        NEITHER_SELECT, ///< neither increment nor decrement
        INC_SELECT,     ///< increment
        DEC_SELECT      ///< decrement
    };

    ZScrollBar(QWidget *parent, const char *name = 0, WFlags f = 0,
        ZSkinService::WidgetClsID clsId = ZSkinService::clsZScrollbar);

    ZScrollBar(Orientation orientation,
        QWidget *parent, const char *name = 0, WFlags f = 0,
        ZSkinService::WidgetClsID clsId = ZSkinService::clsZScrollbar);

    ZScrollBar(int minValue, int maxValue,
        int LineStep, int PageStep, int value,
        Orientation orientation, QWidget *parent,
        const char *name = 0, WFlags f = 0,
        ZSkinService::WidgetClsID clsId = ZSkinService::clsZScrollbar);

    ~ZScrollBar();
    virtual void setOrientation( Orientation );
    Orientation orientation() const;

    virtual void setPalette( const QPalette & );
    void updateSkin(bool redraw);
    QSize	sizeHint() const;
    /// this function will be replaced sizeHint() function in the further
    /// version. It returns width of vertical scroll bar or height of
    /// horizontal scroll bar.
    //int getExtent() const;

    //int	 minValue() const;
    //int	 maxValue() const;
    void setMinValue( int );
    void setMaxValue( int max )
	{
		setRange(0,max);
	};
    //int	 lineStep() const;
    //int	 pageStep() const;
    void setLineStep( int n )
	{
		setSteps(n, pageStep());
	};	
    void setPageStep( int n )
	{
		setSteps(lineStep(),n);
	};
    //int  value() const;
    ///
    /// When value is changed, the increment or decrement button can show
    /// pictures in selection status as user specified
    ///
    //void setValue(int v, enum INCORDEC s = NEITHER_SELECT);

    ///
signals:
    void	valueChanged( int value );
    void	sliderPressed();
    void	sliderMoved( int value );
    void	sliderReleased();
    void	nextLine();
    void	prevLine();
    void	nextPage();
    void	prevPage();
protected slots:
    ///
    /// recover increment or decrement button to standard status
    ///
    void slotRecoverStdStatus();
protected:
    void	resizeEvent( QResizeEvent * );
    void	paintEvent( QPaintEvent * );

    void	valueChange();
    void	stepChange();
    void	rangeChange();

    int		sliderStart() const;

    // obsolete!!!
    QRect	sliderRect() const;

private:
    void init();
    void positionSliderFromValue()  const;
    int rangeValueToSliderPos( int val )  const;
    void sliderMinMax( int &, int & )		const;
    void metrics(int &, int &, int &) const;

    QPixmap getIncPixmap() const;
    QPixmap getDecPixmap() const;
    void drawControls();
private:    
    ZScrollBarPrivate* d;
};

#endif // QT_NO_SCROLLBAR

#endif // QSCROLLBAR_H
