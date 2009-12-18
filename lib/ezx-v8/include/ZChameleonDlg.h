#ifndef _ZCHAMELEONDLG_H
#define _ZCHAMELEONDLG_H

#include <ZBaseDialog.h>

class PHONE_UI_DlgHeader;
class ZWidgetPaddingInfo;
class ZSoftKey;
class ZAppInfoArea;

/* Size: UNKNOWN. Nobody uses it. */

class ZChameleonDlg : public ZBaseDialog
{
    Q_OBJECT
    unsigned int tmp[1024 - sizeof(ZBaseDialog)/4];

public:
    virtual void setContentWidget(QWidget*);
    virtual void onLeftBtnClick();
    virtual void onRightBtnClick();

public slots:
    virtual void slotTimeout();
    virtual void slotKbStateChanged(int, bool);

public:
	ZChameleonDlg(QWidget*, char const*, int, unsigned int, int, ZSkinService::WidgetClsID);
	~ZChameleonDlg();

	void askReturnToIdle(int);
	void customEvent(QCustomEvent*);
	ZAppInfoArea* getAppInfoArea();
	QWidget * getContentWidget();
	void getDlgHeader();
	void getPadVSpace(ZWidgetPaddingInfo*, int*);
	ZSoftKey * getSoftKey();
	QString& getTitle();
	void initialize(ZSkinService::WidgetClsID);
	void keyPressEvent(QKeyEvent*);
	void layoutAreas(int);
	void leftSoftkeyClicked();
	void paintEvent(QPaintEvent*);
	void rightSoftkeyClicked();
	void setAppInfoArea(ZAppInfoArea*);
	void setAutoDismissTime(int);
	void setBackgroundMode(QWidget::BackgroundMode);
	void setCallingHeader(PHONE_UI_DlgHeader*);
	void setPalette(QPalette const&);
	void setReturnIdlePolicy(int, bool);
	void setSoftkeyText(QString const&, QString const&);
	void setSoftkeyTextLeft(QString const&);
	void setSoftkeyTextRight(QString const&);
	void setTitle(QString const&);
	void setTitleIcon(QPixmap const&);
	void setTitleIcon(QString const&);
	void showEvent(QShowEvent*);
	void startDismissTimer();

signals:
	void signalClearKeyPressed();
};
#endif
