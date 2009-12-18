#ifndef __ZFORMCONTAINER_H__
#define __ZFORMCONTAINER_H__

#include <ZDetailView.h>
#include <ZMultiLineEdit.h>
#include <ZGroupBox.h>
#include <ZCheckBox.h>
#include <ZExhibitButton.h>
#include <qstring.h>
#include <qwidget.h>
#include <ZWidget.h>
#include <ZScrollPanel.h>
#include <ZLineEdit.h>
#include <ZSeparator.h>
#include <ZFormItem.h>
#include <ZLabel.h>

#include <ZFmwItem.h>

class ZFormContainerPrivate;

class Q_EXPORT ZFormContainer : public ZScrollPanel
{
       Q_OBJECT

public:
      ZFormContainer( QWidget* parent = 0, WFlags f = 0,
                  ZSkinService::WidgetClsID clsId = ZSkinService::clsZFormContainer );
      virtual ~ZFormContainer();
      
      void addChild(ZFormItem* child, bool adjustWidth = FALSE);
      void addChild(ZLineEdit* child, bool adjustWidth = TRUE){addChild((ZWidget*)child, adjustWidth);}
      void addChild(ZCheckBox* child, bool adjustWidth = TRUE){addChild((ZWidget*)child, adjustWidth);}
      void addChild(ZExhibitButton* child, bool adjustWidth = TRUE){addChild((ZWidget*)child, adjustWidth);}
      void addChild(ZLabel* child, bool adjustWidth = TRUE){addChild((ZWidget*)child, adjustWidth);}
      void addChild(ZSeparator* child, bool adjustWidth = TRUE);
      void addChild(ZGroupBox* child, bool adjustWidth = TRUE);
	  void addChild(ZWidget* child, bool adjustWidth = TRUE);
      virtual void removeChild(ZWidget* child);
      virtual bool eventFilter(QObject * obj, QEvent *e);
      void triggerUpdate(bool doLayout);
      QSize maxmumSizeHint();

public:
      void updateSkin(bool redraw);
      void setPalette( const QPalette & ){updateSkin(TRUE);}

protected:
      void resizeEvent(QResizeEvent*);
      void showEvent (QShowEvent*);

private slots:
      void slotLayoutTimer();

private:
      //void addChild(ZWidget* child, bool adjustWidth);
      void doLayout();
      ZFormContainerPrivate * d;
};

#endif


