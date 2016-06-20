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

/*! @brief The class of the table widget base.
 * @author Greedysky <greedysky@163.com>
 */
class WEATHER_WIDGET_EXPORT WeatherAbstractTableWidget : public QTableWidget
{
    Q_OBJECT
public:
    explicit WeatherAbstractTableWidget(QWidget *parent = 0);
    /*!
     * Object contsructor.
     */
    virtual ~WeatherAbstractTableWidget();

    void clear();
    /*!
     * Clear current items.
     */

public slots:
    virtual void listCellEntered(int row, int column);
    /*!
     * Table widget list cell enter.
     */
    virtual void listCellClicked(int row, int column) = 0;
    /*!
     * Table widget list cell click.
     * Subclass should implement this function.
     */

protected:
    void setTransparent(int angle);
    /*!
     * Set widget transparent.
     */
    void setRowColor(int row, const QColor &color) const;
    /*!
     * Set selected item row color.
     */

    QColor m_defaultBkColor;
    int m_previousColorRow;
    int m_previousClickRow;

};

#endif // WEATHERABSTRACTTABLEWIDGET_H
