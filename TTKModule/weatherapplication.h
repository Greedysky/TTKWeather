#ifndef WEATHERAPPLICATION_H
#define WEATHERAPPLICATION_H

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

#include "weatherabstractmovewidget.h"

namespace Ui {
class WeatherApplication;
}

class WeatherLoadingWidget;
class WeatherQueryCity;
class WeatherFutureItemWidget;

/*! @brief The class of the main applicatin widget.
 * @author Greedysky <greedysky@163.com>
 */
class WEATHER_GUI_EXPORT WeatherApplication : public WeatherAbstractMoveWidget
{
    Q_OBJECT
public:
    explicit WeatherApplication(QWidget *parent = 0);
    /*!
     * Object contsructor.
     */
    ~WeatherApplication();

private slots:
    void loadingFinished();
    /*!
     * Loading main finished.
     */
    void changeStack2Today();
    /*!
     * Changed the stacked widget to today.
     */
    void listCellClickedByText(const QString &name);
    /*!
     * Send query the weather by given name.
     */
    void loadingIconFinished(const QStringList &icons);
    /*!
     * Load the current weather state icons.
     */
    void aboutApplication();
    /*!
     * Show about dialog.
     */

private:
    void initialize();
    /*!
     * Init main widget.
     */

    Ui::WeatherApplication *ui;
    WeatherLoadingWidget *m_loadingWidget;
    WeatherFutureItemWidget *m_futureItem;
    WeatherQueryCity *m_queryCity;
    QString m_currentItemId;

};

#endif // WEATHERAPPLICATION_H
