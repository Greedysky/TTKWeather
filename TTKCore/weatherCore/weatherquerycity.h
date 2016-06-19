#ifndef WEATHERQUERYCITY_H
#define WEATHERQUERYCITY_H

/* =================================================
 * This file is part of the TTK Weather project
 * Copyright (c) 2015 - 2016 Greedysky Studio
 * All rights reserved!
 * Redistribution and use of the source code or any derivative
 * works are strictly forbiden.
   =================================================*/

#include "weatherquery.h"

class WEATHER_CORE_EXPORT WeatherQueryCity : public WeatherQuery
{
    Q_OBJECT
public:
    explicit WeatherQueryCity(QObject *parent = 0);

    virtual void startToQuery(const QString &id = 0);

    inline QString getCityCode(const QString &name) const
    { return m_cityMap[name].toString(); }
    inline const MStriantMap& getCityCodeS() const
    { return m_cityMap; }

public slots:
    virtual void searchFinshed();

protected:
    MStriantMap m_cityMap;

};

#endif // WEATHERQUERYCITY_H
