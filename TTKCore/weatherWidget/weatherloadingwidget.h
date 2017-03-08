#ifndef WEATHERLOADINGWIDGET_H
#define WEATHERLOADINGWIDGET_H

/* =================================================
 * This file is part of the TTK Weather project
 * Copyright (c) 2015 - 2017 Greedysky Studio
 * All rights reserved!
 * Redistribution and use of the source code or any derivative
 * works are strictly forbiden.
   =================================================*/

#include "weatherquerycity.h"
#include "weatherabstractmovedialog.h"

/*! @brief The class of the weather loading widget.
 * @author Greedysky <greedysky@163.com>
 */
class WEATHER_WIDGET_EXPORT WeatherLoadingWidget : public WeatherAbstractMoveDialog
{
    Q_OBJECT
public:
    explicit WeatherLoadingWidget(QWidget *parent = 0);
    /*!
     * Object contsructor.
     */
    virtual ~WeatherLoadingWidget();

    inline WeatherQueryCity *getQueryCity() const { return m_queryCity; }
    /*!
     * Get query city finished.
     */

protected:
    WeatherQueryCity *m_queryCity;

};

#endif // WEATHERLOADINGWIDGET_H
