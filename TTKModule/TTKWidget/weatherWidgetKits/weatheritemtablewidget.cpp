#include "weatheritemtablewidget.h"
#include "weatheruiobject.h"
#include "weatherqueryfuture.h"

WeatherItemTableWidget::WeatherItemTableWidget(QWidget *parent)
    : WeatherAbstractTableWidget(parent),
      m_queryFuture(nullptr),
      m_indexOfItem(-1)
{
    setColumnCount(2);

    QHeaderView *headerView = horizontalHeader();
    headerView->resizeSection(0, 120);
    headerView->resizeSection(1, 200);

    connect(this, SIGNAL(loadingIcon(QStringList)), parent, SLOT(loadingIconFinished(QStringList)));
}

WeatherItemTableWidget::~WeatherItemTableWidget()
{
    delete m_queryFuture;
}

void WeatherItemTableWidget::setItemName(const QString &name, int index)
{
    m_indexOfItem = index;
    if(m_queryFuture == nullptr)
    {
        m_queryFuture = new WeatherQueryFuture(this);
        connect(m_queryFuture, SIGNAL(downloadDataChanged(QString)), SLOT(searchItemInformationDown()));
    }
    m_queryFuture->startToRequest(name);
}

void WeatherItemTableWidget::createItem(const TTK::Weather &weather)
{
    removeItems();
    QStringList names, values;
    names << tr("citynm") << tr("days") << tr("temperature") << tr("humidity")
          << tr("weather") << tr("wind") << tr("winp") << tr("temp_high")
          << tr("temp_low") << tr("humi_high") << tr("humi_low");

    values << weather.m_citynm << QString("%1  %2").arg(weather.m_days, weather.m_week)
           << weather.m_temperature << weather.m_humidity << weather.m_weather
           << weather.m_wind << weather.m_winp << weather.m_temp_high << weather.m_temp_low
           << weather.m_humi_high << weather.m_humi_low;

    setRowCount(names.count());
    for(int i = 0; i < names.count(); ++i)
    {
        QTableWidgetItem *item = new QTableWidgetItem(names[i]);
        item->setForeground(QColor(50, 50, 50));
        QtItemSetTextAlignment(item, Qt::AlignCenter);
        setItem(i, 0, item);

                          item = new QTableWidgetItem(values[i].isEmpty() ? "-" : values[i]);
        item->setForeground(QColor(50, 50, 50));
        QtItemSetTextAlignment(item, Qt::AlignLeft | Qt::AlignVCenter);
        setItem(i, 1, item);
    }
}

void WeatherItemTableWidget::searchItemInformationDown()
{
    const TTK::Weather &weather = m_queryFuture->future(m_indexOfItem);
    Q_EMIT loadingIcon({weather.m_weatidX, weather.m_weatidY});
    createItem(weather);
}
