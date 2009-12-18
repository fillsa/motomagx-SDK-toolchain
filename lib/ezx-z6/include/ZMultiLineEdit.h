#ifndef Z_MULTILINE_H
#define Z_MULTILINE_H

#ifndef QT_H
#include "qtableview.h"
#include "qstring.h"
#include "qlist.h"
#include "qregexp.h"
#endif // QT_H
#include "ZTableView.h"

//#include "tslayout.h"
struct ZMultiLineData;
class ZMultiLineEditCommand;
class QValidator;
struct  ZKbInputField;
class ZSkinBase;

class TsGlyphInfo;
class TsLayoutInfo;
class TsLayout;
class TsBidiCharClass;
class TsCoord;
class TsText;

class Q_EXPORT ZMultiLineEdit : public ZTableView                                                            
{
    Q_OBJECT
        public:

    ZMultiLineEdit( QWidget *parent=0, const char *name=0);
    ZMultiLineEdit( QWidget *parent,bool EZXStyle,int lines = 1,const char *name=0 );
    virtual ~ZMultiLineEdit();
    void setIndent( int idt );
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
    virtual void insertLine( const QString &s, int line = -1 );
    virtual void insertAt( const QString &s, int line, int col, bool mark = FALSE );
    virtual void removeLine( int line );

    enum CursorFlagDirection {
	CF_NONE,
	CF_RTL,
	CF_LTR
    };
    void setCursorFlagDirection(CursorFlagDirection d);

  private:
    enum TextBufferDirection {
        TB_NONE,
        TB_LTR,
        TB_RTL
    };

    CursorFlagDirection cursFlag;
    TextBufferDirection tbufDirection;

  public:
    void cursorPosition( int *line, int *col ) const;
    virtual void setCursorPosition( int line, int col, bool mark = FALSE );
    void getCursorPosition( int *line, int *col ) const;
    bool atBeginning() const;
    bool atEnd() const;
    virtual void setFixedVisibleLines( int ln );
    int maxLineWidth() const;
    void setAlignment( int flags );
    int alignment() const;
    virtual void setValidator( const QValidator * );
    const QValidator * validator() const;
    void setEdited( bool );
    bool edited() const;
    void cursorWordForward( bool mark );
    void cursorWordBackward( bool mark );
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

     virtual void setInsertionMethod( InsertionMethod nSelection );
     virtual void setEchoMode( EchoMode );
     EchoMode echoMode() const;
     void setMaxLength( int m );
     virtual void setFontPercent(float rate);
    int maxLength() const;
    virtual void setMaxLineLength( int m );
    int maxLineLength() const;
    virtual void setMaxLines( int m );
    int maxLines() const;
    virtual void setHMargin( int m );
    int hMargin() const;
    virtual void setSelection( int row_from, int col_from, int row_to, int col_to );
    enum WordWrap 
        {
            NoWrap,   
            WidgetWidth,
            FixedPixelWidth, 
            FixedColumnWidth 
        };

    void setWordWrap( WordWrap mode );
    WordWrap wordWrap() const;
    void setWrapColumnOrWidth( int value );
    int wrapColumnOrWidth() const;
    enum WrapPolicy 
        {
            AtWhiteSpace,
            Anywhere
        };
    void setWrapPolicy( WrapPolicy policy );
    WrapPolicy wrapPolicy() const;
    bool autoUpdate()   const;
    virtual void setAutoUpdate( bool enable );
    void setUndoEnabled( bool enable );
    bool isUndoEnabled() const;
    void setUndoDepth( int depth );
    int undoDepth() const;
    bool isReadOnly() const;
    bool isOverwriteMode() const;
    QString text() const;
    QString phonenoText() const;
    int length() const;
    static void setDefaultTabStop( int ex );
    static int defaultTabStop();
    virtual void show();
    enum TitlePosition { Unknown = 0, TitleTop, TitleLeft };
    void setTitlePosition(TitlePosition titlePos);
    QString title() const; 
    void setTitle(const QString & titleStr);
    void setTruncateInfo(int nStyle = 0, const QString & strReplace = QString::null);
    void setAutoFixedHeight(bool enable);

    virtual void  resetFocusItem(bool);
    virtual QRect getCurrentFocusRect();
    virtual bool  hasNextPrevFocusItem(bool);

    void setNestScrollPanelMode(bool nest);
    bool nestScrollPanelMode() const;
    void setMoveFocusOutRange(bool b);
    bool focusOutRange() const;
    void setAutoExpandInNestMode(bool expand);
    bool autoExpandInNestMode() const;

    void cursorPosBeforeInsert(int,int,int,int *,int *);
    void setWordComplete(bool wc);

    QString getRowString(int);

    void emitTextChanged();

    QPoint calCursorPos( QPoint startPos , int len );
    
    int getLineCount();
    QString getLineContent( int line );
    ZKbInputField * getInputField(); 
    void insertString_if( QPoint pos, QString text ); 


    int  heightViewed() const;
    bool isValidChar( const QChar& ch );
public slots:
        virtual void changeContentSize( int lines,QPoint cursorPos );
    virtual void setText( const QString &s );
    virtual void setReadOnly( bool on );
    virtual void setZEnabled(bool enable);

    bool isZEnabled();
    bool isZDisabled();

    virtual void setOverwriteMode( bool on );
    void      clear();
    void append( const QString &s );
    void       deselect();
    void       selectAll();
    void  smartPunctuation(); 

    void       paste();
    void       pasteSubType(const QCString& subtype);
    void       copyText() const;
    void       copy() const;
    void       cut();
    void       deleteText();

    void insert( const QString& s );
    void       undo();
    void       redo();

  signals:
    void    clicked();
    void    textTrancated();
    void    textChanged();
    void    returnPressed();
    void undoAvailable( bool yes );
    void redoAvailable( bool yes );
    void    copyAvailable( bool );


    void  cursorChanged(int cursorX, int cursorY);

    void  bufferUpdate(int cursorX, int cursorY); 
    void  contentChanged();
    
    void    changeSizeHint( QWidget* widget,QSize size,QPoint cusrorPos,int larger );
    void    linesChanged( int lines,QPoint cursorPos );
    void    rightSmartPuncOccurred();
    void sigCursorUpDown(bool down);

    void contentsResizing(ZMultiLineEdit *, int, int);
    
  protected:
    void    updateMask();
    void    pixelPosToCursorPos(QPoint p, int* x, int* y);
    void    setCursorPixelPosition(QPoint p, bool clear_mark = true);
    void    paintEvent(QPaintEvent * );

	int paintCell_if( QPainter *p , int row , int underlineI , bool underlineHit , int reverseI ,\
                      bool reverseHit , int yPos , int x , QString s , QFontMetrics fm , QRect updateR , QColorGroup g );
    void    paintCell( QPainter *, int row, int col, int xPos, int yPos );
    virtual void drawLineText( QPainter* painter, int x, int y, int width,
                               int height, int flags, const QString& lineStr, int row = 0 , int col = 0);
    virtual void drawTableFrame(QPainter * p, QRect & updateR);

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

    bool    hasMarkedText() const;
    QString markedText() const;
    
    int	    textWidthWithTabs( int lineNo );
    int	    textWidth( int lineNo = -1 );

    QPoint  cursorPoint();
    QPoint  cursorPointViewed();

   
  
  protected:
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
    void linesChangedNoExp(int lines);
    int firstNoVisibleLines(int curLines, const QRect & rt, bool down);

    virtual void backspace();
    virtual void del();
    virtual void home( bool mark=FALSE );
    virtual void end( bool mark=FALSE );
    bool getMarkedRegion( int *line1, int *col1,
                          int *line2, int *col2 ) const;
    int lineLength( int row ) const;
    QString *getString( int row ) const;
    bool isEndOfParagraph( int row ) const;
    QString stringShown( int row ) const;
    virtual void setPalette(const QPalette &);

  protected:
    bool    cursorOn;
    void insertChar( QChar c );
    int     positionToOffsetInternal( int row, int col ) const;
    void    offsetToPositionInternal( int position, int *row, int *col ) const;

    void clearUndoList();

    bool    partiallyInvisible( int row );

    int    getTruncateCount();

  private slots:
    
    void    clipboardChanged();
    void    blinkTimerTimeout();
    void    scrollTimerTimeout();
    void    dndTimeout();
    void    fastDelTimerTimeout();

    void    bufferUpdate();

  private:
    int  doReadOnlyKeyPress( QKeyEvent *e ); 
    bool doModalStatusKeyPress( QKeyEvent *e ); 
    void doSelectKeyPress();
    int doControlKeyPress( QKeyEvent *e);    
    bool insertAtSpecialEzxStyle( const QString &txt, int line );    
    void handleEzxInsertString( const QString &itxt, int line );    
    void handleNormalInsertString( const QString &itxt, int line, int col );

    void wtleWrapLine(int line, int& w, int& nlines );    
    void composeWidth( TsCoord &compWidth );    
    void composeWidth(long&);
    
    void updateFontInfo(QFont *fontStatus, const FONT_INFO_T& fontInfo); 
    void init( QWidget *parent,bool style,int lines,const char *name );
    void filterString( QString& filtered,const QString& s );
    void autoSendScrollRequest( int lines,const QPoint& curPos );
    void setTitlePositionAux(const QString& /*oldTitle*/, int from);
    QString addReplacedStr(const QString & strSource, int row);

    QRect getFormItemTopArea();
    QRect getFormItemLeftArea();
    QRect getFormItemRightArea();
    QRect getFormItemBottomArea();
    QRect getMDTopArea();
    QRect getMDBottomArea();
    QRect getMDLeftArea();
    QRect getMDRightArea();

    QRect getEditArea();

    void drawOtherArea(QPainter * p, const QRect & validrc, const QRect & paintArea, ZSkinBase * pSkinBase);
    void drawMultiArea(QPainter * p, const QRect & validrc, const QRect & paintArea, ZSkinBase * pSkinBase);
    
    QSize updateTextLayout();
    
    int getContentsWidth();

    QCString pickSpecial( QMimeSource* ms, bool always_ask, const QPoint& );

    void       pasteSpecial(const QPoint&);

    struct ZMultiLineEditRow 
    {
        ZMultiLineEditRow( QString string, int width, bool nl = TRUE )
            :s(string), w(width), newline( nl ) 
            {
            };
        QString s;
        int w;
        bool newline;
    };
    QList<ZMultiLineEditRow>*  contents;
    ZMultiLineData*   d;

    int     indent;
    QSize   hint;
    bool    ezx_style;
    int     lines;
    int     minLines;
    bool    underline;

    int layoutLineNumber;
    //TsLayoutInfo layoutInfo;
    TsLayout *layout;
    TsText *tstext;
    QFont *ts_qfont;
    int cursorModel;
    enum eParaAlignment{DIR_UNKNOWN,LTR,RTL};
    int paraAlignment;

    void autoAlignment(TsLayout *layout, TsLayoutInfo &layoutInfo);
    int getParaAlignment(void);
    void invalidateTsLayout(int lineNo, bool andFollowing = FALSE);
    int prepareTsLayout(int lineNo); // return relative line
    int cursorToLayoutIndex(int relLine);
    void layoutIndexToCursor(int index);
    QRegion prepareTsMarkRegion(int markLow, int markHigh, int offset, int row, int x, int y, int txtH, const QString & s);
    QRegion glyphRegion(const TsGlyphInfo & glinfo, int offset, int x, int y, int charBearing);

    bool  isLTRBidiClass(TsBidiCharClass);
    bool  isRTLBidiClass(TsBidiCharClass);

public:
    void specialInputModeCursorModel(bool);
private:

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
    int     blinkTimer; 
    int     scrollTimer; 

    int	    xPosToCursorPos( int lineNo, int xPos );

    int     mapFromView( int xPos, int row );
    int     mapToView( int xIndex, int row );

    void    setWidth( int );
    void    updateCellWidth();
    
    void    makeVisible(bool isDown);
    void    setBottomCell( int row );

    void    newMark( int posx, int posy, bool copy=TRUE );
    void    markWord( int posx, int posy );
    void    extendSelectionWord( int &newX, int&newY);
    int     charClass( QChar );
    void    turnMark( bool on );
    bool    inMark( int posx, int posy ) const;
    bool    beforeMark( int posx, int posy ) const;
    bool    afterMark( int posx, int posy ) const;
    int     setNumRowsAndTruncate();

    int     getOffset(int row);

    void    startAutoScroll();
    void    stopAutoScroll();

    void    cursorLeft( bool mark, bool clear_mark, bool wrap );
    void    cursorRight( bool mark, bool clear_mark, bool wrap );
    void    cursorUp( bool mark, bool clear_mark );
    void    cursorDown( bool mark, bool clear_mark );

    void    wrapLine( int line, int removed = 0);
    void    rebreakParagraph( int line, int removed = 0 );
    void    rebreakAll();
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
    
    enum TextType
    {
        Title = 0,
        Field
    };

    void getSkinFont(QFont & font, QColor & color, TextType type) const;

    void updateSkin(bool redraw);
    
    enum LineType
    {
        Empty_Line = 0,
        Color_Line,
        Pixmap_Line
    };
    
    LineType  lineType(const SelectionState state);

    void lineColor(const SelectionState state, QColor & color);

    QPixmap * getPixmap(const SelectionState state);

    int lineHeight();

    QPixmap loadLinePixmap(const SelectionState state);

    void getLinePixSuffixName(const SelectionState state, QString & suffix);

    LineType changeToLineType(int lineTpye);

    void setViewMarginsEx();

    void drawUnderLine(QPainter * p, int xBase, int yBase, int wDelta);

    void stretchPixmap( QPixmap& pm, int width, int height, PIXMAP_STRETCH_POLICY_E type);

    void setStateFont(bool bChangeState = TRUE);

    int getCursorOffset(int cursorRow, int cursorCol);

    void getCorsorPosition(int & cursorRow, int & cursorCol, int cursorOffset);

    int getCursorState();

  private:  

#if defined(Q_DISABLE_COPY)
    ZMultiLineEdit( const ZMultiLineEdit & );
    ZMultiLineEdit &operator=( const ZMultiLineEdit & );
#endif
};

inline bool ZMultiLineEdit::isReadOnly() const { return readOnly; }

inline bool ZMultiLineEdit::isOverwriteMode() const { return overWrite; }

inline void ZMultiLineEdit::setOverwriteMode( bool on )
{
    overWrite = on;
}

inline int ZMultiLineEdit::lineLength( int row ) const
{
    return contents->at( row )->s.length();
}

inline bool ZMultiLineEdit::atEnd() const
{
    return cursorY == (int)contents->count() - 1
        && cursorX == lineLength( cursorY ) ;
}

inline bool ZMultiLineEdit::atBeginning() const
{
    return cursorY == 0 && cursorX == 0;
}

inline QString *ZMultiLineEdit::getString( int row ) const
{
    return &(contents->at( row )->s);
}

inline int ZMultiLineEdit::numLines() const
{
    return contents->count();
}

#endif 







