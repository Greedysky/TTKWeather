#include "weatherquerycity.h"

#include <QStringList>

WeatherQueryCity::WeatherQueryCity(QObject *parent)
    : WeatherQuery(parent)
{

}

void WeatherQueryCity::startRequest(const QString &id)
{
    Q_UNUSED(id);
    if(m_reply)
    {
        m_reply->deleteLater();
        m_reply = nullptr;
    }

    QNetworkRequest request(TTK::Algorithm::mdII(CITY_QUERY_URL, false));
    TTK::makeUserAgentHeader(&request);

    m_reply = m_manager.get(request);
    connect(m_reply, SIGNAL(finished()), SLOT(downLoadFinished()));
    QtNetworkErrorConnect(m_reply, this, replyError, TTK_SLOT);
}

QString WeatherQueryCity::cityCode(const QString &name) const
{
    return m_cityMap[name].toString();
}

void WeatherQueryCity::downLoadFinished()
{
    if(m_reply == nullptr)
    {
        Q_EMIT downLoadDataChanged({});
        return;
    }

    if(m_reply->error() == QNetworkReply::NoError)
    {
        m_cityMap.clear();

        QJson::Parser json;
        bool ok = false;
        const QVariant &data = json.parse(m_reply->readAll(), &ok);
        if(ok)
        {
            QVariantMap value = data.toMap();
            if(value["success"] == "1")
            {
                value = value["result"].toMap();
                value = value["datas"].toMap();

                for(const QString &key : value.keys())
                {
                    const QVariantMap &city = value[key].toMap();
                    m_cityMap[city["citynm"].toString()] = city["weaid"].toString();
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
