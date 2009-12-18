#ifndef _ZTIMEPICKERDLG_H
#define _ZTIMEPICKERDLG_H

#include <ZWidget.h>
#include <ZPopup.h>
#include <qdatetime.h>

/* Size: 264=66*4 */

class ZTimeModule : public ZWidget
{
	Q_OBJECT
	unsigned int data[66-sizeof(ZWidget)/4];
public:
  ZTimeModule(QTime, QWidget*, char const*, unsigned, ZSkinService::WidgetClsID = ZSkinService::clsZTimePicker);
	void setStartTime(QTime);
};

/* Size: 216=54*4 */

class ZTimePickerDlg : public ZPopup
{
	Q_OBJECT
	unsigned int data[54 - sizeof(ZPopup)/4];
public:
	ZTimePickerDlg(ZTimeModule*, QWidget*, char const*, unsigned);
	~ZTimePickerDlg();
	QTime getTime();
	ZTimeModule* getTimeModule();
	void initialize(ZTimeModule*);
	virtual void keyPressEvent(QKeyEvent*);
	void setTimeModule(ZTimeModule*);
signals:
	void signalCenterSelKeyPressed();
public slots:
	void slotCenterSelKeyPressed();
	int slotResizeAllChild(int);
};

#endif
