#ifndef WEATHEROBJECT_H
#define WEATHEROBJECT_H

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

#include "ttkqtglobal.h"

/*! @brief The namespace of the application object.
 * @author Greedysky <greedysky@163.com>
 */
namespace TTK
{
    struct Weather
    {
        QString m_weaid;
        QString m_days;
        QString m_week;
        QString m_citynm;
        QString m_temperature;
        QString m_humidity;
        QString m_weather;
        QString m_wind;
        QString m_winp;
        QString m_temp_high;
        QString m_temp_low;
        QString m_humi_high;
        QString m_humi_low;
        QString m_weatidX;
        QString m_weatidY;
    };
    TTK_DECLARE_LIST(Weather);

}

#endif //  WEATHEROBJECT_H
