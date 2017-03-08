#ifndef WEATHERSINGLETON_H
#define WEATHERSINGLETON_H

/* =================================================
 * This file is part of the TTK Weather project
 * Copyright (c) 2015 - 2017 Greedysky Studio
 * All rights reserved!
 * Redistribution and use of the source code or any derivative
 * works are strictly forbiden.
   =================================================*/

#include <QMutex>
#include <QScopedPointer>
#include "weatherglobaldefine.h"

template <typename T>
/*! @brief The class of the singleton base.
 * @author Greedysky <greedysky@163.com>
 */
class WEATHER_CORE_EXPORT WeatherSingleton
{
public:
    static T* createInstance();
    /*!
     * Get object instance ptr.
     */

private:
    WeatherSingleton(){}
    /*!
     * Object contsructor.
     */
    ~WeatherSingleton(){}

    static QMutex m_mutex;
    static QScopedPointer<T> m_instance;
    Q_DISABLE_COPY(WeatherSingleton)

};

    ////////////////////////////////////////////////////////////////
    ///                                                           //
    ///              Singleton Implementation                     //
    ///                                                           //
    ////////////////////////////////////////////////////////////////

template<typename T> QMutex WeatherSingleton<T>::m_mutex;
template<typename T> QScopedPointer<T> WeatherSingleton<T>::m_instance;

template<typename T>
T* WeatherSingleton<T>::createInstance()
{
    if(m_instance.isNull())
    {
        m_mutex.lock();
        if(m_instance.isNull())
        {
            m_instance.reset(new T());
        }
        m_mutex.unlock();
    }
    return m_instance.data();
}

    ////////////////////////////////////////////////////////////////
    ///                                                           //
    ///              Singleton Macro                              //
    ///                                                           //
    ////////////////////////////////////////////////////////////////

////Class that will implement the singleton mode,
////must use the macro in it's delare file
#define DECLARE_SINGLETON_CLASS( Class )                        \
    friend class WeatherSingleton<Class>;              \
    friend struct QScopedPointerDeleter<Class>;

#endif // WEATHERSINGLETON_H

