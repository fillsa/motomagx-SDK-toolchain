// _ZN12ZScrollPanelC4EP7QWidgetPKcjN12ZSkinService11WidgetClsIDE
// _ZN12ZScrollPanelD4Ev

#ifndef _E2_EZX_ZPANEL_H
#define _E2_EZX_ZPANEL_H

#include <E2_EZX_ZWidget.h>

class ZPanel  :public ZWidget
{ 
	Q_OBJECT
  char tmp[4096];
public:
	ZPanel(QWidget*, char const*, unsigned, ZSkinService::WidgetClsID);
	~ZPanel();
	/*int minimumSizeHint() const
	int paintEvent(QPaintEvent*)
	int setPalette(QPalette const&)
	int sizeHint() const
	int updateSkin(bool)
	int ~ZPanel [in-charge]()
	int ~ZPanel [not-in-charge]()
	*/
};
#endif
