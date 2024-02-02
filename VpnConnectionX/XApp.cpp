#include "XApp.h"

std::unique_ptr<XApp> m_app(new XApp);

XApp::XApp(QObject *parent) : QObject(parent)
{

}
