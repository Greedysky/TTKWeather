#ifndef WEATHERAPPLICATION_H
#define WEATHERAPPLICATION_H

/* =================================================
 * This file is part of the TTK Weather project
 * Copyright (c) 2015 - 2016 Greedysky Studio
 * All rights reserved!
 * Redistribution and use of the source code or any derivative
 * works are strictly forbiden.
   =================================================*/

#include "weatherabstractmovewidget.h"

namespace Ui {
class WeatherApplication;
}

class WeatherLoadingWidget;
class WeatherQueryCity;
class WeatherItemTableWidget;
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
    virtual ~WeatherApplication();

private slots:
    void loadingFinished();
    /*!
     * Loading main finished.
     */
    void changeStack2Today();
    /*!
     * Changed the stacked widget to today.
     */
    void changeStack2Future();
    /*!
     * Changed the stacked widget to future.
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
    void initWidget();
    /*!
     * Init main widget.
     */

    Ui::WeatherApplication *ui;
    WeatherLoadingWidget *m_loadingWidget;
    WeatherItemTableWidget *m_todayItem;
    WeatherFutureItemWidget *m_futureItem;
    WeatherQueryCity *m_queryCity;
    QString m_currentItemId;

};

#endif // WEATHERAPPLICATION_H
