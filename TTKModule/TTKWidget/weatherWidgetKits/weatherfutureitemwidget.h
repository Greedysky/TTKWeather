#ifndef WEATHERFUTUREITEMWIDGET_H
#define WEATHERFUTUREITEMWIDGET_H

/***************************************************************************
 * This file is part of the TTK Weather project
 * Copyright (C) 2015 - 2025 Greedysky Studio

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
#include "ttkmoduleexport.h"
#include "weatherobject.h"

class QButtonGroup;
class QStackedWidget;
class WeatherItemTableWidget;

static constexpr int COUNT = 5;

/*! @brief The class of the future item widget.
 * @author Greedysky <greedysky@163.com>
 */
class TTK_MODULE_EXPORT WeatherFutureItemWidget : public QWidget
{
    Q_OBJECT
public:
    /*!
     * Object constructor.
     */
    explicit WeatherFutureItemWidget(QWidget *parent = nullptr);
    /*!
     * Object destructor.
     */
    ~WeatherFutureItemWidget();

    /*!
     * Set table item to query differ future weather.
     */
    void setItemName(const QString &name);
    /*!
     * Set table item by weather object.
     */
    void createItem(const TTK::Weather &weather);

private Q_SLOTS:
    /*!
     * Future button item clicked in which.
     */
    void buttonClicked(int index);

private:
    /*!
     * Init widget and parameter.
     */
    void initialize();
    /*!
     * Create future buttons.
     */
    void createButton();

    QString m_itemId;
    QStackedWidget *m_statckedWidget;
    QButtonGroup *m_group;
    QList<WeatherItemTableWidget*> m_items;

};

#endif // WEATHERFUTUREITEMWIDGET_H
