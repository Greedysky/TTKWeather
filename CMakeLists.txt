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

cmake_minimum_required(VERSION 3.0.0)

project(TTKWeather)

set(TTK_MAJOR_VERSION 3)
set(TTK_MINOR_VERSION 1)
set(TTK_PATCH_VERSION 0)
set(TTK_VERSION "${TTK_MAJOR_VERSION}.${TTK_MINOR_VERSION}.${TTK_PATCH_VERSION}.0")

# Find includes in the build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Turn off automatic invocation of the UI
set(CMAKE_AUTOUIC OFF)
# Turn off automatic invocation of the MOC
set(CMAKE_AUTOMOC OFF)
# Turn off automatic invocation of the RCC
set(CMAKE_AUTORCC OFF)

# Build Type
if(NOT CMAKE_BUILD_TYPE OR CMAKE_BUILD_TYPE STREQUAL "")
  set(CMAKE_BUILD_TYPE "Release" CACHE STRING "" FORCE)
endif()
set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS Release Debug)

# Add a compiler flag
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror=return-type -std=c++11 -pthread -Wall")
if("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -pedantic")
else()
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")
  add_definitions(-DQT_NO_DEBUG)
endif()

# clang: error: unsupported option '-fopenmp'
if(NOT ("${CMAKE_C_COMPILER_ID}" MATCHES "Clang"))
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp")
endif()

if(WIN32)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mwindows")
  # Fix "command line is too long" on Windows
  string(APPEND CMAKE_RC_FLAGS " --use-temp-file")
endif()

option(TTK_BUILD_SHARED "TTK BUILD SHARED LIBS" ON)
if(TTK_BUILD_SHARED)
  message(STATUS "TTK build by shared link")
else()
  message(STATUS "TTK build by static link")
endif()

add_definitions(-DQT_THREAD)
add_definitions(-DTTK_LIBRARY)

set(TTK_BASE_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(TTK_COMMON_DIR "${TTK_BASE_DIR}/TTKCommon")
set(TTK_COMMON_BASE_DIR "${TTK_COMMON_DIR}/base")
set(TTK_COMMON_COMPAT_DIR "${TTK_COMMON_DIR}/compat")
set(TTK_COMMON_APP_DIR "${TTK_COMMON_DIR}/TTKApplication")
set(TTK_COMMON_LIB_DIR "${TTK_COMMON_DIR}/TTKLibrary")
set(TTK_COMMON_RUN_DIR "${TTK_COMMON_DIR}/TTKRun")
set(TTK_MODULE_DIR "${TTK_BASE_DIR}/TTKModule")
set(TTK_MODULE_CORE_DIR "${TTK_MODULE_DIR}/TTKCore")
set(TTK_MODULE_WIDGET_DIR "${TTK_MODULE_DIR}/TTKWidget")

include_directories(
  ${TTK_BASE_DIR}
  ${TTK_COMMON_DIR}
  ${TTK_COMMON_LIB_DIR}
  ${TTK_COMMON_BASE_DIR}
  ${TTK_MODULE_DIR}
)


set(TTK_CORE_DIR "${TTK_MODULE_CORE_DIR}/weatherCoreKits")
set(TTK_CORE_UTILS_DIR "${TTK_MODULE_CORE_DIR}/weatherUtilsKits")

include_directories(
  ${TTK_CORE_DIR}
  ${TTK_CORE_UTILS_DIR}
)


set(TTK_WIDGET_DIR "${TTK_MODULE_WIDGET_DIR}/weatherWidgetKits")
set(TTK_WIDGET_CORE_DIR "${TTK_MODULE_WIDGET_DIR}/weatherCoreKits")
set(TTK_WIDGET_UI_DIR "${TTK_MODULE_WIDGET_DIR}/weatherUiKits")

include_directories(
  ${TTK_WIDGET_DIR}
  ${TTK_WIDGET_CORE_DIR}
  ${TTK_WIDGET_UI_DIR}
)


set(TTK_UI_DIR "${TTK_BASE_DIR}/TTKUi")
set(TTK_THIRDPARTY_DIR "${TTK_BASE_DIR}/TTKThirdParty")
set(TTK_TTKSERVICE_DIR "${TTK_BASE_DIR}/TTKService")
set(TTK_UTILS_DIR "${TTK_BASE_DIR}/TTKUtils")
set(TTK_LANGUAGE_DIR "${TTK_BASE_DIR}/TTKLanguage")
set(TTK_RESOURCE_DIR "${TTK_BASE_DIR}/TTKResource")

include_directories(
  ${TTK_THIRDPARTY_DIR}
  ${TTK_THIRDPARTY_DIR}/TTKExtras
)


set(TTK_BUILD_DIR "${CMAKE_BINARY_DIR}/bin")
set(TTK_GENERATE_DIR "${CMAKE_BINARY_DIR}/Generate")

include_directories(${TTK_GENERATE_DIR})

set(LIBRARY_OUTPUT_PATH ${TTK_BUILD_DIR}/${TTK_VERSION})
set(EXECUTABLE_OUTPUT_PATH ${TTK_BUILD_DIR}/${TTK_VERSION})

set(OPENSSL_DIR "" CACHE PATH "Openssl install path")

set(TTK_QT_VERSION "0" CACHE STRING "Select Qt version")
set_property(CACHE TTK_QT_VERSION PROPERTY STRINGS 4 5 6)

if(NOT (TTK_QT_VERSION STREQUAL "4" OR TTK_QT_VERSION STREQUAL "5" OR TTK_QT_VERSION STREQUAL "6"))
  message(FATAL_ERROR "Expected value for TTK_QT_VERSION is invalid")
endif()

set(CMAKE_PREFIX_PATH ${QT_INSTALL_DIR} CACHE PATH "Qt install path")

find_program(QT_QMAKE_EXECUTABLE qmake ${QT_INSTALL_BINS})
if(QT_QMAKE_EXECUTABLE)
  message(STATUS "Found qmake executable: " ${QT_QMAKE_EXECUTABLE})
else()
  message(FATAL_ERROR "Could NOT find qmake executable")
endif()


if(TTK_QT_VERSION VERSION_EQUAL "4")
  set(minimum_required_qt_version "4.8")
  find_package(Qt4 REQUIRED)

  if(QT4_FOUND)
    if("${QT_VERSION_MAJOR}.${QT_VERSION_MINOR}" VERSION_LESS "${minimum_required_qt_version}")
      message(FATAL_ERROR "Fatal error: TTK requires Qt >= ${minimum_required_qt_version} -- you cannot use Qt ${QT_VERSION_MAJOR}.${QT_VERSION_MINOR}.${QT_VERSION_PATCH}.")
    endif()

    set(QT_USE_QTCORE ON)
    set(QT_USE_QTGUI ON)
    set(QT_USE_QTNETWORK ON)
    set(QT_USE_QTXML ON)

    include(${QT_USE_FILE})

    if(WIN32)
      get_filename_component(${QT_LIBRARY_DIR} ${QT_QMAKE_EXECUTABLE} PATH)
    endif()
  else()
    message(FATAL_ERROR "Fatal error: Qt4 was not found on your system. You probably need to set the QT_QMAKE_EXECUTABLE variable")
  endif()
elseif(TTK_QT_VERSION VERSION_EQUAL "5")
  find_package(Qt5 COMPONENTS Core Gui Widgets Network Xml REQUIRED)
elseif(TTK_QT_VERSION VERSION_EQUAL "6")
  find_package(Qt6 COMPONENTS Core Gui Widgets Network Xml Core5Compat REQUIRED)
  # Add a compiler flag
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
endif()


if(TTK_QT_VERSION VERSION_GREATER "4")
  add_definitions(-DQT_DEPRECATED_WARNINGS)
  add_definitions(-DQT_DISABLE_DEPRECATED_BEFORE=0x050400)
endif()


find_program(CCACHE_FOUND ccache)
if(CCACHE_FOUND)
  message(STATUS "Set up ccache module")
  set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE ccache)
  set_property(GLOBAL PROPERTY RULE_LAUNCH_LINK ccache)
endif()


find_program(QT_LRELEASE_EXECUTABLE lrelease ${QT_INSTALL_BINS})
if(QT_LRELEASE_EXECUTABLE)
  message(STATUS "Found lrelease executable: " ${QT_LRELEASE_EXECUTABLE})
else()
  message(FATAL_ERROR "Could NOT find lrelease executable")
endif()


add_subdirectory(TTKCommon)
add_subdirectory(TTKLanguage)
add_subdirectory(TTKUi)
add_subdirectory(TTKThirdParty)
add_subdirectory(TTKModule)
add_subdirectory(TTKService)
add_subdirectory(TTKRun)


set(TTK_INSTALL_DIR "${CMAKE_INSTALL_PREFIX}/${PROJECT_NAME}")
set(TTK_INSTALL_BIN_DIR "${TTK_INSTALL_DIR}/${TTK_VERSION}")

install(DIRECTORY "${TTK_BUILD_DIR}/" DESTINATION "${TTK_INSTALL_DIR}" USE_SOURCE_PERMISSIONS)
install(FILES "${TTK_BASE_DIR}/ChangeLog"
              "${TTK_BASE_DIR}/LICENSE"
              "${TTK_BASE_DIR}/LICENSE.LGPLv3"
              "${TTK_BASE_DIR}/README.md"
              "${TTK_BASE_DIR}/README_cn.md"
              "${TTK_BASE_DIR}/README_tc.md"
              "${TTK_BASE_DIR}/.github/FUNDING.yml"
              "${TTK_UTILS_DIR}/resource/LICENSE.QT-LICENSE-AGREEMENT"
        DESTINATION "${TTK_INSTALL_DIR}/doc")
install(FILES "${TTK_UTILS_DIR}/resource/README.txt" DESTINATION "${TTK_INSTALL_DIR}")
if(WIN32)
  install(FILES "${TTK_UTILS_DIR}/resource/qicon.dll" DESTINATION "${TTK_INSTALL_DIR}")
else()
  install(DIRECTORY "${TTK_UTILS_DIR}/deploy" DESTINATION "${TTK_INSTALL_DIR}")
  install(FILES "${TTK_UTILS_DIR}/install.sh" DESTINATION "${TTK_INSTALL_DIR}")
  install(FILES "${TTK_UTILS_DIR}/uninstall.sh" DESTINATION "${TTK_INSTALL_DIR}")
  install(FILES "${TTK_UTILS_DIR}/deploy/share/appdata/ttkweather.appdata.xml" DESTINATION "${TTK_INSTALL_DIR}/share/metainfo")
endif()
# copy run resource
if(UNIX)
  install(CODE "execute_process(COMMAND \"${TTK_UTILS_DIR}/resource.sh\" \"${TTK_RESOURCE_DIR}\" \"${TTK_INSTALL_BIN_DIR}\")")
endif()
# update and release translations
if(WIN32)
  install(CODE "execute_process(COMMAND \"${TTK_UTILS_DIR}/ts_win.bat\" \"${QT_LRELEASE_EXECUTABLE}\" \"${TTK_INSTALL_BIN_DIR}\" \"${TTK_BASE_DIR}\")")
else()
  install(CODE "execute_process(COMMAND \"${TTK_UTILS_DIR}/ts_unix.py\" \"${QT_LRELEASE_EXECUTABLE}\" \"${TTK_INSTALL_BIN_DIR}\" \"${TTK_BASE_DIR}\")")
endif()
