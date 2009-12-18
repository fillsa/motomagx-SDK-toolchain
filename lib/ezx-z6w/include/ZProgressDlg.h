#ifndef _ZPROGRESSDLG_H
#define _ZPROGRESSDLG_H

#include <ZPopup.h>
#include <ZMeter.h>

/* Size: 216=54*4 */

/*
vtable for ZProgressDlg@@VERSION		 // OBJECT
ZProgressDlg::cancelled()@@VERSION		 // FUNC
ZProgressDlg::cancel()@@VERSION		 // FUNC
ZProgressDlg::changeMeter(int, int)@@VERSION		 // FUNC
ZProgressDlg::changeMeter(int)@@VERSION		 // FUNC
ZProgressDlg::changeMeter(QString const&)@@VERSION		 // FUNC
ZProgressDlg::className() const@@VERSION		 // FUNC
ZProgressDlg::getMeterModule()@@VERSION		 // FUNC
ZProgressDlg::getMeter()@@VERSION		 // FUNC
ZProgressDlg::getMinimumDuration() const@@VERSION		 // FUNC
ZProgressDlg::getProgressTotalStep()@@VERSION		 // FUNC
ZProgressDlg::getProgress()@@VERSION		 // FUNC
ZProgressDlg::keyPressEvent(QKeyEvent*)@@VERSION		 // FUNC
ZProgressDlg::reset()@@VERSION		 // FUNC
ZProgressDlg::setAutoClose(bool)@@VERSION		 // FUNC
ZProgressDlg::setAutoPercentFlag(bool)@@VERSION		 // FUNC
ZProgressDlg::setAutoReset(bool)@@VERSION		 // FUNC
ZProgressDlg::setMMAlign(ZMeterModule::Alignment)@@VERSION		 // FUNC
ZProgressDlg::setMMLabelText(QString const&)@@VERSION		 // FUNC
ZProgressDlg::setProgress(int)@@VERSION		 // FUNC
ZProgressDlg::setProgressTotalStep(int)@@VERSION		 // FUNC
ZProgressDlg::slotResizeAllChild(int)@@VERSION		 // FUNC
ZProgressDlg::staticMetaObject()@@VERSION		 // FUNC
ZProgressDlg::wasCancelled() const@@VERSION		 // FUNC
ZProgressDlg::ZProgressDlg(QString const&, QString const&, int, int, QWidget*, char const*, bool, unsigned int)@@VERSION		 // FUNC
ZProgressDlg::ZProgressDlg(QString const&, QString const&, int, int, QWidget*, char const*, bool, unsigned int)@@VERSION		 // FUNC
ZProgressDlg::ZProgressDlg(QString const&, QString const&, int, QWidget*, char const*, bool, unsigned int)@@VERSION		 // FUNC
ZProgressDlg::ZProgressDlg(QString const&, QString const&, int, QWidget*, char const*, bool, unsigned int)@@VERSION		 // FUNC
ZProgressDlg::ZProgressDlg(QString const&, QString const&, QString const&, QWidget*, char const*, bool, unsigned int)@@VERSION		 // FUNC
ZProgressDlg::ZProgressDlg(QString const&, QString const&, QString const&, QWidget*, char const*, bool, unsigned int)@@VERSION		 // FUNC
ZProgressDlg::ZProgressDlg(QWidget*, char const*, bool, unsigned int)@@VERSION // FUNC
ZProgressDlg::ZProgressDlg(QWidget*, char const*, bool, unsigned int)@@VERSION // FUNC
ZProgressDlg::~ZProgressDlg()@@VERSION		 // FUNC
ZProgressDlg::~ZProgressDlg()@@VERSION		 // FUNC
ZProgressDlg::~ZProgressDlg()@@VERSION		 // FUNC
*/

class ZProgressDlg : public ZPopup
{	
	Q_OBJECT
	unsigned int data[54-sizeof(ZPopup)/4];

public:
    ZProgressDlg(const QString& strDlgTitle,
                 const QString& strInstructText,
                 int nTotalStep,
                 int nMaxSize,
                 QWidget* parent = NULL, const char* name = 0, bool modal = true, WFlags f = 0);
    ZProgressDlg(const QString& strDlgTitle,
                 const QString& strInstructText,
                 const QString& strFileName,
                 QWidget* parent = NULL, const char* name = 0, bool modal = true, WFlags f = 0);
    ZProgressDlg(const QString& strDlgTitle,
                 const QString& strInstructText,
                 int nTotalStep = 10,
                 QWidget* parent = NULL, const char* name = 0, bool modal = true, WFlags f = 0);
    ZProgressDlg(QWidget* parent = NULL, const char* name = 0, bool modal = true, WFlags f = 0);
	
	//ZProgressDlg(QWidget*, char const*, bool, unsigned int);
	//ZProgressDlg(QString const&, QString const&, QString const&, QWidget*, char const*, bool, unsigned int);
	//ZProgressDlg(QString const&, QString const&, int, QWidget*, char const*, bool, unsigned int);
	//ZProgressDlg(QString const&, QString const&, int, int, QWidget*, char const*, bool, unsigned int);
	~ZProgressDlg();

	void autoClose() const;
	void autoReset() const;
	void cancel();
	void cancelled();
	void changeMeter(QString const&);
	void changeMeter(int);
	void changeMeter(int, int);
	void forceShow();
	//void getMeter();
    ZMeter* getMeter();
	//void getMeterModule();
    ZMeterModule* getMeterModule();
	void getMinimumDuration() const;
	void getProgress();
	void getProgressTotalStep();
	void initialize(QString const&, QString const&);
	void keyPressEvent(QKeyEvent*);
	void reset();
	void setAutoClose(bool);
	void setAutoPercentFlag(bool);
	void setAutoReset(bool);
	void setMMAlign(ZMeterModule::Alignment);
	void setMMLabelText(QString const&);
	void setMeterModule(ZMeterModule*);
	void setMinimumDuration(int);
	void setProgress(int);
	void setProgressTotalStep(int);
	bool wasCancelled() const;

public slots:
	void slotLeftSoftKeyClicked();
	void  slotResizeAllChild(int);
};

#endif
