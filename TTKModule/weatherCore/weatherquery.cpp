#include "weatherquery.h"

WeatherQuery::WeatherQuery(QObject *parent)
    : QObject(parent),
      m_reply(nullptr)
{
    m_manager = new QNetworkAccessManager(this);
}

WeatherQuery::~WeatherQuery()
{
    deleteAll();///The release of all the objects
    if(m_manager)
    {
        m_manager->deleteLater();
        m_manager = nullptr;
    }
}

void WeatherQuery::deleteAll()
{
    if(m_reply)
    {
        m_reply->deleteLater();
        m_reply = nullptr;
    }
}

void WeatherQuery::replyError(QNetworkReply::NetworkError)
{
    TTK_ERROR_STREAM("Abnormal network connection");
    deleteAll();
}
