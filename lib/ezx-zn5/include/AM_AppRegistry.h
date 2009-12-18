

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

class AM_RegistryObject;
class AM_Folder;
class AM_AppObject;
class AM_AppLnk;

class AM_AppRegistryImpl;

/*
AM_AppRegistry::AM_AppRegistry(QObject*, char const*)@@VERSION		 // FUNC
AM_AppRegistry::AM_AppRegistry(QObject*, char const*)@@VERSION		 // FUNC
AM_AppRegistry::~AM_AppRegistry()@@VERSION		 // FUNC
AM_AppRegistry::~AM_AppRegistry()@@VERSION		 // FUNC
AM_AppRegistry::~AM_AppRegistry()@@VERSION		 // FUNC
AM_AppRegistry::clearJavaRegistryEntries(AM_RegistryObject::Attribute)@@VERSION // FUNC
AM_AppRegistry::getAllAppObjects(QValueList<AM_AppObject const*>&) const@@VERSION		 // FUNC
AM_AppRegistry::getAppLnk(QUuid const&) const@@VERSION		 // FUNC
AM_AppRegistry::getAppLockValue(QUuid const&, int&)@@VERSION		 // FUNC
AM_AppRegistry::getAppName(QUuid const&, QString&)@@VERSION		 // FUNC
AM_AppRegistry::getAutoStartEnabledAppObjects(QValueList<AM_AppObject const*>&) const@@VERSION		 // FUNC
AM_AppRegistry::getInstalledApplications(bool, QValueList<AM_AppLnk const*>&) const@@VERSION		 // FUNC
AM_AppRegistry::getLockEnabledAppObjects(QValueList<AM_AppRegistry::LockableAppObject>&) const@@VERSION		 // FUNC
AM_AppRegistry::getRegistryObject(QString const&) const@@VERSION		 // FUNC
AM_AppRegistry::getRootFolder() const@@VERSION		 // FUNC
AM_AppRegistry::initMetaObject()@@VERSION		 // FUNC
AM_AppRegistry::init()@@VERSION		 // FUNC
AM_AppRegistry::isAutoStartEnabled(QUuid const&, bool&) const@@VERSION		 // FUNC
AM_AppRegistry::moveRegistryObject(QString const&, QString const&, int)@@VERSION // FUNC
AM_AppRegistry::setAppLockValue(QUuid const&, int)@@VERSION		 // FUNC
AM_AppRegistry::setAutoStartEnabled(QUuid const&, bool)@@VERSION		 // FUNC
AM_AppRegistry::updateFolderOrder(QString const&, QStringList const&)@@VERSION	 // FUNC
AM_AppRegistry::updateRegistryObjectAppearance(QString const&, QString const&, QString const&, QString const&, QString const&, QString const&, bool)@@VERSION	 // FUNC
*/

class AM_AppRegistry : public QObject
{
    Q_OBJECT

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

    //AM_RESULT_CODE_T updateRegistryObjectAppearance( const QString & uid, 
    //    const QString & newName, const QString & newSVGIcon, 
    //    const QString & newSimpleIcon, bool temporary  = false);

    AM_RESULT_CODE_T moveRegistryObject(const QString & uid, 
            const QString & destFolderUid, int position = -1);

    AM_RESULT_CODE_T setAppLockValue(const QUuid & appId, int value);

	///
	//AM_RESULT_CODE_T clearJavaRegistryEntries(AM_RegistryObject::Attribute);
	AM_RESULT_CODE_T clearJavaRegistryEntries(int);
	///

signals:

    void signalFolderOrderUpdated(const QString &folderUid);

    void signalRegistryObjectUpdated(const QString &uid);

    void signalRegistryObjectMoved(const QString &uid, 
            const QString &srcFolderUid, const QString &destFolderUid);

    void signalAppObjectAdded(const QString &uid, const QString &folderUid);

    void signalAppObjectRemoved(const QString &uid, const QString &folderUid);

    void signalCardPlugged(const QStringList & folderUids);

    void signalCardUnplugged(const QStringList & folderUids);

private slots:
    void slotFolderOrderUpdated(const QString & folderUid);
    void slotRegistryObjectUpdated(const QString & uid);
    void slotRegistryObjectMoved(const QString &uid, 
            const QString &srcFolderUid, const QString &destFolderUid);
    void slotAppObjectAdded(const QString &uid, const QString &folderUid);
    void slotAppObjectRemoved(const QString &uid, const QString &folderUid);
    void slotCardPlugged(const QStringList & folderUids);
    void slotCardUnplugged(const QStringList & folderUids);

private:
    AM_AppRegistryImpl * m_impl;
    //AM_AppRegistry(const AM_AppRegistry & rhs);
    //AM_AppRegistry & operator=(const AM_AppRegistry & rhs);
};

#endif 
