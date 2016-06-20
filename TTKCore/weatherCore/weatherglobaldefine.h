#ifndef WEATHERGLOBALDEFINE_H
#define WEATHERGLOBALDEFINE_H

/* =================================================
 * This file is part of the weather project
 * Copyright (c) 2014 - 2015 Greedysky Studio
 * All rights reserved!
 * Redistribution and use of the source code or any derivative
 * works are strictly forbiden.
   =================================================*/

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
#  define MUSIC_CAST
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
#ifdef MUSIC_CAST
#  define MConst_cast(x,y) (const_cast< x >(y))
#else
#  define MConst_cast(x,y) ((x)(y))
#endif

#ifdef MUSIC_CAST
#  define MDynamic_cast(x,y) (dynamic_cast< x >(y))
#else
#  define MDynamic_cast(x,y) ((x)(y))
#endif

#ifdef MUSIC_CAST
#  define MReinterpret_cast(x,y) (reinterpret_cast< x >(y))
#else
#  define MReinterpret_cast(x,y) ((x)(y))
#endif

#ifdef MUSIC_CAST
#  define MStatic_cast(x,y) (static_cast< x >(y))
#else
#  define MStatic_cast(x,y) ((x)(y))
#endif

//////////////////////////////////////
///load logger
#include "weatherlogger.h"

#endif //  WEATHERGLOBALDEFINE_H
