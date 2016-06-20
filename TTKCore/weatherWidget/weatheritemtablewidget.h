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

/*! @brief The class of the item table widget.
 * @author Greedysky <greedysky@163.com>
 */
class WEATHER_WIDGET_EXPORT WeatherItemTableWidget : public WeatherAbstractTableWidget
{
    Q_OBJECT
public:
    explicit WeatherItemTableWidget(QWidget *parent = 0);
    /*!
     * Object contsructor.
     */
    virtual ~WeatherItemTableWidget();

    void setItemName(const QString &name, int index);
    /*!
     * Set table item to query differ future weather.
     */
    void createItem(const WeatherObject::Weather &weather);
    /*!
     * Set table item by weather object.
     */

signals:
    void loadingIcon(const QStringList &icons);
    /*!
     * Load the current weather state icons.
     */

public slots:
    virtual void listCellClicked(int row, int column) override;
    /*!
     * Table widget list cell click.
     */
    void searchItemInformationDown();
    /*!
     * Query diffe future weather by index done.
     */

protected:
    WeatherQueryFuture *m_queryFuture;
    int m_indexOfItem;

};

#endif // WEATHERITEMTABLEWIDGET_H
