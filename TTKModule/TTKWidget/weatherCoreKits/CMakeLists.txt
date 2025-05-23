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

set_property(GLOBAL PROPERTY TTK_WIDGET_CORE_KITS_HEADER_FILES
  ${TTK_WIDGET_CORE_DIR}/weatherabstractmovedialog.h
  ${TTK_WIDGET_CORE_DIR}/weatherabstractmovewidget.h
  ${TTK_WIDGET_CORE_DIR}/weatherabstracttablewidget.h
  ${TTK_WIDGET_CORE_DIR}/weatherloadingwidget.h
  ${TTK_WIDGET_CORE_DIR}/weathermessagebox.h
)

set_property(GLOBAL PROPERTY TTK_WIDGET_CORE_KITS_SOURCE_FILES
  ${TTK_WIDGET_CORE_DIR}/weatherabstractmovedialog.cpp
  ${TTK_WIDGET_CORE_DIR}/weatherabstractmovewidget.cpp
  ${TTK_WIDGET_CORE_DIR}/weatherabstracttablewidget.cpp
  ${TTK_WIDGET_CORE_DIR}/weatherloadingwidget.cpp
  ${TTK_WIDGET_CORE_DIR}/weathermessagebox.cpp
)
