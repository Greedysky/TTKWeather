#ifndef WEATHERSINGLETON_H
#define WEATHERSINGLETON_H

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

template <typename T> QMutex WeatherSingleton<T>::m_mutex;
template <typename T> QScopedPointer<T> WeatherSingleton<T>::m_instance;

template <typename T>
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
#define DECLARE_SINGLETON_CLASS( Class )               \
    friend class WeatherSingleton<Class>;              \
    friend struct QScopedPointerDeleter<Class>;

#endif // WEATHERSINGLETON_H

