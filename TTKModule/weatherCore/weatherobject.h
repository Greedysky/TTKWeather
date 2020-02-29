#ifndef WEATHEROBJECT_H
#define WEATHEROBJECT_H

/* =================================================
 * This file is part of the TTK Weather project
 * Copyright (C) 2015 - 2020 Greedysky Studio

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

#include <QMap>
#include <QVariant>

#ifdef Q_CC_GNU
#  pragma GCC diagnostic ignored "-Wunused-function"
#endif

#define TTK_QT_VERSION_CHECK(major, minor, patch) (QT_VERSION >= QT_VERSION_CHECK(major, minor, patch))
#if TTK_QT_VERSION_CHECK(5,0,0)
#  define TTK_GREATER_NEW
#  if TTK_QT_VERSION_CHECK(5,2,0)
#    define TTK_WINEXTRAS
#  else
#    define TTK_NO_WINEXTRAS
#  endif
#else
#  define TTK_NO_WINEXTRAS
#endif

namespace WeatherObject
{
    typedef signed char                        TTKInt8;         /* 8 bit signed */
    typedef unsigned char                      TTKUInt8;        /* 8 bit unsigned */
    typedef short                              TTKInt16;        /* 16 bit signed */
    typedef unsigned short                     TTKUInt16;       /* 16 bit unsigned */
    typedef int                                TTKInt32;        /* 32 bit signed */
    typedef unsigned int                       TTKUInt32;       /* 32 bit unsigned */
    typedef long long                          TTKInt64;        /* 64 bit signed */
    typedef unsigned long long                 TTKUInt64;       /* 64 bit unsigned */

    typedef double                             TTKDouble;       /* double */
    typedef float                              TTKFloat;        /* float */
    typedef bool                               TTKBool;         /* bool */

    typedef std::string                        TTKString;       /* string */

    ///
    typedef QList<QVariant>                    TTKVariantList;            /* variantlist */
    typedef QList<int>                         TTKIntList;                /* intlist */
    typedef QSet<QVariant>                     TTKVariantSet;             /* variantset */
    typedef QSet<int>                          TTKIntSet;                 /* intset */
    typedef QMap<QString, QVariant>            TTKVariantMap;             /* stringVariantMap */
    typedef QMap<QString, QString>             TTKStringMap;              /* stringsMap */
    typedef QMap<QString, QStringList>         TTKStringListMap;          /* stringStrlistsMap */
    typedef QMap<int, TTKIntList>              TTKIntListMap;             /* intIntlistMap */
    typedef QMap<qint64, QString>              TTKIntStringMap;           /* intStrMap */
    typedef QMapIterator<QString, QVariant>    TTKVariantMapIterator;     /* stringVariantMapIterator */
    typedef QMapIterator<QString, QString>     TTKStringMapterator;       /* stringsMapIterator */
    typedef QMapIterator<QString, QStringList> TTKStringListMapIterator;  /* stringStrlistsMapIterator */
    typedef QMapIterator<int, TTKIntList>      TTKIntListMapIterator;     /* intIntlistMapIterator */
    typedef QMapIterator<qint64, QString>      TTKIntStringMapIterator;   /* intStrMapIterator */
    ///////////////////////////////////////

    typedef struct WeatherPM2P5
    {
        QString m_weaidP;
        QString m_aqi;
        QString m_aqiScope;
        QString m_aqiLevid;
        QString m_aqiLevnm;
        QString m_aqiRemark;
    }WeatherPM2P5;
    typedef QList<WeatherPM2P5> WeatherPM2P5List;
    ///////////////////////////////////////

    typedef struct Weather
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
        WeatherPM2P5 m_pm2p5;
    }Weather;
    typedef QList<Weather> WeatherList;
    ///////////////////////////////////////

}

#endif //  WEATHEROBJECT_H
