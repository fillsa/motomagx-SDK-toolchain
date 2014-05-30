#ifndef _ZPOPUP_H
#define _ZPOPUP_H

#include <qdialog.h>

/* Size:272=68*4 */

class ZPopupHeader : public ZWidget
{
    Q_OBJECT

    unsigned int data[68-sizeof(ZWidget)/4];

public:
    virtual int ZPopupHeader::doLayout();
};

#endif
