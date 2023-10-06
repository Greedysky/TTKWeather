#ifndef WEATHERQUERY_H
#define WEATHERQUERY_H

/***************************************************************************
 * This file is part of the TTK Weather project
 * Copyright (C) 2015 - 2023 Greedysky Studio

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

#include "weatherobject.h"
#include "weatheralgorithmutils.h"
#include "ttkabstractnetwork.h"

#include "qjson/parser.h"

static const QString CITY_QUERY_URL   = "NW8yM1YwWUIrYytySHVON1F4NVJ1UG55UXhCOURHKzBtTjVvenBpUUVWN3lNNGtoVWtmdGdPK3VNU0k5ZXNTeDRIeE0zMmdUK1NTN3JPK2pSZDZqaEE2aU9RRi8zOTRoWVpUYmRVV2prNGZzQXVvdE1xb2JDaldLem4rRXFKckRzbERtcTl4OTVUd2lGU040UlRCdnpBPT0=";
static const QString FUTURE_QUERY_URL = "cXVteW9ic3NEenNTVVN1SkcvdUh0WkVvbXhGaFExRHdOS3JCckVDYzd3c0VwSTYxZzNaZDhnUkNGdlJBdXE5b09Yb0c4MUNEbW1LQWJTSkFuWWRRb3dnc3B1RU5ENFVWTFlpTkFPdTRjTVpCUHRnNk5XMURzTm5sZGx3K0N6VmdjM0dUc2VHWVJVaW5qQVh6blhvVFRmQ3QvQVU9";
///Attention: the interface can be accessed only 750 times per hour

/*! @brief The class of the weather query abstract base.
 * @author Greedysky <greedysky@163.com>
 */
class TTK_MODULE_EXPORT WeatherQuery : public TTKAbstractNetwork
{
    Q_OBJECT
public:
    /*!
     * Object constructor.
     */
    explicit WeatherQuery(QObject *parent = nullptr);

    /*!
     * Start to query data.
     * Subclass should implement this function.
     */
    virtual void startRequest(const QString &id) = 0;

};

#endif // WEATHERQUERY_H
