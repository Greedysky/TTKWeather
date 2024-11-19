#include "weatherabstractmovewidget.h"

WeatherAbstractMoveWidget::WeatherAbstractMoveWidget(QWidget *parent)
    : TTKAbstractMoveWidget(false, parent)
{
    drawWindowShadow(false);
}
