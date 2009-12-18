#ifndef ZPRESSBUTTON_H
#define ZPRESSBUTTON_H

#include <ZBaseButton.h>
#include <qiconset.h>
#include <ZSkinService.h>
#include <ZSkinBase.h>

class ZPressButtonPrivate;

class Q_EXPORT ZPressButton : public ZBaseButton
{
    Q_OBJECT
    Q_ENUMS(TitlePosition)
    Q_OVERRIDE( bool toggleButton WRITE setToggleButton )
    Q_OVERRIDE( bool on WRITE setOn )
    Q_PROPERTY( RelativeAlignment relativeAlignment READ relativeAlignment WRITE setRelativeAlignment)
    Q_PROPERTY( AlignmentFlags alignment READ alignment WRITE setAlignment )
    Q_PROPERTY( TitlePosition titlePosition READ titlePosition WRITE setTitlePosition )
	
public:
   enum TitlePosition{
        TitleTop = 0,      
        TitleLeft		 
    };

public:
    ZPressButton( QWidget *parent, const char *name=0,
            const ZSkinService::WidgetClsID clsId= ZSkinService::clsZPressButton);
    ZPressButton( const QString &text, QWidget *parent, const char* name=0,
            const ZSkinService::WidgetClsID clsId = ZSkinService::clsZPressButton);
    ZPressButton( const QPixmap & pixmap, const QString &text, QWidget *parent, const char* name=0,
            const ZSkinService::WidgetClsID clsId = ZSkinService::clsZPressButton);
    ~ZPressButton();
    QString text() const;
    virtual void setText( const QString & text);
    virtual void setPixmap( const QPixmap & pixmap);
    void      setAlignment(AlignmentFlags align);
    QSize sizeHint() const;
    virtual void setToggleButton( bool enable); //### fjern virtual 3.0
    void  getFrameWidth(int & nleftf, int & nrightf, int & ntopf, int & nbottomf) const;
    void  setTitle(const QString & string);
    QString title() const;
    TitlePosition titlePosition() const;
    void  setTitlePosition(TitlePosition titlePos);
    virtual void setFont(const QFont & fnt);
    void setFontColor(const QColor & color);
    void setEnabled(bool enable);
    bool isZEnabled();
    void setAvailableWidth(int nLen);
public slots:
    virtual void setOn( bool enable);

protected:
    void drawButton( QPainter * );
    void drawButtonLabel( QPainter * );
    void focusInEvent( QFocusEvent * );
    void focusOutEvent( QFocusEvent * );
    void resizeEvent( QResizeEvent * );
    void keyPressEvent(QKeyEvent *);
    void keyReleaseEvent(QKeyEvent *);
    QRect getContentRect() const;
    void setPalette(const QPalette & palette);
    void updateSkin(bool redraw);
    void getBtnFrameWidth(int & nleftf, int & nrightf, int & ntopf, int & nbottomf) const;

private:
    QSize getTitleSize() const;
    QSize getBtnSize() const;
    QRect getTitleRect() const;
    QRect getBtnRect() const;
    QRect getBtnContentRect() const;
    void toggleStateChange(bool enable);

private:
    void init();
    void setPixmap_internal( const QPixmap & pixmap );

private:
    ZPressButtonPrivate * d;
    RelativeAlignment mrelpos;
    TitlePosition mreltitlepos;
    AlignmentFlags    malign;
    QString     mtext;
    QPixmap     * mpixmap;
    QString     mTitleText;

private:
    ZPressButton( const ZPressButton & );
    ZPressButton &operator=( const ZPressButton & );

//private:
//	char data[10000];
};
#endif
