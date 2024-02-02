#include "XSQLManagement.h"

XSQLManagement m_sql;

//==============================================================================
XSQLManagement::XSQLManagement()
{
    m_folderName = "tdata";
    m_maximum_items = 200;
}

//==============================================================================
XSQLManagement::~XSQLManagement()
{
    XData::db.close();
}

//==============================================================================
void XSQLManagement::makeFile(bool m_status)
{
    m_makeFile = m_status;
}

//==============================================================================
void XSQLManagement::initializing()
{
    LOG("initializing...");
    LOG(QString("database checking."));

    // ### check if we using database
    if(!m_makeFile) {
        LOG("database is disabled in project..");
        return;
    }

    if(!QFile::exists(QString("%1//%2").arg(m_folderName).arg("RegInformation.DAT"))) {
        LOG(QString("database initializing faild: %1").arg(QString("%1//%2").arg(m_folderName).arg("RegInformation.DAT")));
        return;
    }

    XData::db = QSqlDatabase::addDatabase("QSQLITE");

    LOG(QString("database catched."));
    XData::db.setDatabaseName(QString("%1//%2").arg(m_folderName).arg("RegInformation.DAT"));

    if(!XData::db.open()) {
        LOG(QString("can't open database: %1").arg(QString("%1//%2").arg(m_folderName).arg("RegInformation.DAT")));
        LOG(QString("error: %1").arg(XData::db.lastError().text()));
        return;
    }

    if(!XData::db.isValid()) {
        LOG(QString("database is not valid: %1").arg(QString("%1//%2").arg(m_folderName).arg("RegInformation.DAT")));
        LOG(QString("error: %1").arg(XData::db.lastError().text()));
        return;
    }

    if(!XData::db.isOpen()) {
        LOG(QString("database is not opened: %1").arg(QString("%1//%2").arg(m_folderName).arg("RegInformation.DAT")));
        LOG(QString("error: %1").arg(XData::db.lastError().text()));
        return;
    }

    //==============================================================================
    // table name defenition here
    QueryResult m_result = query(QString("CREATE TABLE IF NOT EXISTS /**/"));

    if(!m_result.isQueryOk)
        LOG(QString("table /**/ can't create, error: %1").arg(m_result.m_query.lastError().text()));

    // {}

    //==============================================================================
    LOG("database is ready.");
}

//==============================================================================
QueryResult XSQLManagement::query_pagination(QString m_sql_query, int m_page)
{
    int m_offset =  ( m_maximum_items * m_page ) - m_maximum_items;

    QSqlQuery m_query;
    if(m_page < 1) {
        LOG(QString("query: %1, page: %2").arg(m_sql_query).arg(m_page));
        return QueryResult(false, m_query);
    }

    m_sql_query.append(" order by m_index DESC");

    m_sql_query.append(QString(" limit %1 offset %2").arg(m_maximum_items).arg(m_offset));
    m_query.prepare(m_sql_query);
    if(!m_query.exec()) {
        LOG(QString("query error: %1").arg(m_query.lastError().text()));
        return QueryResult(false, m_query);
    }
    else
        return QueryResult(true, m_query);;
}

//==============================================================================
QueryResult XSQLManagement::query(QString m_sql_query)
{
    QSqlQuery m_query;
    m_query.prepare(m_sql_query);
    if(!m_query.exec()) {
        return QueryResult(false, m_query);
    }
    else
        return QueryResult(true, m_query);
}
