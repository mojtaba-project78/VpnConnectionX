#include "XLogManagement.h"

XLogManagement m_log;

//==============================================================================
XLogManagement::XLogManagement()
{}

//==============================================================================
XLogManagement::~XLogManagement()
{
    if(m_file.isOpen())
        m_file.close();
}

//==============================================================================
void XLogManagement::initializing()
{
    LOG("initializing...");

    if(m_make_file) {
        m_folderName = "MyConfigurations";
        m_file.setFileName(QString("%1//%2").arg(m_folderName).arg("Log.txt"));
    }

    m_file.close();
}

//==============================================================================
void XLogManagement::makeFile(bool m_status)
{
    m_make_file = m_status;
}

//==============================================================================
void XLogManagement::addText(QString m_macro_file, QString m_macro_function, int m_macro_line, QString m_text)
{
    if(m_make_file)
        if(!m_file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
            qDebug() << "cant open file: " << m_file.fileName();
            return;
        }

    //FIXME: here we should check debug mode is enable or no
    //if(m_config->get("DEBUGGING/m_debugging").toBool() == false) {
    //    return;
    //}

    QDateTime m_calender = QDateTime::currentDateTime();
    QString m_date = m_calender.date().toString("yyyy/MM/dd");
    QString m_time = m_calender.time().toString("hh:mm:ss");

    QString m_data;
    if(!m_text.isEmpty())
        m_data = QString("[ %1 ][ %2 ] [ %3 ][%4][%5]: %6").arg(m_date).arg(m_time).arg(m_macro_file).arg(m_macro_function).arg(m_macro_line).arg(m_text);
    else
        m_data = QString("[ %1 ][ %2 ] [ %3 ][%4][%5]: emited.").arg(m_date).arg(m_time).arg(m_macro_file).arg(m_macro_function).arg(m_macro_line);

    qDebug() <<	m_data;

    m_data.append("\n");

    if(m_make_file) {
        m_file.write(m_data.toUtf8());
        m_file.close();
    }
}

