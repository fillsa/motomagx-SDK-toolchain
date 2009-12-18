#ifndef __ZPANEL_H_
#define __ZPANEL_H_

#include <ZWidget.h>

/* Size: <= 260 = 65*4 */

class ZPanel  : public ZWidget
{ 
	Q_OBJECT
	unsigned int data[65-sizeof(ZWidget)/4];
public:
  ZPanel(QWidget*, char const*, unsigned, ZSkinService::WidgetClsID = ZSkinService::clsZPanel1);
	~ZPanel();

	void paintEvent(QPaintEvent*);
	void setPalette(QPalette const&);
	void updateSkin(bool);
	QSize minimumSizeHint() const;
	QSize sizeHint() const;
};
#endif
