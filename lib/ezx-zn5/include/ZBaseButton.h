#ifndef ZBASEBUTTON_H
#define ZBASEBUTTON_H

#include "ZFormItem.h"

class ZBaseButtonGroup;
struct ZBaseButtonData;
class QToolBar;

class Q_EXPORT ZBaseButton : public ZFormItem
{
    Q_OBJECT
public:
    ZBaseButton( QWidget *parent, const char *name, WFlags f,ZSkinService::WidgetClsID clsId );
   ~ZBaseButton();
    QString text() const;
    virtual void setText( const QString &);    //???
    const QPixmap *pixmap() const;
    virtual void setPixmap( const QPixmap & ); //???
//    int		accel()	const;
    virtual void	setAccel( int );
    bool	isToggleButton() const;
    enum ToggleType { SingleShot, Toggle, Tristate };
//    ToggleType	toggleType() const;
    virtual void setDown( bool );
    bool	isDown() const;
    bool	isOn() const;
    enum ToggleState { Off, NoChange, On };
//    ToggleState	state() const;
//    bool	autoResize() const;
    virtual void setAutoResize( bool );
//    bool	autoRepeat() const;
    virtual void setAutoRepeat( bool );
    bool	isExclusiveToggle() const;
    bool	focusNextPrevChild( bool next );
    ZBaseButtonGroup *group() const;

	virtual void	setToggleType( ToggleType );
	virtual void	setState( ToggleState );
	
//public slots:
//    void	animateClick();
//    void	toggle();

signals:
    void	pressed();
    void	released();
    void	clicked();
    void	toggled( bool );
    void	stateChanged( int );

protected:
//    void	setToggleButton( bool );
///   virtual void	setToggleType( ToggleType ); //move in public
//    void	setOn( bool );
///    virtual void	setState( ToggleState ); //move in public
    virtual bool hitButton( const QPoint &pos ) const;
//    virtual void drawButton( QPainter * );
//    virtual void drawButtonLabel( QPainter * );
    void	keyPressEvent( QKeyEvent *);
    void	keyReleaseEvent( QKeyEvent *);
    void	mousePressEvent( QMouseEvent * );
    void	mouseReleaseEvent( QMouseEvent * );
    void	mouseMoveEvent( QMouseEvent * );
    void	paintEvent( QPaintEvent * );
//    void	focusInEvent( QFocusEvent * );
//    void	focusOutEvent( QFocusEvent * );
    void	enabledChange( bool );

//private slots:
//    void	animateTimeout();
//    void	autoRepeatTimeout();

private:
    QString	btext;
    QPixmap    *bpixmap;
    uint	toggleTyp	: 2;
    uint	buttonDown	: 1;
    uint	stat		: 2;
    uint	mlbDown		: 1;
    uint	autoresize	: 1;
    uint	animation	: 1;
    uint	repeat		: 1;
    ZBaseButtonData *d;

    friend class ZBaseButtonGroup;
    friend class QToolBar;
//    void          ensureData();
    virtual void setGroup( ZBaseButtonGroup* );
//    QTimer	 *timer();
//    void	nextState();

private:
#if defined(Q_DISABLE_COPY)
    ZBaseButton( const ZBaseButton & );
    ZBaseButton &operator=( const ZBaseButton & );
#endif
};

#endif //ZBASEBUTTON_H
