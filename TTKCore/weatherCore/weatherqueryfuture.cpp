#include "weatherqueryfuture.h"
#include "weatherquerypm2p5.h"

WeatherQueryFuture::WeatherQueryFuture(QObject *parent)
    : WeatherQuery(parent)
{

}

void WeatherQueryFuture::startToQuery(const QString &id)
{
    if(m_reply)
    {
        m_reply->deleteLater();
        m_reply = NULL;
    }

    m_reply = m_manager->get(QNetworkRequest( QUrl(FUTURE_QUERY_URL.arg(id)) ));
    connect(m_reply, SIGNAL(finished()), SLOT(searchFinshed()) );
    connect(m_reply, SIGNAL(error(QNetworkReply::NetworkError)),this,
                     SLOT(replyError(QNetworkReply::NetworkError)) );
}

void WeatherQueryFuture::searchFinshed()
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

        m_futureList.clear();  ///Empty the last search to songsInfo
        QJsonObject jsonObject = parseDoucment.object();
        if(jsonObject.contains("success") &&
           jsonObject.take("success").toString() == "1")
        {
            QJsonArray array = jsonObject.value("result").toArray();
            for(int i=0; i<array.count(); ++i)
            {
                jsonObject = array.at(i).toObject();

                Weather weather;
                weather.m_weaid = jsonObject.value("weaid").toString();
                weather.m_days = jsonObject.value("days").toString();
                weather.m_week = jsonObject.value("week").toString();
                weather.m_citynm = jsonObject.value("citynm").toString();
                weather.m_temperature = jsonObject.value("temperature").toString();
                weather.m_humidity = jsonObject.value("humidity").toString();
                weather.m_weather = jsonObject.value("weather").toString();
                weather.m_wind = jsonObject.value("wind").toString();
                weather.m_winp = jsonObject.value("winp").toString();
                weather.m_temp_high = jsonObject.value("temp_high").toString();
                weather.m_temp_low = jsonObject.value("temp_low").toString();
                weather.m_humi_high = jsonObject.value("humi_high").toString();
                weather.m_humi_low = jsonObject.value("humi_low").toString();
                weather.m_weatidX = jsonObject.value("weather_icon").toString();
                weather.m_weatidY = jsonObject.value("weather_icon1").toString();

                m_futureList << weather;
            }
        }
        else
        {
            qDebug() << "Error:" << jsonObject.take("msg").toString();
            return;
        }
    }

    emit resolvedSuccess();
//    foreach(Weather var, m_futureList)
//    {
//        WeatherQuerPM2P5 *pm = new WeatherQuerPM2P5(this);
//        connect(pm, SIGNAL(repliedPM2P5Finished(WeatherPM2P5)),
//                    SLOT(repliedPM2P5Finished(WeatherPM2P5)));
//        pm->startToQuery(var.m_weaid);
//    }
}

void WeatherQueryFuture::repliedPM2P5Finished(const WeatherPM2P5 &pm)
{
    foreach(Weather var, m_futureList)
    {
        if(var.m_weaid == pm.m_weaidP)
        {
           var.m_pm2p5 = pm;
        }
    }
    emit resolvedSuccess();
}

const Weather& WeatherQueryFuture::getToday()
{
    if(m_futureList.empty())
    {
        m_futureList.append( Weather() );
    }
    return m_futureList.first();
}

const Weather &WeatherQueryFuture::getFuture(int index)
{
    if(index < 0 || index >= m_futureList.count())
    {
        return getToday();
    }
    return m_futureList[index];
}

const WeatherList& WeatherQueryFuture::getFuture() const
{
    return m_futureList;
}
