// Copyright (c) 27-Apr-07 - 2008 Motorola, Inc. All rights reserved.

#ifndef ZLISTBOXITEM_H
#define ZLISTBOXITEM_H

#include <qstring.h>
#include <qstringlist.h>
#include <qmap.h>
#include <qlist.h>
#include <qfont.h>
#include <qpixmap.h>
#include <qevent.h>

#include <ZSkinService.h>
#include <ZWrapLine.h>
#include <ZText.h>
#include "ZListItem.h"

class ZListBox;
class ZListBoxClipper;
class ZListBoxItemPrivate;
class LBSubItemInfo;
class LBItemInfo;

class Q_EXPORT ZListBoxItem : public ZListItem
{
public:        
    ZListBoxItem( ZListBox* listbox, const QString itemType = NULL);
    virtual ~ZListBoxItem();
    enum ShowPriority
    {
       FirstPriority,
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
    bool setSubItem(int index, int subIndex, QString text, QString text2, const QPixmap* icon = NULL, uint percent = 50);
    bool setSubItem(int index, int subIndex, QString text, bool isWrapable = false, const QPixmap* icon = NULL);
    bool setSubItem(int index, int subIndex, QPixmap* iconList, uint count);
    int getCurrentSubItem(int index);
    void setCurrentSubItem(int index, int subIndex);
    void setSubItemShowed(int index, int subIndex, bool showed, bool doUpdate = true);
    QPixmap getPixmap(int index);
    bool setPixmap(int index, const QPixmap& pixmap, bool imageContainer = true);
    void setShowIndicator(bool isShow);
    void keyPressEvent( QKeyEvent *e );
    void showColumn(int index, bool show);
    bool setSortIndex(int index, int subIndex);
    virtual QString getSortText() const;
    virtual int width( const ZListBox * )  const;
    virtual int height( const ZListBox * ) const;
    void setPartialStrInfo(int index,int subindex,int region,int pos,int length);

protected:
    virtual void paint( QPainter * );
	      
private:
    virtual void startMarquee();
    virtual void stopMarquee();
    friend void enalbeAllItemsCache(QList<ZListBoxItem>& list);

private:
    ZListBoxItemPrivate *d;
};

#endif
