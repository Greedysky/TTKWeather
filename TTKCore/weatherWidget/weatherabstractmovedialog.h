#ifndef WEATHERABSTRACTMOVEDIALOG_H
#define WEATHERABSTRACTMOVEDIALOG_H

/* =================================================
 * This file is part of the TTK Weather project
 * Copyright (c) 2015 - 2016 Greedysky Studio
 * All rights reserved!
 * Redistribution and use of the source code or any derivative
 * works are strictly forbiden.
   =================================================*/

#include <QDialog>
#include "weatherglobaldefine.h"

/*! @brief The class of the moving dialog base.
 * @author Greedysky <greedysky@163.com>
 */
class WEATHER_WIDGET_EXPORT WeatherAbstractMoveDialog : public QDialog
{
    Q_OBJECT
public:
    explicit WeatherAbstractMoveDialog(QWidget *parent = 0);
    /*!
     * Object contsructor.
     */
    virtual ~WeatherAbstractMoveDialog();

    void drawWindowRoundedRect(QWidget *widget);
    /*!
     * Set or not draw window bound shadow.
     */

protected:
    virtual void mousePressEvent(QMouseEvent *event) override;
    virtual void mouseMoveEvent(QMouseEvent *event) override;
    virtual void mouseReleaseEvent(QMouseEvent *event) override;
    /*!
     * Override the widget event.
     */

    QPoint m_pressAt;
    bool m_leftButtonPress;

};

#endif // WEATHERABSTRACTMOVEDIALOG_H
