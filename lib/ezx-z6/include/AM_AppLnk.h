

// Copyright (c) 24-Apr-07 - 2008 Motorola, Inc. All rights reserved.


#ifndef AM_APPLNK_H
#define AM_APPLNK_H

#ifndef __cplusplus
#error "This is a C++ header file; it requires C++ to compile."
#endif

class AM_AppLnk
{

public:
    enum AppType
    {
        InvalidAppType = -1,
        UndefinedAppType = InvalidAppType,
        NativeApp = 0,
        JavaApp = 1,
        FaultlineApp = 2,
        WebuiApp = 3
    };

    enum Attribute
    {
        InvalidAttr = 0,    

        System = 1,         
        Preloaded = 2,      
        Installed = 3       
    }; 

	//...
};

#endif

