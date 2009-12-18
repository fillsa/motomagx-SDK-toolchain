#ifndef __ZSDMULTILINEEDIT_H__
#define __ZSDMULTILINEEDIT_H__

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include "ZMultiLineEdit.h"
#include "qcolor.h"

class ZStructureDataParser;


class Q_EXPORT ZSDMultiLineEdit : public ZMultiLineEdit
{
    //Q_OBJECT
public:
    ZSDMultiLineEdit(ZStructureDataParser * pSDParser = 0, QWidget *parent=0, const char *name=0);
    ZSDMultiLineEdit( QWidget *parent,bool EZXStyle,ZStructureDataParser * pSDParser = 0, int lines = 1,
                      const char *name=0);
    virtual ~ZSDMultiLineEdit() {};
    //virtual void setText(const QString & s);
    void setSDParser(ZStructureDataParser * pSDParser);
    ZStructureDataParser * structureDataParser() const {return mSDParser;}
    void setSDTextColor(const QColor & color);
    QColor sdTextColor() const {return mSDTextColor;}
    void setSDTextHighlightColor(const QColor & color);
    QColor sdTextHighlightColor() const {return mSDTextHColor;}
    void setSDSelHighlightColor(const QColor & color);
    QColor sdSelHighlightColor() const {return mSDHighlightColor;}
    enum NavigateMode
    {
        NoNavigate,
        Navigate    
    };
    void setNavigateMode(NavigateMode navigateMode);
    NavigateMode navigateMode() const {return mnavMode;}
signals:
    void sigClickStructureData(const QString & strPre, const QString & strPost, const QString & strType);
    void highlighted(int nIndex);
    void highlighted(const QString & strPre, const QString & strPost, const QString & strType);
    
protected:
    //virtual void drawLineText( QPainter* painter, int x, int y, int width,
    //                          int height, int flags, const QString& lineStr, int row = 0, int col = 0);
    //virtual void drawLineSDText(QPainter* painter, int x, int y,int height, int flags, 
    //                            const QString& lineStr, int row = 0, int col = 0, int nIndex = -1);
    virtual void keyPressEvent(QKeyEvent * e);
    //virtual void resizeEvent(QResizeEvent * e);
    void sdOffsetToPosition();
    int getSDDataPosition(int row, int col, int nIndex, int & nSDBeginCol, int & nSDEndCol, bool & bIsSel);
    //void focusInEvent(QFocusEvent * e);
    //void focusOutEvent(QFocusEvent * e);
    //void customEvent(QCustomEvent * e);

protected slots:    
    void slotTextTruncate();
private:
    void inital();
    void addOffsetPositionInfo(int rowBegin, int colBegin, int rowEnd, int colEnd, int nIndex, int nOffset);
    void updateSDHighlightedArea(int oldSel, int curSel, int nUpOrDown);
    void updateAllLine(int nBeginLine, int nEndLine);
    int sendScrollRequest(int nBeginLine, int nEndLine);
    int getFirstLineParentArea(int nLine, int lookDirect);
    QWidget * getParent();
    QPoint getParentPoint(const QPoint & point, QWidget * pWidget);
    int getStructureDataIndex(int nScrollDir);
    void postCustomEvent(int nScroDir);
    ZStructureDataParser * mSDParser;
    QColor mSDTextColor;
    QColor mSDTextHColor;
    QColor mSDHighlightColor;
    NavigateMode mnavMode;
    typedef struct
    {
        int rowBegin;
        int colBegin;
        int rowEnd;
        int colEnd;
        int nSDIndex;
        int offset;
    }SDPOSTOOFFSET, * LPSDPOSTOOFFSET;
    QList<SDPOSTOOFFSET> mSDPosToOffset;
    int mCurSelSD;
    bool ezx_style;
    int mezx_FVLine;
    int mezx_LVLine;
    int mScrollDirect;
};

#endif //__ZSDMULTILINEEDIT_H__
