//Fix class size for ZN5 by Ant-ON, 26.09.2011


// Copyright (c) 27-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef PUBLIC_API_WIDGET_ZPANEL_H
#define PUBLIC_API_WIDGET_ZPANEL_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "ZWidget.h"
#include "ZSkinService.h"

//Size in ZN5: 0xEC

class ZPanel:public ZWidget
{
	unsigned char fix[0xEC-sizeof(ZWidget)];	
public:
    ZPanel( QWidget * parent=0, const char * name=0, WFlags f=0,
                ZSkinService::WidgetClsID clsId = ZSkinService::clsZPanel1);

    virtual ~ZPanel();

   QSize sizeHint() const;

   QSize minimumSizeHint() const;

protected:
        void paintEvent(QPaintEvent *);
        void setPalette(const QPalette &palette);
        void updateSkin(bool redraw);
};

#endif  

