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

INCLUDEPATH += $$PWD

!contains(CONFIG, TTK_NO_MSVC_LINK_NEED){
HEADERS  += \
    $$PWD/weatherabstractmovedialog.h \
    $$PWD/weatherabstractmovewidget.h \
    $$PWD/weatheritemtablewidget.h \
    $$PWD/weatherfutureitemwidget.h \
    $$PWD/weatheradditemtablewidget.h \
    $$PWD/weatherabstracttablewidget.h \
    $$PWD/weatherloadingwidget.h \
    $$PWD/weathermessagebox.h

}

contains(CONFIG, TTK_BUILD_LIB){
SOURCES += \
    $$PWD/weatherabstractmovedialog.cpp \
    $$PWD/weatherabstractmovewidget.cpp \
    $$PWD/weatheritemtablewidget.cpp \
    $$PWD/weatherfutureitemwidget.cpp \
    $$PWD/weatheradditemtablewidget.cpp \
    $$PWD/weatherabstracttablewidget.cpp \
    $$PWD/weatherloadingwidget.cpp \
    $$PWD/weathermessagebox.cpp

}
