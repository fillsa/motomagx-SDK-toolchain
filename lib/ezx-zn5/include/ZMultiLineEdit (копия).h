//Fix for Motorola ZN5 by Ant-ON, 2009
//Fix for ZN5/U9 by Ant-ON, 25-10-2010

// Copyright (c) 27-Apr-07 - 2008 Motorola, Inc. All rights reserved.

#ifndef Z_MULTILINE_H
#define Z_MULTILINE_H

#include <qtableview.h>
#include <qstring.h>
#include <qlist.h>
#include <qregexp.h>
#include <ZTableView.h>
#include <tslayout.h>

struct ZMultiLineData;
class ZMultiLineEditCommand;
class QValidator;
struct  ZKbInputField;
class ZSkinBase;

class Q_EXPORT ZMultiLineEdit : public ZTableView
{
	//uint data[50];
	unsigned int data[126-sizeof(ZTableView)/4];
	
    Q_OBJECT

public:
   enum CursorFlagExist 
   {
	CF_NONE,
	CF_YES
    };
    enum CursorFlagDirection 
    {
	CF_RTL,
	CF_LTR
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
    enum EchoMode 
    { 
       Normal, 
       NoEcho, 
       Password 
    };
    enum InsertionMethod
    {
       Begin,    
       End,       
       Selection,  
	   atPosNoSelected 
    };
    enum WordWrap 
    {
        NoWrap,   
        WidgetWidth,
        FixedPixelWidth,
        FixedColumnWidth
    };
    enum WrapPolicy 
    {
        AtWhiteSpace,   
        Anywhere  
    };
    enum TitlePosition 
    { 
    	Unknown = 0, 
    	TitleTop, 
    	TitleLeft 
    };
    ZMultiLineEdit( QWidget* parent=0, const char* name=0);
    ZMultiLineEdit( QWidget* parent,bool EZXStyle,int lines = 1,const char* name=0 );
    virtual ~ZMultiLineEdit();
    int getIndent();
    int getLineHeight() const;
    void setUnderline( bool needUnderline = true );
    bool getUnderline();
    void setFilter( const QRegExp& filter, bool match = false );
    const QRegExp& getFilter() const;
    QString textLine( int line ) const;
    int numLines() const;
    QSize sizeHint() const;
    QSize minimumSizeHint() const;
    QSizePolicy sizePolicy() const;
    virtual void setFont( const QFont &font );
    void setInitAutoAlign(InitAutoAlign align);
    void setCursorFlagExist(CursorFlagExist d);
    virtual void insertLine( const QString &s, int line = -1 );
    virtual void insertAt( const QString &s, int line, int col, bool mark = FALSE );
    virtual void removeLine( int line );
    void setCursorFlagDirection(CursorFlagDirection d);
    virtual void setCursorPosition( int line, int col, bool mark = FALSE );
    void getCursorPosition( int* line, int* col ) const;
    bool atBeginning() const;
    bool atEnd() const;
    virtual void setFixedVisibleLines( int ln );
    virtual void setValidator( const QValidator * );
    const QValidator* validator() const;
    void setEdited( bool );
	bool edited() const {return true;};//For compobility
    void cursorWordForward( bool mark );
    virtual void setInsertionMethod( InsertionMethod nSelection );
    virtual void setEchoMode( EchoMode );
    EchoMode echoMode() const;
    void setMaxLength( int m );
    virtual void setFontPercent(float rate);
    int maxLength() const;
    virtual void setMaxLineLength( int m );
    int maxLineLength() const;
    virtual void setMaxLines( int m );
    virtual void setHMargin( int m );
    int hMargin() const;
    virtual void setSelection( int row_from, int col_from, int row_to, int col_to );
    void setWordWrap( WordWrap mode );
    void setWrapPolicy( WrapPolicy policy );
    virtual void setAutoUpdate( bool enable );
    bool isReadOnly() const;
    QString text() const;
    QString phonenoText() const;
    int length() const;
    virtual void show();
    void setTitlePosition(TitlePosition titlePos);
    void setTitle(const QString & titleStr);
    virtual void  resetFocusItem(bool);
    virtual QRect getCurrentFocusRect();
    virtual bool  hasNextPrevFocusItem(bool);
    bool nestScrollPanelMode() const;
    QString getRowString(int i);
    int getLineCount();
    QString getLineContent( int line );
    ZKbInputField*  getInputField();
    void insertString_if( QPoint pos, QString text ); 
    int getInputModeCursorModel(void);
    void backspaceNew(void);
    void insertAtNew( const QString &, int, int, bool);

public slots:
    virtual void changeContentSize( int lines,QPoint cursorPos );
    virtual void setText( const QString &s );
    virtual void setReadOnly( bool on );
    virtual void setZEnabled(bool enable);
    virtual void setOverwriteMode( bool on );
    void      clear();
    void append( const QString &s );
    void       selectAll();
    void       deleteText();
    void insert( const QString& s );

signals:
    void    textTrancated();
    void    textChanged();
    void contentsResizing(ZMultiLineEdit* , int width, int height);
    
protected:
    void    updateMask();
    void    paintEvent(QPaintEvent* );
	int paintCell_if( QPainter* p , int row , int underlineI , bool underlineHit , int reverseI ,\
                      bool reverseHit , int yPos , int x , QString s , QFontMetrics fm , QRect updateR , QColorGroup g );
    void    paintCell( QPainter *, int row, int col, int xPos, int yPos );
    virtual void drawLineText( QPainter* painter, int x, int y, int width,
                               int height, int flags, const QString& lineStr, int row = 0 , int col = 0);
    virtual void drawTableFrame(QPainter*  p, QRect & updateR);
    bool event( QEvent * );
    void    mousePressEvent( QMouseEvent * );
    void    mouseMoveEvent( QMouseEvent * );
    void    mouseReleaseEvent( QMouseEvent * );
    void    mouseDoubleClickEvent( QMouseEvent * );
    void    wheelEvent( QWheelEvent * );
    void    keyPressEvent( QKeyEvent * );
    void keyReleaseEvent(QKeyEvent * );
    void    focusInEvent( QFocusEvent * );
    void    focusOutEvent( QFocusEvent * );
    void    timerEvent( QTimerEvent * );
    void    leaveEvent( QEvent * );
    void    resizeEvent( QResizeEvent * );
    bool    focusNextPrevChild( bool );
    int	    textWidthWithTabs( int lineNo );
    int	    textWidth( int lineNo = -1 );
    virtual void insert( const QString& c, bool mark );
    virtual void newLine();
    virtual void killLine();
    virtual void pageUp( bool mark=FALSE );
    virtual void pageDown( bool mark=FALSE );
    virtual void cursorLeft( bool mark=FALSE, bool wrap = TRUE );
    virtual void cursorRight( bool mark=FALSE, bool wrap = TRUE );
    virtual void cursorUp( bool mark=FALSE );
    virtual void cursorDown( bool mark=FALSE );
    virtual void cursorMove(bool down);
    virtual void backspace();
    virtual void del();
    virtual void home( bool mark=FALSE );
    virtual void end( bool mark=FALSE );
    bool getMarkedRegion( int* line1, int* col1,
                          int* line2, int* col2 ) const;
    int lineLength( int row ) const;
    QString* getString( int row ) const;
    QString stringShown( int row ) const;
    virtual void setPalette(const QPalette &);
    void insertChar( QChar c );
    void  clearUndoList();
    int   getTruncateCount();   
    bool  cursorOn;

private:
    enum LineType
    {
        Empty_Line = 0,
        Color_Line,
        Pixmap_Line
    };
    enum TextType
    {
        Title = 0,
        Field
    };
    enum eParaAlignment
    {
    	DIR_UNKNOWN,
    	LTR,
    	RTL
    };

    struct ZMultiLineEditRow 
    {
        ZMultiLineEditRow( QString string, int width, bool nl = TRUE, bool old = FALSE, eParaAlignment dir = DIR_UNKNOWN )
            :s(string), w(width), newline( nl ), overrideLineDirection( old ), direction( dir ) 
            {
            };
        QString s;
        int w;
        bool newline;
        bool overrideLineDirection;
        eParaAlignment direction;
    };
    
	//????????????????????????
	void doEnterCharBreak(ZMultiLineEditRow*&, int, bool, int, int&, int&, int&, int&, int&, int&, QString&);
	void handleEzxInsertString(ZMultiLineEditRow*, QString const&, int);
	void handleNormalInsertString(ZMultiLineEditRow*, QString const&, int, int);
	void insertAtSpecialEzxStyle(QString const&, int);
	void rebreakLines(ZMultiLineEditRow*&, TsLayoutInfo&, TsLayout_*, int, int&, int&, QString const&, QString const&);
	//????????????????????????
	
    void setTitlePositionAux(const QString& /*oldTitle*/, int from);
    QRect getFormItemTopArea();
    QRect getFormItemLeftArea();
    QRect getFormItemRightArea();
    QRect getFormItemBottomArea();
    QRect getMDTopArea();
    QRect getMDBottomArea();
    QRect getMDLeftArea();
    QRect getMDRightArea();
    QRect getEditArea();
    int getContentsWidth();
    void   pasteSpecial(const QPoint&);
    int     getOffset(int row);
    void    cursorLeft( bool mark, bool clear_mark, bool wrap );
    void    cursorRight( bool mark, bool clear_mark, bool wrap );
    void    cursorUp( bool mark, bool clear_mark );
    void    cursorDown( bool mark, bool clear_mark );
    void    insertAtAux( const QString &s, int line, int col, bool mark = FALSE );
    void    killLineAux();
    void    delAux();
    void    deleteNextChar( int offset, int row, int col );
    void    deleteWord();
    void    addUndoCmd( ZMultiLineEditCommand* );
    void    addRedoCmd( ZMultiLineEditCommand* );
    void    processCmd( ZMultiLineEditCommand*, bool );
    int getHeight() const;
    int getWidth() const;
    QSize getTitleSize() const;
    void getFrameWidth(int & nleft, int & nright, int & ntop, int & nbottom);
    void getMDFrameWidth(int & nleft, int & nright, int & ntop, int & nbottom);
    void getSkinFont(QFont & font, QColor & color, TextType type) const;
    void updateSkin(bool redraw);
    QPixmap* getPixmap(const SelectionState state);
    void getLinePixSuffixName(const SelectionState state, QString & suffix);
    int getCursorOffset(int cursorRow, int cursorCol);
    void getCorsorPosition(int & cursorRow, int & cursorCol, int cursorOffset);
    int getCursorState();
    int getParaAlignment(void);
    void overrideLineDirection(int line, eParaAlignment dir, int removed);
    ZMultiLineEdit( const ZMultiLineEdit & );
    ZMultiLineEdit &operator=( const ZMultiLineEdit & );
    QList<ZMultiLineEditRow>*  contents;
    ZMultiLineData*   d;
    int     indent;
    QSize   hint;
    bool    ezx_style;
    int     lines;
    int     minLines;
    bool    underline;
    bool    readOnly;
    bool    dummy;
    bool    markIsOn;
    bool    dragScrolling ;
    bool    dragMarking;
    bool    textDirty;
    bool    wordMark;
    bool    overWrite;
    bool    isCursorOn;
    int     cursorX;
    int     cursorY;
    int     markAnchorX;
    int     markAnchorY;
    int     markDragX;
    int     markDragY;
    int     curXPos;
    int     scrollTimer; 
    InitAutoAlign initAlign;
    CursorFlagExist cursFlag;
    CursorFlagDirection cursFlagDirection;
    InputContext inputContext;
};
#endif







