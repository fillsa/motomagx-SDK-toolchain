#ifndef ZTABLEVIEW_H
#define ZTABLEVIEW_H

#include "qtableview.h"
#include "ZWidget.h"

class EZXStyle;
class QScrollBar;
class QCornerSquare;

class Q_EXPORT ZTableView : public ZWidget
{
    Q_OBJECT
public:
    virtual void setBackgroundColor( const QColor & );
    virtual void setPalette( const QPalette & );
    void	show();
    void	repaint( bool erase=TRUE );
    void	repaint( int x, int y, int w, int h, bool erase=TRUE );
    void	repaint( const QRect &, bool erase=TRUE );

protected:
    ZTableView( QWidget *parent=0, const char *name=0, WFlags f=0, ZSkinService::WidgetClsID clsId = ZSkinService::clsTotal);
   ~ZTableView();
    int		numRows()	const;
    virtual void setNumRows( int rows, bool updateScrBars = TRUE);
    int		numCols()	const;
    virtual void setNumCols( int );
    int		topCell()	const;
    virtual void setTopCell( int row );
    int		leftCell()	const;
    virtual void setLeftCell( int col );
    virtual void setTopLeftCell( int row, int col );
    int		xOffset()	const;
    virtual void setXOffset( int );
    int		yOffset()	const;
    virtual void setYOffset( int );
    virtual void setOffset( int x, int y, bool updateScrBars = TRUE );
    virtual int cellWidth( int col );
    virtual int cellHeight( int row );
    int		cellWidth()	const;
    int		cellHeight()	const;
    virtual void setCellWidth( int );
    virtual void setCellHeight( int );
    virtual int totalWidth();
    virtual int totalHeight();
    uint	tableFlags()	const;
    bool	testTableFlags( uint f ) const;
    virtual void setTableFlags( uint f );
    void	clearTableFlags( uint f = ~0 );
    bool	autoUpdate()	 const;
    virtual void setAutoUpdate( bool );
    void	updateCell( int row, int column, bool erase=TRUE );
    QRect	cellUpdateRect() const;
    QRect	viewRect()	 const;
    int		lastRowVisible() const;
    int		lastColVisible() const;
    bool	rowIsVisible( int row ) const;
    bool	colIsVisible( int col ) const;
    QScrollBar *verticalScrollBar() const;
    QScrollBar *horizontalScrollBar() const;

private slots:
    void	horSbValue( int );
    void	horSbSliding( int );
    void	horSbSlidingDone();
    void	verSbValue( int );
    void	verSbSliding( int );
    void	verSbSlidingDone();

protected:
    void setClipRect(QPainter * p, int x, int y, int w, int h);
    void setClipRect (QPainter * p, QRect & r );
    void setClipRegion ( QPainter * p, QRegion & rgn ); 
    virtual void paintCell( QPainter *, int row, int col, int xPos, int yPos );
    virtual void paintCell( QPainter *, int row, int col );
    virtual void setupPainter( QPainter * );
    void	paintEvent( QPaintEvent * );
    void   paintEventEx(QPaintEvent *, int, int);
    void	resizeEvent( QResizeEvent * );
    int		findRow( int yPos ) const;
    int		findCol( int xPos ) const;
    bool	rowYPos( int row, int *yPos ) const;
    bool	colXPos( int col, int *xPos ) const;
    int		maxXOffset();
    int		maxYOffset();
    int		maxColOffset();
    int		maxRowOffset();
    int		minViewX()	const;
    int		minViewY()	const;
    int		maxViewX()	const;
    int		maxViewY()	const;
    void	setViewMargins(int left, int top, int right, int bottom);
    virtual void drawTableFrame(QPainter * p, QRect & updateR);
    int		viewWidth()	const;
    int		viewHeight()	const;
    void	scroll( int xPixels, int yPixels );
    void	updateScrollBars();
    void	updateTableSize();

private:
    void	coverCornerSquare( bool );
    void	snapToGrid( bool horizontal, bool vertical );
    virtual void	setHorScrollBar( bool on, bool update = TRUE );
    virtual void	setVerScrollBar( bool on, bool update = TRUE );
    void	updateView();
    int		findRawRow( int yPos, int *cellMaxY, int *cellMinY = 0,
			    bool goOutsideView = FALSE ) const;
    int		findRawCol( int xPos, int *cellMaxX, int *cellMinX = 0,
			    bool goOutsideView = FALSE ) const;
    int		maxColsVisible() const;
    void	updateScrollBars( uint );
    void	updateFrameSize();
    void	doAutoScrollBars();
    void	showOrHideScrollBars();
    int		nRows;
    int		nCols;
    int		xOffs, yOffs;
    int		xCellOffs, yCellOffs;
    short	xCellDelta, yCellDelta;
    short	cellH, cellW;
    uint	eraseInPaint		: 1;
    uint	verSliding		: 1;
    uint	verSnappingOff		: 1;
    uint	horSliding		: 1;
    uint	horSnappingOff		: 1;
    uint	coveringCornerSquare	: 1;
    uint	sbDirty			: 8;
    uint	inSbUpdate		: 1;
    uint	tFlags;
    QRect	cellUpdateR;
    QScrollBar *vScrollBar;
    QScrollBar *hScrollBar;
    QCornerSquare *cornerSquare;
    int viewLeft;
    int viewTop;
    int viewRight;
    int viewBottom;

   EZXStyle * st; 

private:
    ZTableView( const ZTableView & );
    ZTableView &operator=( const ZTableView & );
};

inline int ZTableView::numRows() const
{ return nRows; }

inline int ZTableView::numCols() const
{ return nCols; }

inline int ZTableView::topCell() const
{ return yCellOffs; }

inline int ZTableView::leftCell() const
{ return xCellOffs; }

inline int ZTableView::xOffset() const
{ return xOffs; }

inline int ZTableView::yOffset() const
{ return yOffs; }

inline int ZTableView::cellHeight() const
{ return cellH; }

inline int ZTableView::cellWidth() const
{ return cellW; }

inline uint ZTableView::tableFlags() const
{ return tFlags; }

inline bool ZTableView::testTableFlags( uint f ) const
{ return (tFlags & f) != 0; }

inline QRect ZTableView::cellUpdateRect() const
{ return cellUpdateR; }

inline bool ZTableView::autoUpdate() const
{ return isUpdatesEnabled(); }

inline void ZTableView::repaint( bool erase )
{ repaint( 0, 0, width(), height(), erase ); }

inline void ZTableView::repaint( const QRect &r, bool erase )
{ repaint( r.x(), r.y(), r.width(), r.height(), erase ); }

inline void ZTableView::updateScrollBars()
{ updateScrollBars( 0 ); }
#endif
