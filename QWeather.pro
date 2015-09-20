#-------------------------------------------------
#
# Project created by QtCreator 2015-09-19T11:05:02
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QWeather
TEMPLATE = app

INCLUDEPATH += \
               $$PWD/core \
               $$PWD/widget \
               $$PWD/

TRANSLATIONS += cn.ts

DEFINES += WEATHER_LIBRARY

SOURCES += \
        weathermain.cpp \
        weatherapplication.cpp \
        core/weatherquery.cpp \
        core/weatherquerycity.cpp \
        core/weatherqueryfuture.cpp \
        core/weatherquerypm2p5.cpp \
        widget/weatherabstractmovedialog.cpp \
        widget/weatherabstractmovewidget.cpp \
        widget/weatheritemtablewidget.cpp \
        widget/weatherfutureitemwidget.cpp \
        widget/weatheradditemtablewidget.cpp \
        widget/weatherabstracttablewidget.cpp \
        widget/weatherloadingwidget.cpp \
        widget/weathermessagebox.cpp


HEADERS  += \
        weatherapplication.h \
        core/weatherobject.h \
        core/weatheruiobject.h \
        core/weatherlibexportglobal.h \
        core/weatherquery.h \
        core/weatherquerycity.h \
        core/weatherqueryfuture.h \
        core/weatherquerypm2p5.h \
        widget/weatherabstractmovedialog.h \
        widget/weatherabstractmovewidget.h \
        widget/weatheritemtablewidget.h \
        widget/weatherfutureitemwidget.h \
        widget/weatheradditemtablewidget.h \
        widget/weatherabstracttablewidget.h \
        widget/weatherloadingwidget.h \
        widget/weathermessagebox.h


RESOURCES+= \
        QWeather.qrc

RC_FILE  += \
        QWeather.rc

FORMS    += \
        ui/weatherapplication.ui \
        ui/weathermessagebox.ui
