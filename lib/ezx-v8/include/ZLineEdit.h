#ifndef _ZLINEEDIT_H_
#define _ZLINEEDIT_H_

#include <ZWidget.h>

class QValidator;
class TsGlyphInfo;
class QFont;
class ZFontInfo;
class QEvent;

/* Size: 380=95*4 */

class ZLineEdit : public ZWidget
{
    Q_OBJECT
    unsigned int data[96-sizeof(ZWidget)/4];

public:
    enum	EchoMode { Normal, NoEcho, Password };
    enum	ItemType {
    };
    enum	CursorFlagDirection {
    };
    enum	InsertionMethod {
    };
    enum	TitlePosition {TitleTop, TitleLeft
    };
    enum	StateChangeReason {
    };

    virtual void setMaxLength(int);
    virtual void setFontPercent(float);
    virtual void setFrame(bool);
    virtual void setEchoMode(EchoMode);
    virtual void setValidator(QValidator const*);
    virtual void setSelection(int, int);
    virtual void setCursorPosition(int);
    virtual void setText(QString const&);

     ZLineEdit( QWidget *parent, const char *name=0, const ZSkinService::WidgetClsID clsId = ZSkinService::clsZLineEdit);
     ZLineEdit( const QString &, QWidget *parent, const char *name=0, const ZSkinService::WidgetClsID clsId = ZSkinService::clsZLineEdit);
    ~ZLineEdit();

	void alignment() const;
	void autoAlignment();
	void autoResize() const;
	void backspace();
	void blinkSlot();
	void calCursorPos(int, int);
	void clear();
	void clearValidator();
	void clipboardChanged();
	void cursorChanged(int, int);
	void cursorLeft(bool);
	void cursorPoint();
	void cursorPosition() const;
	void cursorRight(bool);
	void cursorRightFinish(bool, int);
	void cursorWordBackward(bool);
	void cursorWordForward(bool);
	void del();
	void deselect();
	void displayText() const;
	void displayTextWidth(int, int, int);
	void doControlKeyPress(QKeyEvent*, bool);
	void doModalStatusKeyPress(QKeyEvent*, bool&);
	void doSelectKeyPress(QKeyEvent*, bool);
	void dragScrollSlot();
	void echoMode() const;
	void echoModeHasFocus() const;
	void echoModeNoFocus() const;
	void edited() const;
	void emitTextChanged();
	void end(bool);
	bool event(QEvent*);
	void fastDelTimerTimeout();
	void focusInEvent(QFocusEvent*);
	void focusOutEvent(QFocusEvent*);
	void frame() const;
	void getAlterIconHeight() const;
	QRect getContentRect() const;
	void getCurrentFont(QFont&, QColor&, ZLineEdit::ItemType) const;
	void getEditAreaRect() const;
	void getFieldRect() const;
	void getFrameWidth(int&, int&, int&, int&) const;
	void getInputField();
	void getPaddingHeight() const;
	void getPaddingWidth() const;
	void getPredefinedNumbers() const;
	void getPreferredWidth() const;
	QRect getTitleRect() const;
	QSize getTitleSize() const;
	void getUnderlineWidth() const;
	void glyphRegion(TsGlyphInfo const&, int, int);
	void hasMarkedText() const;
	void home(bool);
	void insert(QString const&);
	void isReadOnly() const;
	void isZDisabled();
	void isZEnabled();
	void keyPressEvent(QKeyEvent*);
	void leaveEvent(QEvent*);
	void markedText() const;
	void maxLength() const;
	QSize minimumSizeHint() const;
	void mouseDoubleClickEvent(QMouseEvent*);
	void mouseMoveEvent(QMouseEvent*);
	void mousePressEvent(QMouseEvent*);
	void mouseReleaseEvent(QMouseEvent*);
	void paintEvent(QPaintEvent*);
	void phonenoText() const;
	void prepareTsMarkRegion(int, int, int, int, int, QString const&);
	void repaintArea(int, int);
	void resizeEvent(QResizeEvent*);
	void returnPressed();
	void selectAll();
	void setAlignment(int);
	void setAutoResize(bool);
	void setCursorFlagDirection(CursorFlagDirection);
	void setEchoModeWhenHasFocus(EchoMode);
	void setEchoModeWhenNoFocus(EchoMode);
	void setEdited(bool);
	void setEnabled(bool);
	void setFont(QFont const&);
	void setInsertionMethod(InsertionMethod);
	void setOffsetCursor(bool);
	void setPalette(QPalette const&);
	void setPredefinedNumbers(int);
	void setPreferredWidth(int);
	void setReadOnly(bool);
	void setTitle(QString const&);
	void setTitlePosition(TitlePosition);
	void setZEnabled(bool);
	QSize sizeHint() const;
	QSizePolicy sizePolicy() const;
	void specialInputModeCursorModel(bool);
	void stateChanged(StateChangeReason);
	void tbufChange();
	QString text() const;
	void textChanged(QString const&);
	void titleChanged(QString const&);
	void updateFontInfo(QFont&, ZFontInfo const&);
	void updateSkin(bool);
	void validateAndSet(QString const&, int, int, int);
	QValidator *  validator() const;
	void wrapText(QString, int);
	void wtlePaintCell(QPainter&);
};

#endif
