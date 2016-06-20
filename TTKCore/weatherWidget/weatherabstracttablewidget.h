#ifndef WEATHERABSTRACTTABLEWIDGET_H
#define WEATHERABSTRACTTABLEWIDGET_H

/* =================================================
 * This file is part of the TTK Weather project
 * Copyright (c) 2015 - 2016 Greedysky Studio
 * All rights reserved!
 * Redistribution and use of the source code or any derivative
 * works are strictly forbiden.
   =================================================*/

#include <QTableWidget>
#include <QHeaderView>
#include "weatherglobaldefine.h"
#include "weatherobject.h"
#include "weatheruiobject.h"

class WEATHER_WIDGET_EXPORT WeatherAbstractTableWidget : public QTableWidget
{
    Q_OBJECT
public:
    explicit WeatherAbstractTableWidget(QWidget *parent = 0);
    virtual ~WeatherAbstractTableWidget();

    void clear();

public slots:
    virtual void listCellEntered(int row, int column);
    virtual void listCellClicked(int row, int column) = 0;

protected:
    void setTransparent(int angle);
    void setRowColor(int row, const QColor &color) const;

    QColor m_defaultBkColor;
    int m_previousColorRow;
    int m_previousClickRow;

};

#endif // WEATHERABSTRACTTABLEWIDGET_H
