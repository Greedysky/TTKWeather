# =================================================
# * This file is part of the TTK Weather project
# * Copyright (C) 2015 - 2021 Greedysky Studio
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

QT       += core gui network

equals(QT_MAJOR_VERSION, 4){
QT       += script
CONFIG   += gcc
}
equals(QT_MAJOR_VERSION, 5){
QT       += widgets
}
equals(QT_MAJOR_VERSION, 6){
QT       += widgets core5compat
}

UI_DIR = ./.build/ui/
MOC_DIR = ./.build/moc/
OBJECTS_DIR = ./.build/obj
RCC_DIR = ./.build/rcc

win32{
    msvc{
        !contains(QMAKE_TARGET.arch, x86_64){
             #support on windows XP
             QMAKE_LFLAGS_WINDOWS = /SUBSYSTEM:WINDOWS,5.01
             QMAKE_LFLAGS_CONSOLE = /SUBSYSTEM:CONSOLE,5.01
        }
    }

    gcc{
        QMAKE_CXXFLAGS += -std=c++11
        QMAKE_CXXFLAGS += -Wunused-function
        QMAKE_CXXFLAGS += -Wswitch
    }
}

unix:!mac{
    QMAKE_CXXFLAGS += -std=c++11
    QMAKE_CXXFLAGS += -Wunused-function
    QMAKE_CXXFLAGS += -Wswitch
}

TTKWeather = 1.3.0.0

DEFINES += TTK_LIBRARY

contains(CONFIG, TTK_BUILD_LIB){
  include(TTKModule/weatherUi/WeatherUi.pri)
}

INCLUDEPATH += $$PWD

include(TTKModule/weatherCore/WeatherCore.pri)
include(TTKModule/weatherWidget/WeatherWidget.pri)
