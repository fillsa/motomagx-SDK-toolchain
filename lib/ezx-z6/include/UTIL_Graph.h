#ifndef __UTIL_GRAPH_H__
#define __UTIL_GRAPH_H__ 1

#include <qpixmap.h>

/* Size: UNKNOWN */

class UTIL_Graph
{
public:
    QPixmap drawNegativeColorPixmap(QPixmap const&);
    QPixmap createDisabledPixmap(QPixmap const&);
    void scalePixmap(unsigned char*, int, int, int, unsigned char*, int, int, int, int);
    void overlapPixmaps(QValueList<QPixmap>);
};

#endif
