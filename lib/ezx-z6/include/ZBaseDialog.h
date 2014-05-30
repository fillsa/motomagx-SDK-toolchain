#ifndef __ZBASEDIALOG_H__
#define __ZBASEDIALOG_H__ 1

#include <qdialog.h>

/* Size: UNKNOWN. Not used by anyone. */

class ZBaseDialog : public QDialog
{
	Q_OBJECT
	unsigned int tmp[1024 - sizeof(QDialog)/4];

public:
    ZBaseDialog(QWidget*, char const*, int, unsigned int);
    virtual ~ZBaseDialog();

    void done(int);
    void accept();
    void reject();
    bool qwsEvent(QWSEvent*);
};

#endif
