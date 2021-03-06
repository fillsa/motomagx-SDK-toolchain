//Fix for ZN5/U9 by Ant-ON, 26-01-2010
//Add "fix" by Ant-ON, 11-08-2010
//Chenge fix by Ant-ON, 11.08.2010
//Fix class size for ZN5 by Ant-ON, 26.09.2011

// Copyright (c)  - 2008 Motorola, Inc. All rights reserved.


#ifndef PUBLIC_API_WIDGET_ZSLIDERMODULE_H
#define PUBLIC_API_WIDGET_ZSLIDERMODULE_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "ZWidget.h"
#include "ZSlider.h"
struct ZSliderModuleData;

//Size in ZN5: 0xF0

class ZSliderModule:public ZWidget
{
	Q_OBJECT
	
	unsigned char fix[0xF0-sizeof(ZWidget)];
public:
    enum Alignment{
    NULL_LABEL,
    LEFT,
    TOP,
    RIGHT,
    BOTTOM
  };

    ZSliderModule(QWidget *parent = 0,const char *name =0,
                            const ZSkinService::WidgetClsID clsId = ZSkinService::clsZSliderModule);

    ZSliderModule(ZSlider::Indicator indicator,QWidget *parent=0,const char *name=0,
                           const ZSkinService::WidgetClsID clsId = ZSkinService::clsZSliderModule);

    ZSliderModule( int minValue, int maxValue, int pageStep, int value,
                            ZSlider::Indicator indicator, QWidget *parent=0, const char *name=0,
                            const ZSkinService::WidgetClsID clsId = ZSkinService::clsZSliderModule);

    virtual ~ZSliderModule();

    ZSlider *getSlider() const;

    void setOrientation( Orientation );

    //Orientation orientation() const;
    //void setSliderOrient( bool bVertical) ;
    
    void setAlignment(Alignment alignment);
    
    //Alignment alignment() const;
    //void setThickness(int nCounts);
    //QSize sizeHint() const;

    //void updateSkin(bool redraw);

    virtual void setPalette(const QPalette &palette);

//public:
    //QSize minimumSizeHint() const;
    //bool autoResize() const;
    //void setAutoResize( bool enable );
    //void setSpacingV1(short nSpacing);
    //void setOmgPage(int steps);
    //int omgPage(void);
    //virtual void setOmegaInput(bool flag);

signals:
    void valueChanged(int);

public slots:
    void updateLabel(QString strText);

    void updateLabel();

    //void updateValue();

    //void resizeAll();

private slots:
    void timerDone();
    void valueChange(int);

protected:
    virtual void resizeEvent(QResizeEvent * e);

    void keyPressEvent(QKeyEvent * e);

    void paintEvent(QPaintEvent * e);

    void focusInEvent( QFocusEvent * e );

private:
    void init();
    void arrangeWidget();
    void setSpacingH1(short nSpacing);
    short getSpacingH1() const;
    short getSpacingV1() const;

//private:
//    ZSliderModuleData *d;
};

#endif  
