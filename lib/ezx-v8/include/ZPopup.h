#ifndef _ZPOPUP_H
#define _ZPOPUP_H

#include <qdialog.h>
#include <ZSkinBase.h>
#include <ZFormContainer.h>

class ZAppInfoArea;
class ZSoftKey;
class ZWidget;
class ZPopupHeader;
class ZPopupPrrivate;

struct ZPopupPrivate;

//class ZFormContainer;
class ZDetailView;
class ZIconView;
class ZListBox;
//class ZWidgetBorderInfo;
//class ZWidgetPaddingInfo;
class ZScrollPanel;




/* Size <= 228=57*4 bytes, 216=54*4 */

class ZPopup : public QDialog
{
    Q_OBJECT
    //unsigned int data[54 - sizeof(QDialog)/4];
    unsigned int data[53 - sizeof(QDialog)/4];

public:
    enum POPUP_TYPE_E {
      DIALOG,
      NOTICE
    };
    
    enum PopupCode {
        Rejected = QDialog::Rejected,
        Accepted = QDialog::Accepted, 
        AutoDismissed = 100,
        AnykeyPressed     
    };

    ZPopup(POPUP_TYPE_E = DIALOG, QWidget* parent = 0, char const* name = 0, bool modal = true, int dismiss_time = 0, WFlags f = 0);
    ~ZPopup();
    
    void setTitle(const QString& strTitle);
    QString getTitle();
	void setTitleIcon(const QPixmap& icon);
	void setTitleIcon(const QString& strResourceID);    
    ZPopupHeader* getPopupHeader();
    void enableAia(bool);
    ZAppInfoArea* getAppInfoArea();
	void setInstructText(const QString& str);    
	void setInsTruncPolicy(bool truncated = false);    
    int getBodyAvailableWidth() const;
    int getBodyAvailableHeight();
    void insertChild(ZWidget* child, int index = -1);
    void removeChild(ZWidget* child);
    void insertChild(ZFormContainer*, int index = -1);
    void insertChild(ZIconView*, int index = -1);
    void insertChild(ZDetailView*, int index = -1);
    
    void setSoftkeyTextLeft(const QString&);
    void setSoftkeyTextRight(const QString&);
    void setSoftkeyText(const QString& textLeft, const QString& textRight);
	ZSoftKey * getSoftKey();
	
	void setAutoDismissTime(int msec);
	void setReturnIdlePolicy(int reason, bool disableDefBehavior = false);
		
	virtual void doLayout();			
	virtual void show();
	
	void setScrollable(bool);
	bool getScrollable();
	
	//????????????????
	void setBodyPadding(const WIDGET_PADDING_INFO_T&);
	//???????????????
	void setBodyBorder(WIDGET_BORDER_INFO_T*);
	
	void setBodyBorder(ZSkinBase::BorderPixmaps& pixmaps);	
	void setBodyBackground(QPixmap&);
	void setBodyVSpacing(int);
	//????????????
	void setInstructPadding(const WIDGET_PADDING_INFO_T&);
	
	void setInstructFont(const QFont&);
	void setInstructFontColor(const QColor&);
	void setPalette(const QPalette&);
	
	
public slots:	
    virtual void done(int);
    virtual void accept();
    virtual void reject();
 
signals:		
    void leftSoftkeyClicked();		
	void rightSoftkeyClicked();
	void signalClearKeyPressed();
	void askReturnToIdle(int reason);
	
protected slots:	
    virtual void slotLSKClicked();	
    virtual void slotRSKClicked();
    virtual void slotKbStateChanged(int, bool);
    virtual void slotResizeAllChild(int);    
    
public:    
    ZScrollPanel* getBody() const;
    virtual void keyPressEvent(QKeyEvent*);
    virtual void showEvent(QShowEvent*);
    virtual void hideEvent(QHideEvent*);
    virtual void timerEvent(QTimerEvent*);
    virtual void customEvent(QCustomEvent*);
    
private slots:    
    void slotSPC_resize(ZScrollPanel*, int, int);
    
private:    
    void updateIdleScreenSign();
    void loadSkinData(bool);
    void applySkinData();
    void releaseBodyPixmap();
	void applyBodyBk();
	void removeAndInsert();
	void layoutDialog();
	void layoutNotice();
	void layoutScrollPanel();
	void layoutListbox();
	void layoutFormContainer();
	void layoutDetailView();
	void layoutIconView();
	void layoutNothing();
	void layoutDialogFourAreas();
	void layoutNoticeTwoAreas();
	int getChildrenMaxWidth();
	bool isNeedShowVScrollBar() const;
	void detect_xModal();
	void postLayoutEvent();
	int calculateDesiredContentHeight(const int nWidthMax);
	int calculateBodyAvailWidth(bool bShowScrollbar) const;
	void layout_inner(const int nTop, const int nAvailW);
	void setInsLabelProperty(bool);	

private:	
	ZPopupPrivate* mpData;
};

#endif
