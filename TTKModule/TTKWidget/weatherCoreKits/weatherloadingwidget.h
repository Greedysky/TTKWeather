#ifndef WEATHERLOADINGWIDGET_H
#define WEATHERLOADINGWIDGET_H

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

#include "weatherquerycity.h"
#include "weatherabstractmovedialog.h"

/*! @brief The class of the weather loading widget.
 * @author Greedysky <greedysky@163.com>
 */
class TTK_MODULE_EXPORT WeatherLoadingWidget : public WeatherAbstractMoveDialog
{
    Q_OBJECT
public:
    /*!
     * Object constructor.
     */
    explicit WeatherLoadingWidget(QWidget *parent = nullptr);
    /*!
     * Object destructor.
     */
    ~WeatherLoadingWidget();

    /*!
     * Get query city finished.
     */
    inline WeatherQueryCity *queryCity() const noexcept { return m_queryCity; }

private:
    WeatherQueryCity *m_queryCity;

};

#endif // WEATHERLOADINGWIDGET_H
