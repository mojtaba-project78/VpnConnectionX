#include "XObjectManagement.h"

XObjectManagement m_object;

XObjectManagement::XObjectManagement(QObject *parent) : QObject(parent)
{

}

//==============================================================================
void XObjectManagement::InitializingObject(QObject *m_object)
{
    this->m_object = m_object;
}

//==============================================================================
QObject *XObjectManagement::get()
{
    return this->m_object;
}

//==============================================================================
QVariant XObjectManagement::get(QString objectName, const char *propertyName)
{
    if(m_object->findChild<QObject*>(objectName) != nullptr){
        LOG(QString("objectName '%1' not found."));
        return {};
    }

    return m_object->findChild<QObject*>(objectName)->property(propertyName);
}

//==============================================================================
void XObjectManagement::set(QString objectName, const char *propertyName, QVariant m_value)
{
    if(m_object->findChild<QObject*>(objectName) != nullptr){
        LOG(QString("objectName '%1' not found."));
        return;
    }

    m_object->findChild<QObject*>(objectName)->setProperty(propertyName, m_value);
}

//==============================================================================
void XObjectManagement::CallFunction(const char *functionName)
{
    QMetaObject::invokeMethod(m_object, functionName);
}

//==============================================================================
void XObjectManagement::CallFunction(const char *functionName, QVariantMap mapOfValues)
{
    QMetaObject::invokeMethod(m_object, functionName, Q_ARG(QVariant, QVariant::fromValue(mapOfValues)));
}

//==============================================================================
void XObjectManagement::CallFunctionSingle(const char *functionName, QVariant value)
{
    QMetaObject::invokeMethod(m_object, functionName, Q_ARG(QVariant, QVariant::fromValue(value)));
}

//==============================================================================
void XObjectManagement::CallFunction(QString objectName, const char *functionName)
{
    if(m_object->findChild<QObject*>(objectName) == nullptr) {
        LOG(QString("objectName '%1' not found."));
        return;
    }

    QObject* myObject = m_object->findChild<QObject*>(objectName);
    QMetaObject::invokeMethod(myObject, functionName);
}

//==============================================================================
void XObjectManagement::CallFunction(QString objectName, const char *functionName, QVariantMap mapOfValues)
{
    if(m_object->findChild<QObject*>(objectName) == nullptr) {
        LOG(QString("objectName '%1' not found."));
        return;
    }

    QObject* myObject = m_object->findChild<QObject*>(objectName);
    QMetaObject::invokeMethod(myObject, functionName, Q_ARG(QVariant, QVariant::fromValue(mapOfValues)));
}

//==============================================================================
void XObjectManagement::CallFunctionSingle(QString objectName, const char *functionName, QVariant value)
{
    if(m_object->findChild<QObject*>(objectName) == nullptr) {
        LOG(QString("objectName '%1' not found."));
        return;
    }

    QObject* myObject = m_object->findChild<QObject*>(objectName);
    QMetaObject::invokeMethod(myObject, functionName, Q_ARG(QVariant, QVariant::fromValue(value)));
}
