#ifndef WEATHERUIOBJECT_H
#define WEATHERUIOBJECT_H

/***************************************************************************
 * This file is part of the TTK Weather project
 * Copyright (C) 2015 - 2023 Greedysky Studio

 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License along
 * with this program; If not, see <http://www.gnu.org/licenses/>.
 ***************************************************************************/

#include "ttkglobal.h"

namespace WeatherUIObject
{
///ToolButton
    const QString ToolButtonStyle01 = " \
            QToolButton{border:none; background-color:transparent;}\
            QToolButton::hover{background-color:rgba(255,255,255,20)}";

///PushButton
    const QString PushButtonStyle01 = " \
            QPushButton{background-color:rgb(173,216,230);border:none;}\
            QPushButton::hover{\
            background:qlineargradient(x1:0,y1:0,x2:0,y2:1,\
            stop:0 #3BA1E6,stop: 0.5 #3BA1E6,stop: 1.0 #3BA1E6);\
            border:none;}";

///TableWidget
    const QString TableWidgetStyle01 =
#if defined Q_OS_UNIX && !TTK_QT_VERSION_CHECK(5,7,0) //Fix linux selection-background-color stylesheet bug
            "QTableWidget::item:selected{ background:rgba(20, 20, 20, 40); }";
#else
            "QTableWidget{ selection-background-color:rgba(20, 20, 20, 40); }";
#endif

///ScrollBar
    const QString ScrollBarStyle01 = " \
            QScrollBar{ background: #F0F0F0;width: 8px;}\
            QScrollBar::handle{background: #CFCFCF; min-width: 20px;min-height: 20px;}\
            QScrollBar::handle:vertical::disabled{ background:#DBDBDB;}\
            QScrollBar::handle:vertical:hover{ background:#DBDBDB; border:1px solid rgb(230,115,0);}\
            QScrollBar::add-line, QScrollBar::sub-line { background: none; border: none;}\
            QScrollBar::add-page, QScrollBar::sub-page { background: none; }\
            QScrollBar::up-arrow:vertical{border-image: url(':/usermanager/uparrow');}\
            QScrollBar::down-arrow:vertical{border-image: url(':/usermanager/downarrow');}";

///Menu
    const QString MenuStyle01 = " \
            QMenu {border: 1px solid gray; padding: 5px; background-color: white; }\
            QMenu::item {padding: 5px 25px 5px 30px;border: 1px solid transparent; }\
            QMenu::item:disabled {color: #666666;}\
            QMenu::item:selected { color: white; background: #BBBBBB;}\
            QMenu::separator {height: 1px;background: #BBBBBB;margin-top: 5px; margin-bottom: 5px;}";

}

#endif //  WEATHERUIOBJECT_H
