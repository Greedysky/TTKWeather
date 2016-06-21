cmake_minimum_required(VERSION 2.8.11)

project(TTKWeather)
set(TARGET_NAME TTKWeather)

if(COMMAND cmake_policy)
    cmake_policy(SET CMP0003 OLD)
    cmake_policy(SET CMP0005 OLD)
endif(COMMAND cmake_policy)

add_definitions(-DQT_NO_DEBUG)
add_definitions(-DQT_THREAD)

set(WEATHER_APP_SOURCES
  weatherapplicationmain.cpp
)

add_executable(${TARGET_NAME} TTKApp.rc ${WEATHER_APP_SOURCES})
add_dependencies(${TARGET_NAME} WeatherCore)

if(TTK_QT_VERSION VERSION_GREATER "4")
  list(APPEND QT5_LIBS Qt5::Core Qt5::Network Qt5::Gui Qt5::Widgets WeatherCore)
  target_link_libraries(${TARGET_NAME} ${QT5_LIBS})
else()
  list(APPEND QT4_LIBS ${QT_QTSCRIPT_LIBRARY} ${QT_QTGUI_LIBRARY} ${QT_QTNETWORK_LIBRARY} ${QT_QTCORE_LIBRARY} WeatherCore)
  target_link_libraries(${TARGET_NAME} ${QT4_LIBS})
endif()
