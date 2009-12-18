#ifndef __ZPROGRESSSLIDER_H__
#define __ZPROGRESSSLIDER_H__

#include "ZWidget.h"
#include "qrangecontrol.h"
#include "ZSkinBase.h"
//#include "ZSkinTool.h"

class QTimer;
class ZSkinTool;
struct ZProgressSliderPrivate;

class ZProgressSlider : public ZWidget, public QRangeControl //,public ZSkinBase
{
    Q_OBJECT
    Q_PROPERTY( int minValue READ minValue WRITE setMinValue )
    Q_PROPERTY( int maxValue READ maxValue WRITE setMaxValue )
    Q_PROPERTY( int lineStep READ lineStep WRITE setLineStep )
    Q_PROPERTY( int pageStep READ pageStep WRITE setPageStep )
    Q_PROPERTY( int value READ value WRITE setValue )
    Q_PROPERTY( Orientation orientation READ orientation WRITE setOrientation )
  
public:

    enum Indicator{
      NULL_MINMAX,
      TEXT,
      ICON      
    };

    ZProgressSlider( QWidget *parent=NULL, const char *name=0,const ZSkinService::WidgetClsID clsId = ZSkinService::clsZProgressSlider );
    ZProgressSlider( Indicator indicator,Orientation orientation, QWidget *parent=NULL, const char *name=0,const ZSkinService::WidgetClsID clsId = ZSkinService::clsZProgressSlider );
    ZProgressSlider( int minValue, int maxValue, int pageStep, int value, Indicator indicator,Orientation orientation,
	     QWidget *parent=NULL, const char *name=0 ,const ZSkinService::WidgetClsID clsId = ZSkinService::clsZProgressSlider);

    virtual ~ZProgressSlider();

    virtual void	setOrientation( Orientation orientation);
    Orientation orientation() const;

    int	 minValue() const;
    int	 maxValue() const;
    void setMinValue( int );
    void setMaxValue( int );
    int	 lineStep() const;
    int	 pageStep() const;
    void setLineStep( int i );
    void setPageStep( int i);
    int  value() const;
    void setPixmap(QPixmap increment,QPixmap decrement);
    void reset();
    void showThumb( bool bShow );
    void setThickness(int nCounts);
    int	thickness() const;

    virtual QSize sizeHint() const;
    virtual QSize minimumSizeHint() const;

    void  setEnabled(bool enable);
    bool  isZEnabled();
    bool  isZDisabled();

    bool  autoResize() const;
    void  setAutoResize( bool enable );

    void  setSelectionState( const ZSkinBase::SelectionState state );
 
public slots:
    virtual void	setValue( int );
    void	addStep();
    void	subtractStep();
    void        updateState();
signals:
    void	valueChanged( int value );
    void        progresssliderSizeChange();
    void        signalSelect();
protected:
    void	resizeEvent( QResizeEvent * );
    void	paintEvent( QPaintEvent * );

    void	keyPressEvent( QKeyEvent * );
    void        keyReleaseEvent( QKeyEvent *e ) ;
    void	focusInEvent( QFocusEvent *e );
    void	focusOutEvent( QFocusEvent *e );

    void	valueChange();
    void	rangeChange();

    virtual void paintSlider( QPainter *, const QRect & );
   
    void        updateSkin(bool redraw);
    virtual void setPalette(const QPalette &palette);

private:
    QRect	sliderRect() const;

    void	init();
    int		positionFromValue( int ) const;
    int		valueFromPosition( int ) const;
    void	moveSlider( int );
    void	reallyMoveSlider( int );
    int		slideLength() const;
    int		available() const;
    void	initTicks();
    void        resizeSlider();
    ZProgressSliderPrivate *d;
    QCOORD	sliderPos;
    int		sliderVal;
    bool	track;
    QCOORD	tickOffset;
    Orientation orient;
    Indicator indi;
    void loadLRS( WIDGET_PADDING_INFO_T &pad,int &nSpacing) const;

    QPixmap thumbBPixmap;
    //ZSkinTool skinTool;
    int nSliderLength;
    int nThumbV,nThumbH;
    int defaultVal;
    bool bShowThumb;
    void updatePixmap(enum SelectionState states);

    void setSpacingS1(int nSpacing);
    short getSpacingS1() const;

private:	// Disabled copy constructor and operator=
#if defined(Q_DISABLE_COPY)
    ZProgressSlider( const ZProgressSlider & );
    ZProgressSlider &operator=( const ZProgressSlider & );
#endif
};


inline ZProgressSlider::Orientation ZProgressSlider::orientation() const
{
    return orient;
}


#endif // __ZPROGRESSSLIDER_H__
