#ifndef ZSOFTKEY_H   
#define ZSOFTKEY_H

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

class ZSoftKey : public ZWidget
{
    Q_OBJECT
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
    void setClickedSlot(KEY_IDX nIdx,
                        const QObject* receiver,
                        const char* member);
    void prevClickedSlot(KEY_IDX nIdx);
    void disableClickedSlot(KEY_IDX nIdx);
    void enableClickedSlot(KEY_IDX nIdx);
    void showButton(KEY_IDX nIdx, bool bShow);
    void setButtonEnable(KEY_IDX nIdx, bool enable);
    bool isButtonEnabled(KEY_IDX nIdx);
    void setBgOverlapPixmap(KEY_IDX nIdx, const QPixmap& pmap, int alpha);
	void setTextForOptMenuShow(const QString& txtForHasOptMenu, const QString& txtForHasNoOptMenu);
    void setTextForOptMenuHide(const QString& text);
    ~ZSoftKey();
	
	//~~~~~~~~~~~
    void setButtonDown(KEY_IDX nIdx, bool);	
	//~~~~~~~~~~~
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
    void setTextSelfShow(int op);
    void hideButton(QPainter* p, ZSoftButton* pBtn);

private:
    ZSoftKey(const ZSoftKey&);
    ZSoftKey& operator=(const ZSoftKey&);
 
private:
    ZSoftKeyPrivate* d;
};
#endif
