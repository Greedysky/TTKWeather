#ifndef WEATHERQUERYPM2P5_H
#define WEATHERQUERYPM2P5_H

/* =================================================
 * This file is part of the TTK Weather project
 * Copyright (c) 2015 - 2017 Greedysky Studio
 * All rights reserved!
 * Redistribution and use of the source code or any derivative
 * works are strictly forbiden.
   =================================================*/

#include "weatherquery.h"

/*! @brief The class of the weather pm2p5 query.
 * @author Greedysky <greedysky@163.com>
 */
class WEATHER_CORE_EXPORT WeatherQuerPM2P5 : public WeatherQuery
{
    Q_OBJECT
public:
    explicit WeatherQuerPM2P5(QObject *parent = 0);
    /*!
     * Object contsructor.
     */

    virtual void startToQuery(const QString &id = 0) override;
    /*!
     * Start to query data.
     */

signals:
    void repliedPM2P5Finished(const WeatherObject::WeatherPM2P5 &pm);
    /*!
     * Download PM2P5 data finished.
     */

public slots:
    virtual void searchFinshed() override;
    /*!
     * Download data from net finished.
     */

};

#endif // WEATHERQUERYPM2P5_H
