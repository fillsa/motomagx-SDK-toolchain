//Fix for ZN5/U9 by Ant-ON, 25-10-2010
//Chenge fix by Ant-ON, 11.08.2010

#ifndef ZFORMITEM_H
#define ZFORMITEM_H

#include "ZWidget.h"

class ZFormItemPrivate;

//Size in ZN5: ??

class Q_EXPORT ZFormItem : public ZWidget
{
    Q_OBJECT
	
	unsigned char fix[0xEC-sizeof(ZWidget)];
public:
	enum {HIGHEST_PRI = 2};
	enum {SECOND_ICON_NUM = 3};
	enum LAYOUT_STYLE {STACK, PARALLEL};

	ZFormItem( QWidget* parent = 0, const char *name=0, WFlags f = 0,
		  ZSkinService::WidgetClsID clsId = ZSkinService::clsZFormItem );

	virtual ~ZFormItem();
	bool isFormItem();
	//void setTitle(const QString& title);
	//void setPrimIcon(const QPixmap& pmap);
	//int  setSecondIcon(const QPixmap& pmap, int idx, int priority = 0);
	//void removePrimIcon();
	//void removeSecondIcon(int idx);
	//void setLayoutStyle(LAYOUT_STYLE s);
	LAYOUT_STYLE layoutStyle();

protected:
	void paintTitleRegion(QPainter* painter);
	QRect getFormWidgetRect();
	//QSize titleRegionSizeHint();
	int getFormItemPadding(int nIdx);
	int getSpacingV1();
	int getSpacingH1();
	int getSpacingH2();
	ZSkinBase* getFormItemSkinBase();
      
public:
	void updateSkin(bool redraw);
	void setPalette( const QPalette & ){updateSkin(TRUE);}
     
private:
	friend class ZFormItemPrivate;
//    ZFormItemPrivate * d;
};

#endif  //ZFORMITEM_H


