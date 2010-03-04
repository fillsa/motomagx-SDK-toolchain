//Create by Ant-ON, 2010

#include <ZMyConfig.h>

#ifndef EZX_U9
//Only for ZN5

#ifndef ZSOFTKEYL_H   
#define ZSOFTKEYL_H

#include <ZSoftKey.h>

class ZSoftKeyL : public ZWidget
{
	uint fix[10]; //Fix small incorrect header
    Q_OBJECT
public:
	ZSoftKeyL(const QString& type, QWidget* parent, QWidget *watcher = 0);
	~ZSoftKeyL();

	void setButtonDown(ZSoftKey::KEY_IDX nIdx, bool);	
	void setText(KEY_IDX nIdx , const QString& str, TEXT_PRIORITY prior = ZERO);
	
	//??
	void showSoftkey();
	void hide();
	void hideSoftkey();
	void setAlpha(int);
	void setMenuPopup(bool);
	//

protected:
	bool parseType(const QString& type);
	bool createBtn();
	void setCstR(); 
	void connectKeySignalToSlot(ZOptionsMenu* optMenu);
	bool handleShortcutKeyOneBtn(int key, bool bKeyPressed);
	
	void paintEvent(QPaintEvent*);
	void resizeEvent(QResizeEvent*);
	
	//??
	void rSoftkeyUpLOnSoftkey();
	void sigFadeOutComplete();
	void sigFadeInComplete();
	//
	
public slots:
	void slotFadeIn();
	void slotFadeOut();
	void slotRightKeyReleasedL();

private:
    ZSoftKeyL(const ZSoftKeyL&);
    ZSoftKeyL& operator=(const ZSoftKeyL&);

};

#endif
#endif
