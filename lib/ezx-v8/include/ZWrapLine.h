#ifndef ZWRAPLINE_H
#define ZWRAPLINE_H

#include "qstring.h"
#include "qlist.h"
#include "qfont.h"
#include <qnamespace.h>

class TsLayout;
class TsLayoutInfo;

class Q_EXPORT ZWrapLine
{
public:
    ZWrapLine(QString &strSource);
    ~ZWrapLine();

public:
    enum WordWrap {
        NoWrap,
        WidgetWidth,
        FixedPixelWidth,
        FixedColumnWidth
    };
    enum WrapPolicy {
        AtWhiteSpace,
        Anywhere
    };

    void setStrSource(QString &strSource);
    bool wrapLine(const QFont & font);
    int getNumLines();
    int getLineContent(int line,QString & string,bool & newline);
    void clear();
    void setWrapPolicy( WrapPolicy policy );
    WrapPolicy wrapPolicy() const;
    void setWordWrap( WordWrap mode );
    WordWrap wordWrap() const;
    void setWrapColumnOrWidth( int );
    int wrapColumnOrWidth() const;
    void setAlignment( Qt::AlignmentFlags flags );
    Qt::AlignmentFlags alignment() const;
    void setContentsWidth(int nWidth);
    int width() const;
    int height() const;
    void draw ( QPainter * p, int x, int y, const QRect & clipRect) const;

private:
#ifndef QT_NO_WTLE
    void autoAlignment(TsLayout *layout, TsLayoutInfo &layoutInfo);
#endif

#ifndef QT_NO_MOT_ALIGN_AUTO
    bool alignmentAuto;
#endif
    
    WordWrap wordwrap;
    WrapPolicy wrappolicy;
    int lr_marg;
    int marg_extra;
    int wrapcol;
    Qt::AlignmentFlags align;
    QString mvstrSource;
    int contentWidth;
    int nMaxRowWidth;

    short chartable[256];
    void clearChartable();
    
    QFont mfont;

    struct ZWrapLineEditRow {
        ZWrapLineEditRow( QString string, int width, bool nl = TRUE )
            :s(string), w(width), newline( nl )
        {
        };
        QString s;
        int w;
        bool newline;
    };
    QList<ZWrapLineEditRow> *contents;
};

#endif 
