#ifndef WEATHERQUERYCITY_H
#define WEATHERQUERYCITY_H

/* =================================================
 * This file is part of the TTK Weather project
 * Copyright (c) 2015 - 2016 Greedysky Studio
 * All rights reserved!
 * Redistribution and use of the source code or any derivative
 * works are strictly forbiden.
   =================================================*/

#include "weatherquery.h"

/*! @brief The class of the weather city query.
 * @author Greedysky <greedysky@163.com>
 */
class WEATHER_CORE_EXPORT WeatherQueryCity : public WeatherQuery
{
    Q_OBJECT
public:
    explicit WeatherQueryCity(QObject *parent = 0);
    /*!
     * Object contsructor.
     */

    virtual void startToQuery(const QString &id = 0) override;
    /*!
     * Start to query data.
     */

    QString getCityCode(const QString &name) const;
    /*!
     * Get city code by name.
     */
    const WeatherObject::MStriantMap& getCityCodes() const;
    /*!
     * Get all cities code.
     */

public slots:
    virtual void searchFinshed() override;
    /*!
     * Download data from net finished.
     */

protected:
    WeatherObject::MStriantMap m_cityMap;

};

#endif // WEATHERQUERYCITY_H
