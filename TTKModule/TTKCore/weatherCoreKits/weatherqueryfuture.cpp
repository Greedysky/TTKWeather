#include "weatherqueryfuture.h"

WeatherQueryFuture::WeatherQueryFuture(QObject *parent)
    : WeatherQuery(parent)
{

}

void WeatherQueryFuture::startRequest(const QString &id)
{
    if(m_reply)
    {
        m_reply->deleteLater();
        m_reply = nullptr;
    }

    QNetworkRequest request(TTK::Algorithm::mdII(FUTURE_QUERY_URL, false).arg(id));
    TTK::makeUserAgentHeader(&request);

    m_reply = m_manager.get(request);
    connect(m_reply, SIGNAL(finished()), SLOT(downLoadFinished()));
    QtNetworkErrorConnect(m_reply, this, replyError, TTK_SLOT);
}

void WeatherQueryFuture::downLoadFinished()
{
    if(m_reply == nullptr)
    {
        return;
    }

    if(m_reply->error() == QNetworkReply::NoError)
    {
        m_futureList.clear();

        QJson::Parser json;
        bool ok = false;
        const QVariant &data = json.parse(m_reply->readAll(), &ok);
        if(ok)
        {
            QVariantMap value = data.toMap();
            if(value["success"] == "1")
            {
                const QVariantList &datas = value["result"].toList();
                for(const QVariant &var : qAsConst(datas))
                {
                    if(var.isNull())
                    {
                        continue;
                    }

                    value = var.toMap();

                    TTK::Weather weather;
                    weather.m_weaid = value["weaid"].toString();
                    weather.m_days = value["days"].toString();
                    weather.m_week = value["week"].toString();
                    weather.m_citynm = value["citynm"].toString();
                    weather.m_temperature = value["temperature"].toString();
                    weather.m_humidity = value["humidity"].toString();
                    weather.m_weather = value["weather"].toString();
                    weather.m_wind = value["wind"].toString();
                    weather.m_winp = value["winp"].toString();
                    weather.m_temp_high = value["temp_high"].toString();
                    weather.m_temp_low = value["temp_low"].toString();
                    weather.m_humi_high = value["humi_high"].toString();
                    weather.m_humi_low = value["humi_low"].toString();
                    weather.m_weatidX = value["weather_icon"].toString();
                    weather.m_weatidY = value["weather_icon1"].toString();
                    m_futureList << weather;
                }
            }
        }
        else
        {
            TTK_ERROR_STREAM("Reply Error");
        }
    }

    Q_EMIT downLoadDataChanged({});
}

const TTK::Weather& WeatherQueryFuture::today()
{
    if(m_futureList.empty())
    {
        m_futureList.append(TTK::Weather());
    }
    return m_futureList.front();
}

const TTK::Weather &WeatherQueryFuture::future(int index)
{
    if(index < 0 || index >= m_futureList.count())
    {
        return today();
    }
    return m_futureList[index];
}

const TTK::WeatherList& WeatherQueryFuture::future() const
{
    return m_futureList;
}
