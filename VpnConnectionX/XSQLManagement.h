#ifndef XSQLMANAGEMENT_H
#define XSQLMANAGEMENT_H

#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

#include "XObjectManagement.h"
#include "XLogManagement.h"
#include "XData.h"

struct QueryResult
{
    QueryResult(){}
    QueryResult(bool isQueryOk, QSqlQuery m_query) :
        isQueryOk(isQueryOk), m_query(m_query)
    {}
    void setData(bool isQueryOk, QSqlQuery m_query) {
        this->m_query = m_query;
        this->isQueryOk =  isQueryOk;
    }
    void clear() {
        m_query.clear();
        isQueryOk = NULL;
    }

    bool isQueryOk;
    QSqlQuery m_query;
};

//==============================================================================
class XSQLManagement
{
public:
    XSQLManagement();
    ~XSQLManagement();

    void makeFile(bool m_status);

    void initializing();

    QueryResult query(QString m_sql_query);
    QueryResult query_pagination(QString m_sql_query, int m_page = 1);

    int m_maximum_items;
private:
    QString m_folderName;
    bool m_makeFile;
};

extern XSQLManagement m_sql;

#endif // XSQLMANAGEMENT_H
