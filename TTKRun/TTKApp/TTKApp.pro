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

TEMPLATE = app

include($$PWD/../../TTKWeather.pri)

DESTDIR = $$OUT_PWD/../../bin/$$TTKVersion
TARGET = TTKWeather

LIBS += -L$$DESTDIR -lTTKCore

INCLUDEPATH += \
    $$PWD/../../TTKModule \
    $$PWD/../../TTKModule/weatherCore \
    $$PWD/../../TTKModule/weatherWidget

win32:msvc{
HEADERS += \
    $$PWD/../../TTKModule/weatherapplication.h \
    $$PWD/../../TTKModule/weatherWidget\weatherabstractmovewidget.h
}

SOURCES += $$PWD/weatherapplicationmain.cpp

win32:RC_FILE = $$PWD/TTKApp.rc
