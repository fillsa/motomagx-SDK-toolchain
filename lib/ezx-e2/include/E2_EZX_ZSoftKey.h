//This file is create by lasly
//u can use it to create e2 native program
//and u can find my blog in http://my.opera.com/Lasly
// e2_ezx_sdk_0.01

// ZSoftKey 下面凡是以？开头的注释都是猜测的用途，没有经过测试

// _ZN8ZSoftKeyC4ERK7QStringP7QWidgetS4_
// _ZN8ZSoftKeyD4Ev

#ifndef _E2_EZX_ZSOFTKEY_H
#define _E2_EZX_ZSOFTKEY_H

#include <qstring.h>
#include <qwidget.h>
#include <qobject.h>
#include <qevent.h>
#include <E2_EZX_ZWidget.h>
#include <E2_EZX_ZOptionsMenu.h>

class ZSoftKey : public ZWidget
{
	Q_OBJECT
	char tmp[4096];
public:
	enum KEY_IDX
	{
		LEFT,
		RIGHT,
	};
	enum TEXT_PRIORITY
	{
		NONE
	};
	ZSoftKey(QString const&, QWidget*, QWidget*);
	void setText(ZSoftKey::KEY_IDX, QString const&, ZSoftKey::TEXT_PRIORITY);
	void setClickedSlot(ZSoftKey::KEY_IDX, QObject const*, char const*);
	void setOptMenu(ZSoftKey::KEY_IDX, ZOptionsMenu*);
	ZOptionsMenu* getOptMenu(ZSoftKey::KEY_IDX);
	void disableClickedSlot(ZSoftKey::KEY_IDX);
	void enableClickedSlot(ZSoftKey::KEY_IDX);
	~ZSoftKey();

public slots:
	void slotBtnClicked(ZSoftKey::KEY_IDX);
	void slotBtnPressed(ZSoftKey::KEY_IDX);
	void slotBtnReleased(ZSoftKey::KEY_IDX);
	void slotLeftKeyPressed();
	void slotLeftKeyReleased();
	void slotMenuHide();
	void slotMenuShow();
	void slotRightKeyPressed();
	void slotRightKeyReleased();
	/*
	void connectKeySignalToSlot(ZOptionsMenu*);
	void connectSubMenuToSlot(ZOptionsMenu*);
	void createBtn();
	bool eventFilter(QObject*, QEvent*);<img src="<img src="<img src="">">">
	ZOptionsMenu* getOptMenu(ZSoftKey::KEY_IDX);
	void handleBtnBySK(ZSoftKey::KEY_IDX, bool, bool);
	void handleDefaultKey();
	void handleShortcutKey(int, bool);
	void handleShortcutKeyOneBtn(int, bool);
	void handleShortcutKeyThreeBtn(int, bool);
	void handleShortcutKeyTwoBtn(int, bool);
	void hideButton(QPainter*, ZSoftButton*);
	void initBtn(QString const&);
	void initFont();
	bool isButtonEnabled(ZSoftKey::KEY_IDX);
	bool isButtonShow(ZSoftKey::KEY_IDX);
	void paintEvent(QPaintEvent*);
	void parseType(QString const&);
	void prevClickedSlot(ZSoftKey::KEY_IDX);
	void prevResourceID(ZSoftKey::KEY_IDX);
	CString prevText(ZSoftKey::KEY_IDX);
	void reparent(QWidget*, unsigned, QPoint const&, bool);
	void resizeEvent(QResizeEvent*);
	void setBgOverlapPixmap(ZSoftKey::KEY_IDX, QPixmap const&, int);
	void setBtnGeometry();
	void setButtonEnable(ZSoftKey::KEY_IDX, bool);
	void setCstR();
	void setKeyEventWatcher(QWidget*);
	void setPalette(QPalette const&);
	void setResourceID(ZSoftKey::KEY_IDX, QString const&, ZSoftKey::TEXT_PRIORITY);
	void setText(ZSoftKey::KEY_IDX, QString const&, ZSoftKey::TEXT_PRIORITY);
	void setTextSelfShow(int);
	void showButton(ZSoftKey::KEY_IDX, bool);
	void sizeHint();
	int updateFont(QFont*, ZFontInfo const&);
	*/
};

#endif
