#ifndef WEATHERAPPLICATION_H
#define WEATHERAPPLICATION_H

/* =================================================
 * This file is part of the weather project
 * Copyright (c) 2014 - 2015 Greedysky Studio
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

class WEATHER_GUI_EXPORT WeatherApplication : public WeatherAbstractMoveWidget
{
    Q_OBJECT
public:
    explicit WeatherApplication(QWidget *parent = 0);
    ~WeatherApplication();

private slots:
    void loadingFinished();
    void changeStack2Today();
    void changeStack2Future();
    void listCellClickedByText(const QString &name);
    void loadingIconFinished(const QStringList &icons);

private:
    void initWidget();

    Ui::WeatherApplication *ui;
    WeatherLoadingWidget *m_loadingWidget;
    WeatherItemTableWidget *m_todayItem;
    WeatherFutureItemWidget *m_futureItem;
    WeatherQueryCity *m_queryCity;
    QString m_currentItemId;

};

#endif // WEATHERAPPLICATION_H
