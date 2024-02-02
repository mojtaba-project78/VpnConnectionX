#ifndef XWINDOWMANAGEMENT_H
#define XWINDOWMANAGEMENT_H

#include <QObject>
#include <QString>
#include <QtDebug>
#include <memory>

#include "XAppConfiguration.h"
#include "XObjectManagement.h"
#include "XLogManagement.h"

class XWindowManagement : public QObject
{
    Q_OBJECT
public:
    explicit XWindowManagement(QObject *parent = nullptr);

public slots:
	void openWindow(int m_windowId);
	void openWindow(int m_windowId, const char* functionName);
	void openWindow(int m_windowId, const char* functionName, QVariant value);
	void openWindow(int m_windowId, const char* functionName, QVariantMap mapOfValue);

	void openPage(QString m_objectName);
	void openPage(QString m_objectName, QString functionName);
	void openPage(QString m_objectName, QString functionName, QVariantMap map);
	void closePage(QString objectName);

};

extern std::unique_ptr<XWindowManagement> m_window;

#endif // XWINDOWMANAGEMENT_H
