/*
# Revision History:
# 
#    date         coreid  description
# ---------------------------------------------------------------------------
#    02-Jun-2008  BeZ     changed return type for functions:
#                            ZDetailItem::paint(), ZDetailItem::height() 
*/

#ifndef _ZDETAILVIEW_H
#define _ZDETAILVIEW_H

#include <ZScrollPanel.h>
#include <ZWrapLine.h>


class QPainter;
class ZDetailView;
class ZDetailItemPrivate;

class ZDetailItem
{
public:

      enum ItemType{ItemTypeSeparator, ItemTypeA, ItemTypeB, ItemTypeC, ItemTypeD, 
                    ItemTypeE, ItemTypeF, ItemTypeG, ItemTypeH, ItemTypeI, ItemTypeJ};

      enum FontType{FontTitle, FontContent, FontSDHighlighted, FontSDStandard};
      enum ColorType{ColorTitle, ColorContent, ColorSDHighlighted, ColorSDStandard};
	
	ZDetailItem(QString text = QString(""), QPixmap* icon = NULL, ZDetailView* parent = NULL);
	ZDetailItem(ItemType, QString title = QString(""), QChar titleColon = QChar(), ZDetailView* parent = NULL);
    virtual ~ZDetailItem();
    
    void setReservedData(unsigned int rsvData);
    unsigned int getReservedData();
    void appendTextIconRow(QString text);
    void appendTextIconRow(QPixmap& icon);
    void appendTextIconRow(QString text, QPixmap& icon, bool IconLeftOrLabelBottom=TRUE);
    void clearAllRow(); 
    void removeRow(uint index); 
    ItemType itemType() const;
    void enableStructureDataParse(bool enable);
    void setParseType(QString type);
    void enableTitleParse(bool enable);
          
public:
      virtual void paint(QPainter& painter);
                
protected:
      void setParent(ZDetailView * parent);
      virtual int height(const ZDetailView *);

      void setRect(int x, int y, int w, int h);
      QRect rect() const;

      void setDirty(bool dirty);
      bool dirty() const;

      void doParse();
                      
private:

     int ZDetailItem::separatorHeight(const ZDetailView * view);

      uint getSDCount() const;
      void getSDData(int index, QString& origin, QString& replaced, QString& type) const; 
      int currentSDIndex() const;
      QRect getSDRect(int index) const;
      void setCurrentSD(int index);

      ZDetailItemPrivate* d;

      friend class ZDetailView;
      friend class ZDetailItemPrivate;

};

/* Size: UNKNOWN*/

class ZDetailView : public ZScrollPanel
{
    Q_OBJECT

public:
      ZDetailView( QWidget* parent = 0, WFlags f = 0,
                  ZSkinService::WidgetClsID clsId = ZSkinService::clsZDetailView1 );
      virtual ~ZDetailView();

      void addItem(ZDetailItem* item);
      void removeItem(ZDetailItem* item);
      void insertIntem(ZDetailItem* item, ZDetailItem* after);
	  void triggerUpdate( bool doLayout );
      QRect itemRect( ZDetailItem *item ) const;	  
      QSize maxmumSizeHint() const;    
      //void setStructureDataParser(ZStructureDataParser* parser);
      //ZStructureDataParser* getStructureDataParser() const;

      void setWrapPolicy(ZWrapLine::WrapPolicy);

      ZDetailItem* current() const;
      int currentSDIndex() const;

      uint getStructureDataCount() const{return getSDCount();}
      bool getStructureData(int id, QString& origin, QString& replaced, QString& type);

      void setFont(ZDetailItem::FontType type, QFont& font);  
      
public:
      virtual uint getStepInScrollPanel(bool) const;
      virtual void  resetFocusItem(bool);
      virtual QRect getCurrentFocusRect(bool) const;
      virtual bool  hasNextPrevFocusItem(bool)const;
      virtual bool noFocusMode() const;
                  
public:
    void updateSkin(bool redraw);                  
                  
signals:
    void returnPressed(const ZDetailItem* item, const QString & origin, const QString & replaced, const QString & type);
    void highlighted(const ZDetailItem* item, const QString & origin, const QString & replaced, const QString & type);

protected:

    void viewportPaintEvent( QPaintEvent * event);
    void keyPressEvent( QKeyEvent *e );
    void resizeEvent( QResizeEvent * );
    void focusInEvent( QFocusEvent *e );
    void focusOutEvent( QFocusEvent *e );
    void showEvent (QShowEvent*);

    void updateItem( ZDetailItem * );
    
private slots:
    void refreshSlot();
        
private:
    void doLayout() const;
    int getMaxItemWidth() const;
    int wrapSpace() const;
    QFont& font(ZDetailItem::FontType) const;
    QColor color(ZDetailItem::ColorType) const;
    ZWrapLine::WrapPolicy wrapPolicy() const;
    void ensureCurrentVisible();
    QFont& getSeparatorFont() const;
    QPixmap& getSeparatorImage(int index) const;
    ZSkinBase* getSeparatorSkin() const;
    ZSkinBase* getItemSkin() const;    
    void setFontData(QFont& font, int size, int style) const;

    uint getSDCount() const;
    QRect getSDRect(int index) const;
    void setCurrentSD(int index, bool scroll = TRUE);

    bool isOutlined() const;
    int outlinedSize() const;
    int outlinedColor() const;
    
    //ZDetailViewPrivate * d;

    friend class ZDetailItem;
    friend class ZDetailItemPrivate;        


};

#endif
