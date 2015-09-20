#ifndef WEATHERQUERYFUTURE_H
#define WEATHERQUERYFUTURE_H

/* =================================================
 * This file is part of the weather project
 * Copyright (c) 2014 - 2015 Greedysky Studio
 * All rights reserved!
 * Redistribution and use of the source code or any derivative
 * works are strictly forbiden.
   =================================================*/

#include "weatherquery.h"

class WEATHER_CORE_EXPORT WeatherQueryFuture : public WeatherQuery
{
    Q_OBJECT
public:
    explicit WeatherQueryFuture(QObject *parent = 0);

    virtual void startToQuery(const QString &id = 0);

    const Weather &getToday();
    const Weather &getFuture(int index);
    const WeatherList &getFuture() const;

public slots:
    virtual void searchFinshed();

protected:
    WeatherList m_futureList;

};

#endif // WEATHERQUERYFUTURE_H
