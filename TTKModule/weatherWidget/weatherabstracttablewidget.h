#ifndef WEATHERABSTRACTTABLEWIDGET_H
#define WEATHERABSTRACTTABLEWIDGET_H

/* =================================================
 * This file is part of the TTK Weather project
 * Copyright (C) 2015 - 2020 Greedysky Studio

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

#include <QTableWidget>
#include <QHeaderView>
#include "weatherglobaldefine.h"
#include "weatherobject.h"
#include "weatheruiobject.h"

/*! @brief The class of the table widget base.
 * @author Greedysky <greedysky@163.com>
 */
class WEATHER_WIDGET_EXPORT WeatherAbstractTableWidget : public QTableWidget
{
    Q_OBJECT
public:
    explicit WeatherAbstractTableWidget(QWidget *parent = 0);
    /*!
     * Object contsructor.
     */
    virtual ~WeatherAbstractTableWidget();

    void clear();
    /*!
     * Clear current items.
     */

public slots:
    virtual void listCellEntered(int row, int column);
    /*!
     * Table widget list cell enter.
     */
    virtual void listCellClicked(int row, int column) = 0;
    /*!
     * Table widget list cell click.
     * Subclass should implement this function.
     */

protected:
    void setTransparent(int angle);
    /*!
     * Set widget transparent.
     */
    void setRowColor(int row, const QColor &color) const;
    /*!
     * Set selected item row color.
     */

    QColor m_defaultBkColor;
    int m_previousColorRow;
    int m_previousClickRow;

};

#endif // WEATHERABSTRACTTABLEWIDGET_H
