// _ZN12ZProgressDlgC4EP7QWidgetPKcbj
// _ZN12ZProgressDlgC4ERK7QStringS2_iiP7QWidgetPKcbj
// _ZN12ZProgressDlgC4ERK7QStringS2_iP7QWidgetPKcbj
// _ZN12ZProgressDlgC4ERK7QStringS2_S2_P7QWidgetPKcbj
// _ZN12ZProgressDlgD4Ev


#ifndef _E2_EZX_ZPROGRESSDLG_H
#define _E2_EZX_ZPROGRESSDLG_H

#include <qstring.h>
#include <qwidget.h>

class ZProgressDlg : public QWidget
{	
	Q_OBJECT
public: 
	char tmp[1024];
	ZProgressDlg(QString const&, QString const&, QString const&, QWidget*, char const*, bool, unsigned);
	ZProgressDlg(QString const&, QString const&, int, QWidget*, char const*, bool, unsigned);
	ZProgressDlg(QString const&, QString const&, int, int, QWidget*, char const*, bool, unsigned);
	ZProgressDlg(QWidget*, char const*, bool, unsigned);
	~ZProgressDlg();
	void setAutoPercentFlag(bool);
	void setAutoReset(bool);
	void setProgress(int);
	bool wasCancelled() const;
	/*
	int autoClose() const
	int autoReset() const
	int cancel()
	int cancelled()
	int changeMeter(QString const&)
	int changeMeter(int)
	int changeMeter(int, int)
	int className() const
	int forceShow()
	int getMeter()
	int getMeterModule()
	int getMinimumDuration() const
	int getProgress()
	int getProgressTotalStep()
	int initMetaObject()
	int initialize(QString const&, QString const&)
	int keyPressEvent(QKeyEvent*)
	int reset()
	int setAutoClose(bool)
	int setAutoPercentFlag(bool)
	int setAutoReset(bool)
	int setMMAlign(ZMeterModule::Alignment)
	int setMMLabelText(QString const&)
	int setMeterModule(ZMeterModule*)
	int setMinimumDuration(int)
	int setProgress(int)
	int setProgressTotalStep(int)
	int slotLeftSoftKeyClicked()
	int slotResizeAllChild(int)
	int staticMetaObject()
	int tr(char const*)
	int tr(char const*, char const*)
	int wasCancelled() const
	int ~ZProgressDlg [in-charge deleting]()
	int ~ZProgressDlg [in-charge]()
*/
};

#endif
