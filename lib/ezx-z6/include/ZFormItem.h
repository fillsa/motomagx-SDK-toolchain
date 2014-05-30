#ifndef _ZFORMITEM_H_
#define _ZFORMITEM_H_ 1

#include <ZWidget.h>

/* Size: UNKNOWN. Used only as base class for ZLineEdit(380),
 *	ZColorControl(NU, >=276), ZSegmentField, ZExhibitButton(284),
 *	ZBaseButton(>=276)
 *
 *	ZColorControl keeps some QString at 268. I guess size
 *	of ZFormItem is 268=67*4
 */

class ZFormItem : public ZWidget
{
    Q_OBJECT
    unsigned int data[67 - sizeof(ZWidget)/4];
public:
    ZFormItem(QWidget*, char const*, unsigned int, ZSkinService::WidgetClsID);
    ~ZFormItem();

    void setPalette(QPalette const&);
    void updateSkin(bool);
};

#endif
