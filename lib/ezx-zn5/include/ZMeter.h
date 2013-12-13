//Fix for ZN5/U9 by Ant-ON, 25-10-2010
//Chenge fix by Ant-ON, 11.08.2010
//Fix class size for ZN5 by Ant-ON, 26.09.2011

// Copyright (c) 27-Apr-07 - 2008 Motorola, Inc. All rights reserved.

#ifndef __ZMETER_H_
#define __ZMETER_H_

#include <qwidget.h>
#include <ZSkinBase.h>

struct ZMeterData;

//Size in ZN5: 0xF0

class ZMeter : public ZWidget
{
    Q_OBJECT

	unsigned char fix[0xF0-sizeof(ZWidget)];
public:
    enum Information{
       NULL_MINMAX,
       TEXT,
       ICON
    };
 
    enum Alignment{
      TWO_BOTTOM,
      LEFT_TOP,
      RIGHT_BOTTOM
    };

    enum PixmapSetting{
      HORIZONTAL_PIXMAP,
      VERTICAL_PIXMAP,
      ALL_PIXMAP
    };
  
    ZMeter(int nTotalCounts,int nMaxSize,
            QWidget *parent=0, const char *name=0, WFlags f=0,
            const ZSkinService::WidgetClsID clsId = ZSkinService::clsZMeter_Indicator2);

    ZMeter(QString strFileName="",QWidget *parent = 0,const char *name=0,WFlags f=0,
            const ZSkinService::WidgetClsID clsId = ZSkinService::clsZMeter_Indicator3);

    ZMeter( int nTotalCounts,QWidget *parent=0, const char *name=0, WFlags f=0,
            const ZSkinService::WidgetClsID clsId = ZSkinService::clsZMeter_Indicator1);

    virtual ~ZMeter();

    void reset();
    void pause();
	
    //int  totalSteps() const;

    int  progress() const;

    //void setMinText( QString strMinText );
    //void setMaxText( QString strMaxText );
    
    //QString minText();
    //QString maxText();

    //void setPixmap(QPixmap minPixmap,QPixmap maxPixmap,PixmapSetting setting);

    //void setOrientation(Orientation orientation);
    //Orientation orientation() const;

    void setAlignment(Alignment alignment);
    //Alignment alignment() const;

    void setInformation(Information information);
    //Information information() const;

    //QSize sizeHint() const;
    //QSize minimumSizeHint() const;

    void setMaxSize( int nMaxSize);
    //int  maxSize() const;

    //bool autoResize () const;
    void setAutoResize ( bool enable );

    //void  setEnabled(bool enable);
    //bool  isZEnabled();
    //bool  isZDisabled();
  
    bool  paused () const;

    //bool  running () const;
 
signals:
    void meterSizeChange();

public slots: 
    virtual void setTotalSteps( int totalSteps ); // ???
    virtual void setProgress( int progress ); // ???
    //void sizeChanged();
    
//protected:
    //void resizeEvent(QResizeEvent *);
    //void paintEvent(QPaintEvent *);
    //void updateSkin(bool redraw);
    //virtual void setPalette(const QPalette &palette);
    //void showEvent ( QShowEvent *e );
    
private:
    enum Types{                   // MeterType 
       STATIC,                           // tile
       DETERMINATE,               // stretch
       INDETERMINATE             // indeterminate
     };

     void init();

//     ZMeterData *d;

     void initButton();

/*
     Information info;
     Orientation orien;
     Alignment align;

     int nTotalSteps;
     int progress_val;
     Types typ;
*/

    void setSpacingS2(int nSpacing);
    short getSpacingS2()const;

    void  setSpacingS1(int nSpacing);
    short getSpacingS1() const;
    void  getIndicatorLength() const;
    //QSize meterATypeSizeHint() const;
    //QSize meterBTypeSizeHint() const;
    QSize ZMeter::getIndicatorSize() const;
    int getIndicatorX() const;
    int getIndicatorY() const;
    //void drawIndicatorContents( QPixmap& all,int xPoint,int yPoint,QSize sz );
};

struct ZMeterModuleData;

//Size in ZN5: 0xF0

class ZMeterModule:public ZWidget  //QWidget,public ZSkinBase
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

    ZMeterModule( int nTotalCounts, int nMaxSize, QWidget *parent = 0,const char *name =0,WFlags f=0,
            const ZSkinService::WidgetClsID clsId = ZSkinService::clsZMeterModule,
            const ZSkinService::WidgetClsID clsIdMeter = ZSkinService::clsZMeter_Indicator2);
    ZMeterModule(QString strFileName="",
            QWidget *parent=NULL,const char *name=0,WFlags f=0,
            const ZSkinService::WidgetClsID clsId = ZSkinService::clsZMeterModule,
            const ZSkinService::WidgetClsID clsIdMeter = ZSkinService::clsZMeter_Indicator3);
    ZMeterModule(int nTotalCounts,QWidget *parent=NULL, const char *name=0, WFlags f=0,
            const ZSkinService::WidgetClsID clsId = ZSkinService::clsZMeterModule,
            const ZSkinService::WidgetClsID clsIdMeter = ZSkinService::clsZMeter_Indicator1);

    virtual ~ZMeterModule();
    ZMeter *getMeter() const;
    void setAlignment(Alignment alignment);
    //Alignment alignment() const;

    //void setOrientation(Orientation orientation);
    //Orientation orientation() const;

    void setLabelText(QString strText);

    //QSize sizeHint() const;
    //QSize minimumSizeHint() const;

    //void setMaxSize(int nMaxSize);

    //bool autoResize () const;
    //void setAutoResize ( bool enable );

    //void setSpacingV1(short nSpacing);

//public slots:
//    void sizeChanged(); 

protected:
    //virtual void resizeEvent(QResizeEvent *); 
    //void paintEvent(QPaintEvent *);
    //void resizeAll();
    void updateSkin(bool redraw);
    //virtual void setPalette(const QPalette &palette);

private:
/*
    ZMeterModuleData *d;
    int m_nValue;
    Alignment align;
    Orientation orien;
*/
    void arrangeWidgets();
    void init();
    void setSpacingH1(short nSpacing);
    short getSpacingH1() const;

    short getSpacingV1() const;
};

#endif
