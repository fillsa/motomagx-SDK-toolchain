// Copyright (c) 27-Oct-2005 - 2008 Motorola, Inc. All rights reserved.

/////////////////////////////////////////////////////////////////////
/// $Id: qt/include/qbutton.h   2.3.6   edited 2001-01-26 $
///
/// Definition of QButton class
///
/// Created : 941115
///
/// Copyright (C) 1992-2000 Trolltech AS.  All rights reserved.
///
/// This file is part of the widgets module of the Qt GUI Toolkit.
///
/// This file may be distributed under the terms of the Q Public License
/// as defined by Trolltech AS of Norway and appearing in the file
/// LICENSE.QPL included in the packaging of this file.
///
/// This file may be distributed and/or modified under the terms of the
/// GNU General Public License version 2 as published by the Free Software
/// Foundation and appearing in the file LICENSE.GPL included in the
/// packaging of this file.
///
/// Licensees holding valid Qt Enterprise Edition or Qt Professional Edition
/// licenses may use this file in accordance with the Qt Commercial License
/// Agreement provided with the Software.
///
/// This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
/// WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
///
/// See http://www.trolltech.com/pricing.html or email sales@trolltech.com for
///   information about Qt Commercial License Agreements.
/// See http://www.trolltech.com/qpl/ for QPL licensing information.
/// See http://www.trolltech.com/gpl/ for GPL licensing information.
///
/// Contact info@trolltech.com if any conditions of this licensing are
/// not clear to you.
///
/// Motorola changes the file for Linux Java
///
///Drafted Header Files, will be revised in LJ6.3. They can be private or renamed
///////////////////////////////////////////////////////////////////////////

#ifndef PUBLIC_API_WIDGET_ZBASEBUTTON_H
#define PUBLIC_API_WIDGET_ZBASEBUTTON_H

#include "ZFormItem.h"

//#ifndef QT_NO_BUTTON


class ZBaseButtonGroup;
struct ZBaseButtonData;
class QToolBar;

/* Size: UNKNOWN >= 276=69*4 */

class Q_EXPORT ZBaseButton : public ZFormItem
{
    unsigned int data[68 - sizeof(ZFormItem)/4];//68
    /* Flags are at offset 272 */
    unsigned int state2;
    	
    Q_OBJECT
    Q_ENUMS( ToggleType ToggleState )
    Q_PROPERTY( QString text READ text WRITE setText )
    Q_PROPERTY( QPixmap pixmap READ pixmap WRITE setPixmap )
    Q_PROPERTY( int accel READ accel WRITE setAccel )
    Q_PROPERTY( bool toggleButton READ isToggleButton )
    Q_PROPERTY( ToggleType toggleType READ toggleType )
    Q_PROPERTY( bool down READ isDown WRITE setDown DESIGNABLE false  )
    Q_PROPERTY( bool on READ isOn )
    Q_PROPERTY( ToggleState toggleState READ state )
    Q_PROPERTY( bool autoResize READ autoResize WRITE setAutoResize )
    Q_PROPERTY( bool autoRepeat READ autoRepeat WRITE setAutoRepeat )
    Q_PROPERTY( bool exclusiveToggle READ isExclusiveToggle )

public:
    ZBaseButton( QWidget *parent, const char *name, WFlags f,ZSkinService::WidgetClsID clsId );
   ~ZBaseButton();

    QString text() const;
    virtual void setText( const QString &);
    const QPixmap *pixmap() const;
    virtual void setPixmap( const QPixmap & );

    int		accel()	const;
    virtual void	setAccel( int );

    bool	isToggleButton() const;
    enum ToggleType { SingleShot, Toggle, Tristate };
    ToggleType	toggleType() const;

    virtual void setDown( bool );
    bool	isDown() const;

    bool	isOn() const;

    enum ToggleState { Off, NoChange, On };
    ToggleState	state() const;

    bool	autoResize() const; // obsolete
    virtual void setAutoResize( bool ); // obsolete

    bool	autoRepeat() const;
    virtual void setAutoRepeat( bool );

    bool	isExclusiveToggle() const;

    bool	focusNextPrevChild( bool next );

    ZBaseButtonGroup *group() const;

    void setState( ToggleState );
    virtual void	setToggleType( ToggleType );

public slots:
    void	animateClick();
    void	toggle();

signals:
    void	pressed();
    void	released();
    void	clicked();
    void	toggled( bool );
    void	stateChanged( int );

protected:
    void	setToggleButton( bool );
    ///virtual void	setToggleType( ToggleType ); //move in public
    virtual void	setOn( bool );
    //virtual void	setState( ToggleState );

    virtual bool hitButton( const QPoint &pos ) const;
    virtual void drawButton( QPainter * );
    virtual void drawButtonLabel( QPainter * );

    void	keyPressEvent( QKeyEvent *);
    void	keyReleaseEvent( QKeyEvent *);
    void	mousePressEvent( QMouseEvent * );
    void	mouseReleaseEvent( QMouseEvent * );
    void	mouseMoveEvent( QMouseEvent * );
    void	paintEvent( QPaintEvent * );
    void	focusInEvent( QFocusEvent * );
    void	focusOutEvent( QFocusEvent * );

    void	enabledChange( bool );

private slots:
    void	animateTimeout();
    void	autoRepeatTimeout();

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
    void          ensureData();
    virtual void setGroup( ZBaseButtonGroup* );
    QTimer	 *timer();
    void	nextState();

private:	// Disabled copy constructor and operator=
    ZBaseButton( const ZBaseButton & );
    ZBaseButton &operator=( const ZBaseButton & );
};


inline QString ZBaseButton::text() const
{
    return btext;
}

inline const QPixmap *ZBaseButton::pixmap() const
{
    return bpixmap;
}

inline bool ZBaseButton::isToggleButton() const
{
    return toggleTyp != SingleShot;
}

inline  bool ZBaseButton::isDown() const
{
    return buttonDown;
}

inline bool ZBaseButton::isOn() const
{
    return stat != Off;
}

inline bool ZBaseButton::autoResize() const // obsolete
{
    return autoresize;
}

inline bool ZBaseButton::autoRepeat() const
{
    return repeat;
}

inline ZBaseButton::ToggleState ZBaseButton::state() const
{
    //return ToggleState(stat);
    return (ToggleState)((state2>>3) & 3);
}

inline void ZBaseButton::setToggleButton( bool b )
{
    setToggleType( b ? Toggle : SingleShot );
}

inline void ZBaseButton::setOn( bool y )
{
    setState( y ? On : Off );
}

inline ZBaseButton::ToggleType ZBaseButton::toggleType() const
{
    return ToggleType(toggleTyp);
}

//#endif // QT_NO_BUTTON

#endif //PUBLIC_API_WIDGET_ZBASEBUTTON_H
