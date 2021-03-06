//Chenge fix by Ant-ON, 11.08.2010
//Fix class size for ZN5 by Ant-ON, 25.09.2011

// Copyright (c) 27-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef ZSOFTKEY_H    
#define ZSOFTKEY_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include <ZWidget.h>
#include <qstring.h>
#include <qfont.h>
#include <ZWidgetSkinProps.h>

class QStringList;
class ZSoftButton;
class QString;
class QPopupMenu;
class ZOptionsMenu;
class ZSoftKeyPrivate;

// Size in ZN5: 0xF0

class ZSoftKey : public ZWidget
{
    Q_OBJECT
    
    unsigned char fix[0xF0-sizeof(ZWidget)];
public:
    enum KEY_IDX
    {
        LEFT,       ///< Left soft button
        RIGHT,      ///< Right soft button
        MID         ///< Middle soft button
    };

    enum TEXT_PRIORITY {
        ZERO,
        ONE,
        TWO
    };

    ZSoftKey(const QString& type, QWidget* parent, QWidget *watcher = 0);

    void setOptMenu(KEY_IDX nIdx, ZOptionsMenu* optMenu);

    ZOptionsMenu* getOptMenu(KEY_IDX nIdx);

    void setText(KEY_IDX nIdx , const QString& str, TEXT_PRIORITY prior = ZERO);

    void prevText(KEY_IDX nIdx);

    void setResourceID(KEY_IDX nIdx, const QString& str, TEXT_PRIORITY prior = ZERO);

    //void prevResourceID(KEY_IDX nIdx);

    void setClickedSlot(KEY_IDX nIdx,
                        const QObject* receiver,
                        const char* member);

    void prevClickedSlot(KEY_IDX nIdx);

    void disableClickedSlot(KEY_IDX nIdx);

    void enableClickedSlot(KEY_IDX nIdx);

    bool eventFilter( QObject *obj, QEvent *e);

    void showButton(KEY_IDX nIdx, bool bShow);

    //bool isButtonShow(KEY_IDX nIdx);

    void setButtonEnable(KEY_IDX nIdx, bool enable);

    bool isButtonEnabled(KEY_IDX nIdx);

    void setBgOverlapPixmap(KEY_IDX nIdx, const QPixmap& pmap, int alpha);

    virtual QSize sizeHint() const;

    virtual void setPalette( const QPalette & pal );

    void setTextForOptMenuHide(const QString& text);
    //QString textForOptMenuHide();

    void setTextForOptMenuShow(const QString& txtForHasOptMenu, const QString& txtForHasNoOptMenu);
    //void textForOptMenuShow(QString&  txtForHasOptMenu, QString& txtForHasNoOptMenu);

    ~ZSoftKey();

    //void setWidgetPixmapPrefix(QString& prefix );

public slots:
    void slotBtnClicked(KEY_IDX nIdx);

    void slotBtnPressed(KEY_IDX nIdx);

    void slotBtnReleased(KEY_IDX nIdx);

//protected slots:
    //void slotLeftKeyPressed();
    //void slotLeftKeyReleased();
    //void slotRightKeyPressed();
    //void slotRightKeyReleased();
    //void slotMenuHide();
    //void slotMenuShow();

protected:
    //void updateFont(QFont* pFont, const FONT_INFO_T& fntInfo);
    //void initFont();
    //bool initBtn(const QString& type);

    void setCstR();

    //bool parseType(const QString& type);

    bool createBtn();

    //void setBtnGeometry();
    //bool handleShortcutKeyThreeBtn(int key, bool bKeyPressed);
    //bool handleShortcutKeyTwoBtn(int key, bool bKeyPressed);
    //bool handleShortcutKeyOneBtn(int key, bool bKeyPressed);
    //bool handleDefaultKey();

    void setTextSelfShow(int op);

    virtual void paintEvent(QPaintEvent*);

    //void hideButton(QPainter* p, ZSoftButton* pBtn);

    void connectKeySignalToSlot(ZOptionsMenu* optMenu);

    void connectSubMenuToSlot(ZOptionsMenu* optMenu);
protected:
    //bool handleShortcutKey(int key, bool bKeyPressed);
    //bool handleBtnBySK(KEY_IDX nIdx, bool bKeyPressed, bool bSendSignal = true);
    //void reparent (QWidget * parent, WFlags, const QPoint &, bool showIt=FALSE);
    //void setKeyEventWatcher( QWidget *watcher);

    virtual void resizeEvent(QResizeEvent*);

    //void setBgTransparentFB1(int alpha);

private:
    ZSoftKey(const ZSoftKey&);
    ZSoftKey& operator=(const ZSoftKey&);

//private:
//    ZSoftKeyPrivate* d;
};
#endif
