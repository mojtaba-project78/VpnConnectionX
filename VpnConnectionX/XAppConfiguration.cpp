#include "XAppConfiguration.h"

std::unique_ptr<XAppConfiguration> m_config(new XAppConfiguration);

//==============================================================================
XAppConfiguration::XAppConfiguration(QObject *parent) : QObject(parent)
{
    m_folderName = "MyConfigurations";
}

void XAppConfiguration::initializing()
{
    LOG("initializing...");

    if(!QFile::exists(QString("%1//%2").arg(m_folderName).arg("Configuration.ini"))) {
        LOG(QString("file not found: %1").arg(QString("%1//%2").arg(m_folderName).arg("Configuration.ini")));

        //==============================================================================
        // creating data types
        QSettings m_config(QString("%1//%2").arg(m_folderName).arg("Configuration.ini"), QSettings::Format::IniFormat);
        m_config.setValue("WARNINGS/DONT_EDIT_REWRITE_VALUES", "");

        return;
    }
    QVariantMap map;

    //==============================================================================
    // ### define variables here...
    map.clear();
}

//==============================================================================
QVariant XAppConfiguration::get(QString m_key)
{
    QSettings m_config(QString("%1//%2").arg(m_folderName).arg("Configuration.ini"), QSettings::Format::IniFormat);
    return m_config.value(m_key);
}

//==============================================================================
void XAppConfiguration::update(QString m_key, QVariant m_value)
{
	LOG(QString("Config Updated from (%1: %2) to (%3: %4)").arg(m_key).arg(get(m_key).toString()).arg(m_key).arg(m_value.toString()));
    QSettings m_config(QString("%1//%2").arg(m_folderName).arg("Configuration.ini"), QSettings::Format::IniFormat);
    m_config.setValue(m_key, m_value);
}
