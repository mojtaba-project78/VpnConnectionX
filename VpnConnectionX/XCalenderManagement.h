#ifndef XCALENDERMANAGEMENT_H
#define XCALENDERMANAGEMENT_H

#include <QDateTime>

struct XTime
{
	QString m_time, m_date, m_timestamp;
};

class XCalenderManagement
{
public:

	XTime now();
};

extern XCalenderManagement m_calender;

#endif // XCALENDERMANAGEMENT_H
