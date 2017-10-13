#ifndef WEATHERUIOBJECT_H
#define WEATHERUIOBJECT_H

/* =================================================
 * This file is part of the TTK Weather project
 * Copyright (C) 2015 - 2017 Greedysky Studio

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
 ================================================= */

#include <QObject>
#include <QDebug>

namespace WeatherUIObject
{
///ToolButton
//////////////////////////////////////////////////////
    const QString MToolButtonStyle02 = " \
            QToolButton{background-color:transparent;}";

    const QString MToolButtonStyle01 = MToolButtonStyle02 + " \
            QToolButton::hover{background-color:rgba(255,255,255,20)}";

///ToolButton
//////////////////////////////////////////////////////
    const QString MPushButtonStyle01 = "\
            QPushButton{background-color:transparent;}";

    const QString MPushButtonStyle02 = MPushButtonStyle01 + "\
            QPushButton{border-none;}";

    const QString MPushButtonStyle03 = MPushButtonStyle02 + " \
            QPushButton{font-size:17px;font-weight:bold;color:#FFFFFF}\
            QPushButton::hover{\
            background:qlineargradient(x1:0,y1:0,x2:0,y2:1,stop:0 rgba(255,255,255,100), \
            stop: 0.5 rgba(255,255,255,100),stop: 1.0 rgba(255,255,255,100));\
            border:none;}";

    const QString MPushButtonStyle04 = " \
            QPushButton{background-color:rgb(173,216,230);border:none;}\
            QPushButton::hover{\
            background:qlineargradient(x1:0,y1:0,x2:0,y2:1,\
            stop:0 #3BA1E6,stop: 0.5 #3BA1E6,stop: 1.0 #3BA1E6);\
            border:none;}";

///TableWidget
//////////////////////////////////////////////////////
    const QString MTableWidgetStyle01 = " \
            QTableWidget{selection-background-color: rgba(20,20,20,40);}";

///ScrollBar
//////////////////////////////////////////////////////
    const QString MScrollBarStyle01 = " \
            QScrollBar{ background: #F0F0F0;width: 8px;}\
            QScrollBar::handle{background: #CFCFCF; min-width: 20px;min-height: 20px;}\
            QScrollBar::handle:vertical::disabled{ background:#DBDBDB;}\
            QScrollBar::handle:vertical:hover{ background:#DBDBDB; border:1px solid rgb(230,115,0);}\
            QScrollBar::add-line, QScrollBar::sub-line { background: none; border: none;}\
            QScrollBar::add-page, QScrollBar::sub-page { background: none; }\
            QScrollBar::up-arrow:vertical{border-image: url(':/usermanager/uparrow');}\
            QScrollBar::down-arrow:vertical{border-image: url(':/usermanager/downarrow');}";

///Menu
//////////////////////////////////////////////////////
    const QString MMenuStyle03 = " \
            QMenu {border: 1px solid gray; padding: 5px; }\
            QMenu::item {padding: 5px 25px 5px 30px;border: 1px solid transparent; }\
            QMenu::item:disabled {color: #666666;}\
            QMenu::item:selected { color: white; background: #BBBBBB;}\
            QMenu::separator {height: 1px;background: #BBBBBB;margin-top: 5px; margin-bottom: 5px;}";

    const QString MMenuStyle01 = MMenuStyle03 + " \
            QMenu { background-color: white;}";

    const QString MMenuStyle02 = MMenuStyle03 + " \
            QMenu { color:white; background-color: rgba(0,0,0,50);}";


}


#endif //  WEATHERUIOBJECT_H
