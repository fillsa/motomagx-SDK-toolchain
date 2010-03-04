//Fix for ZN5 by Ant-ON, 2009
//Fix for ZN5/U9 by Ant-ON, 25-10-2010

// Copyright (c) 27-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef PUBLIC_API_WIDGET_ZFORMCONTAINER_H
#define PUBLIC_API_WIDGET_ZFORMCONTAINER_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "ZScrollPanel.h"
#include "ZFormItem.h"
#include "ZDetailItem.h"
#include "ZSeparator.h"
#include "ZMultiLineEdit.h"
#include "ZLineEdit.h"
#include "ZGroupBox.h"
#include "ZCheckBox.h"
#include "ZExhibitButton.h"
#include "ZLabel.h"

class ZFormContainerPrivate;

class Q_EXPORT ZFormContainer : public ZScrollPanel
{
       Q_OBJECT

public:
      ZFormContainer( QWidget* parent = 0, WFlags f = 0,
                  ZSkinService::WidgetClsID clsId = ZSkinService::clsZFormContainer );

      virtual ~ZFormContainer();

      void addChild(ZFormItem* child, bool adjustWidth = FALSE,ZWidget *after=NULL);

      void addChild(ZLineEdit* child, bool adjustWidth = TRUE,ZWidget *after=NULL);

      void addChild(ZCheckBox* child, bool adjustWidth = TRUE,ZWidget *after=NULL);

      void addChild(ZExhibitButton* child, bool adjustWidth = TRUE,ZWidget *after=NULL);

      void addChild(ZMultiLineEdit* child, bool adjustWidth = TRUE,ZWidget *after=NULL);

      void addChild(ZSeparator* child, bool adjustWidth = TRUE,ZWidget *after=NULL);

      void addChild(ZGroupBox* child, bool adjustWidth = TRUE,ZWidget *after=NULL);

      void addChild(ZLabel* child, bool adjustWidth = TRUE,ZWidget *after=NULL)
      {
		  addChild((ZWidget*)child, adjustWidth, after);
	  }

      void addChild(ZWidget* child, bool adjustWidth = TRUE,ZWidget *after=NULL);
      
      //void resizeChild(ZWidget* child, int w);

      virtual void removeChild(ZWidget* child);

      virtual bool eventFilter(QObject * obj, QEvent *e);

      void triggerUpdate(bool doLayout);

      //QSize maxmumSizeHint();

public:
      void updateSkin(bool redraw);
      void setPalette( const QPalette & );

protected:

      void resizeEvent(QResizeEvent*);

      void showEvent (QShowEvent*);
protected slots:
      virtual void slotResizeChild();

//private slots:
//      void slotLayoutTimer();

private:
      void doLayout();

      ZFormContainerPrivate * d;
};

#endif

