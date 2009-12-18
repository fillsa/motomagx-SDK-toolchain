
#ifndef _E2_EZX_ZLISTBOX_H
#define _E2_EZX_ZLISTBOX_H

#include <E2_EZX_ZWidget.h>
#include <E2_EZX_ZScrollPanel.h>
class ZListBox;


class ZListItem
{
public: 
	char tmp[256];
	ZListItem(ZListBox*, QString); 	
	~ZListItem();
	bool isChecked() const;
	void check(bool);
	/*
	int check(bool)
	int current() const
	int drawImage(QPainter*, int, int, int, int, QPixmap const&, int)
	int drawSeparator(QPainter*, int, int, int, int)
	int getItemType() const
	int getMarkColumnType() const
	int getReservedData()
	int getSelectionState()
	int getZStyle() const
	int isChecked() const
	int isSelectable() const
	int partialChecked() const
	int separatorHeight(ZListBox const*) const
	int setActive()
	int setEnabled(bool)
	int setPartialChecked(bool)
	int setReservedData(unsigned)
	int setSelectable(bool)
	int setSeparator(QString, QPixmap const*)
	int setWrapPolicy(ZWrapLine::WrapPolicy)
	int setZStyle(ZSkinService::WidgetClsID)
	int truncate(QString&, int, unsigned, QFont&, QString)
	int update(bool)
	int ~ZListItem [in-charge deleting]()
	int ~ZListItem [not-in-charge]() 
	*/
};
 
class ZListBoxItem: public ZListItem
{
public: 
	char tmp[256];
	ZListBoxItem(ZListBox*, QString);
	~ZListBoxItem();
/*
	int appendSubItem(int, QPixmap*, unsigned)
	int appendSubItem(int, QString, QString, QPixmap const*, unsigned, ZListBoxItem::ShowPriority)
	int appendSubItem(int, QString, bool, QPixmap const*)
	int deleteSubItem(int, int)
	int drawTextColumn(QPainter*, int, LBItemInfo*, int)
	int getCurrentSubItem(int)
	int getPixmap(int)
	int getSubItemIcon(int, int)
	int getSubItemText(int, int, bool)
	int height(ZListBox const*) const
	int isIndicatorShowed(LBItemInfo*) const
	int isShowSubItemIcon() const
	int keyPressEvent(QKeyEvent*)
	int nextShowedSubItem(LBItemInfo*)
	int paint(QPainter*)
	int prevShowedSubItem(LBItemInfo*)
	int setCurrentSubItem(int, int)
	int setPixmap(int, QPixmap const&)
	int setSortIndex(int, int)
	int setSubItem(int, int, QPixmap*, unsigned)
	int setSubItem(int, int, QString, QString, QPixmap const*, unsigned)
	int setSubItem(int, int, QString, bool, QPixmap const*)
	int setSubItemShowed(int, int, bool)
	int showColumn(int, bool)
	int startMarquee()
	int stopMarquee()
	int textColumnItemHeight(ZListBox const*, LBItemInfo*, int) const
	int textColumnSubItemHeight(ZListBox const*, LBItemInfo*, LBSubItemInfo*, int) const
	int width(ZListBox const*) const
	int ~ZListBoxItem [in-charge deleting]()
	int ~ZListBoxItem [not-in-charge]()
*/
};

class ZSettingItem: public ZListItem
{
public: 
	char tmp[256];
	ZSettingItem(ZListBox*, QString);
	~ZSettingItem();
	int appendSubItem(int index, QString text, bool isWrapable = false);
	bool setPixmap(int index, const QPixmap& pixmap);
/*
	int appendSubItem(int, QString, bool, SettingItemRegion)
	int deleteSubItem(int, int)
	int drawTextColumn(QPainter*, int, SetItemInfo*, int)
	int getPixmap(int)
	int getSubItemCount(int)
	int getSubItemText(int, int)
	int height(ZListBox const*) const
	int paint(QPainter*)
	int setPixmap(int, QPixmap const&)
	int setSortIndex(int, int)
	int setSubItem(int, int, QString, bool, SettingItemRegion)
	int startMarquee()
	int stopMarquee()
	int textColumnItemHeight(ZListBox const*, SetItemInfo*, int) const
	int textColumnSubItemHeight(ZListBox const*, SetItemInfo*, SetSubItemInfo*, int) const
	int width(ZListBox const*) const
	int ~ZSettingItem [in-charge]()
	int ~ZSettingItem [not-in-charge]()
*/
};

class ZListBox : public ZScrollPanel
{
	Q_OBJECT
public: 
	char tmp[4096];
      ZListBox( QWidget* parent = 0, WFlags f = 0,
                  ZSkinService::WidgetClsID clsId = ZSkinService::clsZListBox1 );
      ZListBox( QString type, QWidget* parent=0, WFlags f = 0,
                  ZSkinService::WidgetClsID clsId = ZSkinService::clsZListBox1);
	~ZListBox();
    void insertItem( const ZListItem * item, int index=-1, bool autoHighlighted = TRUE );
    void insertItem( const ZListItem * item, const ZListItem *after, bool autoHighlighted = TRUE);
	void showAllSubItem(bool);
	void setCurrentItem(int);
	bool isSelected(int) const;
	void selected(int);
	void checkItem(int, bool);
	bool itemChecked(int);
	void setZItemStyle(ZSkinService::WidgetClsID);
	bool itemVisible(ZListItem const*);
	bool itemVisible(int);
	void adjustItems();
	void tryGeometry(int, int) const;
	
      enum ListItemRegion 
         {LISTITEM_REGION_A,
          LISTITEM_REGION_B, 
          LISTITEM_REGION_C};
	void setItemFont(ListItemRegion region, ZSkinBase::SelectionState state, QFont& font);
	void setItemFont(ListItemRegion region, QFont& font, bool highlighted = FALSE);
	void clear();
	int count() const;
	ZListBoxItem *item( int index ) const;
	int currentItem() const;
	virtual void setCurrentItem( ZListItem * item);
	/*
	Rect itemRect(ZListItem*) const;
	int align(ZListBox::ITEMALIGN) const
	int changeItem(ZListItem const*, int)
	int checkItem(ZListItem*, bool)
	int checkItem(int, bool)
	int className() const
	int clear()
	int clicked(ZListItem*)
	int clicked(ZListItem*, QPoint const&)
	int count() const
	int currentChanged(ZListBoxItem*)
	int currentChanged(ZListItem*)
	int currentChanged(ZSettingItem*)
	int currentItem() const
	int currentRow() const
	int defaultItemHeight() const
	int doLayout() const
	int doubleClicked(ZListItem*)
	int enableEllpsis(bool)
	int enableMarquee(ZListBox::ListItemRegion, bool)
	int ensureCurrentVisible()
	int firstItem() const
	int focusInEvent(QFocusEvent*)
	int focusOutEvent(QFocusEvent*)
	int getCurrentFocusRect(bool) const
	int getDeleteItemCallBackFunction() const
	int getEllpsis(ZListBox::ListItemRegion)
	int getImageContainerSkin(ZSkinBase::SelectionState)
	int getItemFont(ZListBox::ListItemRegion, bool) const
	int getItemSkin(ZSkinService::WidgetClsID, ZSkinBase::SelectionState) const
	int getItemType()
	int getListBoxSpace(ZListItem*) const
	int getMaxItemWidth() const
	int getSeparatorFont() const
	int getSeparatorImage(int) const
	int getSeparatorSkin(ZSkinService::WidgetClsID) const
	int getZItemStyle(bool) const
	int hasNextPrevFocusItem(bool) const
	int highlighted(ZListBoxItem*)
	int highlighted(ZListItem*)
	int highlighted(ZSettingItem*)
	int highlighted(int)
	int indImage(ZSkinBase::SelectionState) const
	int index(ZListItem const*) const
	int init(QString, QWidget*, unsigned, ZSkinService::WidgetClsID)
	int initMetaObject()
	int insertItem(ZListItem const*, ZListItem const*, bool)
	int isEnableEllpsis()
	int isSelected(ZListItem const*) const
	int isShowAllSubItem() const
	int isShowSubItemIcon() const
	int item(int) const
	int itemAt(QPoint) const
	int itemChecked(ZListItem*)
	int itemChecked(int)
	int itemFont(ZListBox::ListItemRegion, ZSkinBase::SelectionState) const
	int itemHeight(int) const
	int itemVisible(ZListItem const*)
	int itemVisible(int)
	int itemsChecked()
	int keyPressEvent(QKeyEvent*)
	int markImage(ZSkinBase::SelectionState, bool, bool) const
	int marqueeEnabled(ZListBox::ListItemRegion) const
	int maxmumSizeHint() const
	int minimumSizeHint() const
	int mouseDoubleClickEvent(QMouseEvent*)
	int mousePressEvent(QMouseEvent*)
	int moveItem(int, int)
	int numRows() const
	int radioItemChecked()
	int refreshSlot()
	int removeItem(int)
	int resetFocusItem(bool)
	int resizeEvent(QResizeEvent*)
	int returnPressed(ZListBoxItem*)
	int returnPressed(ZListItem*)
	int returnPressed(ZSettingItem*)
	int returnPressed(int)
	int rowAt(int) const
	int selectBtns(ZListItem*)
	int selected(ZListBoxItem*)
	int selected(ZListItem*)
	int selected(ZSettingItem*)
	int selected(int)
	int selectionChanged(ZListBoxItem*)
	int selectionChanged(ZListItem*)
	int selectionChanged(ZSettingItem*)
	int setAlign(ZListBox::ITEMALIGN, int)
	int setBottomItem(int)
	int setCurrentItem(ZListItem*)
	int setCurrentItem(int)
	int setCurrentItem(int, bool)
	int setDefaultItemHeight(int)
	int setDeleteItemCallBackFunction(void (*)(ZListItem*))
	int setEllpsis(QString, ZListBox::ListItemRegion)
	int setFontData(QFont&, int, int) const
	int setItemFont(ZListBox::ListItemRegion, QFont&, bool)
	int setItemFont(ZListBox::ListItemRegion, ZSkinBase::SelectionState, QFont&)
	int setItemType(QString)
	int setListItemType(ZListItem::ListItemType)
	int setSelected(ZListItem*, bool)
	int setSelected(int, bool)
	int setSeparatorFont(QFont&)
	int setShowSubItemIcon(bool)
	int setTopItem(int)
	int setZBorder(ZWidgetBorderInfo*)
	int setZItemStyle(ZSkinService::WidgetClsID)
	int showEvent(QShowEvent*)
	int showedSubItemChanged(int, int)
	int sizeHint() const
	int sort(bool)
	int staticMetaObject()
	int takeItem(ZListItem const*)
	int textAlign(ZListBox::ListItemRegion, ZSkinBase::SelectionState)
	int textColor(ZListBox::ListItemRegion, ZSkinBase::SelectionState)
	int topItem() const
	int tr(char const*)
	int tr(char const*, char const*)
	int triggerUpdate(bool)
	int updateItem(ZListItem*)
	int updateItem(int)
	int updateSkin(bool)
	int viewportMouseDoubleClickEvent(QMouseEvent*)
	int viewportMousePressEvent(QMouseEvent*)
	int viewportPaintEvent(QPaintEvent*)
	int ~ZListBox [in-charge deleting]()
	int ~ZListBox [in-charge]()
	*/
};
#endif
