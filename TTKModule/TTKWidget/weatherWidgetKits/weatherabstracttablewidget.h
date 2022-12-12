#ifndef WEATHERABSTRACTTABLEWIDGET_H
#define WEATHERABSTRACTTABLEWIDGET_H

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

#include <QHeaderView>
#include <QTableWidget>
#include "ttkglobaldefine.h"
#include "weatherobject.h"
#include "weatheruiobject.h"

/*! @brief The class of the table widget base.
 * @author Greedysky <greedysky@163.com>
 */
class TTK_MODULE_EXPORT WeatherAbstractTableWidget : public QTableWidget
{
    Q_OBJECT
public:
    /*!
     * Object contsructor.
     */
    explicit WeatherAbstractTableWidget(QWidget *parent = nullptr);
    ~WeatherAbstractTableWidget();

public Q_SLOTS:
    /*!
     * Table widget item cell enter.
     */
    virtual void itemCellEntered(int row, int column);
    /*!
     * Table widget item cell click.
     * Subclass should implement this function.
     */
    virtual void itemCellClicked(int row, int column);
    /*!
     * Remove all items.
     */
    virtual void removeItems();

protected:
    /*!
     * Set selected item row color.
     */
    void setRowColor(int row, const QColor &color) const;

    int m_previousColorRow;
    int m_previousClickRow;
    QColor m_backgroundColor;

};

#endif // WEATHERABSTRACTTABLEWIDGET_H
