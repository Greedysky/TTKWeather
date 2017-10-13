#ifndef WEATHERLOGGER_H
#define WEATHERLOGGER_H

/* =================================================
 * This file is part of the TTK Weather project
 * Copyright (C) 2015 - 2017 Greedysky Studio

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

#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include "weathersingleton.h"

#define CURRENTTIME QTime::currentTime().toString("hh:mm:ss:zzz")
#define CURRENTDATE QDate::currentDate().toString("yyyy-MM-dd")
#define LOG_END  QString("log::npos")

#define M_LOGGER (*WeatherLogger::createInstance())
#define M_MESSAGE(str, msg) \
{ \
    M_LOGGER.setLevel(msg); \
    M_LOGGER << str << LOG_END;\
}

#ifdef WEATHER_DEBUG
    #define M_LOGGER_INFO(str)  M_MESSAGE(str, "[Info]")
    #define M_LOGGER_DEBUG(str) M_MESSAGE(str, "[Debug]")
    #define M_LOGGER_WARN(str)  M_MESSAGE(str, "[Warn]")
    #define M_LOGGER_TRACE(str) M_MESSAGE(str, "[Trace]")
    #define M_LOGGER_ERROR(str) M_MESSAGE(str, "[Error]")
    #define M_LOGGER_FATAL(str) M_MESSAGE(str, "[Fatal]")
#else
    #define M_LOGGER_INFO(str)  Q_UNUSED(str)
    #define M_LOGGER_DEBUG(str) Q_UNUSED(str)
    #define M_LOGGER_WARN(str)  Q_UNUSED(str)
    #define M_LOGGER_TRACE(str) Q_UNUSED(str)
    #define M_LOGGER_ERROR(str) Q_UNUSED(str)
    #define M_LOGGER_FATAL(str) Q_UNUSED(str)
#endif

/*! @brief The class of the application logger.
 * @author Greedysky <greedysky@163.com>
 */
class WEATHER_CORE_EXPORT WeatherLogger
{
public:
    static inline WeatherLogger* createInstance()
    {
        static WeatherLogger obj;
        return &obj;
    }
    /*!
     * Get object instance ptr.
     */

    inline void setLevel(const QString &level)
    {
        m_levelType = level;
    }
    /*!
     * Set logger level.
     */
    inline QString level() const
    {
        return m_levelType;
    }
    /*!
     * Get logger level.
     */

    inline WeatherLogger &operator <<(bool t)
    {
#ifdef WEATHER_DEBUG
        m_streamString.append( QString("%1 ").arg(t ? "true" : "false") );
#else
        Q_UNUSED(t);
#endif
        return *this;
    }
    inline WeatherLogger &operator<<(char t) { return debugData<char>(t); }
    inline WeatherLogger &operator<<(signed short t) { return debugData<short>(t);}
    inline WeatherLogger &operator<<(unsigned short t) { return debugData<ushort>(t); }
    inline WeatherLogger &operator<<(signed int t) { return debugData<int>(t); }
    inline WeatherLogger &operator<<(unsigned int t) { return debugData<uint>(t); }
    inline WeatherLogger &operator<<(signed long t) { return debugData<long>(t); }
    inline WeatherLogger &operator<<(unsigned long t) { return debugData<ulong>(t); }
    inline WeatherLogger &operator<<(qint64 t) { return debugData<qint64>(t); }
    inline WeatherLogger &operator<<(quint64 t) { return debugData<quint64>(t); }
    inline WeatherLogger &operator<<(float t) { return debugData<float>(t); }
    inline WeatherLogger &operator<<(double t) { return debugData<double>(t); }
    inline WeatherLogger &operator<<(const char *t) { return debugData<const char*>(t); }
    inline WeatherLogger &operator<<(const QString &t)
    {
#ifdef WEATHER_DEBUG
        if(t == LOG_END)
        {
            m_stream << QString("[%1 %2]:  %3").arg(CURRENTDATE).arg(CURRENTTIME).arg(m_streamString) << endl;
            m_streamString.clear();
        }
        else
        {
            debugData<QString>(t);
        }
#else
        Q_UNUSED(t);
#endif
        return *this;
    }
    inline WeatherLogger &operator<<(const QStringRef &t) { return debugData<QString>(t.toString()); }
    inline WeatherLogger &operator<<(const QLatin1String &t) { return debugData<QLatin1String>(t); }
    inline WeatherLogger &operator<<(const QByteArray &t) { return debugData<QString>(QString(t)); }
    /*!
     * Operator << override.
     */

private:
    WeatherLogger()
    {
#ifdef WEATHER_DEBUG
        m_file.setFileName("logger.txt");
        m_file.open(QIODevice::WriteOnly | QIODevice::Append);
        m_stream.setDevice(&m_file);
        m_stream << QString().rightJustified(70, '=') << endl;
        m_levelType = "[Info]";
#endif
    }
    /*!
     * Object contsructor.
     */

    ~WeatherLogger()
    {
#ifdef WEATHER_DEBUG
        m_file.close();
#endif
    }

    template <class T>
    WeatherLogger &debugData(const T &data)
    {
#ifdef WEATHER_DEBUG
        m_streamString.append( QString("%1 %2 ").arg(m_levelType).arg(data) );
#else
        Q_UNUSED(data);
#endif
        return *this;
    }
    /*!
     * Output debug data into local file.
     */

    QTextStream m_stream;
    QString m_streamString;
    QString m_levelType;
    QFile m_file;

};

#endif // WEATHERLOGGER_H
