#ifndef WEATHERLOADINGWIDGET_H
#define WEATHERLOADINGWIDGET_H

/* =================================================
 * This file is part of the TTK Weather project
 * Copyright (c) 2015 - 2016 Greedysky Studio
 * All rights reserved!
 * Redistribution and use of the source code or any derivative
 * works are strictly forbiden.
   =================================================*/

#include "weatherquerycity.h"
#include "weatherabstractmovedialog.h"

class WEATHER_WIDGET_EXPORT WeatherLoadingWidget : public WeatherAbstractMoveDialog
{
    Q_OBJECT
public:
    explicit WeatherLoadingWidget(QWidget *parent = 0);
    ~WeatherLoadingWidget();

    inline WeatherQueryCity *getQueryCity() const {return m_queryCity;}

protected:
    WeatherQueryCity *m_queryCity;

};

#endif // WEATHERLOADINGWIDGET_H
