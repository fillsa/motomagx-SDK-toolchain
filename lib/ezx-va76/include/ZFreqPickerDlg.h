//Writed by Ant-ON, 2009

#ifndef ZFREQPICKERDLG
#define ZFREQPICKERDLG

#include "ZFreqModule.h"
#include <ZPopup.h>

class ZSingleCaptureDlg : public ZPopup
{
public:
	ZFreqPickerDlg(ZFreqModule*, QWidget*, char const*, unsigned int);
	ZFreqPickerDlg(ZFreqModule*, QWidget*, char const*, unsigned int);
	~ZFreqPickerDlg();
	
	ZFreqModule * getFreqModule();
	void getFreq();
	void initialize(ZFreqModule*);
	void keyPressEvent(QKeyEvent*);
	void setFreqModule(ZFreqModule*);
	
signals:
	void signalCenterSelKeyPressed();
	
public slots:
	void slotCenterSelKeyPressed();
	void slotResizeAllChild(int);
};

#endif //ZFREQPICKERDLG
