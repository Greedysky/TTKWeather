#ifndef WEATHERQUERYPM2P5_H
#define WEATHERQUERYPM2P5_H

/* =================================================
 * This file is part of the weather project
 * Copyright (c) 2014 - 2015 Greedysky Studio
 * All rights reserved!
 * Redistribution and use of the source code or any derivative
 * works are strictly forbiden.
   =================================================*/

#include "weatherquery.h"

class WEATHER_CORE_EXPORT WeatherQuerPM2P5 : public WeatherQuery
{
    Q_OBJECT
public:
    explicit WeatherQuerPM2P5(QObject *parent = 0);

    virtual void startToQuery(const QString &id = 0);

signals:
    void repliedPM2P5Finished(const WeatherPM2P5 &pm);

public slots:
    virtual void searchFinshed();

};

#endif // WEATHERQUERYPM2P5_H
