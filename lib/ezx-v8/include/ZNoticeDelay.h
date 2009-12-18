#ifndef _ZNOTICEDELAY_H_
#define _ZNOTICEDELAY_H_
#include "ZPopup.h"

#include "qstring.h"
#include "qobjectdefs.h"
#include "qwidget.h"
#include "qglobal.h"
#include "qnamespace.h"
#include "qpixmap.h"
#include "qpalette.h"
#include "qevent.h"



class ZMeter;
class ZMeterModule;

struct ZNoticeDelayPrivate;

class ZNoticeDelay : public ZPopup
{
    Q_OBJECT

public:
    ZNoticeDelay(const QString& strInstructText,
                 ZMeterModule* pMeterModule = NULL,
                 QWidget* parent = NULL,        
                 const char* name = 0,
                 WFlags f = 0);

    virtual ~ZNoticeDelay();
    ZMeterModule* getMeterModule();
    ZMeter* getMeter();


protected slots:

    virtual void slotResizeAllChild(int);

protected:
    void keyPressEvent( QKeyEvent *e );

private:

    ZNoticeDelayPrivate* mpData;


};


#endif

