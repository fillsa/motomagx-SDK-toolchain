#ifndef ZBASEBUTTONGROUP_H
#define ZBASEBUTTONGROUP_H

#ifndef QT_H
#include "qgroupbox.h"
#endif // QT_H

#ifndef QT_NO_BUTTONGROUP

/*
vtable for ZBaseButtonGroup@@VERSION		 // OBJECT
*/


class ZBaseButton;
class ZBaseButtonList;

class Q_EXPORT ZBaseButtonGroup : public QGroupBox
{
    Q_OBJECT
};

/*
class Q_EXPORT ZBaseButtonGroup : public QGroupBox
{
    Q_OBJECT
    Q_PROPERTY( bool exclusive READ isExclusive WRITE setExclusive )
    Q_PROPERTY( bool radioButtonExclusive READ isRadioButtonExclusive WRITE setRadioButtonExclusive )
	
public:
    ZBaseButtonGroup( QWidget *parent=0, const char *name=0 );
    ZBaseButtonGroup( const QString &title,
		  QWidget *parent=0, const char* name=0 );
    ZBaseButtonGroup( int columns, Orientation o,
		  QWidget *parent=0, const char *name=0 );
    ZBaseButtonGroup( int columns, Orientation o, const QString &title,
		  QWidget *parent=0, const char* name=0 );
   ~ZBaseButtonGroup();

    bool	isExclusive() const;
    bool	isRadioButtonExclusive() const { return radio_excl; }
    virtual void setExclusive( bool );
    virtual void setRadioButtonExclusive( bool );

public:
    int		insert( ZBaseButton *, int id=-1 );
    void	remove( ZBaseButton * );
    ZBaseButton    *find( int id ) const;
    int		id( ZBaseButton * ) const;
    int		count() const;

    virtual void setButton( int id );

    virtual void moveFocus( int );

    ZBaseButton    *selected();

signals:
    void	pressed( int id );
    void	released( int id );
    void	clicked( int id );

protected slots:
    void	buttonPressed();
    void	buttonReleased();
    void	buttonClicked();
    void	buttonToggled( bool on );

private:
    void	init();
    bool	excl_grp;
    bool	radio_excl;
    ZBaseButtonList *buttons;

private:	// Disabled copy constructor and operator=
#if defined(Q_DISABLE_COPY)
    ZBaseButtonGroup( const ZBaseButtonGroup & );
    ZBaseButtonGroup &operator=( const ZBaseButtonGroup & );
#endif
};
*/

#endif // QT_NO_BUTTONGROUP

#endif // ZBASEBUTTONGROUP_H
