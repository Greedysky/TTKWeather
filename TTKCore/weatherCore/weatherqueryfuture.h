#ifndef WEATHERQUERYFUTURE_H
#define WEATHERQUERYFUTURE_H

/* =================================================
 * This file is part of the TTK Weather project
 * Copyright (c) 2015 - 2017 Greedysky Studio
 * All rights reserved!
 * Redistribution and use of the source code or any derivative
 * works are strictly forbiden.
   =================================================*/

#include "weatherquery.h"

/*! @brief The class of the weather future query.
 * @author Greedysky <greedysky@163.com>
 */
class WEATHER_CORE_EXPORT WeatherQueryFuture : public WeatherQuery
{
    Q_OBJECT
public:
    explicit WeatherQueryFuture(QObject *parent = 0);
    /*!
     * Object contsructor.
     */

    virtual void startToQuery(const QString &id = 0) override;
    /*!
     * Start to query data.
     */

    const WeatherObject::Weather &getToday();
    /*!
     * Get today weather information.
     */
    const WeatherObject::Weather &getFuture(int index);
    /*!
     * Get future weather information by day.
     */
    const WeatherObject::WeatherList &getFuture() const;
    /*!
     * Get all future weather information.
     */

public slots:
    virtual void searchFinshed() override;
    /*!
     * Download data from net finished.
     */
    void repliedPM2P5Finished(const WeatherObject::WeatherPM2P5 &pm);
    /*!
     * Download PM2P5 data finished.
     */

protected:
    WeatherObject::WeatherList m_futureList;

};

#endif // WEATHERQUERYFUTURE_H
