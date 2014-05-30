#ifndef __ZSOFTKEY_H__
#define __ZSOFTKEY_H__

#include <ZWidget.h>
#include <qstring.h>
#include <qfont.h>
#include <ZSkinBase.h>

class QStringList;
class ZSoftButton;
class QString;
class QPopupMenu;
class ZOptionsMenu;
class ZSoftKeyPrivate;

class ZSoftKey : public ZWidget
{
Q_OBJECT
public:
    enum KEY_IDX {LEFT, RIGHT ,MID};
    enum TEXT_PRIORITY {ZERO, ONE, TWO};
    ZSoftKey(const QString& type, QWidget* parent, QWidget *watcher = 0); 
    void setOptMenu(KEY_IDX nIdx, ZOptionsMenu* optMenu);
    ZOptionsMenu* getOptMenu(KEY_IDX nIdx);
    void setText(KEY_IDX nIdx , const QString& str, TEXT_PRIORITY prior = ZERO);
    void prevText(KEY_IDX nIdx);
    void setResourceID(KEY_IDX nIdx, const QString& str, TEXT_PRIORITY prior = ZERO);
    void prevResourceID(KEY_IDX nIdx);
    void setClickedSlot(KEY_IDX nIdx, const QObject* receiver, const char* member);
    void prevClickedSlot(KEY_IDX nIdx);
    void disableClickedSlot(KEY_IDX nIdx);
    void enableClickedSlot(KEY_IDX nIdx);
    bool eventFilter( QObject *, QEvent * );
    void showButton(KEY_IDX nIdx, bool bShow);
    bool isButtonShow(KEY_IDX nIdx);
    void setButtonEnable(KEY_IDX nIdx, bool enable);
    bool isButtonEnabled(KEY_IDX nIdx);
    void setBgOverlapPixmap(KEY_IDX nIdx, const QPixmap& pmap, int alpha);
    virtual QSize sizeHint();
    virtual void setPalette( const QPalette & pal );
    void setTextForOptMenuHide(const QString& text);
    QString textForOptMenuHide();
    void setTextForOptMenuShow(const QString& txtForHasOptMenu, const QString& txtForHasNoOptMenu);
    void textForOptMenuShow(QString&  txtForHasOptMenu, QString& txtForHasNoOptMenu);
    ~ZSoftKey();
public slots:
    void slotBtnClicked(KEY_IDX nIdx);
    void slotBtnPressed(KEY_IDX nIdx);
    void slotBtnReleased(KEY_IDX nIdx);
    
protected slots:
    void slotLeftKeyPressed();
    void slotLeftKeyReleased();
    void slotRightKeyPressed();
    void slotRightKeyReleased();
    void slotMenuHide();
    void slotMenuShow();
protected:
    void updateFont(QFont* pFont, const FONT_INFO_T& fntInfo);
    void initFont();
    bool initBtn(const QString& type);
    void setCstR();  
    bool parseType(const QString& type);
    bool createBtn();
    void setBtnGeometry();
    bool handleShortcutKeyThreeBtn(int key, bool bKeyPressed);
    bool handleShortcutKeyTwoBtn(int key, bool bKeyPressed);
    bool handleShortcutKeyOneBtn(int key, bool bKeyPressed);
    bool handleDefaultKey();
    void setTextSelfShow(int op); // 0: show  1: hide
    virtual void paintEvent(QPaintEvent*);
    void hideButton(QPainter* p, ZSoftButton* pBtn);
    void connectKeySignalToSlot(ZOptionsMenu* optMenu);
    void connectSubMenuToSlot(ZOptionsMenu* optMenu);
protected:
    bool handleShortcutKey(int key, bool bKeyPressed);
    bool handleBtnBySK(KEY_IDX nIdx, bool bKeyPressed, bool bSendSignal = true);
    void reparent (QWidget * parent, WFlags, const QPoint &, bool showIt=FALSE);
    void setKeyEventWatcher( QWidget *watcher);
    virtual void resizeEvent(QResizeEvent*);
private:
    ZSoftKey(const ZSoftKey&);
    ZSoftKey& operator=(const ZSoftKey&);
private:
    ZSoftKeyPrivate* d;
    int m_nBtnNum;
    int m_nDataId; //this id is used to save the softkeydata id which has menu in its soft button
	bool m_bSelfShowText;
    bool* m_bShortcutKeyPressed;
    QString m_strType;
    QString m_strSubType;
    QWidget *m_pWatcher;
    bool m_isUserSetWatcher;
    bool m_bRightBtnState; //false: disable, true : enable
    static QFont* m_pFontStd;
    static QFont* m_pFontH;
    static int m_nFontReferNum;
};
#endif
