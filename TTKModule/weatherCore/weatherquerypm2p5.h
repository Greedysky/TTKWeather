#ifndef WEATHERQUERYPM2P5_H
#define WEATHERQUERYPM2P5_H

/***************************************************************************
 * This file is part of the TTK Weather project
 * Copyright (C) 2015 - 2022 Greedysky Studio

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
 ***************************************************************************/

#include "weatherquery.h"

/*! @brief The class of the weather pm2p5 query.
 * @author Greedysky <greedysky@163.com>
 */
class TTK_MODULE_EXPORT WeatherQuerPM2P5 : public WeatherQuery
{
    Q_OBJECT
public:
    explicit WeatherQuerPM2P5(QObject *parent = 0);
    /*!
     * Object contsructor.
     */

    virtual void startToQuery(const QString &id = 0) override final;
    /*!
     * Start to query data.
     */

signals:
    void repliedPM2P5Finished(const WeatherObject::WeatherPM2P5 &pm);
    /*!
     * Download PM2P5 data finished.
     */

public slots:
    virtual void searchFinshed() override final;
    /*!
     * Download data from net finished.
     */

};

#endif // WEATHERQUERYPM2P5_H
