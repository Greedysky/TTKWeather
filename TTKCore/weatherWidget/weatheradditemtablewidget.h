#ifndef WEATHERADDITEMTABLEWIDGET_H
#define WEATHERADDITEMTABLEWIDGET_H

/* =================================================
 * This file is part of the TTK Weather project
 * Copyright (c) 2015 - 2016 Greedysky Studio
 * All rights reserved!
 * Redistribution and use of the source code or any derivative
 * works are strictly forbiden.
   =================================================*/

#include "weatherabstracttablewidget.h"

class WEATHER_WIDGET_EXPORT WeatherAddItemTableWidget : public WeatherAbstractTableWidget
{
    Q_OBJECT
public:
    explicit WeatherAddItemTableWidget(QWidget *parent = 0);
    ~WeatherAddItemTableWidget();

    void loadingIconFinished(const QStringList &icons);

signals:
    void listCellClickedByText(const QString &name);

public slots:
    virtual void listCellClicked(int row, int column);
    void addCityClicked();
    void deleteCityClicked();

protected:
    virtual void contextMenuEvent(QContextMenuEvent *event);

};

#endif // WEATHERADDITEMTABLEWIDGET_H
