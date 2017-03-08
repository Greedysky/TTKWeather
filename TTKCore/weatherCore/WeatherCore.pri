# =================================================
# * This file is part of the TTK Weather project
# * Copyright (c) 2015 - 2017 Greedysky Studio
# * All rights reserved!
# * Redistribution and use of the source code or any derivative
# * works are strictly forbiden.
# =================================================

INCLUDEPATH += $$PWD

!contains(CONFIG, TTK_NO_MSVC_LINK_NEED){
HEADERS  += \
    $$PWD/weatherglobaldefine.h \
    $$PWD/weatherversion.h \
    $$PWD/weatherlogger.h \
    $$PWD/weatherobject.h \
    $$PWD/weathersingleton.h \
    $$PWD/weatherquery.h \
    $$PWD/weatherquerycity.h \
    $$PWD/weatherqueryfuture.h \
    $$PWD/weatherquerypm2p5.h \
    $$PWD/weathercryptographichash.h

}

contains(CONFIG, TTK_BUILD_LIB){
SOURCES += \
    $$PWD/weatherquery.cpp \
    $$PWD/weatherquerycity.cpp \
    $$PWD/weatherqueryfuture.cpp \
    $$PWD/weatherquerypm2p5.cpp \
    $$PWD/weathercryptographichash.cpp

}
