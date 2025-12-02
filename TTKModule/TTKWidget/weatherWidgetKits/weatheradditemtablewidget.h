#ifndef WEATHERADDITEMTABLEWIDGET_H
#define WEATHERADDITEMTABLEWIDGET_H

/***************************************************************************
 * This file is part of the TTK Weather project
 * Copyright (C) 2015 - 2026 Greedysky Studio

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

#include "weatherabstracttablewidget.h"

/*! @brief The class of the add item table widget.
 * @author Greedysky <greedysky@163.com>
 */
class TTK_MODULE_EXPORT WeatherAddItemTableWidget : public WeatherAbstractTableWidget
{
    Q_OBJECT
public:
    /*!
     * Object constructor.
     */
    explicit WeatherAddItemTableWidget(QWidget *parent = nullptr);
    /*!
     * Object destructor.
     */
    ~WeatherAddItemTableWidget();

    /*!
     * Load the current weather state icons.
     */
    void loadingIconFinished(const QStringList &icons);

Q_SIGNALS:
    /*!
     * Send query the weather by given name.
     */
    void itemCellClickedByText(const QString &name);

public Q_SLOTS:
    /*!
     * Table widget item cell click.
     */
    virtual void itemCellClicked(int row, int column) override final;
    /*!
     * Add city button click.
     */
    void addCityClicked();
    /*!
     * Delete city button click.
     */
    void deleteCityClicked();

private:
    /*!
     * Override the widget event.
     */
    virtual void contextMenuEvent(QContextMenuEvent *event) override final;

};

#endif // WEATHERADDITEMTABLEWIDGET_H
