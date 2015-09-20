#ifndef WEATHERLIBEXPORTGLOBAL_H
#define WEATHERLIBEXPORTGLOBAL_H

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


#ifdef WEATHER_GUI
#  define WEATHER_GUI_EXPORT Q_DECL_EXPORT
#else
#  define WEATHER_GUI_IMPORT Q_DECL_IMPORT
#endif

#ifdef WEATHER_WIDGET
#  define WEATHER_WIDGET_EXPORT Q_DECL_EXPORT
#else
#  define WEATHER_WIDGET_IMPORT Q_DECL_IMPORT
#endif

#ifdef WEATHER_CORE
#  define WEATHER_CORE_EXPORT Q_DECL_EXPORT
#else
#  define WEATHER_CORE_IMPORT Q_DECL_IMPORT
#endif


#endif //  WEATHERLIBEXPORTGLOBAL
