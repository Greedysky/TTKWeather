#include "weatherquerycity.h"

#include <QStringList>

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
        m_reply = nullptr;
    }

    m_reply = m_manager->get(QNetworkRequest(QUrl(WeatherCryptographicHash().decrypt(CITY_QUERY_URL, URL_KEY))));
    connect(m_reply, SIGNAL(finished()), SLOT(searchFinshed()) );
    QtNetworkErrorConnect(m_reply, this, replyError);
}

QString WeatherQueryCity::getCityCode(const QString &name) const
{
    return m_cityMap[name].toString();
}

const TTKVariantMap& WeatherQueryCity::getCityCodes() const
{
    return m_cityMap;
}

void WeatherQueryCity::searchFinshed()
{
    if(m_reply == nullptr)
    {
        return;
    }

    if(m_reply->error() == QNetworkReply::NoError)
    {
        QByteArray bytes = m_reply->readAll();///Get all the data obtained by request
        m_cityMap.clear();
#if TTK_QT_VERSION_CHECK(5,0,0)
        QJsonParseError jsonError;
        QJsonDocument parseDoucment = QJsonDocument::fromJson(bytes, &jsonError);
        ///Put the data into Json
        if(jsonError.error != QJsonParseError::NoError || !parseDoucment.isObject())
        {
            Q_EMIT resolvedSuccess();
            return ;
        }

        QJsonObject jsonObject = parseDoucment.object();
        if(jsonObject.contains("success") && jsonObject.take("success").toString() == "1")
        {
            jsonObject = jsonObject.take("result").toObject();
            jsonObject = jsonObject.take("datas").toObject();

            QJsonObject indata;
            foreach(QString key, jsonObject.keys())
            {
                indata = jsonObject.value(key).toObject();
                m_cityMap[indata.value("citynm").toString()] = indata.value("weaid").toString();
            }
        }
        else
        {
            TTK_LOGGER_ERROR(QString("Error: %1").arg(jsonObject.take("msg").toString()));
            Q_EMIT resolvedSuccess();
            return;
        }
#else
        QScriptEngine engine;
        QScriptValue sc = engine.evaluate("value=" + QString(bytes));
        if(sc.property("success").isValid() &&
           sc.property("success").toString() == "1")
        {
            if(sc.property("result").isValid())
            {
                sc = sc.property("result");
                if(sc.property("datas").isValid())
                {
                    sc = sc.property("datas");
                    for(int i = 1; i < 3000; ++i)
                    {
                        QScriptValue value = sc.property(QString::number(i));
                        if(!value.isValid())
                        {
                            continue;
                        }

                        m_cityMap[value.property("citynm").toString()] = value.property("weaid").toString();
                    }
                }
            }
        }
        else
        {
            TTK_LOGGER_ERROR(QString("Error: %1").arg(sc.property("msg").toString()));
            Q_EMIT resolvedSuccess();
            return;
        }
#endif
    }
    Q_EMIT resolvedSuccess();
}
