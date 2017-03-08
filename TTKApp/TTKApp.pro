# =================================================
# * This file is part of the TTK Weather project
# * Copyright (c) 2015 - 2017 Greedysky Studio
# * All rights reserved!
# * Redistribution and use of the source code or any derivative
# * works are strictly forbiden.
# =================================================

TEMPLATE = app
win32{
  TARGET = ../../bin/TTKWeather
  LIBS += -L../bin -lWeatherCore
}
unix{
  TARGET = ../lib/TTKWeather
  LIBS += -L../lib -lWeatherCore
}

contains(CONFIG, TTK_BUILD_LIB){
    CONFIG -= TTK_BUILD_LIB
}

CONFIG += TTK_NO_MSVC_LINK_NEED
win32{
    msvc{
        CONFIG -= TTK_NO_MSVC_LINK_NEED
    }
}

INCLUDEPATH += ../TTKCore

include(../TTKWeather.pri)
unix:VERSION += $$TTKWeather

!contains(CONFIG, TTK_NO_MSVC_LINK_NEED){
HEADERS  += \
    ../TTKCore/weatherapplication.h
}

SOURCES += \
    weatherapplicationmain.cpp

win32{
    RC_FILE = TTKApp.rc
}
