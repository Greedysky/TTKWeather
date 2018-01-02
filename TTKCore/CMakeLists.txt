cmake_minimum_required(VERSION 2.8.11)

project(WeatherCore)
set(TARGET_NAME WeatherCore)

if(COMMAND cmake_policy)
    cmake_policy(SET CMP0003 OLD)
    cmake_policy(SET CMP0005 OLD)
    cmake_policy(SET CMP0028 OLD)
endif(COMMAND cmake_policy)

add_definitions(-DQT_NO_DEBUG)
add_definitions(-DQT_THREAD)

set(WEATHER_HEADERS
    ${WEATHER_CORE_DIR}/weatherglobaldefine.h
    ${WEATHER_CORE_DIR}/weatherversion.h
    ${WEATHER_CORE_DIR}/weatherlogger.h
    ${WEATHER_CORE_DIR}/weatherobject.h
    ${WEATHER_CORE_DIR}/weathersingleton.h
    ${WEATHER_CORE_DIR}/weatherquery.h
    ${WEATHER_CORE_DIR}/weatherquerycity.h
    ${WEATHER_CORE_DIR}/weatherqueryfuture.h
    ${WEATHER_CORE_DIR}/weatherquerypm2p5.h
    ${WEATHER_CORE_DIR}/weathercryptographichash.h
    ${WEATHER_WIDGET_DIR}/weatherabstractmovedialog.h
    ${WEATHER_WIDGET_DIR}/weatherabstractmovewidget.h
    ${WEATHER_WIDGET_DIR}/weatheritemtablewidget.h
    ${WEATHER_WIDGET_DIR}/weatherfutureitemwidget.h
    ${WEATHER_WIDGET_DIR}/weatheradditemtablewidget.h
    ${WEATHER_WIDGET_DIR}/weatherabstracttablewidget.h
    ${WEATHER_WIDGET_DIR}/weatherloadingwidget.h
    ${WEATHER_WIDGET_DIR}/weathermessagebox.h
    ${WEATHER_LIB_DIR}/weatherapplication.h
  )

set(WEATHER_SOURCES
    ${WEATHER_CORE_DIR}/weatherquery.cpp
    ${WEATHER_CORE_DIR}/weatherquerycity.cpp
    ${WEATHER_CORE_DIR}/weatherqueryfuture.cpp
    ${WEATHER_CORE_DIR}/weatherquerypm2p5.cpp
    ${WEATHER_CORE_DIR}/weathercryptographichash.cpp
    ${WEATHER_WIDGET_DIR}/weatherabstractmovedialog.cpp
    ${WEATHER_WIDGET_DIR}/weatherabstractmovewidget.cpp
    ${WEATHER_WIDGET_DIR}/weatheritemtablewidget.cpp
    ${WEATHER_WIDGET_DIR}/weatherfutureitemwidget.cpp
    ${WEATHER_WIDGET_DIR}/weatheradditemtablewidget.cpp
    ${WEATHER_WIDGET_DIR}/weatherabstracttablewidget.cpp
    ${WEATHER_WIDGET_DIR}/weatherloadingwidget.cpp
    ${WEATHER_WIDGET_DIR}/weathermessagebox.cpp
    ${WEATHER_LIB_DIR}/weatherapplication.cpp
  )

SET(WEATHER_UIS
    ${WEATHER_UI_DIR}/weatherapplication.ui
    ${WEATHER_UI_DIR}/weathermessagebox.ui
)

SET(WEATHER_QRC
    ${WEATHER_QRC_DIR}/TTKWeather.qrc
)

if(TTK_QT_VERSION VERSION_GREATER "4")
  QT5_WRAP_UI(WEATHER_UIS_H ${WEATHER_UIS})
  QT5_WRAP_CPP(WEATHER_MOC_H ${WEATHER_HEADERS})

  QT5_ADD_RESOURCES(WEATHER_RCC_SRCS ${WEATHER_QRC})
  
  if(TTK_BUILD_SHARED STREQUAL "true")
    add_library(${TARGET_NAME} SHARED ${WEATHER_SOURCES} ${WEATHER_RCC_SRCS} ${WEATHER_UIS_H} ${WEATHER_MOC_H} ${WEATHER_HEADERS})
  else()
    add_library(${TARGET_NAME} STATIC ${WEATHER_SOURCES} ${WEATHER_RCC_SRCS} ${WEATHER_UIS_H} ${WEATHER_MOC_H} ${WEATHER_HEADERS})
  endif()
  list(APPEND QT5_LIBS Qt5::Core Qt5::Network Qt5::Gui Qt5::Widgets)
  target_link_libraries(${TARGET_NAME} ${QT5_LIBS})
else()
  QT4_WRAP_UI(WEATHER_UIS_H ${WEATHER_UIS})
  QT4_WRAP_CPP(WEATHER_MOC_H ${WEATHER_HEADERS})

  QT4_ADD_RESOURCES(WEATHER_RCC_SRCS ${WEATHER_QRC})

  if(TTK_BUILD_SHARED STREQUAL "true")
    add_library(${TARGET_NAME} SHARED ${WEATHER_SOURCES} ${WEATHER_RCC_SRCS} ${WEATHER_UIS_H} ${WEATHER_MOC_H} ${WEATHER_HEADERS})
  else()
    add_library(${TARGET_NAME} STATIC ${WEATHER_SOURCES} ${WEATHER_RCC_SRCS} ${WEATHER_UIS_H} ${WEATHER_MOC_H} ${WEATHER_HEADERS})
  endif()
  list(APPEND QT4_LIBS ${QT_QTSCRIPT_LIBRARY} ${QT_QTGUI_LIBRARY} ${QT_QTNETWORK_LIBRARY} ${QT_QTCORE_LIBRARY})
  target_link_libraries(${TARGET_NAME} ${QT4_LIBS})
endif()
