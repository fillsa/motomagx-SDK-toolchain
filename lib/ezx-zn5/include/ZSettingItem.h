//Fix for Motorola ZN5 by Ant-ON

// Copyright (c) 27-Apr-07 - 2008 Motorola, Inc. All rights reserved.

#ifndef ZSETTINGITEM_H
#define ZSETTINGITEM_H

#include <qstring.h>
#include <qlist.h>
#include <qfont.h>
#include <qpixmap.h>

#include <ZSkinService.h>
#include <ZWrapLine.h>
#include <ZText.h>
#include "ZListItem.h"

class ZListBox;
class ZSettingItemPrivate;

enum SettingItemRegion {SETTINGITEM_REGION_A, SETTINGITEM_REGION_B};

class SetSubItemInfo
{
 
public:
  SetSubItemInfo():marquee(NULL), isWrapable(false), region(SETTINGITEM_REGION_B){}
  ~SetSubItemInfo(){if(marquee) delete marquee;}
  QString  text;
  ZMarqueeText *marquee;
  bool isWrapable;
  SettingItemRegion region;
};

class SetItemInfo
{
public:
    SetItemInfo(QString t,int w,QPixmap* pixmap=NULL);
    ~SetItemInfo();
    QString type;
    short width;
    bool fixWidth;
    QPixmap* pm;
    QList<SetSubItemInfo> mtiList; 
};

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
    virtual QString getSortText() const;

protected:
    virtual void paint( QPainter * );

private:
    virtual void startMarquee();
    virtual void stopMarquee();
    virtual ListItemType listitemType() const;
    ZSettingItemPrivate *d;

};

#endif
