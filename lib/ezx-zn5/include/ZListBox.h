//Fix for Motorola ZN5 by Ant-ON

// Copyright (c) 27-Apr-07 - 2008 Motorola, Inc. All rights reserved.

#ifndef ZLISTBOX_H
#define ZLISTBOX_H

#include <qpixmap.h>
#include <qtimer.h>

#include <ZSkinService.h>
#include "ZScrollPanel.h"
#include "ZListItem.h"
#include "ZListBoxItem.h"
#include "ZSettingItem.h"

class ZListBoxPrivate;

class Q_EXPORT ZListBox : public ZScrollPanel
{
       uint temp[40];	

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
    uint count() const;
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
    ZListItem *item( int index ) const;
    int index( const ZListItem * item) const;
    bool itemVisible( int index );
    bool itemVisible( const ZListItem * item);
    QRect itemRect( ZListItem *item ) const;
    ZListItem *firstItem() const;
    ZListItem *lastItem() const;
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
    void enableEllpsis(bool enable);
    void setCurrentItem(int index, bool next);
    typedef void (*DeleteItemCallBack)(ZListItem*);
    DeleteItemCallBack getDeleteItemCallBackFunction() const ;
    void setDefaultItemHeight(int height);
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
    ZSkinService::WidgetClsID getZItemStyle(bool isSeparator = FALSE) const;
    void setItemFont(ListItemRegion region, SelectionState state, QFont& font);
    QFont& itemFont(ListItemRegion region, SelectionState state) const;
    void enableMarquee(ListItemRegion region, bool enable);
    bool marqueeEnabled(ListItemRegion region) const;
    bool highlightCurItemNoFocus() const;
    void enableHighlightCurItemNoFocus(bool enable);
	   
public:
    void showAllSubItem(bool bShow = true);
    ZListItem * itemAt( QPoint pt) const;
	void setPartialColor(QColor &c,SelectionState state);
	QColor getPartialColor(SelectionState state);
    void setPalette( const QPalette & );


public:
    void setItemFont(ListItemRegion region, QFont& font, bool highlighted = FALSE);
    QFont& getItemFont(ListItemRegion region, bool highlighted = FALSE) const;

public slots:
    virtual void ensureCurrentVisible();

signals:
    void highlighted( ZListBoxItem * );
    void selected( int index );
    void selected( ZListItem * );
    void selected( ZListBoxItem * );
    void selected( ZSettingItem * );
    void selectionChanged( ZListBoxItem * );
    void currentChanged( ZListBoxItem * );
    void returnPressed( ZListBoxItem * );

protected:
    void viewportResizeEvent( QResizeEvent* );
    void hideEvent ( QHideEvent * );
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
    void toggleCurrentItem();

private:
    int getMaxItemWidth() const;
    QFont& getSeparatorFont() const;

    QPixmap& getSeparatorImage(int index) const;
    ZSkinBase* getSeparatorSkin(ZSkinService::WidgetClsID) const;
    
    ZSkinBase* getImageContainerSkin(SelectionState state);

    int textAlign(ListItemRegion region, SelectionState state);
    QColor textColor(ListItemRegion region, SelectionState state);

    ZListBoxPrivate * d;
};

#endif


