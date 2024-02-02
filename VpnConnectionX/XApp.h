#ifndef XAPP_H
#define XAPP_H

#include <QObject>

#include <memory>

#include "XCalenderManagement.h"
#include "XWindowsManagement.h"
#include "XNetworkManagement.h"
#include "XAppConfiguration.h"
#include "XLogManagement.h"
#include "XObjectManagement.h"
#include "XFileManagement.h"
#include "XSQLManagement.h"

class XApp : public QObject
{
    Q_OBJECT
public:
    explicit XApp(QObject *parent = nullptr);

signals:

};

extern std::unique_ptr<XApp> m_app;

#endif // XAPP_H
