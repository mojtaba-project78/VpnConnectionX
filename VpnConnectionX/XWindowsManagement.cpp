#include "XWindowsManagement.h"

std::unique_ptr<XWindowManagement> m_window(new XWindowManagement);

XWindowManagement::XWindowManagement(QObject *parent) : QObject(parent)
{}

//==============================================================================
void XWindowManagement::openWindow(int m_windowId)
{
	m_object.CallFunctionSingle("showWindow", m_windowId);
}

void XWindowManagement::openWindow(int m_windowId, const char *functionName)
{
	m_object.CallFunction(functionName);
	m_object.CallFunctionSingle("showWindow", m_windowId);
}

void XWindowManagement::openWindow(int m_windowId, const char *functionName, QVariant value)
{
	m_object.CallFunctionSingle(functionName, value);
	m_object.CallFunctionSingle("showWindow", m_windowId);
}

void XWindowManagement::openWindow(int m_windowId, const char *functionName, QVariantMap mapOfValue)
{
	m_object.CallFunction(functionName, mapOfValue);
	m_object.CallFunctionSingle("showWindow", m_windowId);
}

//==============================================================================
void XWindowManagement::openPage(QString m_objectName)
{
    m_object.CallFunction(m_objectName, "open");
}

//==============================================================================
void XWindowManagement::openPage(QString m_objectName, QString functionName)
{
    m_object.CallFunction(m_objectName, functionName.toStdString().c_str());
    m_object.CallFunction(m_objectName, "open");
}

//==============================================================================
void XWindowManagement::openPage(QString m_objectName, QString functionName, QVariantMap map)
{
    m_object.CallFunction(m_objectName, functionName.toStdString().c_str(), map);
    m_object.CallFunction(m_objectName, "open");
}

//==============================================================================
void XWindowManagement::closePage(QString m_objectName)
{
    m_object.CallFunction(m_objectName, "close");
}

