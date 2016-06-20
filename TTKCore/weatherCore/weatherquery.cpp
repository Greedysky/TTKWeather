#include "weatherquery.h"

WeatherQuery::WeatherQuery(QObject *parent)
    : QObject(parent), m_reply(NULL)
{
    m_manager = new QNetworkAccessManager(this);
}

WeatherQuery::~WeatherQuery()
{
    deleteAll();///The release of all the objects
    if(m_manager)
    {
        m_manager->deleteLater();
        m_manager = NULL;
    }
}

void WeatherQuery::deleteAll()
{
    if(m_reply)
    {
        m_reply->deleteLater();
        m_reply = NULL;
    }
}

void WeatherQuery::replyError(QNetworkReply::NetworkError)
{
    M_LOGGER_ERROR("Abnormal network connection");
    deleteAll();
}
