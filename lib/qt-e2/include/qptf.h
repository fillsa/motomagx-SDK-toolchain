//////////////////////////////////////////////////////////////////////////
//
//  fox Add
//
//////////////////////////////////////////////////////////////////////////

#ifndef _QPTF_H_
#define _QPTF_H_

#ifndef QT_H
#include "qstring.h"
#include "qrect.h"
#include "qpixmap.h"
#endif // QT_H

class Q_EXPORT QPTF
{
    
public:
    QPTF(void);
    virtual ~QPTF();
    virtual int getPacketId();
    virtual int ptf_getState();
    virtual int globalRect();
    virtual int sendPackage();
    virtual int sendPackage(int, QRect, int, int, QString, QString);
    virtual int getPackageType();
    virtual int getPtfText();
    virtual int setPtfText(const QString&);
    virtual int getPtfPixmap();
    virtual int getPtfIconId();
    virtual int setPtfIconId(const QString&);

    int fillInIcon(unsigned char*, QString);
    int fillInRect(unsigned char*, QRect);
    int fillInRect(unsigned char*, int, int, int, int);
    int fillInText(unsigned char*, QString);
    int fillInType(unsigned char*);
    int fillInType(unsigned char*, int);
    int decrePackNo(void);
    int fillInState(unsigned char*);
    int fillInState(unsigned char*, int);
    int getWritePipe(void);
    int isFlexBitSet(void);
    int setPtfPixmap(const QPixmap&);
    int setPtfPixmap(const QString&);
    int setPtfOverlay(const QString&);
    int closeWritePipe(void);
    int fillInHeadTime(unsigned char*, int);
    int setPackageType(int);
    int createWritePipe(void);
    int sendPackage_Base(void);
    int fillInPayloadSend(unsigned char*, int);
    int getTotalRectangle(void);
    int sendPackage_Button(void);
    int sendPackage_Slider(void);
    int sendPackage_CheckBox(void);
    int sendPackage_RadioButton(void);
    int report(void);
    int sendEnd(void);
    int setPackNo(unsigned char);
private:
    int PackageType;    //fox f: 4 = 0
    QString FValue8;    //fox f: 8
    QString FValueC;    //fox f: $C
    int temp10;         //fox f: $10 = 0
    int temp14;         //fox f: $14 = 0
    int temp18;         //fox f: $18 = -1
    int temp1C;         //fox f: $1C = 0

    static int _bflex;    //.bss:417708B8 _ZN4QPTF6_bflexE % 4                    ; DATA XREF: .got:4176AB98.o
    static int _shmbuff;  //.bss:417708C0 _ZN4QPTF8_shmbuffE % 4                  ; DATA XREF: .got:4176BEA4.o
    static const int ptf_pipe = -1;  //.data:4175D5F0 _ZN4QPTF8ptf_pipeE DCD 0xFFFFFFFF       ; DATA XREF: .got:4176B8FC.o
    static int _flex_set; //.bss:417708BC _ZN4QPTF9_flex_setE % 4                 ; DATA XREF: .got:4176AEBC.o
};

#endif
