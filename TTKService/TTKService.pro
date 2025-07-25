# ***************************************************************************
# * This file is part of the TTK Weather project
# * Copyright (C) 2015 - 2025 Greedysky Studio
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

include($$PWD/../TTKWeather.pri)
include($$PWD/../TTKCommon/TTKApplication/TTKApplication.pri)

TARGET = TTKService

LIBS += -L$$DESTDIR -lTTKCore

INCLUDEPATH += \
    $$PWD/../TTKModule \
    $$PWD/../TTKModule/TTKCore/weatherCoreKits \
    $$PWD/../TTKModule/TTKWidget/weatherCoreKits

win32:msvc{
HEADERS += \
    $$PWD/../TTKModule/weatherapplication.h \
    $$PWD/../TTKModule/TTKWidget/weatherCoreKits/weatherabstractmovewidget.h
}

SOURCES += $$PWD/weatherservicemain.cpp

win32:RC_FILE = $$PWD/$${TARGET}.rc
