#ifndef ZNUMBERCONTROL_H
#define ZNUMBERCONTROL_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "ZButton.h"
#include "ZSkinBase.h"
#include "ZNumModule.h"

class ZLabel;
class ZNumberControlPrivate;
class ZNumPickerDlg;

class ZNumberControl : public ZButton
{
    Q_OBJECT
public:
    ZNumberControl(int nMaxLen, QWidget * parent, const char * name = 0, WFlags f = 0);
    ZNumberControl(int nMaxLen, const QString & title, TitlePosition titlePos = TitleTop, QWidget * parent = 0, 
                   const char * name = 0, WFlags f = 0);
    ~ZNumberControl();
	void setLabel(ZLabel *pLabel,ZNumModule::RelativeAlignment alignment);
	int getValue();
	void setMaxValue( int nValue );
	void setMinValue( int nValue );
	void setValue( int nValue );
    void setLineStep( int nStep);
    void setWrapping(bool bOn);
	int maxValue();
    int minValue();
	bool wrapping();
    int lineStep();
    void getFrameWidth(int & nleftw, int & nrightw, int & ntopw, int & nbottomw) const;
    void setDlgTitle(const QString & title);
    void setSoftkeyTextLeft(const QString& strText);
    void setSoftkeyTextRight(const QString& strText);
    void setSoftkeyText(const QString& strLeft, const QString& strRight);
    ZNumPickerDlg * numPickerDlg();
signals:
	void selectOK();
    void selectCancel();
protected slots:
    void slotClick();
    void slotSelectOK();
    void slotSelectCancel();
protected:
    virtual QRect getContentRect() const;
    virtual void getBtnFrameWidth(int & nleftw, int & nrightw, int & ntopw, int & nbottomw) const;
    virtual void getLabelFrameWidth(int & nleftw, int & nrightw, int & ntopw, int & nbottomw) const;
    virtual void drawBorderEx(ItemType itemType, QPainter * p, const QRect * rect = NULL);
    virtual void drawBackgroundEx(ItemType itemType, QPainter * p, const QRect * rect = NULL);
    virtual int  getBtnHSpacing() const;
    virtual int  getTitleSpacing(TitlePosition titlePos = TitleTop) const;
    virtual void stateChanged(StateChangeReason stChangeReason);
    virtual void titleChanged(const QString & title);
    virtual void getCurrentFont(QFont & font, QColor & ftColor, ItemType itemType) const ;
    void updateSkin(bool redraw);
    virtual void setPalette(const QPalette &);
private:
    void init(int nMaxLen);
    bool createNumPickerDlg();
private:
    ZNumberControlPrivate * d;
};

#endif
