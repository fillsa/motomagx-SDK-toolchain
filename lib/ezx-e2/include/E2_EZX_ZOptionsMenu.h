#ifndef _E2_EZX_ZOPTIONMENU_H
#define _E2_EZX_ZOPTIONMENU_H

#include <E2_EZX_ZWidget.h>

class ZOptionsMenu;

class ZOptionsMenuItem
{
	
	char tmp[256];
public:
	ZOptionsMenuItem(ZOptionsMenu*);
	~ZOptionsMenuItem();
	int calcHeight();
	void paint(QPainter*, int, int, int, int);
	void setText(QString const&);
};

class ZOptionsMenu : public ZWidget
{
	Q_OBJECT
	char tmp[4096];
public:
    ZOptionsMenu( QRect & limitRect, QWidget * parent = 0,
                  const char * name = 0, WFlags f = 0,
                  const ZSkinService::WidgetClsID clsId = ZSkinService::clsZOptionsMenu);
	~ZOptionsMenu ();
	void insertItem(QString const&, ZOptionsMenu*, QPixmap const*, bool, int, int);
	void connectItem(int, QObject const*, char const*);
	void insertItem(QString const&, QPixmap const*, QObject const*, char const*, bool, bool, bool, int, int);
	int getActiveItemId();
	void setItemChecked(int, bool);
//	void insertItem(ZOptionsMenuItem*, int, int);

/*
	int aboutToHide()
	int aboutToShow()
	int activated(int)
	int canceled()
	int changeItem(int, QString const&, QPixmap const*)
	int className() const
	int clear()
	int closeEvent(QCloseEvent*)
	int connectItem(int, QObject const*, char const*)
	int count()
	int disabledReason(int) const
	int disconnectItem(int, QObject const*, char const*)
	int drawScrollIndicator(QPainter*)
	int emitSignals()
	int findItem(int, ZOptionsMenu**) const
	int focusInEvent(QFocusEvent*)
	int focusOutEvent(QFocusEvent*)
	int fontChange(QFont const&)
	int getActiveItemId()
	int getIdFromIndex(int)
	int getIndexFromId(int)
	int hide()
	int highlighted(int)
	int initMetaObject()
	int initShow()
	int insertItem(QString const&, QPixmap const*, QObject const*, char const*, bool, bool, bool, int, int)
	int insertSeparator(int, int)
	int isItemChecked(int) const
	int isItemEnabled(int) const
	int keyPressEvent(QKeyEvent*)
	int keyReleaseEvent(QKeyEvent*)
	int lSoftkeyDown()
	int lSoftkeyUp()
	int limitRect() const
	int onShortcut(QKeyEvent*)
	int paintEvent(QPaintEvent*)
	int popup()
	int rSoftkeyDown()
	int rSoftkeyUp()
	int removeItem(int, bool)
	int removeItemFromVisibleList(ZOptionsMenu*, ZOptionsMenuItem*)
	int setActiveItem(int)
	int setDisabledReason(int, QString const&)
	int setDisabledReasonDlgTitle(int, QString const&)
	int setFixedWidth(int)
	int setItemEnabled(int, bool)
	int setItemPadding(ZWidgetPaddingInfo const&)
	int setItemSpacing(int)
	int setLimitRect(QRect const&)
	int setPalette(QPalette const&)
	int setPosition(ZOptionsMenu::CornerE, QPoint&)
	int setSpacing(int)
	int setTextAlignment(Qt::AlignmentFlags)
	int setWrap(bool)
	int show()
	int slotScrollTextTimer()
	int startHScroll()
	int staticMetaObject()
	int textAlignment() const
	int tr(char const*)
	int tr(char const*, char const*)
	int unsetFixedWidth()
	int updateSize()
	int updateVisibleItems(int, bool)
	int wrap() const
	int ~ZOptionsMenu [in-charge deleting]()
	int ~ZOptionsMenu [in-charge]()
*/
};

#endif

