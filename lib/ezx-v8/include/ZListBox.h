#ifndef __ZLISTBOX_H_
#define __ZLISTBOX_H_

#include <ZScrollPanel.h>
#include <ZWrapLine.h>
#include <ZSkinBase.h>

class ZListBox;
class Q_EXPORT ZListItem
{
public:        
    ZListItem( ZListBox* listbox, const QString itemType = NULL);
    virtual ~ZListItem();
    enum ListItemType {LISTBOXITEM, SETTINGITEM};
    QString getItemType() const;
    ZListBox* listBox() const { return lb; }
    void setActive();
    void check(bool b);
    bool isChecked() const;
    QString getMarkColumnType() const;
    void setReservedData(unsigned int rsvData);
    unsigned int getReservedData();
    void setEnabled(bool enabled);
    bool enabled() const ;
    bool selected() const { return current(); }
    bool current() const;
    void setSelectable( bool b = FALSE );
    bool isSelectable() const;
    ZListItem *next() const {return n;}
    ZListItem *prev() const {return p;}
    void setWrapPolicy(ZWrapLine::WrapPolicy policy);
    ZWrapLine::WrapPolicy getWrapPolicy(){return wrapPolicy;}
     void setZStyle(ZSkinService::WidgetClsID style);
     ZSkinService::WidgetClsID getZStyle() const;
     void setSeparator(const QString text, const QPixmap* icon = NULL);
     bool isSeparatorItem() const {return isSeparator;}
     virtual QString getSortText() const {return QString("");};
    virtual int width( const ZListBox * )  const {return 0;};
    virtual int height( const ZListBox * ) const {return 0;};
    void setPartialChecked(bool partial);
    bool partialChecked() const;
 protected:
    virtual void paint( QPainter * ) {};
    int separatorHeight(const ZListBox* listbox) const;
    void drawSeparator(QPainter *painter, int x, int y, int width, int height);
 private:
    virtual void startMarquee() {};
    virtual void stopMarquee() {};
    virtual ListItemType listitemType() const {return LISTBOXITEM;};
 protected:
    void update(bool all);
    void drawImage(QPainter* painter, int x, int y, int width, int height, const QPixmap& pm, int flag);
    QString truncate(QString& str, int len, uint width, QFont& font, QString ellpsis = NULL);
    ZSkinBase::SelectionState getSelectionState();
 protected:
    ZListBox* lb;
    QString itemType;
    ZListItem * p, * n;
    enum ToggleState { OFF, NOCHANGE, ON};
    short stat;
    QPixmap* mSepIcon;
    QString* mSepText;                                                                      
    unsigned int reserved;
    ZWrapLine::WrapPolicy wrapPolicy;
    ZSkinService::WidgetClsID itemClsId;
    uint down:1;
    uint isEnabled:1;
    uint isSeparator:1;
    uint selectable:1;
    uint dirty:1;
    uint own_style:1;
    uint mPartialChecked : 1;
    friend class ZListBox;
    friend class ZListBoxClipper;
};

class LBItemInfo;
class LBSubItemInfo;

class Q_EXPORT ZListBoxItem : public ZListItem
{
public:        
    ZListBoxItem( ZListBox* listbox, const QString itemType = NULL);
    virtual ~ZListBoxItem();
    
    enum ShowPriority
    {
       FirstPriority ,
       SecondPriority, 
       EquityPriority 
    };
    
    int appendSubItem(int index, const QString text, const QString text2, const QPixmap* icon = NULL, 
                      uint percent = 50, ShowPriority priority = EquityPriority);                     
    int appendSubItem(int index, const QString text, bool isWrapable = false, const QPixmap* icon = NULL);
    int appendSubItem(int index, QPixmap* iconList, uint count);
    QString getSubItemText(int index, int subIndex, bool text2 = false);
    QList<QPixmap> getSubItemIcon(int index, int subIndex);
    bool deleteSubItem(int index, int subIndex);
    bool setSubItem(int index, int subIndex, QString text, QString text2, const QPixmap* icon = NULL, uint percent = 50, ZListBoxItem::ShowPriority prior = EquityPriority);
    bool setSubItem(int index, int subIndex, QString text, bool isWrapable = false, const QPixmap* icon = NULL);
    bool setSubItem(int index, int subIndex, QPixmap* iconList, uint count);
    int getCurrentSubItem(int index);
    void setCurrentSubItem(int index, int subIndex);
    void setSubItemShowed(int index, int subIndex, bool showed);
    QPixmap getPixmap(int index);
    bool setPixmap(int index, const QPixmap& pixmap, bool = false);
    void setShowIndicator(bool isShow){isShowIndicator = isShow;}
    void keyPressEvent( QKeyEvent *e );
     void showColumn(int index, bool show);
    bool setSortIndex(int index, int subIndex);
    int  sortIndex() const { return sortIdx;} 
    int  sortSubIndex() const {return sortSubIdx;}
    virtual QString getSortText() const {return sortText?(*sortText):QString("");}
    virtual int width( const ZListBox * )  const;
    virtual int height( const ZListBox * ) const;
protected:
    virtual void paint( QPainter * );
private:
    virtual void startMarquee();
    virtual void stopMarquee();
    virtual ListItemType listitemType() const {return LISTBOXITEM;}
    void drawTextColumn(QPainter *painter, int xp,LBItemInfo* item, int validWidth );
    int textColumnSubItemHeight(const ZListBox* listbox, LBItemInfo* item, LBSubItemInfo* subItem, int width) const;
    int textColumnItemHeight(const ZListBox* listbox, LBItemInfo* item, int width) const ;
    int prevShowedSubItem(LBItemInfo* item);
    int nextShowedSubItem(LBItemInfo* item);
    bool isIndicatorShowed(LBItemInfo* item) const;
    bool isShowSubItemIcon() const;
private:
    QList< LBItemInfo > list;
    short sortIdx;
    short sortSubIdx;
    QString *sortText;
    uint isShowIndicator:1;
    uint marquee:1;
    uint own_showSubItemIcon :1; 
    uint showSubItemIcon : 1;

};

enum SettingItemRegion {SETTINGITEM_REGION_A, SETTINGITEM_REGION_B};

class SetSubItemInfo;
class SetItemInfo;

class Q_EXPORT ZSettingItem : public ZListItem
{
public:        
    ZSettingItem( ZListBox* container = 0, const QString itemType = NULL);
    virtual ~ZSettingItem();
    int appendSubItem(int index, QString text, bool isWrapable = false);
    int appendSubItem(int index, QString text, bool isWrapable, SettingItemRegion region);
    int getSubItemCount(int index);
    QString getSubItemText(int index, int subIndex);
    bool deleteSubItem(int index, int subIndex);
    bool setSubItem(int index, int subIndex, QString text, bool isWrapable = false, SettingItemRegion region = SETTINGITEM_REGION_B);
    QPixmap getPixmap(int index);
    bool setPixmap(int index, const QPixmap& pixmap);
    virtual int width( const ZListBox * )  const;
    virtual int height( const ZListBox * ) const;
    bool setSortIndex(int index, int subIndex);
    int  sortIndex() const { return sortIdx;} 
    int  sortSubIndex() const {return sortSubIdx;}
    virtual QString getSortText() const {return sortText?(*sortText):QString("");}
  protected:
    virtual void paint( QPainter * );
 private:    
    void drawTextColumn(QPainter *painter, int xp,SetItemInfo* item, int validWidth );
    int textColumnSubItemHeight(const ZListBox*, SetItemInfo* item, SetSubItemInfo* subItem, int width) const;
    int textColumnItemHeight(const ZListBox*, SetItemInfo* item, int width) const ;
    virtual void startMarquee();
    virtual void stopMarquee();
    virtual ListItemType listitemType() const {return SETTINGITEM;}
  private:
    QList< SetItemInfo > list;
    short sortIdx;
    short sortSubIdx;
    QString *sortText;
    uint marquee:1;
    uint own_style:1;
};

class ZListBoxPrivate;

class Q_EXPORT ZListBox : public ZScrollPanel
{
       friend class ZListItem;
       friend class ZListBoxItem;
       friend class ZSettingItem;
       friend class ZListBoxPrivate;
       Q_OBJECT
public:
      ZListBox( QWidget* parent = 0, WFlags f = 0,
                  ZSkinService::WidgetClsID clsId = ZSkinService::clsZListBox1 );
      ZListBox( QString type, QWidget* parent=0, WFlags f = 0,
                  ZSkinService::WidgetClsID clsId = ZSkinService::clsZListBox1);

      virtual ~ZListBox();
      void setListItemType(ZListItem::ListItemType type);
      int count() const;
      void insertItem( const ZListItem * item, int index=-1, bool autoHighlighted = TRUE );
      void insertItem( const ZListItem * item, const ZListItem *after, bool autoHighlighted = TRUE);
      void clear();
      void changeItem( const ZListItem * item, int index );
      void takeItem( const ZListItem * item);
      void removeItem( int index );
      int currentItem() const;
      virtual void setCurrentItem( int index );
      virtual void setCurrentItem( ZListItem * item);
      int topItem() const;
      virtual void setTopItem( int index );
      virtual void setBottomItem( int index );
      ZListBoxItem *item( int index ) const;
      int index( const ZListItem * item) const;
      bool itemVisible( int index );
      bool itemVisible( const ZListItem * item);
      QRect itemRect( ZListItem *item ) const;
      ZListItem *firstItem() const;
      void setSelected( int index, bool select);
      virtual void setSelected( ZListItem * item, bool select);
      bool isSelected( int index) const;
      bool isSelected( const ZListItem * item) const;
      void sort( bool ascending = TRUE );
      QSize sizeHint() const;
      QSize maxmumSizeHint() const;
      QSize minimumSizeHint() const;
      void triggerUpdate( bool doLayout );
      int itemHeight( int index = 0 ) const;
      virtual void  resetFocusItem(bool);
      virtual QRect getCurrentFocusRect(bool) const;
      virtual bool  hasNextPrevFocusItem(bool)const;
      int getListBoxSpace(ZListItem*) const;
	  QString getItemType();
	  void setItemType( QString type );
	  void checkItem( int index, bool select);
	  bool itemChecked(int index);
	  void checkItem( ZListItem* item, bool select );
	  bool itemChecked( ZListItem* item );
      QList<ZListItem>* itemsChecked();
      int radioItemChecked();
      void moveItem(int from, int to);
      void updateSkin(bool redraw);
      void setZBorder( WIDGET_BORDER_INFO_T borderItems[StateCount]);
      void enableEllpsis(bool enable);
      bool isEnableEllpsis();
      void setCurrentItem(int index, bool next);
      typedef void (*DeleteItemCallBack)(ZListItem*);
      void setDeleteItemCallBackFunction(DeleteItemCallBack func);
      DeleteItemCallBack getDeleteItemCallBackFunction() const ;
      void setDefaultItemHeight(int height);
      int defaultItemHeight() const;

       ZSkinBase* getItemSkin(ZSkinService::WidgetClsID style, SelectionState state) const ;
public:
      enum ITEMALIGN{ALIGN_MARK, ALIGN_IMAGE, ALIGN_REGION_A, ALIGN_REGION_B, ALIGN_REGION_C, ALIGN_ROWTYPETHREE};      
      void setAlign(ITEMALIGN element, int align);
      int align(ITEMALIGN element) const;
      enum ListItemRegion 
         {LISTITEM_REGION_A,
          LISTITEM_REGION_B, 
          LISTITEM_REGION_C};
      void setEllpsis(QString ellpsis, ListItemRegion region = LISTITEM_REGION_C);
      QString getEllpsis(ListItemRegion region = LISTITEM_REGION_C);
      void setZItemStyle(ZSkinService::WidgetClsID style);
      ZSkinService::WidgetClsID getZItemStyle(bool isSeparator = FALSE) const;
      void setItemFont(ListItemRegion region, ZSkinBase::SelectionState state, QFont& font);
      QFont& itemFont(ListItemRegion region, SelectionState state) const;
      void enableMarquee(ListItemRegion region, bool enable);
      bool marqueeEnabled(ListItemRegion region) const;
  public:
      void setShowSubItemIcon(bool show);
      bool isShowSubItemIcon() const;
      void showAllSubItem(bool bShow = true);
      bool isShowAllSubItem() const;
      ZListItem * itemAt( QPoint pt) const;
      void setPalette( const QPalette & ){updateSkin(TRUE);}
public:
      // Please don't use following functions.
      void setItemFont(ListItemRegion region, QFont& font, bool highlighted = FALSE);
      QFont& getItemFont(ListItemRegion region, bool highlighted = FALSE) const;
     
public slots:
      virtual void ensureCurrentVisible();

public:
signals:
    void highlighted( int index );
    void highlighted( ZListItem * );
    void highlighted( ZListBoxItem * );
    void highlighted( ZSettingItem * );
    void selected( int index );
    void selected( ZListItem * );
    void selected( ZListBoxItem * );
    void selected( ZSettingItem * );
    void selectionChanged( ZListItem * );
    void selectionChanged( ZListBoxItem * );
    void selectionChanged( ZSettingItem * );
    void currentChanged( ZListItem * );
    void currentChanged( ZListBoxItem * );
    void currentChanged( ZSettingItem * );
    void returnPressed( int );
    void returnPressed( ZListItem * );
    void returnPressed( ZListBoxItem * );
    void returnPressed( ZSettingItem * );
    void clicked( ZListItem * );
    void clicked( ZListItem *, const QPoint & );
    void doubleClicked( ZListItem * );
    void showedSubItemChanged(int index, int subIndex);
protected:
    void viewportPaintEvent( QPaintEvent * event);
    void viewportMousePressEvent( QMouseEvent * );
    void mousePressEvent ( QMouseEvent * );
    void viewportMouseDoubleClickEvent( QMouseEvent * );
    void mouseDoubleClickEvent( QMouseEvent * );
    void keyPressEvent( QKeyEvent *e );
    void focusInEvent( QFocusEvent *e );
    void focusOutEvent( QFocusEvent *e );
    void resizeEvent( QResizeEvent * );
    void showEvent( QShowEvent * );
    void updateItem( int index );
    void updateItem( ZListItem * );
    void toggleCurrentItem();
    void doLayout() const;
private slots:
    void refreshSlot();
    void adjustItems();
private:
    void init(QString type,QWidget * parent,WFlags f, const ZSkinService::WidgetClsID clsId );
    void selectBtns(ZListItem* it);
    void tryGeometry( int, int ) const;
    int numRows() const; 
    int currentRow() const;
    int rowAt( int ) const;
    void setFontData(QFont& font, int size, int style) const;  
    int getMaxItemWidth() const;   
    QPixmap& indImage(SelectionState state)const;
    QPixmap& markImage(SelectionState state, bool single, bool partial) const;
    void setSeparatorFont(QFont& font);
    QFont& getSeparatorFont() const;
    QPixmap& getSeparatorImage(int index) const;
    ZSkinBase* getSeparatorSkin(ZSkinService::WidgetClsID) const;   
    ZSkinBase* getImageContainerSkin(SelectionState state);
    int textAlign(ListItemRegion region, SelectionState state);
    QColor textColor(ListItemRegion region, SelectionState state);
    ZListBoxPrivate * d;
};

#endif
