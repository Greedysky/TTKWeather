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

set_property(GLOBAL PROPERTY TTK_CORE_KITS_HEADER_FILES
  ${TTK_CORE_DIR}/weatherquery.h
  ${TTK_CORE_DIR}/weatherquerycity.h
  ${TTK_CORE_DIR}/weatherobject.h
  ${TTK_CORE_DIR}/weatherqueryfuture.h
)

set_property(GLOBAL PROPERTY TTK_CORE_KITS_SOURCE_FILES
  ${TTK_CORE_DIR}/weatherquery.cpp
  ${TTK_CORE_DIR}/weatherquerycity.cpp
  ${TTK_CORE_DIR}/weatherqueryfuture.cpp
)
