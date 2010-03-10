#ifndef __ZOPTIONSMENU_H__
#define __ZOPTIONSMENU_H__

#include <qfont.h>
#include <qframe.h>
#include <qlist.h>
#include <qmap.h>
#include <ZSkinBase.h>
#include <ZWidget.h>

class QSignal;
class ZOptionsMenu;

class Q_EXPORT ZOptionsMenuItem
{
public:
    virtual ~ZOptionsMenuItem();
    QString text() const;
    void setText( const QString & text );
    ZOptionsMenu* subMenu() const;
    void setPixmap(QPixmap * pm);
protected:
    ZOptionsMenuItem( ZOptionsMenu * menu );
    virtual void paint( QPainter * painter, int x1, int y1, int x2, int y2 );

private:
    uint hasSubMenu : 1;
    uint isCheckable : 1;
    uint isChecked : 1;
    uint isSeparator : 1;
    uint isEnabled : 1;
    uint isSelectable : 1;
    uint isTruncH : 1;
    
private:    
    virtual void calcHeight();    
    int mId;
    int mHeight;
    int mYPos;
    ZOptionsMenu * mSubMenu;
    ZOptionsMenu * mMenu;
    QPixmap mBackgroundPixmap;
    QPixmap * mPixmapData;
    QString mDisabledReason;
    QString mDisabledReasonDlgTitle;
    QString mText;
    QString mTruncatedText;
    QSignal * mSignal;
    friend class ZOptionsMenu;
};

inline QString ZOptionsMenuItem::text() const
{
    return mText;
}

inline void ZOptionsMenuItem::setPixmap(QPixmap * pm)
{
    mPixmapData = pm;
}

inline ZOptionsMenu* ZOptionsMenuItem::subMenu() const
{
    return  hasSubMenu ? mSubMenu : NULL;
}

typedef QList<ZOptionsMenuItem> ZOptionsMenuItemList;


typedef QListIterator<ZOptionsMenuItem> ZOptionsMenuItemListIt;

class ZOptionsMenuPrivate;

class Q_EXPORT ZOptionsMenu : public ZWidget  
{
    Q_OBJECT

public:
    enum CornerE
    {
        TopLeft,
        TopRight,
        BottomLeft,
        BottomRight
    };
    enum EffectsE
    {
        NoEffect,
        Scroll,
        Fade
    };
    ZOptionsMenu( QRect & limitRect, QWidget * parent = 0,
                  const char * name = 0, WFlags f = 0,
                  const ZSkinService::WidgetClsID clsId = ZSkinService::clsZOptionsMenu);

    virtual ~ZOptionsMenu();
    virtual void setActiveItem( int index );
    int getActiveItemId();
    bool isItemChecked( int id ) const;
    void setItemChecked( int id, bool check );
    void changeItem(
        int id, const QString &text, const QPixmap * pixmap = NULL );
    void clear();
    bool connectItem(
        int id, const QObject * receiver, const char * memberFunc );
    bool disconnectItem(
        int id, const QObject * receiver, const char * memberFunc );
    uint count();
    QString disabledReason( int id ) const;
    int getIdFromIndex( int index );
    int getIndexFromId( int id );
    ZOptionsMenuItem * findItem( int id, ZOptionsMenu ** parent = 0 ) const;
    void setDisabledReason( int id, const QString & reason );
    void setDisabledReasonDlgTitle( int id, const QString & title );
    bool isItemEnabled( int id ) const;
    void setItemEnabled( int id, bool enable );
    void setSpacing( const int V1 );
    void setItemSpacing( const int H1 );
    void setItemPadding( const WIDGET_PADDING_INFO_T & pad );
    int insertItem(
        const QString & text,
        const QPixmap * pixmap = NULL,
        const QObject * receiver = NULL,
        const char * memberFunc = NULL,
        bool enable = true,
        bool checkable = false,
        bool checked = false,
        int id = -1,
        int index = -1 );
    int insertItem(
        const QString & text,
        ZOptionsMenu * sub,
        const QPixmap * pixmap = NULL,
        bool enable = true,
        int id = -1,
        int index = -1 );
    int insertItem(
        ZOptionsMenuItem * item, int id = -1, int index = -1 );
    int insertSeparator( int id = -1, int index = -1 );
    void setFixedWidth( int width );
    void unsetFixedWidth();
    void removeItem( int id, bool needUpdate = TRUE );
    QRect limitRect() const;
    void setLimitRect( const QRect & rect );
    void setPosition( CornerE corner, QPoint & point );
    AlignmentFlags textAlignment() const;
    void setTextAlignment( AlignmentFlags align );
    bool wrap() const;
    void setWrap( bool wrap );

signals:
    void aboutToHide();
    void aboutToShow();
    void activated( int itemId );
    void canceled();
    void highlighted( int itemId );
    void lSoftkeyDown();
    void lSoftkeyUp();
    void rSoftkeyDown();
    void rSoftkeyUp();

public slots:
    virtual void hide();
    void popup();
    virtual void show();

protected:
    virtual void closeEvent( QCloseEvent * e );
    virtual void focusInEvent( QFocusEvent * e );
    virtual void focusOutEvent( QFocusEvent * e );
    virtual void paintEvent( QPaintEvent * e );
    virtual void drawScrollIndicator( QPainter * painter );
    virtual void fontChange( const QFont & oldFont );
    virtual void keyReleaseEvent( QKeyEvent * e);
    virtual void keyPressEvent( QKeyEvent * e );
    virtual void setPalette( const QPalette & );

private slots:

    void emitSignals();
    
    void objectDestroyed();
private:
    void startMarquee();
    void removeItemFromVisibleList(ZOptionsMenu* pMenu, ZOptionsMenuItem* pItem);
    void initShow();
    void onShortcut( QKeyEvent * e );
    void updateSize();
    void updateVisibleItems( int index, bool atBottom );
    ZOptionsMenuPrivate * d;
    friend class ZOptionsMenuItem;

};

#endif // __ZOPTIONSMENU_H__
