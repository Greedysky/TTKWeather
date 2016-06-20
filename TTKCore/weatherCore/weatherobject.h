#ifndef WEATHEROBJECT_H
#define WEATHEROBJECT_H

/* =================================================
 * This file is part of the weather project
 * Copyright (c) 2014 - 2015 Greedysky Studio
 * All rights reserved!
 * Redistribution and use of the source code or any derivative
 * works are strictly forbiden.
   =================================================*/

#include <QMap>

#ifdef Q_CC_GNU
#  pragma GCC diagnostic ignored "-Wunused-function"
#endif

#if QT_VERSION >= QT_VERSION_CHECK(5,0,0)
#  define MUSIC_QT_5
#  if QT_VERSION >= QT_VERSION_CHECK(5,2,0)
#    define MUSIC_WINEXTRAS
#  endif
#endif
///////////////////////////////////////

const QString CITY_QUERY_URL = "http://api.k780.com:88/?app=weather.city&format=json";
const QString FUTURE_QUERY_URL = "http://api.k780.com:88/?app=weather.future&weaid=%1&\
                                  appkey=15437&sign=cf444d86cbe7b5e13ab5958101d3044d&format=json";
const QString PM2P5_QUERY_URL = "http://api.k780.com:88/?app=weather.pm25&weaid=%1&\
                                  appkey=15437&sign=cf444d86cbe7b5e13ab5958101d3044d&format=json";
///Attention: the interface can be accessed only 750 times per hour
///////////////////////////////////////
///
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

    typedef QList<QStringList> MStringLists;    /* stringlists */
    typedef QList<int> MIntList;                /* intlist */
    typedef QList<MIntList> MIntLists;          /* intlists */
    typedef QSet<int> MIntSet;                  /* intset */
    typedef QSet<MIntSet> MIntSets;             /* intsets */
    typedef QMap<QString, QVariant> MStriantMap;    /* stringVariantMap */
    typedef QMap<QString, QStringList> MStringsListMap; /* stringStrlistsMap */
    typedef QMap<int, MIntList> MIntsListMap;        /* intIntlistMap */
    typedef QMap<qint64, QString> MIntStringMap;      /* intStrMap */
    typedef QMapIterator<QString, QVariant> MStriantMapIt;    /* stringVariantMapIt */
    typedef QMapIterator<QString, QStringList> MStringsListMapIt; /* stringStrlistsMapIt */
    typedef QMapIterator<int, MIntList> MIntsListMapIt;        /* intIntlistMapIt */
    typedef QMapIterator<qint64, QString> MIntStringMapIt;      /* intStrMapIt */
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
