#ifndef _ZPRESSBUTTON_H
#define _ZPRESSBUTTON_H 1

#include <qwidget.h>
#include <ZBaseButton.h>
#include <ZSkinBase.h>

/* Size <= 312=78*4 */

class ZPressButton : public ZBaseButton
{
    Q_OBJECT
    unsigned int data[78 - sizeof(ZBaseButton)/4];

public:
    virtual void setToggleButton(bool);
    virtual void setOn(bool);

    enum TitlePosition {
    };

    ZPressButton(QPixmap const&, QString const&, QWidget*, char const* name = 0, ZSkinService::WidgetClsID = ZSkinService::clsZPressButton);
    ZPressButton(QString const&, QWidget*, char const* name = 0, ZSkinService::WidgetClsID = ZSkinService::clsZPressButton);
    ZPressButton(QWidget*, char const* name = 0, ZSkinService::WidgetClsID = ZSkinService::clsZPressButton);
	~ZPressButton();

	void alignment() const;
	void drawButton(QPainter*);
	virtual void drawButtonLabel(QPainter*);
	void focusInEvent(QFocusEvent*);
	void focusOutEvent(QFocusEvent*);
	void getBtnFrameWidth(int&, int&, int&, int&) const;
	void getContentRect() const;
	void getFrameWidth(int&, int&, int&, int&) const;
	void isZDisabled();
	void isZEnabled();
	void keyPressEvent(QKeyEvent*);
	void keyReleaseEvent(QKeyEvent*);
	void pixmap() const;
	void reAdjustSize(bool, int, int);
	void relativeAlignment() const;
	void resize(QSize const&);
	void resize(int, int);
	void resizeEvent(QResizeEvent*);
	void selectionStateChanged(ZSkinBase::SelectionState);
	void setAlignment(Qt::AlignmentFlags);
	void setAvailableWidth(int);
	void setEnabled(bool);
	void setFont(QFont const&);
	void setFontColor(QColor const&);
	void setGeometry(QRect const&);
	void setGeometry(int, int, int, int);
	void setPalette(QPalette const&);
	void setPixmap(QPixmap const&);
	void setRelativeAlignment(ZSkinBase::RelativeAlignment);
	void setState(ZSkinBase::SelectionState);
	virtual void setText(QString const&);
	void setTitle(QString const&);
    QString title() const;	
	void setTitlePosition(ZPressButton::TitlePosition);
	QSize sizeHint() const;
	void text() const;
	void titlePosition() const;
	void toggle();
	void truncateHead(QString const&, int, unsigned int, QFont const&, QString);
	void truncateTail(QString const&, int, unsigned int, QFont const&, QString);
	void updateSkin(bool);
};

#endif
