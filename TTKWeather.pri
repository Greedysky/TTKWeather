# ***************************************************************************
# * This file is part of the TTK Weather project
# * Copyright (C) 2015 - 2022 Greedysky Studio
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
# ***************************************************************************

QT       += core gui network
equals(QT_MAJOR_VERSION, 4){ #Qt4
QT       += script
CONFIG   += gcc
}
greaterThan(QT_MAJOR_VERSION, 4){ #Qt5
    QT   += widgets
    equals(QT_MAJOR_VERSION, 6){ #Qt6
        QT   += core5compat
    }
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
        QMAKE_CXXFLAGS += -std=c++11  -Wunused-function -Wswitch
    }
}

unix:!mac{
    QMAKE_CXXFLAGS += -std=c++11 -Wunused-function -Wswitch
}

TTKWeather = 1.6.0.0

DEFINES += TTK_LIBRARY

INCLUDEPATH += $$PWD

include($$PWD/TTKModule/weatherUi/WeatherUi.pri)
include($$PWD/TTKModule/weatherCore/WeatherCore.pri)
include($$PWD/TTKModule/weatherWidget/WeatherWidget.pri)
