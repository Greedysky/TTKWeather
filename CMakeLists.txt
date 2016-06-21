cmake_minimum_required(VERSION 2.8.11)

add_definitions(-DWEATHER_LIBRARY)

# Find includes in the build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Turn on automatic invocation of the MOC
set(CMAKE_AUTOMOC OFF)
# Add a compiler flag
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O2 -pthread -fopenmp -Wall")
# Build Type
set(CMAKE_BUILD_TYPE Release CACHE STRING "set build type to Release")  
set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS Release Debug)

set(TTK_BUILD_SHARED "true" CACHE STRING "TTK build by shared link")
set_property(CACHE TTK_BUILD_SHARED PROPERTY STRINGS true false)
if(TTK_BUILD_SHARED STREQUAL "true")
  message(STATUS "TTK build by shared link")
else()
  message(STATUS "TTK build by static link")
endif()

set(WEATHER_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(WEATHER_LIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/TTKCore")
set(WEATHER_CORE_DIR "${WEATHER_LIB_DIR}/weatherCore")
set(WEATHER_WIDGET_DIR "${WEATHER_LIB_DIR}/weatherWidget")
set(WEATHER_UI_DIR "${WEATHER_LIB_DIR}/weatherUi")

set(WEATHER_SCRIPT_DIR "${WEATHER_DIR}/TTKScript")
set(WEATHER_QRC_DIR "${WEATHER_DIR}/TTKQrc")
set(WEATHER_LANGUAGE_DIR "${WEATHER_DIR}/TTKLanguage")
set(WEATHER_RESOURCE_DIR "${WEATHER_DIR}/TTKResource")

include_directories(${WEATHER_DIR})
include_directories(${WEATHER_LIB_DIR})
include_directories(${WEATHER_CORE_DIR})
include_directories(${WEATHER_WIDGET_DIR})

set(LIBRARY_OUTPUT_PATH ${CMAKE_CACHEFILE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CACHEFILE_DIR}/bin) 

set(TTK_QT_VERSION "0" CACHE STRING "Expected Qt version")
set_property(CACHE TTK_QT_VERSION PROPERTY STRINGS 4 5)

if(NOT (TTK_QT_VERSION STREQUAL "4" OR TTK_QT_VERSION STREQUAL "5"))
  message(FATAL_ERROR "Expected value for TTK_QT_VERSION is either '4' or '5'")
endif()

set(CMAKE_PREFIX_PATH ${QT_INSTALL_DIR} CACHE PATH "Qt install path")

find_program(QT_QMAKE_EXECUTABLE qmake ${QT_INSTALL_BINS})
if(QT_QMAKE_EXECUTABLE)
  message(STATUS "Found qmake executable: " ${QT_QMAKE_EXECUTABLE})
else()
  message(FATAL_ERROR "Could NOT find qmake executable")
endif()


if(TTK_QT_VERSION VERSION_GREATER "4")
  find_package(Qt5Core REQUIRED)
  find_package(Qt5Gui REQUIRED)
  find_package(Qt5Widgets REQUIRED)
  find_package(Qt5Network REQUIRED)
else()
  set(minimum_required_qt_version "4.6")
  find_package(Qt4 REQUIRED)
  
  if(QT4_FOUND)
    if("${QT_VERSION_MAJOR}.${QT_VERSION_MINOR}" VERSION_LESS "${minimum_required_qt_version}")
      message(FATAL_ERROR "error: TTK requires Qt >= ${minimum_required_qt_version} -- you cannot use Qt ${QT_VERSION_MAJOR}.${QT_VERSION_MINOR}.${QT_VERSION_PATCH}.")
    endif()

    set(QT_USE_QTCORE ON)
    set(QT_USE_QTGUI ON)
    set(QT_USE_QTNETWORK ON)
    set(QT_USE_QTSCRIPT ON)
    include(${QT_USE_FILE})

    if(WIN32)
      get_filename_component(${QT_LIBRARY_DIR} ${QT_QMAKE_EXECUTABLE} PATH)
    endif()
  else()
    message(FATAL_ERROR "error: Qt4 was not found on your system. You probably need to set the QT_QMAKE_EXECUTABLE variable")
  endif()
endif()


find_program(QT_LRELEASE_EXECUTABLE lrelease ${QT_INSTALL_BINS})
if(QT_LRELEASE_EXECUTABLE)
  message(STATUS "Found lrelease executable: " ${QT_LRELEASE_EXECUTABLE})
  if(WIN32)
    execute_process(COMMAND ${WEATHER_SCRIPT_DIR}/win.bat ${QT_LRELEASE_EXECUTABLE} ${EXECUTABLE_OUTPUT_PATH})
  else(UNIX)
    execute_process(COMMAND ${WEATHER_SCRIPT_DIR}/linux.sh ${QT_LRELEASE_EXECUTABLE} ${MUSIC_DIR} ${EXECUTABLE_OUTPUT_PATH})
  endif()
else()
  message(FATAL_ERROR "Could NOT find lrelease executable")
endif()

add_subdirectory(TTKCore)
add_subdirectory(TTKApp)