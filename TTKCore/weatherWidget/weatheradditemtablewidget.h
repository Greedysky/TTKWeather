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

/*! @brief The class of the add item table widget.
 * @author Greedysky <greedysky@163.com>
 */
class WEATHER_WIDGET_EXPORT WeatherAddItemTableWidget : public WeatherAbstractTableWidget
{
    Q_OBJECT
public:
    explicit WeatherAddItemTableWidget(QWidget *parent = 0);
    /*!
     * Object contsructor.
     */
    virtual ~WeatherAddItemTableWidget();

    void loadingIconFinished(const QStringList &icons);
    /*!
     * Load the current weather state icons.
     */

signals:
    void listCellClickedByText(const QString &name);
    /*!
     * Send query the weather by given name.
     */

public slots:
    virtual void listCellClicked(int row, int column);
    /*!
     * Table widget list cell click.
     */
    void addCityClicked();
    /*!
     * Add city button click.
     */
    void deleteCityClicked();
    /*!
     * Delete city button click.
     */

protected:
    virtual void contextMenuEvent(QContextMenuEvent *event);
    /*!
     * Override the widget event.
     */

};

#endif // WEATHERADDITEMTABLEWIDGET_H
