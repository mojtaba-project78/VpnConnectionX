#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "XApp.h"

int main(int argc, char *argv[])
{
	QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

	QGuiApplication app(argc, argv);

	// ### register classes here

	{
		//==============================================================================
		qmlRegisterSingletonType<XApp>("XApp.uri", 1, 0, "Api_app", [&](QQmlEngine *engine, QJSEngine *scriptEngine) -> QObject * {
			Q_UNUSED(engine)
			Q_UNUSED(scriptEngine)
			return m_app.get();
		});
		LOG(QString("Datatype { %1 } Successfully Registered.").arg("XApp"));

		//==============================================================================
		qmlRegisterSingletonType<XWindowManagement>("XWindowManagement.uri", 1, 0, "Api_windows", [&](QQmlEngine *engine, QJSEngine *scriptEngine) -> QObject * {
			Q_UNUSED(engine)
			Q_UNUSED(scriptEngine)
			return m_window.get();
		});
		LOG(QString("Datatype { %1 } Successfully Registered.").arg("XWindowManagement"));

		//==============================================================================
		qmlRegisterSingletonType<XAppConfiguration>("XAppConfiguration.uri", 1, 0, "Api_config", [&](QQmlEngine *engine, QJSEngine *scriptEngine) -> QObject * {
			Q_UNUSED(engine)
			Q_UNUSED(scriptEngine)
			return m_config.get();
		});
		LOG(QString("Datatype { %1 } Successfully Registered.").arg("XAppConfiguration"));

		//==============================================================================
	}

	QQmlApplicationEngine engine;
	const QUrl url(QStringLiteral("qrc:/main.qml"));
	QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
					 &app, [url](QObject *obj, const QUrl &objUrl) {
		if (!obj && url == objUrl)
			QCoreApplication::exit(-1);
	}, Qt::QueuedConnection);
	engine.load(url);

	m_object.InitializingObject(engine.rootObjects().first());

	m_file.initializing();

	m_sql.makeFile(false);
	m_sql.initializing();

	m_config->initializing();

	m_log.makeFile(false);
	m_log.initializing();

	m_window->openWindow(XData::Windows::WN_STARTUP);

	int r = app.exec();
	//==============================================================================
	m_app = nullptr;
	m_config = nullptr;
	m_window = nullptr;

	return r;
}
