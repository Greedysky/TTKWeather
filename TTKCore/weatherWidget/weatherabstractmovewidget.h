#ifndef WEATHERABSTRACTMOVEWIDGET_H
#define WEATHERABSTRACTMOVEWIDGET_H

/* =================================================
 * This file is part of the TTK Weather project
 * Copyright (c) 2015 - 2016 Greedysky Studio
 * All rights reserved!
 * Redistribution and use of the source code or any derivative
 * works are strictly forbiden.
   =================================================*/

#include <QWidget>
#include <QMouseEvent>
#include "weatherlibexportglobal.h"

class WEATHER_WIDGET_EXPORT WeatherAbstractMoveWidget : public QWidget
{
    Q_OBJECT
public:
    explicit WeatherAbstractMoveWidget(QWidget *parent = 0);
    virtual ~WeatherAbstractMoveWidget();

    void drawWindowRoundedRect(QWidget *widget);

protected:
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);

    QPoint m_pressAt;
    bool m_leftButtonPress;

};

#endif // WEATHERABSTRACTMOVEWIDGET_H
