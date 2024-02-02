#include "XFileManagement.h"

XFileManagement m_file;

XFileManagement::XFileManagement()
{
    m_rootFolder = "tdata";
    m_folderName = "MyConfigurations";
    m_filesNameList = {
        QString("%1//%2").arg(m_folderName).arg("Configuration.ini"),
        QString("%1//%2").arg(m_folderName).arg("Log.txt"),
        QString("%1//%2").arg(m_rootFolder).arg("RegInformation.DAT")
    };

    m_fileNameResetingList = {
        QString("%1//%2").arg(m_folderName).arg("Log.txt")
    };
}

void XFileManagement::initializing()
{
    if(!QDir().exists(m_rootFolder))
        QDir().mkdir(m_rootFolder);

    if(!QDir().exists(m_folderName))
        QDir().mkdir(m_folderName);

    // reseting file if exist
    for(int index = 0; index < m_fileNameResetingList.size(); index++) {
        if(QFile::exists(m_fileNameResetingList.at(index)))
            QFile::resize(m_fileNameResetingList.at(index), 0);
    }

    // make file if not exist
    for(int index = 0; index < m_filesNameList.size(); index++) {
        if(!QFile::exists(m_filesNameList.at(index))) {
            QFile(m_filesNameList.at(index)).open(QIODevice::NewOnly);
        }
    }

    // close all files
    for(int index = 0; index < m_filesNameList.size(); index++) {
        QFile m_file(m_filesNameList.at(index));
        if(m_file.isOpen())
            m_file.close();
    }
}

void XFileManagement::setApplicationDirectory(QString m_path)
{
    this->m_path = m_path;
}

QString XFileManagement::getApplicationDirectory()
{
    return m_path;
}
