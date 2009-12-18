#ifndef ZLINEEDIT_H
#define ZLINEEDIT_H

#include "ZFormItem.h"
#include "qstring.h"
#include "ZSkinService.h"
#include "ZKbInputField.h"
#include "tslayout.h"
#define LTR_MARK 0x200E;
#define RTL_MARK 0x200F;
#define isOdd(x) (x % 2)
#define isEven(x) (!(x % 2))

class ZLineEditPrivate;
class QValidator;
class ZScrollPanel;

class ZLineEdit : public ZFormItem
{
    Q_OBJECT
	
public:
   enum    TitlePosition
   {
       TitleTop,
       TitleLeft
   };
   enum  EchoMode 
   {
        Normal,
        NoEcho,
        Password 
   };
   enum InsertionMethod
   {
        Begin,  
        End,      
        Selection 
   };
   enum CursorFlagDirection 
   {
	CF_RTL,
	CF_LTR 
   };
   enum CursorFlagExist
   {
	CF_NONE,
	CF_YES
    };
   enum InputContext
   {
        IC_NONE,
        IC_SCROLLING,
        IC_TEXT_INPUT
   };
   enum InitAutoAlign
   {
        AlignmentLeft,
        AlignmentRight
   };

    ZLineEdit( QWidget *parent, const char *name=0,
            const ZSkinService::WidgetClsID clsId = ZSkinService::clsZLineEdit);
    ZLineEdit( const QString &, QWidget *parent, const char *name=0,
               const ZSkinService::WidgetClsID clsId = ZSkinService::clsZLineEdit);
    ~ZLineEdit();
    QString text() const;
    QString textWithPredict() const;
    QString displayText() const;
    QString phonenoText() const;
    int  maxLength()	const;
    virtual void setMaxLength( int );
    virtual void setFontPercent(float rate);
    virtual void setFrame( bool enable );
    bool frame() const;
    virtual void setEchoMode( EchoMode mode);
    ZLineEdit::EchoMode echoMode() const;
    TitlePosition titlePosition() const {return mTitlePos;}
    void setTitlePosition(TitlePosition titlePos);
    QString title() const {return mTitle;}
    void setTitle(const QString & titleStr);
    void setReadOnly( bool enable);//virtual
    bool isReadOnly() const;
    virtual void setValidator( const QValidator *v );
    const QValidator* validator() const;
    QSize	sizeHint() const;
    QSize	minimumSizeHint() const;
    QSizePolicy sizePolicy() const;
    virtual void setFont( const QFont & );
    virtual void setSelection( int start, int length);
    void setCursorFlagDirection(CursorFlagDirection d); 
    void setInitAutoAlign(InitAutoAlign align);
    void setCursorFlagExist(CursorFlagExist d); 
    int  heightViewed() const;    
private:
    void scrollN(QKeyEvent* e);

    InitAutoAlign initAlign;
    CursorFlagExist cursFlag;
    CursorFlagDirection cursFlagDirection;
    InputContext inputContext;

public:
    virtual void setCursorPosition( int newPos );
    int cursorPosition() const;
    bool validateAndSet( const QString &newText, int newPos, int newMarkAnchor, int newMarkDrag);
    void setAlignment( int flag );
    int alignment() const;
    void cursorLeft( bool mark);
    void cursorRight( bool mark);
    void        backspaceNew();
    void cursorRightFinish( bool mark, int cp );
    void  cursorWordForward( bool mark );
    void  cursorWordBackward( bool mark );
    void  backspace();
    void  del();
    void home( bool mark );
    void  end( bool mark );
    void  setEdited( bool on);
    bool  edited() const;
    bool  hasMarkedText() const;
    QString  markedText() const;
    void setOffsetCursor(bool on);
    ZKbInputField  *getInputField();
    void  emitTextChanged();
    int  calCursorPos( int col , int len );
    QPoint  cursorPoint();
    void setPreferredWidth(int nWidth);
    int  getPreferredWidth() const;
    void setPredefinedNumbers(int nCount);
    int  getPredefinedNumbers( ) const;
    bool autoResize () const;
    void setAutoResize ( bool enable );
    void setInsertionMethod( enum InsertionMethod nSelection );
    void setEchoModeWhenNoFocus( EchoMode  mode );
    void setEchoModeWhenHasFocus( EchoMode  mode );
    ZLineEdit::EchoMode echoModeNoFocus() const;
    ZLineEdit::EchoMode echoModeHasFocus() const;
    virtual void setEnabled(bool enable);
    bool isZEnabled();
    bool isZDisabled();
    QStringList wrapText(QString,int);

public slots:
    virtual void setText( const QString &text);
    void  selectAll();
    void  deselect();
    void  clearValidator();
    void insert( const QString &);
    void        insertNew( const QString &);
    bool     isLTRBidiClass(TsBidiCharClass);
    bool     isRTLBidiClass(TsBidiCharClass);
    bool     isNumericBidiClass(TsBidiCharClass);
    bool     isNeutralBidiClass(TsBidiCharClass); 
    void  clear();

signals:
    void  textChanged( const QString &);
    void committedTextChanged( const QString &keyword);
    void  returnPressed();

protected:
    enum ItemType
    {
       FormItem,
       Label,
       Widget
    };
    enum StateChangeReason
    {
       RFocusIn,
       RFocusOut,
       RKeyPress,
       RKeyRelease
    };
    bool  event( QEvent * );
    void  mousePressEvent( QMouseEvent * );
    void  mouseMoveEvent( QMouseEvent * );
    void  mouseReleaseEvent( QMouseEvent * );
    void  mouseDoubleClickEvent( QMouseEvent * );
    void  keyPressEvent( QKeyEvent * );
    void  focusInEvent( QFocusEvent * );
    void  focusOutEvent( QFocusEvent * );
    void  paintEvent( QPaintEvent * );
    void  resizeEvent( QResizeEvent * );
    void  leaveEvent( QEvent * );
    QSize  getTitleSize() const;
    QRect  getTitleRect() const;
    QRect  getEditAreaRect() const;
    QRect  getContentRect() const;
    int  getContentWidth() const;
    int  getContentHeight() const;
    int  getPaddingWidth() const;
    int  getPaddingHeight() const;
    QRect  getFieldRect() const;
    void  stateChanged(StateChangeReason stChangeReason);
    void  titleChanged(const QString & title);
    void  getCurrentFont(QFont & font, QColor & ftColor, ItemType itemType) const;
    void  getFrameWidth(int & nleftw, int & nrightw, int & ntopw, int & nbottomw) const;
    void  updateSkin(bool redraw);
    virtual void setPalette(const QPalette &);
    void  repaintArea( int, int );
    int  offset;

private slots:
    void  clipboardChanged();
    void  blinkSlot();
    void  dragScrollSlot();
    void  fastDelTimerTimeout();

private:
    void  newMark( int pos, bool copy=TRUE );
    void  markWord( int pos );
    int  lastCharVisible() const;
    int  minMark() const;
    int  maxMark() const;
    int  frameW() const;
    void  init();
    void updateOffset();
    int xPosToCursorPos( int ) const;
    void blinkOn();
    void makePixmap() const;
    void undoInternal();
    void redoInternal();
    void setMode(EchoMode mode);
    ZLineEdit( const ZLineEdit & );
    ZLineEdit &operator=( const ZLineEdit & );
    int getUnderlineWidth() const;
    int getAlterIconHeight() const;
    bool isHyphenAuto() const;

    int  getRealMaxLen() const;
    QString	tbuf;
    ZLineEditPrivate* d;
    int  cursorPos;
    int  maxLen;
    int  markAnchor;
    int  markDrag;
    bool  cursorOn;
    bool  dragScrolling;
    bool  scrollingLeft;
    int  alignmentFlag;
    bool  ed;
    bool  offsetCursor;
    QString mTitle;
    TitlePosition mTitlePos;
    int  m_nSelection;
    bool isPasswordSelection;

public:
    void setScrollParent(ZScrollPanel *);
    void ensureDisplayed();
};
#endif // __ZLINEEDIT_H__
