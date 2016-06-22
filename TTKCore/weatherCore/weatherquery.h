#ifndef WEATHERQUERY_H
#define WEATHERQUERY_H

/* =================================================
 * This file is part of the TTK Weather project
 * Copyright (c) 2015 - 2016 Greedysky Studio
 * All rights reserved!
 * Redistribution and use of the source code or any derivative
 * works are strictly forbiden.
   =================================================*/

#include "weatherglobaldefine.h"
#include "weatherobject.h"

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
