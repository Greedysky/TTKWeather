#ifndef WEATHERFUTUREITEMWIDGET_H
#define WEATHERFUTUREITEMWIDGET_H

/* =================================================
 * This file is part of the TTK Weather project
 * Copyright (c) 2015 - 2016 Greedysky Studio
 * All rights reserved!
 * Redistribution and use of the source code or any derivative
 * works are strictly forbiden.
   =================================================*/

#include <QWidget>
#include "weatherglobaldefine.h"
#include "weatherobject.h"

#define COUNT 5

class QButtonGroup;
class QStackedWidget;
class WeatherItemTableWidget;

/*! @brief The class of the future item widget.
 * @author Greedysky <greedysky@163.com>
 */
class WEATHER_WIDGET_EXPORT WeatherFutureItemWidget : public QWidget
{
    Q_OBJECT
public:
    explicit WeatherFutureItemWidget(QWidget *parent = 0);
    /*!
     * Object contsructor.
     */
    virtual ~WeatherFutureItemWidget();

    void setItemName(const QString &name);
    /*!
     * Set table item to query differ future weather.
     */
    void createItem(const WeatherObject::Weather &weather);
    /*!
     * Set table item by weather object.
     */

private slots:
    void buttonClicked(int index);
    /*!
     * Future button item clicked in which.
     */

protected:
    void initWidget();
    /*!
     * Init future button widget.
     */
    void createButton();
    /*!
     * Create future buttons.
     */

    QString m_itemId;
    QStackedWidget *m_statckedWidget;
    QButtonGroup *m_group;
    QList<WeatherItemTableWidget*> m_itemLists;

};

#endif // WEATHERFUTUREITEMWIDGET_H
