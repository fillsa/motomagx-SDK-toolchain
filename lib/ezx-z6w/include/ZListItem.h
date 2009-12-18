
// Copyright (c) 27-Apr-07 - 2008 Motorola, Inc. All rights reserved.

#ifndef ZLISTITEM_H
#define ZLISTITEM_H

#include <qlist.h>
#include <qfont.h>
#include <qpixmap.h>

#include <ZSkinService.h>
#include <ZWrapLine.h>
#include <ZText.h>
#include <ZSkinBase.h>

class ZListBox;
class ZListBoxClipper;

class Q_EXPORT ZListItem
{
public:        
    ZListItem( ZListBox* listbox, const QString itemType = NULL);
    virtual ~ZListItem();
    enum ListItemType {LISTBOXITEM, SETTINGITEM};
    QString getItemType() const;
    ZListBox* listBox() const;
    void setActive();
    void check(bool b);
    bool isChecked() const;
    QString getMarkColumnType() const;
    void setReservedData(unsigned int rsvData);
    unsigned int getReservedData();
    void setEnabled(bool enabled);
    bool enabled() const;
    void setSelectable( bool b = FALSE );
    bool isSelectable() const;
    ZListItem *next() const;
    void setWrapPolicy(ZWrapLine::WrapPolicy policy);
    ZWrapLine::WrapPolicy getWrapPolicy();
    void setZStyle(ZSkinService::WidgetClsID style);
    ZSkinService::WidgetClsID getZStyle() const;
    void setSeparator(const QString text, const QPixmap* icon = NULL);
    bool isSeparatorItem() const;
    virtual QString getSortText() const;

protected:
    ZSkinBase::SelectionState getSelectionState();

protected:
    ZListBox* lb;
    QString itemType;
    ZListItem * p, * n;
    enum ToggleState { OFF, NOCHANGE, ON};
    short stat;
    QPixmap* mSepIcon;
    QString* mSepText;
    ZMarqueeText* mSepMarqueeText;                                                                      
    unsigned int reserved;
    ZWrapLine::WrapPolicy wrapPolicy;
    ZSkinService::WidgetClsID itemClsId;
    uint down:1;
    uint isEnabled:1;
    uint isSeparator:1;
    uint selectable:1;
    uint dirty:1;
    uint own_style:1;
    friend class ZListBox;
    friend class ZListBoxClipper;

};

#endif

