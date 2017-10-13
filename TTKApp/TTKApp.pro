# =================================================
# * This file is part of the TTK Weather project
# * Copyright (C) 2016 - 2017 Greedysky Studio
#
# * This program is free software; you can redistribute it and/or modify
# * it under the terms of the GNU General Public License as published by
# * the Free Software Foundation; either version 3 of the License, or
# * (at your option) any later version.
#
# * This program is distributed in the hope that it will be useful,
# * but WITHOUT ANY WARRANTY; without even the implied warranty of
# * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# * GNU General Public License for more details.
#
# * You should have received a copy of the GNU General Public License along
# * with this program; If not, see <http://www.gnu.org/licenses/>.
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
