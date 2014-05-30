#ifndef __ZLABEL_H__
#define __ZLABEL_H__

#ifndef QT_H
#include "qtimer.h"
#include "qrect.h"
#endif // QT_H

#include "ZWidget.h"
#include "ZWrapLine.h"
#include "ZSkinBase.h"
//#include "ZSkinService.h"

#define MARQUEE_FOREVER  -1
#define MARQUEE_NOFOREVER 0
#define TRANCATE_FROMEND -1

typedef int NumLines;
typedef int TruncateNum;
typedef unsigned char TruncateStat;

class ZLabelPrivate;

class Q_EXPORT ZLabel : public ZWidget 
{
    Q_OBJECT
    Q_ENUMS(MarqueeDirection TextDirection MarqueeState)
    Q_PROPERTY( QString text READ text WRITE setText )
    Q_PROPERTY( AlignmentFlags alignment READ alignment WRITE setAlignment )

    Q_PROPERTY( NumLines numlines READ numLines WRITE setNumLines)
    Q_PROPERTY( TextDirection textdirection READ textDirection WRITE setTextDirection )
    Q_PROPERTY( TruncateNum truncatenum READ truncateNum WRITE setTruncateNum )
    Q_PROPERTY( QString truncatestring READ truncateString WRITE setTruncateString )
    Q_PROPERTY( TruncateStat truncatestat READ truncateStat WRITE setTruncateStat )
    Q_PROPERTY( int marqueespeed READ marqueeSpeed WRITE setMarqueeSpeed )
    Q_PROPERTY( int marqueestep READ marqueeStep WRITE setMarqueeStep )
    Q_PROPERTY( MarqueeDirection marqueedirection READ marqueeDirection WRITE setMarqueeDirection )
    Q_PROPERTY( int marqueerepetition READ marqueeRepetition WRITE setMarqueeRepetition )

    Q_PROPERTY(int leading READ leading WRITE setLeading)
    Q_PROPERTY(int preferredwidth READ preferredWidth WRITE setPreferredWidth)
    Q_PROPERTY(MarqueeState marqueestate READ marqueeState WRITE setMarqueeState)

public:
    ZLabel( QWidget *parent, const char *name=0, WFlags f=0,
            const ZSkinService::WidgetClsID clsId = ZSkinService::clsTotal );
    ZLabel( const QString &text, QWidget *parent, const char *name=0,
           WFlags f=0, const ZSkinService::WidgetClsID clsId = ZSkinService::clsTotal);
    enum MarqueeState{
        None = 0,
        Standard,
        Highlighted
    };
    
    enum MarqueeDirection{
        Left = 0,
        Right,
        Top,
        Bottom
    };

    enum TextDirection{
        LeftToRight = 0,
        RightToLeft
    };

	enum AlignmentFlags { AlignLeft = 0x0001, AlignRight = 0x0002, AlignHCenter = 0x0004, AlignTop = 0x0008, AlignBottom = 0x0010, AlignVCenter = 0x0020, AlignCenter = AlignVCenter | AlignHCenter, SingleLine = 0x0040, DontClip = 0x0080, ExpandTabs = 0x0100, ShowPrefix = 0x0200, WordBreak = 0x0400, DontPrint = 0x1000 };
public:

    ~ZLabel();
    QString text() const { return ltext; }
    AlignmentFlags  alignment() const { return align; }
    virtual void setAlignment( AlignmentFlags alignment );
     NumLines numLines() const ;
    void     setNumLines(NumLines numlines);
    TextDirection textDirection() const ;
    void setTextDirection(TextDirection tdirection);
    TruncateNum truncateNum() const ;
    void setTruncateNum(TruncateNum truncatenum);
    QString truncateString() const ;
    void setTruncateString(const QString & truncateStr);
    TruncateStat truncateStat() const ;
    void setTruncateStat(TruncateStat truncatestat);
    int marqueeSpeed() const;
    void setMarqueeSpeed(int marqueespeed);
    int marqueeStep() const;
    void setMarqueeStep(int marqueestep);
    MarqueeDirection marqueeDirection() const;
    void setMarqueeDirection(MarqueeDirection marqueedirection);
    int marqueeRepetition() const;
    void setMarqueeRepetition(int marqueerepetition);
    int leading() const;
    void setLeading(int leading);
    void setFontColor(const QColor & color);
    QColor fontColor() const;
    int preferredWidth() const;
    void setPreferredWidth(int preferredw);
    ZWrapLine::WrapPolicy wrapPolicy() const;
    void setWrapPolicy(ZWrapLine::WrapPolicy wrappolicy);
    bool autoResize() const { return autoresize; }
    virtual void setAutoResize( bool enable);
    MarqueeState marqueeState() const;
    void setMarqueeState(MarqueeState marqueeStat);
    void   marqueePlay();
    void   marqueePause();
    QSize sizeHint() const;
    void        getFrameWidth(int & nleftf,int & nrightf, int & ntopf, int & nbottomf) const;
    virtual void setGeometry(int x,int y, int w, int h);
    virtual void setGeometry(const QRect & r);
    virtual void resize(int w, int h);
    int heightForWidth ( int w ) const;
    void setPadding( const WIDGET_PADDING_INFO_T & padd );
    virtual void setEnabled(bool enable);
    bool isZEnabled();
    bool isZDisabled();
    void setParentBackground(bool isParentBg);
    bool isParentBackground();
   void setOutline(bool outline,QColor outc=QColor(255,0,0),QColor innerc=QColor(0,0,0));//added by huangtao
    virtual void setPalette(const QPalette &);
    void adjustHeightBySetting(int nPreferredHeight);
    int  getContentNumLines();

public slots:
    virtual void setText( const QString &);
    void clear();

protected:
    void paintEvent(QPaintEvent *);
    virtual void fontChange( const QFont & );
    virtual void showEvent ( QShowEvent * );
    QRect getContentRect(); 

private slots:
    void slotScrollTimer();    

private:
    void init();
    void clearContents();
    void updateLabel( QSize oldSizeHint );
    QSize sizeForWidth( ) const;
    void paintHscroll(QPainter * p);
    void paintVscroll(QPainter * p);
    void paintStaticText(QPainter * p);
    int getLineH() const;
    int getHTotalWidth();
    int getVTotalHeight();
    void getTruncStr(QString & string,char addchar,int addnums);
    void wrapLine();
    int  getSpaceWidth();
    void startScroll();
    void stopScroll(bool bRScroll = 0);
    int  getRealNums();
    bool isScroll();
    QRect getLabelRect();
    QString getTrancatestr(const QString & str);
    int getSpacing() const { return (mleading - font().pointSize()); }
    
    QString ltext;

    AlignmentFlags align;
    
    uint autoresize:1;
    int mleading;
    int mpreferredw;

    int mvHScroll;
    int mvHTotalWidth;
    int mvVScroll;
    int mvVTotalHight;
    int nMarqueeing;
    int nCurMarNum;

    NumLines mvnumlines;
    TextDirection mvtextdirection;
    TruncateNum mvtruncatenum;
    QString mvtruncateStr;
    TruncateStat mvtruncatestat;

    QTimer * pScrollTimer;
    ZWrapLine * pWrapLine;
    ZLabelPrivate * d;
    void drawOutlineText(QPainter *p, QColor tc, QColor oc,
            int x, int y, int w, int h, int flags,
            const QString& str, int len = -1, QRect *br=0,
            char **internal=0 );


private:    
#if defined(Q_DISABLE_COPY)
    ZLabel( const ZLabel & );
    ZLabel &operator=( const ZLabel & );
#endif

private:

    typedef struct _tagMarquee{
        int speed;
        int step;
        MarqueeDirection direction;
        int repetition;  
    }Marquee,*LPMarquee;
    
    Marquee mvMarquee;
    MarqueeState mMarqueeState;

protected:
    
};
    
#endif // __ZLABEL_H__
