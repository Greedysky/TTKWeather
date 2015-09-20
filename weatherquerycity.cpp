#include "weatherquerycity.h"

WeatherQueryCity::WeatherQueryCity(QObject *parent)
    : WeatherQuery(parent)
{

}

void WeatherQueryCity::startToQuery(const QString &id)
{
    Q_UNUSED(id);
    if(m_reply)
    {
        m_reply->deleteLater();
        m_reply = NULL;
    }

    m_reply = m_manager->get(QNetworkRequest( QUrl(CITY_QUERY_URL) ));
    connect(m_reply, SIGNAL(finished()), SLOT(searchFinshed()) );
    connect(m_reply, SIGNAL(error(QNetworkReply::NetworkError)),this,
                     SLOT(replyError(QNetworkReply::NetworkError)) );
}

void WeatherQueryCity::searchFinshed()
{
    if(m_reply == NULL)
    {
        return;
    }
    m_reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
    if(m_reply->error() == QNetworkReply::NoError)
    {
        QByteArray bytes = m_reply->readAll();///Get all the data obtained by request
        QJsonParseError jsonError;
        QJsonDocument parseDoucment = QJsonDocument::fromJson(bytes, &jsonError);
        ///Put the data into Json
        if(jsonError.error != QJsonParseError::NoError ||
           !parseDoucment.isObject())
        {
            return ;
        }

        m_cityMap.clear();  ///Empty the last search to songsInfo
        QJsonObject jsonObject = parseDoucment.object();
        if(jsonObject.contains("success") &&
           jsonObject.take("success").toString() == "1")
        {
            jsonObject = jsonObject.take("result").toObject();
            QJsonObject indata;

            foreach(QString key, jsonObject.keys() )
            {
                indata = jsonObject.value(key).toObject();
                m_cityMap[indata.value("citynm").toString()] =
                          indata.value("weaid").toString();
            }
        }
        else
        {
            qDebug() << "Error:" << jsonObject.take("msg").toString();
            return;
        }
    }
    emit resolvedSuccess();
}
