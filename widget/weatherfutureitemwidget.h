#ifndef WEATHERFUTUREITEMWIDGET_H
#define WEATHERFUTUREITEMWIDGET_H

/* =================================================
 * This file is part of the weather project
 * Copyright (c) 2014 - 2015 Greedysky Studio
 * All rights reserved!
 * Redistribution and use of the source code or any derivative
 * works are strictly forbiden.
   =================================================*/

#include <QWidget>
#include "weatherlibexportglobal.h"
#include "weatherobject.h"

#define COUNT 5

class QButtonGroup;
class QStackedWidget;
class WeatherItemTableWidget;

class WEATHER_WIDGET_EXPORT WeatherFutureItemWidget : public QWidget
{
    Q_OBJECT
public:
    explicit WeatherFutureItemWidget(QWidget *parent = 0);
    ~WeatherFutureItemWidget();

    void setItemName(const QString &name);
    void createItem(const Weather &weather);

private slots:
    void buttonClicked(int index);

protected:
    void initWidget();
    void createButton();

    QString m_itemId;
    QStackedWidget *m_statckedWidget;
    QButtonGroup *m_group;
    QList<WeatherItemTableWidget*> m_itemLists;

};

#endif // WEATHERFUTUREITEMWIDGET_H
