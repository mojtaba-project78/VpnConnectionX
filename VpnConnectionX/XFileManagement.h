#ifndef XFILEMANAGEMENT_H
#define XFILEMANAGEMENT_H

#include <QFile>
#include <QDir>
#include <QtDebug>
#include <QVector>
#include <QString>

class XFileManagement
{
public:
    XFileManagement();

    void initializing();

    void setApplicationDirectory(QString m_path);
    QString getApplicationDirectory();

public:
    QVector<QString> m_filesNameList;
    QVector<QString> m_fileNameResetingList;
    QString m_folderName;
    QString m_rootFolder;
    QString m_path;
};

extern XFileManagement m_file;

#endif // XFILEMANAGEMENT_H
