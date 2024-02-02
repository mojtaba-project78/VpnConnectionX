#include "XNetworkManagement.h"

XNetworkManagement::XNetworkManagement()
{

}

QString XNetwork::toPostFormat(QVariantMap paramPost)
{
	QString post;
	for(int index = 0; index < paramPost.size(); index++)
		if(index == 0)
			post += QString("%1=%2").arg(paramPost.keys().at(index)).arg(paramPost.value(paramPost.keys().at(index)).toString());
		else
			post += QString("&%1=%2").arg(paramPost.keys().at(index)).arg(paramPost.value(paramPost.keys().at(index)).toString());

	return post;
}

//==============================================================================
void XNetwork::get(QString m_url, std::function<void ()> myFunction)
{
	this->sendRequest(m_url, {}, {}, myFunction);
}

void XNetwork::get(QString m_url, QVector<QString> m_header, std::function<void ()> myFunction)
{
	this->sendRequest(m_url, m_header, {}, myFunction);
}

//==============================================================================
void XNetwork::post(QString m_url, QVariantMap m_postValue, std::function<void ()> myFunction)
{
	this->sendRequest(m_url, {}, m_postValue, myFunction);
}

void XNetwork::post(QString m_url, QVector<QString> m_header, QVariantMap m_postValue, std::function<void ()> myFunction)
{
	this->sendRequest(m_url, m_header, m_postValue, myFunction);
}

QString XNetwork::get_response()
{
	return m_response;
}

//==============================================================================
void XNetwork::sendRequest(QString m_url, QVector<QString> m_header, QVariantMap m_postValue, std::function<void()> m_function)
{
	m_busy = true;

	m_manager.reset(new QNetworkAccessManager);

	m_request.setUrl(QUrl(m_url));
	if(!m_header.isEmpty())
		for(int index = 0; index < m_header.size(); index++)
			m_request.setRawHeader(m_header.at(index).split(':').at(0).toUtf8(), m_header.at(index).split(':').at(1).toUtf8());

	this->myFunction = m_function;

	QObject::connect(m_manager.data(), &QNetworkAccessManager::finished, &m_loop, &QEventLoop::quit);
	QObject::connect(m_manager.data(), &QNetworkAccessManager::finished, [&]()
	{
		m_busy = false;
	});

	// ### manage request timeout
	QTimer::singleShot(8000, [&]()
	{
		m_reply->abort();
		m_busy = false;
		LOG("request timeout.");
	});

	if(m_postValue.isEmpty())
		m_reply = m_manager->get(m_request);
	else
		m_reply = m_manager->post(m_request, toPostFormat(m_postValue).toUtf8());

	m_loop.exec();

	if(m_reply->error() == QNetworkReply::NoError)
	{
		m_response =  m_reply->readAll();
		myFunction();
	}
	else
	{
		LOG(QString("Network Error: %1").arg(m_reply->errorString()));
		return;
	}
}
