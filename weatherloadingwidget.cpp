#include "weatherloadingwidget.h"

WeatherLoadingWidget::WeatherLoadingWidget(QWidget *parent)
    : WeatherAbstractMoveDialog(parent)
{
    resize(200, 110);
    setStyleSheet("background-image:url(':/image/loading')");
    drawWindowRoundedRect(this);

    m_queryCity = new WeatherQueryCity(this);
    connect(m_queryCity, SIGNAL(resolvedSuccess()),
                 parent, SLOT(loadingFinished()));
    m_queryCity->startToQuery();
}

WeatherLoadingWidget::~WeatherLoadingWidget()
{
    delete m_queryCity;
}
