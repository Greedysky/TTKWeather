#ifndef WEATHERITEMTABLEWIDGET_H
#define WEATHERITEMTABLEWIDGET_H

/* =================================================
 * This file is part of the TTK Weather project
 * Copyright (c) 2015 - 2016 Greedysky Studio
 * All rights reserved!
 * Redistribution and use of the source code or any derivative
 * works are strictly forbiden.
   =================================================*/

#include "weatherabstracttablewidget.h"

class WeatherQueryFuture;

class WEATHER_WIDGET_EXPORT WeatherItemTableWidget : public WeatherAbstractTableWidget
{
    Q_OBJECT
public:
    explicit WeatherItemTableWidget(QWidget *parent = 0);
    virtual ~WeatherItemTableWidget();

    void setItemName(const QString &name, int index);
    void createItem(const Weather &weather);

signals:
    void loadingIcon(const QStringList &icons);

public slots:
    virtual void listCellClicked(int row, int column);
    void searchItemInformationDown();

protected:
    WeatherQueryFuture *m_queryFuture;
    int m_indexOfItem;

};

#endif // WEATHERITEMTABLEWIDGET_H
