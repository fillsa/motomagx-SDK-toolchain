#ifndef __ZTABLEVIEW_H_
#define __ZTABLEVIEW_H_

#include <ZWidget.h>

/* Size: UNKNOWN, not used directly,
 * only as base for ZMultiLineEdit(504) and ZColorPicker(376) */

class ZTableView : public ZWidget
{
    Q_OBJECT
    unsigned int data[94 - sizeof(ZWidget)/4];

public:
	ZTableView( QWidget *parent=0, const char *name=0, WFlags f=0, ZSkinService::WidgetClsID clsId = ZSkinService::clsTotal);
	~ZTableView();
    
    bool rowYPos( int row, int *yPos ) const;
    bool colXPos( int col, int *xPos ) const;
    virtual int cellWidth( int col );
    virtual int cellHeight( int row );
    int		cellWidth()	const;
    int		cellHeight()	const;
    
    virtual void setNumRows(int, bool);
    virtual void setNumCols(int);
    virtual void setTopCell(int);
    virtual void setLeftCell(int);
    virtual void setTopLeftCell(int, int);
    virtual void setXOffset(int);
    virtual void setYOffset(int);
    virtual void setOffset(int, int, bool);
    virtual void setCellWidth(int);
    virtual void setCellHeight(int);
    virtual void totalWidth();
    virtual void totalHeight();
    virtual void setTableFlags(unsigned int);
    virtual void setAutoUpdate(bool);
    virtual void paintCell(QPainter*, int, int, int, int);
    virtual void paintCell(QPainter*, int, int);
    virtual void setupPainter(QPainter*);
    virtual void drawTableFrame(QPainter*, QRect&);
    virtual void setHorScrollBar(bool, bool);
    virtual void setVerScrollBar(bool, bool);
};

#endif
