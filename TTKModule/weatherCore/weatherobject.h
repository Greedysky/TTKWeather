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

#if QT_VERSION >= QT_VERSION_CHECK(5,0,0)
#  define WEATHER_QT_5
#  if QT_VERSION >= QT_VERSION_CHECK(5,2,0)
#    define WEATHER_WINEXTRAS
#  endif
#endif

namespace WeatherObject
{
    typedef signed char MInt8;           /* 8 bit signed */
    typedef unsigned char MUint8;        /* 8 bit unsigned */
    typedef short MInt16;                /* 16 bit signed */
    typedef unsigned short MUint16;      /* 16 bit unsigned */
    typedef int MInt32;                  /* 32 bit signed */
    typedef unsigned int MUint32;        /* 32 bit unsigned */
    typedef long long MInt64;            /* 64 bit signed */
    typedef unsigned long long MUint64;  /* 64 bit unsigned */

    typedef double MDouble;              /* double */
    typedef float MFloat;                /* float */
    typedef bool MBool;                  /* bool */

    typedef QList<QStringList> MStringLists;                      /* stringlists */
    typedef QList<int> MIntList;                                  /* intlist */
    typedef QList<MIntList> MIntLists;                            /* intlists */
    typedef QSet<int> MIntSet;                                    /* intset */
    typedef QSet<MIntSet> MIntSets;                               /* intsets */
    typedef QMap<QString, QVariant> MStriantMap;                  /* stringVariantMap */
    typedef QMap<QString, QStringList> MStringsListMap;           /* stringStrlistsMap */
    typedef QMap<int, MIntList> MIntsListMap;                     /* intIntlistMap */
    typedef QMap<qint64, QString> MIntStringMap;                  /* intStrMap */
    typedef QMapIterator<QString, QVariant> MStriantMapIt;        /* stringVariantMapIt */
    typedef QMapIterator<QString, QStringList> MStringsListMapIt; /* stringStrlistsMapIt */
    typedef QMapIterator<int, MIntList> MIntsListMapIt;           /* intIntlistMapIt */
    typedef QMapIterator<qint64, QString> MIntStringMapIt;        /* intStrMapIt */
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
