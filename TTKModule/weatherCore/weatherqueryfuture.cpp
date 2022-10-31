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
        m_reply = nullptr;
    }

    m_reply = m_manager->get(QNetworkRequest(QUrl(TTKCryptographicHash().decrypt(FUTURE_QUERY_URL, URL_KEY).arg(id))));
    connect(m_reply, SIGNAL(finished()), SLOT(searchFinshed()));
    QtNetworkErrorConnect(m_reply, this, replyError);
}

void WeatherQueryFuture::searchFinshed()
{
    if(m_reply == nullptr)
    {
        return;
    }

    if(m_reply->error() == QNetworkReply::NoError)
    {
        QByteArray bytes = m_reply->readAll();///Get all the data obtained by request
        m_futureList.clear();
#if TTK_QT_VERSION_CHECK(5,0,0)
        QJsonParseError jsonError;
        QJsonDocument parseDoucment = QJsonDocument::fromJson(bytes, &jsonError);
        ///Put the data into Json
        if(jsonError.error != QJsonParseError::NoError ||
           !parseDoucment.isObject())
        {
            Q_EMIT resolvedSuccess();
            return ;
        }

        QJsonObject jsonObject = parseDoucment.object();
        if(jsonObject.contains("success") &&
           jsonObject.take("success").toString() == "1")
        {
            QJsonArray array = jsonObject.value("result").toArray();
            for(int i = 0; i < array.count(); ++i)
            {
                jsonObject = array.at(i).toObject();

                WeatherObject::Weather weather;
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
            TTK_ERROR_STREAM(QString("Error: %1").arg(jsonObject.take("msg").toString()));
            Q_EMIT resolvedSuccess();
            return;
        }
#else
        QScriptEngine engine;
        QScriptValue sc = engine.evaluate("value=" + QString(bytes));
        if(sc.property("success").isValid() &&
           sc.property("success").toString() == "1")
        {
            if(sc.property("result").isArray())
            {
                QScriptValueIterator it(sc.property("result"));
                while(it.hasNext())
                {
                    it.next();
                    QScriptValue value = it.value();

                    WeatherObject::Weather weather;
                    weather.m_weaid = value.property("weaid").toString();
                    weather.m_days = value.property("days").toString();
                    weather.m_week = value.property("week").toString();
                    weather.m_citynm = value.property("citynm").toString();
                    weather.m_temperature = value.property("temperature").toString();
                    weather.m_humidity = value.property("humidity").toString();
                    weather.m_weather = value.property("weather").toString();
                    weather.m_wind = value.property("wind").toString();
                    weather.m_winp = value.property("winp").toString();
                    weather.m_temp_high = value.property("temp_high").toString();
                    weather.m_temp_low = value.property("temp_low").toString();
                    weather.m_humi_high = value.property("humi_high").toString();
                    weather.m_humi_low = value.property("humi_low").toString();
                    weather.m_weatidX = value.property("weather_icon").toString();
                    weather.m_weatidY = value.property("weather_icon1").toString();

                    m_futureList << weather;
                }
            }
        }
        else
        {
            TTK_ERROR_STREAM(QString("Error: %1").arg(sc.property("msg").toString()));
            Q_EMIT resolvedSuccess();
            return;
        }
#endif
    }

    Q_EMIT resolvedSuccess();
//    foreach(Weather var, m_futureList)
//    {
//        WeatherQuerPM2P5 *pm = new WeatherQuerPM2P5(this);
//        connect(pm, SIGNAL(repliedPM2P5Finished(WeatherPM2P5)),
//                    SLOT(repliedPM2P5Finished(WeatherPM2P5)));
//        pm->startToQuery(var.m_weaid);
//    }
}

void WeatherQueryFuture::repliedPM2P5Finished(const WeatherObject::WeatherPM2P5 &pm)
{
    foreach(WeatherObject::Weather var, m_futureList)
    {
        if(var.m_weaid == pm.m_weaidP)
        {
           var.m_pm2p5 = pm;
        }
    }
    Q_EMIT resolvedSuccess();
}

const WeatherObject::Weather& WeatherQueryFuture::getToday()
{
    if(m_futureList.empty())
    {
        m_futureList.append( WeatherObject::Weather() );
    }
    return m_futureList.front();
}

const WeatherObject::Weather &WeatherQueryFuture::getFuture(int index)
{
    if(index < 0 || index >= m_futureList.count())
    {
        return getToday();
    }
    return m_futureList[index];
}

const WeatherObject::WeatherList& WeatherQueryFuture::getFuture() const
{
    return m_futureList;
}
