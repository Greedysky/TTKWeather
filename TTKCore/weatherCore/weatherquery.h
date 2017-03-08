#ifndef WEATHERQUERY_H
#define WEATHERQUERY_H

/* =================================================
 * This file is part of the TTK Weather project
 * Copyright (c) 2015 - 2016 Greedysky Studio
 * All rights reserved!
 * Redistribution and use of the source code or any derivative
 * works are strictly forbiden.
   =================================================*/

#include "weatherobject.h"
#include "weathercryptographichash.h"
///////////////////////////////////////

const QString CITY_QUERY_URL   = "OVV1ZU9jUDVKbURUN29kQ3AvSTR0aTg5Z2RMaXNEd000U3dzaGMrU244Zkw0L3h4QlErWWgzTGcrenlxWGlLS2lVRmZVSXk2V1ZZPQ==";
const QString FUTURE_QUERY_URL = "S0crZVVyUWdpQVg1S05hUUNERXY0NmZkY3JCY1BpV0dOa1c0Z3VWYTVScFVIeDFpNWhnbmZpdnprN1RWeU1sdEt5TlFPY1NjVTVCbmsxZFY4b1VmUGVyQjk2SEJOWDZqOE1YOC9zWnQ3T2dYeWlZd0huZlVvR2FEVmdCVFphU25haVJCUHBQOUJLSWptSzFSNmZFTXYvOEo5ZENEcjRYZw==";
const QString PM2P5_QUERY_URL  = "LzJmUW92R3VMdW9UdVI5Uk9CaTJLWGhuRnJSbkVUZlJTbXFidjJCRDJwNnRvWFpRVWxrZ1c4MmM3ZzZ5RU15eGVsMExjTnZoYkQvTFpDQXZpVS9vb1NBRXhYTDVCeTBFZHNvc1FBSmIxUVJWd0ZvRk9waE1nN2FxbTAreFU1RFNRUi9vZkp5aHhGYUIvcXl6aG9uV1Y1NGtXR0k9";
///Attention: the interface can be accessed only 750 times per hour
///////////////////////////////////////
///
#ifdef WEATHER_QT_5
#   include <QJsonParseError>
#   include <QJsonDocument>
#   include <QJsonObject>
#   include <QJsonArray>
#else
#   include <QtScript/QScriptEngine>
#   include <QtScript/QScriptValue>
#   include <QtScript/QScriptValueIterator>
#endif

#include <QNetworkReply>
#include <QNetworkRequest>
#include <QNetworkAccessManager>

/*! @brief The class of the weather query abstract base.
 * @author Greedysky <greedysky@163.com>
 */
class WEATHER_CORE_EXPORT WeatherQuery : public QObject
{
    Q_OBJECT
public:
    explicit WeatherQuery(QObject *parent = 0);
    /*!
     * Object contsructor.
     */
    ~WeatherQuery();

    virtual void startToQuery(const QString &id = 0) = 0;
    /*!
     * Start to query data.
     * Subclass should implement this function.
     */

signals:
    void resolvedSuccess();
    /*!
     * Send download data from net.
     */

public slots:
    virtual void searchFinshed() = 0;
    /*!
     * Download data from net finished.
     * Subclass should implement this function.
     */
    void replyError(QNetworkReply::NetworkError error);
    /*!
     * Download reply error.
     */

protected:
    void deleteAll();
    /*!
     * Release the network object.
     */

    QNetworkAccessManager *m_manager;
    QNetworkReply *m_reply;

};

#endif // WEATHERQUERY_H
