#include "weatherabstracttablewidget.h"

WeatherAbstractTableWidget::WeatherAbstractTableWidget(QWidget *parent)
    : TTKAbstractTableWidget(parent)
{
    setStyleSheet(WeatherUIObject::TableWidgetStyle01 + WeatherUIObject::ScrollBarStyle01);

    QPalette plt = palette();
    plt.setBrush(QPalette::Base, QBrush(QColor(255, 255, 255, 150)));
#if defined Q_OS_UNIX && !TTK_QT_VERSION_CHECK(5,7,0) //Fix linux selection-background-color stylesheet bug
    plt.setBrush(QPalette::Highlight, QColor(20, 20, 20, 20));
#endif
    setPalette(plt);
}
