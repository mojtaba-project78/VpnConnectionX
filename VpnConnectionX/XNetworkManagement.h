#ifndef XNETWORKMANAGEMENT_H
#define XNETWORKMANAGEMENT_H

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QScopedPointer>
#include <QTimer>
#include <memory>
#include <QFutureWatcher>
#include <QEventLoop>
#include <QTimer>
#include <functional>

#include "XLogManagement.h"

class XNetwork
{
public:
	QString toPostFormat(QVariantMap paramPost);

	void get(QString m_url, std::function<void()> myFunction);
	void get(QString m_url, QVector<QString> m_header, std::function<void()> myFunction);

	void post(QString m_url, QVariantMap m_postValue, std::function<void()> myFunction);
	void post(QString m_url, QVector<QString> m_header, QVariantMap m_postValue, std::function<void()> myFunction);

	QString get_response();

protected:
	void sendRequest(QString m_url, QVector<QString> m_header = {}, QVariantMap m_postValue = {}, std::function<void()> myFunction = {});

private:
	QScopedPointer<QNetworkAccessManager> m_manager;
	QNetworkRequest m_request;
	QNetworkReply *m_reply;
	QEventLoop m_loop;
	std::function<void()> myFunction;
	bool m_busy;
	QString m_response;
};

class XNetworkManagement
{
public:
	XNetworkManagement();
};

#endif // XNETWORKMANAGEMENT_H
