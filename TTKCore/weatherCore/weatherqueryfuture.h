#ifndef WEATHERQUERYFUTURE_H
#define WEATHERQUERYFUTURE_H

/* =================================================
 * This file is part of the TTK Weather project
 * Copyright (c) 2015 - 2016 Greedysky Studio
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

    const WeatherObject::Weather &getToday();
    const WeatherObject::Weather &getFuture(int index);
    const WeatherObject::WeatherList &getFuture() const;

public slots:
    virtual void searchFinshed();
    void repliedPM2P5Finished(const WeatherObject::WeatherPM2P5 &pm);

protected:
    WeatherObject::WeatherList m_futureList;

};

#endif // WEATHERQUERYFUTURE_H
