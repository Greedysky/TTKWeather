#ifndef WEATHERGLOBALDEFINE_H
#define WEATHERGLOBALDEFINE_H

/* =================================================
 * This file is part of the TTK Weather project
 * Copyright (C) 2015 - 2019 Greedysky Studio

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

#include <QtCore/qglobal.h>

#ifdef QT_DEBUG
#   define WEATHER_DEBUG
#endif

#ifdef WEATHER_LIBRARY
#  define WEATHER_GUI
#  define WEATHER_WIDGET
#  define WEATHER_CORE
#endif
//////////////////////////////////////
#ifdef __cplusplus
#  define WEATHER_CAST
#endif
//////////////////////////////////////

//////////////////////////////////////
///exoprt
///
///
#define WEATHER_EXPORT

#ifdef WEATHER_GUI
#  ifdef WEATHER_EXPORT
#    define WEATHER_GUI_EXPORT Q_DECL_EXPORT
#  else
#    define WEATHER_GUI_IMPORT Q_DECL_IMPORT
#  endif
#endif

#ifdef WEATHER_WIDGET
#  ifdef WEATHER_EXPORT
#    define WEATHER_WIDGET_EXPORT Q_DECL_EXPORT
#  else
#    define WEATHER_WIDGET_IMPORT Q_DECL_IMPORT
#  endif
#endif

#ifdef WEATHER_CORE
#  ifdef WEATHER_EXPORT
#    define WEATHER_CORE_EXPORT Q_DECL_EXPORT
#  else
#    define WEATHER_CORE_IMPORT Q_DECL_IMPORT
#  endif
#endif

//////////////////////////////////////
///cast
///
#ifdef WEATHER_CAST
#  define MConst_cast(x,y) (const_cast< x >(y))
#else
#  define MConst_cast(x,y) ((x)(y))
#endif

#ifdef WEATHER_CAST
#  define MDynamic_cast(x,y) (dynamic_cast< x >(y))
#else
#  define MDynamic_cast(x,y) ((x)(y))
#endif

#ifdef WEATHER_CAST
#  define MReinterpret_cast(x,y) (reinterpret_cast< x >(y))
#else
#  define MReinterpret_cast(x,y) ((x)(y))
#endif

#ifdef WEATHER_CAST
#  define MStatic_cast(x,y) (static_cast< x >(y))
#else
#  define MStatic_cast(x,y) ((x)(y))
#endif

//////////////////////////////////////
///load logger
#include "weatherlogger.h"

#endif //  WEATHERGLOBALDEFINE_H
