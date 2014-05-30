#ifndef CALLS_Z6
#define CALLS_Z6

/*
Heder create by Ant-ON

Usage:

    PHONE_RecentCall_Interface * call = new PHONE_RecentCall_Interface();
    
    QSortedList<PHONE_ENG_RecentCall> callList;
    call->rc_getTable(CALL_CATEGORY_UNANSWERED, callList);
*/

#include <qdatetime.h>
#include <qsortedlist.h>

typedef enum
{
	CALL_CATEGORY_NONE,
	CALL_CATEGORY_ANSWERED,
	CALL_CATEGORY_UNANSWERED,
	CALL_CATEGORY_CALLED,
	CALL_CATEGORY_FREQUENT
} CALL_CATEGORY_T;

class PHONE_ENG_RecentCall
{
	uint data[20];
	
	public:	
		PHONE_ENG_RecentCall();
		PHONE_ENG_RecentCall(PHONE_ENG_RecentCall const&);
		PHONE_ENG_RecentCall(QString const&, QDateTime const&, int);
		PHONE_ENG_RecentCall(QString const&, QDateTime const&, int, bool);
		~PHONE_ENG_RecentCall();
		void setPhoneNumber(QString const&);
		void setStartDateTime(QDateTime const&);
		const QString getPhoneNumber() const;
		QDateTime const getStartDateTime() const;
};

class PHONE_RecentCall_Interface
{
	uint data[20];
	
	public:
		PHONE_RecentCall_Interface();
		~PHONE_RecentCall_Interface();
		int getLastDialedNumber(QString&);
		int rc_getTable(CALL_CATEGORY_T, QSortedList<PHONE_ENG_RecentCall>&);
		int rc_add(PHONE_ENG_RecentCall);
		int rc_clearNotification();
		int rc_deleteAll(CALL_CATEGORY_T);
		int rc_delete(PHONE_ENG_RecentCall const&);
		int rc_getMaxTelNoLength(CALL_CATEGORY_T, unsigned int&);
		int rc_getNumberRecords(CALL_CATEGORY_T, unsigned int&);
		int rc_getUsedRecords(CALL_CATEGORY_T, unsigned int&);
};

#endif
