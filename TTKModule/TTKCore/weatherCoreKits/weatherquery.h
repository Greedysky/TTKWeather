#ifndef WEATHERQUERY_H
#define WEATHERQUERY_H

/***************************************************************************
 * This file is part of the TTK Weather project
 * Copyright (C) 2015 - 2026 Greedysky Studio

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

#include "qjson/json.h"

///Attention: the interface can be accessed only 750 times per hour
static constexpr const char *CITY_QUERY_URL = "QXZyZjlwM05TR09KcEF6QWZCeVhiYUlQMkY2SXE4OEl2RzU5VVEzMnkvRzZ2Y3NQTzEzbmxUcHJBNk5XSjQvR1czYzRqUExWejdPcG9ibmpkL0RqR0tRR1h6UnFSK2g5a2VVM2RBYVdpS25TSmc2QldlOVQ1NmZ1dk5JM3E3RlpnU3RvcHZzUjdzSXJDVzdwYXdDNExBPT0=";
static constexpr const char *FUTURE_QUERY_URL = "WVRpbm1tSXJsZEdZRlRvYVowTkJWVGpTa3NBdXRuZXoxd1RVT3IxdWR0K20yMHhDd041aUt2emZ2aVEvUEFMb09wd1B5b09ueHZhZ05uN3htYWtxeW5ObmEzMVdPZ3FFUi9GVW5CN211MWFOaFlmMW05cmlGeGR0WXVUL3VnWDFXWTZMaU1GbHFpYnQzV2N5WVFmWDRsQ1o5NTQ9";

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
    virtual void startToRequest(const QString &id) = 0;

};

#endif // WEATHERQUERY_H
