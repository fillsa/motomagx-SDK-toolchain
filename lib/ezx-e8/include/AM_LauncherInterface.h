#ifndef AM_LAUNCHERINTERFACE_H
#define AM_LAUNCHERINTERFACE_H

#include "AM_Global.h"
#include "AM_Defs.h"

class QUuid;

class AM_LauncherInterface : public QObject
{
    Q_OBJECT
public:

    AM_LauncherInterface(QObject  * parent = 0, const char * name=0);
    virtual ~AM_LauncherInterface();

    static QCString getLauncherChannel( void );
    static bool autoOpen( const QString &file, bool);
    static bool launchApp( const QUuid& app, bool  );

	//...
};

#endif
