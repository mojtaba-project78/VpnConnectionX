#ifndef XAPPCONFIGURATION_H
#define XAPPCONFIGURATION_H

#include <QObject>
#include <QString>
#include <QDebug>
#include <QFile>
#include <QSettings>
#include <QVariant>
#include <QVariantMap>

#include <memory>

#include "XObjectManagement.h"
#include "XLogManagement.h"

class XAppConfiguration : public QObject
{
    Q_OBJECT
public:
    explicit XAppConfiguration(QObject *parent = nullptr);

        void initializing();

    Q_INVOKABLE
        QVariant get(QString m_key);

    Q_INVOKABLE
        void update(QString m_key, QVariant m_value);

private:
        QString m_folderName;
};

extern std::unique_ptr<XAppConfiguration> m_config;

#endif // XAPPCONFIGURATION_H
