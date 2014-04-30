// Fix for U9 by Ant-ON, 30.04.2014
// Fix for ZN5 by Ant-ON, 18.03.2011
// Fix for ZN5 by Ant-ON, 23.03.2011
// Fix class size for ZN5 by Ant-ON, 25.09.2011

// Copyright (c) 25-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef AM_APP_REGISTRY_H
#define AM_APP_REGISTRY_H

#ifndef __cplusplus
#error "This is C++ header file; it requires C++ to compile."
#endif

#include <qobject.h>
#include <qvaluelist.h>
#include <qstring.h>
#include <qstringlist.h>
#include <quuid.h>

#include "AM_Defs.h"
#include "AM_RegistryObject.h"

#include <ZMyConfig.h>

class AM_AppLnk;
class AM_Folder;
class AM_AppObject;
class AM_AppRegistryImpl;

//Size: 0x28

class AM_AppRegistry : public QObject
{
    Q_OBJECT
    
    unsigned char data[0x28-sizeof(QObject)];
public:

    struct LockableAppObject
    {
        const AM_AppObject * appObject;
        int lockValue;
    };

    AM_AppRegistry(QObject * parent = 0, const char * name = 0);
    ~AM_AppRegistry();

    AM_RESULT_CODE_T init();
    const AM_RegistryObject * getRegistryObject(const QString & uid) const;
    const AM_Folder * getRootFolder() const;
    const AM_AppLnk * getAppLnk(const QUuid & appId) const;
    void getInstalledApplications(bool all, QValueList<const AM_AppLnk *> & appLnkList) const;
    void getAllAppObjects(QValueList<const AM_AppObject *> & appObjectList) const;
    AM_RESULT_CODE_T getLockEnabledAppObjects(QValueList<LockableAppObject> & lockableList) const;
    void getAutoStartEnabledAppObjects(QValueList<const AM_AppObject *> & autoStartList) const;
    AM_RESULT_CODE_T isAutoStartEnabled(const QUuid & appId, bool & enabled) const;
    static AM_RESULT_CODE_T getAppLockValue(const QUuid & appId, int & value);
    static AM_RESULT_CODE_T getAppName(const QUuid & appId, QString & appName);
    AM_RESULT_CODE_T setAutoStartEnabled(const QUuid & appId, bool enabled);
    AM_RESULT_CODE_T updateFolderOrder(const QString & folderUid, const QStringList & uidList);
    AM_RESULT_CODE_T updateRegistryObjectAppearance(const QString & uid, 
            const QString & newName, const QString & newBigIcon, 
            const QString & newSmallIcon, const QString & newAniIcon,
            const QString & newSVGIcon, bool temporary = false);
    AM_RESULT_CODE_T moveRegistryObject(const QString & uid, 
            const QString & destFolderUid, int position = -1);
    AM_RESULT_CODE_T setAppLockValue(const QUuid & appId, int value);
#ifdef EZX_ZN5
	AM_RESULT_CODE_T clearJavaRegistryEntries(AM_RegistryObject::Attribute);
#endif 
};

#endif 
