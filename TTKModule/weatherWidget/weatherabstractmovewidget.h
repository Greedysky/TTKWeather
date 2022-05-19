#ifndef WEATHERABSTRACTMOVEWIDGET_H
#define WEATHERABSTRACTMOVEWIDGET_H

/***************************************************************************
 * This file is part of the TTK Weather project
 * Copyright (C) 2015 - 2022 Greedysky Studio

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

#include <QWidget>
#include <QMouseEvent>
#include "ttkglobaldefine.h"

/*! @brief The class of the moving widget base.
 * @author Greedysky <greedysky@163.com>
 */
class TTK_MODULE_EXPORT WeatherAbstractMoveWidget : public QWidget
{
    Q_OBJECT
public:
    explicit WeatherAbstractMoveWidget(QWidget *parent = 0);
    /*!
     * Object contsructor.
     */
    ~WeatherAbstractMoveWidget();

protected:
    virtual void mousePressEvent(QMouseEvent *event) override final;
    virtual void mouseMoveEvent(QMouseEvent *event) override final;
    virtual void mouseReleaseEvent(QMouseEvent *event) override final;
    /*!
     * Override the widget event.
     */

    QPoint m_pressAt;
    bool m_leftButtonPress;

};

#endif // WEATHERABSTRACTMOVEWIDGET_H
