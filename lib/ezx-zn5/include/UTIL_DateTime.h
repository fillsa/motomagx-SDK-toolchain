//
// Writen by Ant-ON, 2010
//
// email: prozanton@gmail.com
//

#ifndef UTIL_DATATIME_H 
#define UTIL_DATATIME_H

#include <qstring.h>
#include <qdatetime.h>

class UTIL_DateTime : public QObject
{
    Q_OBJECT
public:
	UTIL_DateTime(QObject* parent=0, const char* name=0);
	~UTIL_DateTime();
	
	enum DateFormat
    {
		mm_dd_yyyy
	};
	
	enum TimeFormat
    {
		TIME_12,
		TIME_24	
	};
	
	enum DateAccuracy
    {
	};
	
	enum TimeAccuracy
    {
	};	
	
	QString dateToString(QDate const&, DateAccuracy);
	QString dateToString(QDate const&, DateFormat, DateAccuracy);
	QDateTime getCurrentUTC();
	DateFormat getDateFormat();
	void getDateTimeFormat();
	bool getLocalTimeZone(int&, int&, int&, double&, QString&, QString&);
	QString getMonthName(int);
	QString getMonthShortName(int);
	TimeFormat getTimeFormat();
	QString getTZRuleFromDstRule(QString const&);
	QString getWeekdayName(int);
	bool isDateTimeChangeAllowed();
	bool setDateFormat(DateFormat);
	bool setTimeFormat(TimeFormat);
	void setTimeZoneEnv();
	QString timeToString(QTime const&, TimeAccuracy);
	QString timeToString(QTime const&, TimeFormat, TimeAccuracy);
	QString toString(QDate const&);
	QString toString(QTime const&);
	void updateTimeZoneEnv();
	
private slots:
	void slotFormatChanged(QCString const&, QArray<char> const&);

private:
	uint fix[10];
};

#endif
