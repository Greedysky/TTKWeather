#ifndef WEATHERBUTTONDELEGATE_H
#define WEATHERBUTTONDELEGATE_H

#include <QItemDelegate>
#include "weatherlibexportglobal.h"

class QPushButton;

class WEATHER_WIDGET_EXPORT WeatherButtonDelegate : public QItemDelegate
{
public:
    explicit WeatherButtonDelegate(QObject* parent = 0);
    ~WeatherButtonDelegate();

    QSize sizeHint(const QStyleOptionViewItem &option,
                   const QModelIndex &) const;
    void paint(QPainter *painter,
               const QStyleOptionViewItem &option,
               const QModelIndex &index) const;
private:
    QPushButton *m_pushButton;

};

#endif // WEATHERBUTTONDELEGATE_H
