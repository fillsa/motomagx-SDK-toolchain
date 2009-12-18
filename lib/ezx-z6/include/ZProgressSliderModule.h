#ifndef __ZPROGRESSSLIDER_MODULE_H__
#define __ZPROGRESSSLIDER_MODULE_H__

//#include "qwidget.h"
#include "ZWidget.h"
#include "ZProgressSlider.h"
//#include "ZSkinBase.h"

struct ZProgressSliderModuleData;

class ZProgressSliderModule:public ZWidget 
{
Q_OBJECT

public:
   enum Alignment{
    NULL_LABEL,
    LEFT,
    TOP,
    RIGHT,
    BOTTOM
   };

   ZProgressSliderModule(QWidget *parent = 0,const char *name =0,const ZSkinService::WidgetClsID clsId = ZSkinService::clsZProgressSliderModule);
   ZProgressSliderModule(ZProgressSlider::Indicator indicator,QWidget *parent=0,const char *name=0,const ZSkinService::WidgetClsID clsId = ZSkinService::clsZProgressSliderModule);
   ZProgressSliderModule(int minValue, int maxValue, int pageStep, int value, ZProgressSlider::Indicator indicator,QWidget *parent=0, const char *name=0,const ZSkinService::WidgetClsID clsId = ZSkinService::clsZProgressSliderModule);

    virtual ~ZProgressSliderModule();
    ZProgressSlider *getSlider() const;
    void	setOrientation( Orientation orientation);
    Orientation orientation() const;
    void setAlignment(Alignment alignment);
    Alignment alignment() const;
    virtual QSize sizeHint() const;
    virtual QSize minimumSizeHint() const;
    void setThickness(int nCounts);

    bool autoResize() const;
    void setAutoResize( bool enable );

signals:
    void valueChanged(int nValue);

public slots:
     void updateLabel(QString str);
     void updateLabel();
     void resizeAll();
private slots:

    void valueChange(int nValue); 
    void timerDone();

protected:
    virtual void resizeEvent(QResizeEvent *); 
    void keyPressEvent(QKeyEvent *);
    void paintEvent(QPaintEvent *);
    void updateSkin(bool redraw);
    virtual void setPalette(const QPalette &palette);
    void  focusInEvent( QFocusEvent * e);

private:
    ZProgressSliderModuleData *d;
    int m_nValue;
    bool m_bHasTime;
    Alignment align;
    Orientation orien;
    void init();
    void arrangeWidgets();
    void setSpacingH1(short nSpacing);
    short getSpacingH1() const;
    void setSpacingV1(short nSpacing);
    short getSpacingV1() const;
};

inline ZProgressSliderModule::Orientation ZProgressSliderModule::orientation( ) const
{
    return orien;
} 

inline ZProgressSliderModule::Alignment ZProgressSliderModule::alignment( ) const
{
   return align;
}

#endif
