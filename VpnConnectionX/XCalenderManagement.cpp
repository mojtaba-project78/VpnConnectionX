#include "XCalenderManagement.h"

XCalenderManagement m_calender;

XTime XCalenderManagement::now()
{
	QDateTime m_datetime = QDateTime::currentDateTime();

	XTime m_time;
	m_time.m_date = m_datetime.toString("yyyy/MM/dd");
	m_time.m_time = m_datetime.toString("hh:mm");
	m_time.m_timestamp = QString::number(m_datetime.toTime_t());

	return m_time;
}
