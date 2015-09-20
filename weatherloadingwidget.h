#ifndef WEATHERLOADINGWIDGET_H
#define WEATHERLOADINGWIDGET_H

#include "weatherquerycity.h"
#include "weatherabstractmovedialog.h"

class WEATHER_WIDGET_EXPORT WeatherLoadingWidget : public WeatherAbstractMoveDialog
{
    Q_OBJECT
public:
    explicit WeatherLoadingWidget(QWidget *parent = 0);
    ~WeatherLoadingWidget();

    inline WeatherQueryCity *getQueryCity() const {return m_queryCity;}

protected:
    WeatherQueryCity *m_queryCity;

};

#endif // WEATHERLOADINGWIDGET_H
