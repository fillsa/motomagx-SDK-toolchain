// _ZN14ZFormContainerC4EP7QWidgetjN12ZSkinService11WidgetClsIDE
// _ZN14ZFormContainerD4Ev

#ifndef _E2_EZX_ZFORMCONTAINER_H
#define _E2_EZX_ZFORMCONTAINER_H

#include <qstring.h>
#include <qwidget.h>
#include <E2_EZX_ZWidget.h>
#include <E2_EZX_ZWidgetContainer.h> 

class ZFormContainer : public ZWidgetContainer
{ 
	Q_OBJECT
  char tmp[4096];
 public:
	ZFormContainer(QWidget* parent = NULL, unsigned type = 0, ZSkinService::WidgetClsID cls = ZSkinService::NONE);
	~ZFormContainer();
	void addChild(ZWidget* child, bool adjustWidth = TRUE);
	
/*	
	void addChild(ZFormItem*, bool);
	void addChild(ZGroupBox*, bool);
	void addChild(ZMultiLineEdit*, bool);
	void addChild(ZSeparator*, bool);
	*/
/*	int className() const
	int doLayout()
	int initMetaObject()
	int maxmumSizeHint()
	int removeChild(ZWidget*)
	int resizeEvent(QResizeEvent*)
	int showEvent(QShowEvent*)
	int slotLayoutTimer()
	int staticMetaObject()
	int tr(char const*)
	int tr(char const*, char const*)
	int triggerUpdate(bool)
	int updateSkin(bool)
	*/
};
#endif
