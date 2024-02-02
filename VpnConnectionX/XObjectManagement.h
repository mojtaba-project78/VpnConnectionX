#ifndef XOBJECTMANAGEMENT_H
#define XOBJECTMANAGEMENT_H

#include <QObject>
#include <QVariant>
#include <QVariantMap>

#include "XLogManagement.h"

class XObjectManagement : public QObject
{
    Q_OBJECT
public:
    explicit XObjectManagement(QObject *parent = nullptr);

    void InitializingObject(QObject* m_object);

    QObject* get();
    QVariant get(QString objectName, const char* propertyName);
    void set(QString objectName, const char* propertyName, QVariant m_value);

    void CallFunction(const char* functionName);
    void CallFunction(const char* functionName, QVariantMap mapOfValues);
    void CallFunctionSingle(const char* functionName, QVariant value);
    void CallFunction(QString objectName, const char* functionName);
    void CallFunction(QString objectName, const char* functionName, QVariantMap mapOfValues);
    void CallFunctionSingle(QString objectName, const char* functionName, QVariant value);

private:
    QObject* m_object;
};

extern XObjectManagement m_object;

#endif // XOBJECTMANAGEMENT_H
