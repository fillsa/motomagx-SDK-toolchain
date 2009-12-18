

// Copyright (c) 27-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef PUBLIC_API_WIDGET_ZOPTIONSMENU_H
#define PUBLIC_API_WIDGET_ZOPTIONSMENU_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include <qfont.h>
#include <qframe.h>
#include <qlist.h>
#include <qmap.h>
#include "ZWidget.h"
#include "ZSkinService.h"

#include "ZOptMenuParser.h"  

class QSignal;
class ZOptionsMenu;
struct ZOptionsMenuItemPrivate;

class Q_EXPORT ZOptionsMenuItem
{
public:
//	unsigned int data[18];
    virtual ~ZOptionsMenuItem();

    QString text() const;

    void setText( const QString & text );

    ZOptionsMenu* subMenu() const;

protected:
    ZOptionsMenuItem( ZOptionsMenu * menu );

    virtual void paint( QPainter * painter, int x1, int y1, int x2, int y2 );

    void drawHighlight(QPainter& painter,const QRect* r, bool border);

private:
    virtual void calcHeight();

private:
    ZOptionsMenuItemPrivate * dd;
    friend class ZOptionsMenu;
};

typedef QList<ZOptionsMenuItem> ZOptionsMenuItemList;

typedef QListIterator<ZOptionsMenuItem> ZOptionsMenuItemListIt;

typedef QList<ZOptionsMenu> ZSubMenuIList;

class ZOptionsMenuPrivate;

class Q_EXPORT ZOptionsMenu : public ZWidget
{
    Q_OBJECT
	//unsigned int data[66-sizeof(ZWidget)/4];
//	unsigned int data[66-sizeof(ZWidget)/4];
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
	
/*
ZOptionsMenu::changeItem(int, QString const&, QPixmap const*)@@VERSION		 // FUNC
ZOptionsMenu::className() const@@VERSION		 // FUNC
ZOptionsMenu::clear()@@VERSION		 // FUNC
ZOptionsMenu::closeEvent(QCloseEvent*)@@VERSION		 // FUNC
ZOptionsMenu::connectItem(int, QObject const*, char const*)@@VERSION		 // FUNC
ZOptionsMenu::count()@@VERSION		 // FUNC
ZOptionsMenu::disconnectItem(int, QObject const*, char const*)@@VERSION		 // FUNC
ZOptionsMenu::drawScrollIndicator(QPainter*)@@VERSION		 // FUNC
ZOptionsMenu::findItem(int, ZOptionsMenu**) const@@VERSION		 // FUNC
ZOptionsMenu::focusInEvent(QFocusEvent*)@@VERSION		 // FUNC
ZOptionsMenu::focusOutEvent(QFocusEvent*)@@VERSION		 // FUNC
ZOptionsMenu::fontChange(QFont const&)@@VERSION		 // FUNC
ZOptionsMenu::getActiveItemId()@@VERSION		 // FUNC
ZOptionsMenu::getAllItemIds()@@VERSION		 // FUNC
ZOptionsMenu::getCurrentSelectedItemId()@@VERSION		 // FUNC
ZOptionsMenu::getIdFromIndex(int)@@VERSION		 // FUNC
ZOptionsMenu::getIndexFromId(int)@@VERSION		 // FUNC
ZOptionsMenu::getItemParentId(int)@@VERSION		 // FUNC
ZOptionsMenu::getItemSubMenu(int)@@VERSION		 // FUNC
ZOptionsMenu::getItemSubMenuNum(int)@@VERSION		 // FUNC
ZOptionsMenu::getListFromConfig(QList<MenuItem>&, QString, QString)@@VERSION	 // FUNC
ZOptionsMenu::getMenuDisplayState(ZOptionsMenu*)@@VERSION		 // FUNC
ZOptionsMenu::hideEvent(QHideEvent*)@@VERSION		 // FUNC
ZOptionsMenu::hide()@@VERSION		 // FUNC
ZOptionsMenu::initMetaObject()@@VERSION		 // FUNC
ZOptionsMenu::insertItem(QString const&, QPixmap const*, QObject const*, char const*, bool, bool, bool, int, int, bool)@@VERSION		 // FUNC
ZOptionsMenu::insertItem(QString const&, ZOptionsMenu*, QPixmap const*, bool, int, int, bool, bool, bool)@@VERSION		 // FUNC
ZOptionsMenu::insertItem(ZOptionsMenuItem*, int, int)@@VERSION		 // FUNC
ZOptionsMenu::isItemEnabled(int) const@@VERSION		 // FUNC
ZOptionsMenu::isItemHided(int) const@@VERSION		 // FUNC
ZOptionsMenu::ItemState(ZOptionsMenu*, ZOptionsMenu*, MenuItem*)@@VERSION	 // FUNC
ZOptionsMenu::keyPressEvent(QKeyEvent*)@@VERSION		 // FUNC
ZOptionsMenu::keyReleaseEvent(QKeyEvent*)@@VERSION		 // FUNC
ZOptionsMenu::limitRect() const@@VERSION		 // FUNC
ZOptionsMenu::paintEvent(QPaintEvent*)@@VERSION		 // FUNC
ZOptionsMenu::popup()@@VERSION		 // FUNC
ZOptionsMenu::removeItemFromVisibleList(ZOptionsMenu*, ZOptionsMenuItem*)@@VERSION		 // FUNC
ZOptionsMenu::removeItem(int, bool)@@VERSION		 // FUNC
ZOptionsMenu::resetHS(ZOptionsMenu*)@@VERSION		 // FUNC
ZOptionsMenu::setActiveItem(int)@@VERSION		 // FUNC
ZOptionsMenu::setDisabledReasonDlgTitle(int, QString const&)@@VERSION		 // FUNC
ZOptionsMenu::setDisabledReason(int, QString const&)@@VERSION		 // FUNC
ZOptionsMenu::setItemCheckable(int, bool)@@VERSION		 // FUNC
ZOptionsMenu::setItemChecked(int, bool)@@VERSION		 // FUNC
ZOptionsMenu::setItemEnabled(int, bool)@@VERSION		 // FUNC
ZOptionsMenu::setItemHide(int, bool)@@VERSION		 // FUNC
ZOptionsMenu::setItemSubMenu(int, ZOptionsMenu*)@@VERSION		 // FUNC
ZOptionsMenu::setLimitRect(int)@@VERSION		 // FUNC
ZOptionsMenu::setLimitRect(QRect const&)@@VERSION		 // FUNC
ZOptionsMenu::setMenu(QString, QString)@@VERSION		 // FUNC
ZOptionsMenu::setMenu(ZOptMenuParser*, QString)@@VERSION		 // FUNC
ZOptionsMenu::setPalette(QPalette const&)@@VERSION		 // FUNC
ZOptionsMenu::setPosition(ZOptionsMenu::CornerE, QPoint&)@@VERSION		 // FUNC
ZOptionsMenu::show()@@VERSION		 // FUNC
ZOptionsMenu::staticMetaObject()@@VERSION		 // FUNC
ZOptionsMenu::ZOptionsMenu(QRect&, QWidget*, char const*, unsigned int, ZSkinService::WidgetClsID, QString, QString)@@VERSION		 // FUNC
ZOptionsMenu::ZOptionsMenu(QRect&, QWidget*, char const*, unsigned int, ZSkinService::WidgetClsID, QString, QString)@@VERSION		 // FUNC
ZOptionsMenu::ZOptionsMenu(QRect&, QWidget*, char const*, unsigned int, ZSkinService::WidgetClsID)@@VERSION		 // FUNC
ZOptionsMenu::ZOptionsMenu(QRect&, QWidget*, char const*, unsigned int, ZSkinService::WidgetClsID)@@VERSION		 // FUNC
ZOptionsMenu::ZOptionsMenu(QRect&, QWidget*, char const*, unsigned int, ZSkinService::WidgetClsID, ZOptMenuParser*, QString)@@VERSION		 // FUNC
ZOptionsMenu::ZOptionsMenu(QRect&, QWidget*, char const*, unsigned int, ZSkinService::WidgetClsID, ZOptMenuParser*, QString)@@VERSION		 // FUNC
ZOptionsMenu::~ZOptionsMenu()@@VERSION		 // FUNC
ZOptionsMenu::~ZOptionsMenu()@@VERSION		 // FUNC
ZOptionsMenu::~ZOptionsMenu()@@VERSION		 // FUNC
*/


//ZOptionsMenu::ZOptionsMenu(QRect&, QWidget*, char const*, unsigned int, ZSkinService::WidgetClsID, bool)
    ZOptionsMenu( QRect & limitRect, QWidget * parent = 0, const char * name = 0,
                             WFlags f = 0, const ZSkinService::WidgetClsID clsId = ZSkinService::clsZOptionsMenu
                             );
							 
//ZOptionsMenu::ZOptionsMenu(QRect&, QWidget*, char const*, unsigned int, ZSkinService::WidgetClsID, ZOptMenuParser*, QString, bool)
    ZOptionsMenu( QRect & limitRect, QWidget * parent, const char * name,
                             WFlags f, const ZSkinService::WidgetClsID clsId,
                             ZOptMenuParser * parserClass, QString menuName                          
                             );
//ZOptionsMenu::ZOptionsMenu(QRect&, QWidget*, char const*, unsigned int, ZSkinService::WidgetClsID, QString, QString)
     ZOptionsMenu( QRect & limitRect, QWidget * parent, const char * name,
                              WFlags f, const ZSkinService::WidgetClsID clsId,
                              QString fileName, QString menuName
                              );

    virtual ~ZOptionsMenu();
//ZOptionsMenu::setMenu(ZOptMenuParser*, QString)
    void setMenu( ZOptMenuParser * parserClass, QString menuName);
//ZOptionsMenu::setMenu(QString, QString)
    void setMenu( QString fileName, QString menuName);

    virtual void setActiveItem( int index );

    int getActiveItemId();

    int getCurrentSelectedItemId();

    bool isItemChecked( int id ) const;

    void setItemChecked( int id, bool check );

    void setItemCheckable( int id, bool checkable );

    void changeItem( int id, const QString &text, const QPixmap * pixmap = NULL );

    void clear();

    bool connectItem( int id, const QObject * receiver, const char * memberFunc );

    bool disconnectItem( int id, const QObject * receiver, const char * memberFunc );

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

    void setItemSpacing( const int H1 ) {}; //not in lib this function

    void setItemPadding( const WIDGET_PADDING_INFO_T & pad );


//ZOptionsMenu::insertItem(QString const&, QPixmap const*, QObject const*, char const*, bool, bool, bool, int, int, bool)
    int insertItem(
        const QString & text,
        const QPixmap * pixmap = NULL,
        const QObject * receiver = NULL,
        const char * memberFunc = NULL,
        bool enable = true,
        bool checkable = false,
        bool checked = false,
        int id = -1,
        int index = -1,
	bool hide = false );
//ZOptionsMenu::insertItem(QString const&, ZOptionsMenu*, QPixmap const*, bool, int, int, bool, bool, bool)
    int insertItem(
        const QString & text,
        ZOptionsMenu * sub,
        const QPixmap * pixmap = NULL,
        bool enable = true,
        int id = -1,
        int index = -1,
	bool hide = false,
        bool checkable = false,
        bool checked = false );
//ZOptionsMenu::insertItem(ZOptionsMenuItem*, int, int)
    int insertItem( ZOptionsMenuItem * item, int id = -1, int index = -1 );

    int insertSeparator( int id = -1, int index = -1 ) {return 0;};//not function in library

//    void setFixedWidth( int width );

//    void unsetFixedWidth();

    void removeItem( int id, bool needUpdate = TRUE );

    QRect limitRect() const;

    void setLimitRect( const QRect & rect );

    void setLimitRect( int maxLineNum = 5 );

    void setPosition( CornerE corner, QPoint & point );

    AlignmentFlags textAlignment() const;

    void setTextAlignment( AlignmentFlags align );

    bool wrap() const;

    void setWrap( bool wrap );

    bool isItemHided( int id ) const;

    void setItemHide(int id, bool hided);

     void setItemSubMenu(int id, ZOptionsMenu * sub);

     ZOptionsMenu* getItemSubMenu(int id);

    itemList getAllItemIds();

    int getItemParentId( int id );

    int getItemSubMenuNum( int id );

    virtual void setPalette( const QPalette & );
    void setAutoAddCloseItem(bool bAutoAddCloseItem);
    bool isAutoAddCloseItem();

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

    void hideEvent( QHideEvent * );

    virtual void closeEvent( QCloseEvent * e );

    virtual void focusInEvent( QFocusEvent * e );

    virtual void focusOutEvent( QFocusEvent * e );

    virtual void paintEvent( QPaintEvent * e );

    virtual void drawScrollIndicator( QPainter * painter );

    virtual void fontChange( const QFont & oldFont );

    virtual void keyReleaseEvent( QKeyEvent * e);

    virtual void keyPressEvent( QKeyEvent * e );

//    virtual void migrateEvent(QMigrateEvent*);
private slots:
    void slotWaitWrapFinished();

    void objectDestroyed();
    void clickCloseItem();
private:
    void startMarquee();
    int insertItemToMenu(ZOptionsMenuItem *item, int id, int index);

    void init( QRect & limitRect );

    void ItemState( ZOptionsMenu * menu, ZOptionsMenu * subMenu, menuItem * item );
    void getListFromConfig( itemList & iList, QString fileName, QString screenName );
    void genMenu( QRect & limitRect, itemList myList );
    void removeItemFromVisibleList( ZOptionsMenu* pMenu, ZOptionsMenuItem* pItem );
    void resetHS( ZOptionsMenu* pMenu );
    bool getMenuDisplayState( ZOptionsMenu * menu );

    void initShow();
    void onShortcut( QKeyEvent * e );

    void updateSize();

    void updateVisibleItems( int index, bool atBottom );

private:
    ZOptionsMenuPrivate * d;

    friend class ZOptionsMenuItem;

    int scrollingInPage(int n);

    int scrollingInNextPage(int n, bool keepLast);

    bool isHighlightTop();

    bool isHighlightBottom();

    void setHighlightTop();

    void setHighlightBottom();

    int findEdge(bool isBottom);

    void omgScroll(QKeyEvent *e);
};
#endif
