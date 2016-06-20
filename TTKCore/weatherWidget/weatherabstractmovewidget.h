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
#include "weatherglobaldefine.h"

/*! @brief The class of the moving widget base.
 * @author Greedysky <greedysky@163.com>
 */
class WEATHER_WIDGET_EXPORT WeatherAbstractMoveWidget : public QWidget
{
    Q_OBJECT
public:
    explicit WeatherAbstractMoveWidget(QWidget *parent = 0);
    /*!
     * Object contsructor.
     */
    virtual ~WeatherAbstractMoveWidget();

    void drawWindowRoundedRect(QWidget *widget);
    /*!
     * Set or not draw window bound shadow.
     */

protected:
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);
    /*!
     * Override the widget event.
     */

    QPoint m_pressAt;
    bool m_leftButtonPress;

};

#endif // WEATHERABSTRACTMOVEWIDGET_H
