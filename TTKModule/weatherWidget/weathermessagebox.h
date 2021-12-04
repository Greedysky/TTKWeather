#ifndef WEATHERMESSAGEBOX_H
#define WEATHERMESSAGEBOX_H

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

#include "weatherabstractmovedialog.h"

namespace Ui {
class WeatherMessageBox;
}

/*! @brief The class of the messagebox widget.
 * @author Greedysky <greedysky@163.com>
 */
class WEATHER_WIDGET_EXPORT WeatherMessageBox : public WeatherAbstractMoveDialog
{
    Q_OBJECT
public:
    explicit WeatherMessageBox(QWidget *parent = 0);
    /*!
     * Object contsructor.
     */
    virtual ~WeatherMessageBox();

    void setText(const QString &text) const;
    /*!
     * Set context text.
     */

public slots:
    void buttonClicked(int index);
    /*!
     * Confirm or cancal button clicked, set the state.
     */

protected:
    Ui::WeatherMessageBox *ui;
    int m_status;

};

#endif // WEATHERMESSAGEBOX_H
