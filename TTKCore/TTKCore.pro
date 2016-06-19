#-------------------------------------------------
#
# Project created by QtCreator 2015-09-19T11:05:02
#
# =================================================
# * This file is part of the TTK Weather project
# * Copyright (c) 2015 - 2016 Greedysky Studio
# * All rights reserved!
# * Redistribution and use of the source code or any derivative
# * works are strictly forbiden.
# =================================================

win32:TARGET = ../../bin/WeatherCore
unix:TARGET = ../lib/WeatherCore
TEMPLATE = lib

CONFIG += TTK_BUILD_LIB

INCLUDEPATH += $$PWD

include(../TTKWeather.pri)
unix:VERSION += $$TTKWeather

SOURCES += \
    weatherapplication.cpp 

HEADERS  += \
    weatherapplication.h

RESOURCES += \
    ../TTKQrc/Weather.qrc
    