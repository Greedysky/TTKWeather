#ifndef WEATHERQUERY_H
#define WEATHERQUERY_H

/* =================================================
 * This file is part of the TTK Weather project
 * Copyright (C) 2015 - 2017 Greedysky Studio

 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License along
 * with this program; If not, see <http://www.gnu.org/licenses/>.
 ================================================= */

#include "weatherobject.h"
#include "weathercryptographichash.h"
///////////////////////////////////////

const QString CITY_QUERY_URL   = "ekNER2dwVUVmdGNQMTEveHM5Mks5RVBDWWc3aUdSNUZna3lVSERMbE9PMjB5YnRiSldiVXVoMndkYVovdllMMjJvZU50TjRyVHRzPQ==";
const QString FUTURE_QUERY_URL = "ek9nWXpERUdmK3AxM2lYZTVLQlQweW9LKzEvZDZhYURwL0NmMlp4Z3JhbUV1U3c2Vkc1ZVZwZVFhTk8zcCtsNzRSUEtkOEhHblU4MnNhVnZQOVkwVnI1QldMM2dRR2VzeVFubW40U0ErdUhnUm1hN0NxcHN3amU1WmYwc2VmdGpGZExyYW92UzRnZHlabmNJL1dVVEx0Zm9rTUs1QURxQg==";
const QString PM2P5_QUERY_URL  = "aGV1THF2REJXRVhDOEpWQzU4NVNieXU2a2dYQTBaL3kxc2xLWnU5VGpmRGpyeWpUMUVaZGtlWW1BNGlwMGNUMXE5OVcvM2Ntc1hMazFuTVJBVVNBMHU2ZFpEYWlMaUFlMVBnR09YbWpBc21PQXR6eGg1TUtiays5NEZJenNzV0xaakZmeC9lZkI1NFdEZkFZNVAzN0JSTHVkQjg9";
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
