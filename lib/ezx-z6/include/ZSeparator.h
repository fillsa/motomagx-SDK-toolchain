#ifndef ZSEPARATOR_H
#define ZSEPARATOR_H


#include <qrect.h>
#include <qpixmap.h>
#include <ZSkinBase.h>
#include <ZWidget.h>

struct ZSeparatorData;
class ZLabel;
class ZSeparator:public ZWidget
{
	
public:
      enum RelativeAlignment
	  {
        LEFT,
        RIGHT
      };

       ZSeparator(QWidget *parent = 0,const char *name = 0 , WFlags f = 0,
                   const ZSkinService::WidgetClsID clsId = ZSkinService::clsZSeparator1);
       ZSeparator(const QPixmap &leftPixmap,const QPixmap &rightPixmap,
                   bool bLeftStretch = false,bool bRightStretch = true,
                   QWidget *parent = 0,const char *name = 0 , WFlags f = 0,
                   const ZSkinService::WidgetClsID clsId = ZSkinService::clsZSeparator1);
        virtual ~ZSeparator();
	
        virtual bool isSeparatorTypeWidget() const {return TRUE;}
        void setRelativeAlignment(RelativeAlignment alignment);
	    void setOrientation(Orientation orientation);
	    void setIconPixmap(const QPixmap &pixmap);
        void setIconPixmap(const QPixmap &pixmap,QRect rect,bool bHeightWidth = true,bool bXY = false);
	    void setLabel(ZLabel *label);
	    void setLabel(ZLabel *label,QRect rect,bool bHeightWidth = true,bool bXY = false);
        void setChildPosition( int nChildX, int nChildY );
        void setLeftPixmap(const QPixmap &pixmap,bool bStretch = false);
        void setRightPixmap(const QPixmap &pixmap,bool bStretch = true);
        void setLeftStretch(bool bStretch);
        void setRightStretch(bool bStretch);
        Orientation orientation() const;
        RelativeAlignment relativeAlignment() const;
        ZLabel *getLabel();
        QSize sizeHint() const;
        QSize minimumSizeHint() const;
        void setLength(int nLen);
        bool autoResize() const;
        void setAutoResize( bool enable );

protected:
	   virtual void paintEvent(QPaintEvent *);
       void drawHorz();
	   void drawVert();
       virtual void resizeEvent(QResizeEvent *);
       void updateSkin(bool redraw);
       virtual void setPalette(const QPalette &palette);

private:
	struct ZSeparatorData *d;

	void init(const QPixmap &leftPixmap,const QPixmap &rightPixmap,
            bool bLeftStretch,bool bRightStretch);
    //class ZSkinTool tool;
    int nPixmapCount;
    QPixmap leftStretchPixmap,oneStretchPixmap,rightStretchPixmap;
    void resizeHorz();
    void resizeVert();
    RelativeAlignment  m_relativeAlignment;
    Orientation  m_orientation;
    void getCurrentFont(QFont & font, QColor & ftColor);
    void setSpacingH2(int nSpacing);
    short getSpacingH2()const;
    void setSpacingH1(int nSpacing);
    short getSpacingH1()const;
};

inline ZSeparator::Orientation ZSeparator::orientation()const
{
    return m_orientation;
}

inline ZSeparator::RelativeAlignment ZSeparator::relativeAlignment() const
{
    return m_relativeAlignment;
}

#endif
