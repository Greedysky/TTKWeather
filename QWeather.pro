#-------------------------------------------------
#
# Project created by QtCreator 2015-09-19T11:05:02
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QWeather
TEMPLATE = app

TRANSLATIONS += cn.ts

DEFINES += WEATHER_LIBRARY

SOURCES += \
        weathermain.cpp \
        weatherapplication.cpp \
        weatherabstractmovedialog.cpp \
        weatherabstractmovewidget.cpp \
        weatherquery.cpp \
        weatherquerycity.cpp \
        weatherqueryfuture.cpp \
        weatheritemtablewidget.cpp \
        weatherfutureitemwidget.cpp \
        weatheradditemtablewidget.cpp \
        weatherabstracttablewidget.cpp \
        weatherloadingwidget.cpp


HEADERS  += \
        weatherapplication.h \
        weatherobject.h \
        weatheruiobject.h \
        weatherlibexportglobal.h \
        weatherabstractmovedialog.h \
        weatherabstractmovewidget.h \
        weatherquery.h \
        weatherquerycity.h \
        weatherqueryfuture.h \
        weatheritemtablewidget.h \
        weatherfutureitemwidget.h \
        weatheradditemtablewidget.h \
        weatherabstracttablewidget.h \
        weatherloadingwidget.h


RESOURCES+= \
        QWeather.qrc

RC_FILE  += \
        QWeather.rc

FORMS    += \
        weatherapplication.ui
