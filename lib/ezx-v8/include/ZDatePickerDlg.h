#ifndef _ZDATAPICKERDLG_H
#define _ZDATAPICKERDLG_H

#include <ZWidget.h>
#include <ZPopup.h>
#include <qdatetime.h>

/* Size: 264=66*4 */

class ZDateModule : public ZWidget
{
	Q_OBJECT
	unsigned int data[67-sizeof(ZWidget)/4];
public:
	ZDateModule(QWidget*, char const*, unsigned, ZSkinService::WidgetClsID);
	void setDateValue(QDate);
};

/* Size: 216*4 */

class ZDatePickerDlg : public ZPopup
{
	Q_OBJECT
	unsigned int data[54 - sizeof(ZPopup)/4];
public:
	ZDatePickerDlg(ZDateModule*, QWidget*, char const*, bool, unsigned);
	QDate getResultDate();
};

#endif

