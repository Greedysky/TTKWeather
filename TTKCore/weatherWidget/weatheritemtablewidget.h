#ifndef WEATHERITEMTABLEWIDGET_H
#define WEATHERITEMTABLEWIDGET_H

/* =================================================
 * This file is part of the TTK Weather project
 * Copyright (C) 2015 - 2019 Greedysky Studio

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

#include "weatherabstracttablewidget.h"

class WeatherQueryFuture;

/*! @brief The class of the item table widget.
 * @author Greedysky <greedysky@163.com>
 */
class WEATHER_WIDGET_EXPORT WeatherItemTableWidget : public WeatherAbstractTableWidget
{
    Q_OBJECT
public:
    explicit WeatherItemTableWidget(QWidget *parent = 0);
    /*!
     * Object contsructor.
     */
    virtual ~WeatherItemTableWidget();

    void setItemName(const QString &name, int index);
    /*!
     * Set table item to query differ future weather.
     */
    void createItem(const WeatherObject::Weather &weather);
    /*!
     * Set table item by weather object.
     */

signals:
    void loadingIcon(const QStringList &icons);
    /*!
     * Load the current weather state icons.
     */

public slots:
    virtual void listCellClicked(int row, int column) override;
    /*!
     * Table widget list cell click.
     */
    void searchItemInformationDown();
    /*!
     * Query diffe future weather by index done.
     */

protected:
    WeatherQueryFuture *m_queryFuture;
    int m_indexOfItem;

};

#endif // WEATHERITEMTABLEWIDGET_H
