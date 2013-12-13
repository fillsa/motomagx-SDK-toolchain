//Fix for E8 by Ant-ON, 23.03.2011

// Copyright (c) 09-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef HSPLUGINSETTINGINFO_H
#define HSPLUGINSETTINGINFO_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

#include <qstring.h>

class QWidget;

class HSPluginSettingInfo
{
public:

    virtual ~HSPluginSettingInfo(){};

    //virtual QString getIcon() const {return "";}
    
    virtual QString getValue() const {return QString::null;}

    virtual QString getName() const = 0;

    //virtual bool IsItemGrayout() const {return false;}

    virtual void showSetting(QWidget* parent) = 0;
};

#endif  
