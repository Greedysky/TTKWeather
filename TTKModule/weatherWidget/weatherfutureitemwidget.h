#ifndef WEATHERFUTUREITEMWIDGET_H
#define WEATHERFUTUREITEMWIDGET_H

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
#include "weatherglobaldefine.h"
#include "weatherobject.h"

#define COUNT 5

class QButtonGroup;
class QStackedWidget;
class WeatherItemTableWidget;

/*! @brief The class of the future item widget.
 * @author Greedysky <greedysky@163.com>
 */
class WEATHER_WIDGET_EXPORT WeatherFutureItemWidget : public QWidget
{
    Q_OBJECT
public:
    explicit WeatherFutureItemWidget(QWidget *parent = 0);
    /*!
     * Object contsructor.
     */
    ~WeatherFutureItemWidget();

    void setItemName(const QString &name);
    /*!
     * Set table item to query differ future weather.
     */
    void createItem(const WeatherObject::Weather &weather);
    /*!
     * Set table item by weather object.
     */

private slots:
    void buttonClicked(int index);
    /*!
     * Future button item clicked in which.
     */

protected:
    void initialize();
    /*!
     * Init future button widget.
     */
    void createButton();
    /*!
     * Create future buttons.
     */

    QString m_itemId;
    QStackedWidget *m_statckedWidget;
    QButtonGroup *m_group;
    QList<WeatherItemTableWidget*> m_itemLists;

};

#endif // WEATHERFUTUREITEMWIDGET_H
