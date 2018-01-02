#ifndef WEATHERQUERYFUTURE_H
#define WEATHERQUERYFUTURE_H

/* =================================================
 * This file is part of the TTK Weather project
 * Copyright (C) 2015 - 2018 Greedysky Studio

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
