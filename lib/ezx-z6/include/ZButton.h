#ifndef __ZBUTTON_H__
#define __ZBUTTON_H__

#include "ZBaseButton.h"
#include "qapplication.h"
#include "ZSkinBase.h"
#include "ZText.h"
#define CUSTOMEVENT_TYPE   QEvent::User + 435

class ZButton : public ZBaseButton
{
    Q_OBJECT
    Q_ENUMS(TitlePosition)
    Q_PROPERTY( TitlePosition titlePosition READ titlePosition WRITE setTitlePosition )
     
public:
    enum TitlePosition
    {
        TitleTop,
        TitleLeft
    };

    ZButton(QWidget * parent =0, const char * name =0 , WFlags f = 0,ZSkinService::WidgetClsID clsId = ZSkinService::clsZFormItem);
    ZButton(const QString & title,TitlePosition titlePos = TitleTop, QWidget * parent = 0 , 
                   const char * name = 0, WFlags f = 0 ,ZSkinService::WidgetClsID clsId = ZSkinService::clsZFormItem);
    virtual ~ZButton();

public:
    virtual QString text() const {return mtext;}
    virtual void setText(const QString & text);
    virtual void setNum(const int nNum); 
    virtual const QPixmap * pixmap() const {return mpixmap;}
    virtual void setPixmap(const QPixmap & pixmap);
    TitlePosition titlePosition() const {return mTitlePos;}
    void setTitlePosition(TitlePosition titlePos);
    QString title() const {return mtitle;}
    void setTitle(const QString & title) ;
    virtual QSize sizeHint() const;
    ZSkinBase::RelativeAlignment relativeAlignment() const {return mrelPos;}
    void      setRelativeAlignment(ZSkinBase::RelativeAlignment relativeAlign);
    void setEnabled(bool enable);
    bool isZEnabled();
    bool isZDisabled();
    void setFont(const QFont & font);
    void enableTruncation(bool isEnable);
    bool isEnableTruncation();
    void enableMarquee(bool isEnable);
    bool isEnableMarquee();
    enum MarqueeDirect {LeftM, RightM, TopM, BottomM};
    void setMarqueeDirect(MarqueeDirect md);
    MarqueeDirect getMarqueeDirect();
    void setAvailableWidth(int nLen);

protected:
    enum ItemType
    {
        FormItem,
        Label,
        Widget
    };
 
    enum StateChangeReason
    {
        RFocusIn,
        RFocusOut,
        RKeyPress,
        RKeyRelease
    };
    
    virtual void drawButton(QPainter * p);
    virtual void drawButtonLabel(QPainter * p);
    virtual void resizeEvent( QResizeEvent * e);
    virtual void keyPressEvent(QKeyEvent * e);
    virtual void keyReleaseEvent(QKeyEvent * e);
    virtual void focusInEvent(QFocusEvent * e);
    virtual void focusOutEvent(QFocusEvent * e);

    
protected:
    QSize getTitleSize() const;
    QSize getBtnSize() const;
    QRect getTitleRect() const;
    QRect getBtnRect() const;
    QRect getBtnContentRect() const;
    void reAdjustSize(bool bAll = false,int w=-1,int h=-1);
 
private:
    QString mtext;
    QPixmap * mpixmap;
    TitlePosition mTitlePos;
    QString mtitle;

    bool mIsEnabled;
    bool mIsTruncText;
    bool mIsMarqueeText;
    MarqueeDirect mMarqueeDirect;
    ZMarqueeText *mMarqueeText;
    ZSkinBase::RelativeAlignment mrelPos; 
    //int mLen; 
};

#endif //__ZBUTTON_H__
