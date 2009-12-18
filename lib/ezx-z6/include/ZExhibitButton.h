#ifndef __EXHIBITBUTTON_H__
#define __EXHIBITBUTTON_H__

//#include "qwidget.h"
#include "ZSkinBase.h"
#include "ZFormItem.h"
#include "ZPressButton.h"

class ZLabel;
//class ZPressButton;
class ZExhibitButtonPrivate;

class Q_EXPORT ZExhibitButton : public ZFormItem //public QWidget, public ZSkinBase
{
    Q_OBJECT
    Q_ENUMS(TitlePosition)
    Q_PROPERTY(int numrows READ numRows WRITE setNumRows)
    Q_PROPERTY(TitlePosition titlposition READ titlePosition WRITE setTitlePosition)
public:
    ZExhibitButton( QWidget * parent = 0,const char * name = 0,WFlags f = 0,
            const ZSkinService::WidgetClsID clsId = ZSkinService::clsZExhibitButton);
    ~ZExhibitButton();
    enum TitlePosition{
        TitleTop = 0,
        TitleLeft
    };
    int    numRows() const;
    void   setNumRows(int numrows);
    void setExhibitValue(const QString & string);
    void setButtonText(const QString & string);
    void setButtonPixmap(const QPixmap & pixmap);
    const ZLabel * label() const;
    const ZPressButton * pressButton() const;
    virtual void setGeometry(int x,int y, int w, int h);
    virtual void setGeometry(const QRect & r);
    virtual void resize(int w, int h);
    virtual void move(int x, int y);
    virtual void move(const QPoint &);
    void getFrameWidth(int & nleftf,int & nrightf,int & ntopf, int & nbottomf) const ;
    void setTitle(const QString & strTitle);
    QString title();
    TitlePosition titlePosition() const;
    void  setTitlePosition(TitlePosition titlePos);
    QSize sizeHint() const;
    void setEnabled(bool enable);
    bool isZEnabled();
    bool isZDisabled();

public slots:
    virtual void setFocus();
protected:
    virtual void paintEvent(QPaintEvent * );
    virtual void focusInEvent(QFocusEvent * );
    virtual void focusOutEvent(QFocusEvent * );
    virtual void keyPressEvent(QKeyEvent * );
    virtual void keyReleaseEvent(QKeyEvent * );
    virtual void moveEvent ( QMoveEvent *e );
    void setPalette(const QPalette & palette);

    void updateSkin(bool redraw);
signals:
    void sigExhibitBtnClick();
private:
    bool init();
    QRect getContentRect() const;
    void getEBtnFrameWidth(int & nleftf,int & nrightf,int & ntopf, int & nbottomf) const ;
    QRect getEBtnContentRect() const;
    QPoint getContentTopLeft() const;
    int getContentHeight() const;
    int getContentWidth() const;  
    QSize getTitleSize() const;
    QSize getBtnSize() const;
    QSize getLabelSize() const; 
    void resizeExhibitButton();
    QRect getTitleRect() const;
    QRect getBtnRect() const;
    QRect getLabelRect() const;
    QRect getExhibitBtnRect() const;
    void setLabelFontInfo(SelectionState nState);
private:
    ZExhibitButtonPrivate * d;
    int mnumrows; 
    QString mstring;
    QString mtitle;
    TitlePosition mrelpos;
};

#endif //__EXHIBITBUTTON_H__

