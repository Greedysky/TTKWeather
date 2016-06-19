#ifndef WEATHERQUERY_H
#define WEATHERQUERY_H

/* =================================================
 * This file is part of the TTK Weather project
 * Copyright (c) 2015 - 2016 Greedysky Studio
 * All rights reserved!
 * Redistribution and use of the source code or any derivative
 * works are strictly forbiden.
   =================================================*/

#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonParseError>

#include <QNetworkReply>
#include <QNetworkRequest>
#include <QNetworkAccessManager>

#include "weatherlibexportglobal.h"
#include "weatherobject.h"

class WEATHER_CORE_EXPORT WeatherQuery : public QObject
{
    Q_OBJECT
public:
    explicit WeatherQuery(QObject *parent = 0);
    ~WeatherQuery();

    virtual void startToQuery(const QString &id = 0) = 0;

signals:
    void resolvedSuccess();

public slots:
    virtual void searchFinshed() = 0;
    void replyError(QNetworkReply::NetworkError error);

protected:
    void deleteAll();

    QNetworkAccessManager *m_manager;
    QNetworkReply *m_reply;

};

#endif // WEATHERQUERY_H
