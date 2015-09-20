#include "weatherquerypm2p5.h"

WeatherQuerPM2P5::WeatherQuerPM2P5(QObject *parent)
    : WeatherQuery(parent)
{

}

void WeatherQuerPM2P5::startToQuery(const QString &id)
{
    if(m_reply)
    {
        m_reply->deleteLater();
        m_reply = NULL;
    }

    m_reply = m_manager->get(QNetworkRequest( QUrl(PM2P5_QUERY_URL.arg(id)) ));
    connect(m_reply, SIGNAL(finished()), SLOT(searchFinshed()) );
    connect(m_reply, SIGNAL(error(QNetworkReply::NetworkError)),this,
                     SLOT(replyError(QNetworkReply::NetworkError)) );
}

void WeatherQuerPM2P5::searchFinshed()
{
    if(m_reply == NULL)
    {
        return;
    }

    WeatherPM2P5 pm2p5List;
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

        QJsonObject jsonObject = parseDoucment.object();
        if(jsonObject.contains("success") &&
           jsonObject.take("success").toString() == "1")
        {
            jsonObject = jsonObject.value("result").toObject();

            pm2p5List.m_weaidP = jsonObject.value("weaid").toString();
            pm2p5List.m_aqi = jsonObject.value("aqi").toString();
            pm2p5List.m_aqiLevid = jsonObject.value("aqi_levid").toString();
            pm2p5List.m_aqiLevnm = jsonObject.value("aqi_levnm").toString();
            pm2p5List.m_aqiScope = jsonObject.value("aqi_scope").toString();
            pm2p5List.m_aqiRemark = jsonObject.value("aqi_remark").toString();
        }
        else
        {
            qDebug() << "Error:" << jsonObject.take("msg").toString();
            return;
        }
    }

    emit repliedPM2P5Finished(pm2p5List);
    deleteLater();
}
