#include "weatheritemdelegate.h"
#include "weatheruiobject.h"

#include <QPainter>
#include <QPushButton>

WeatherButtonDelegate::WeatherButtonDelegate(QObject *parent)
    : QItemDelegate(parent)
{
    m_pushButton  = new QPushButton;
//    m_pushButton->setStyleSheet(MusicUIObject::MCheckBoxStyle01);
}

WeatherButtonDelegate::~WeatherButtonDelegate()
{
    delete m_pushButton;
}

QSize WeatherButtonDelegate::sizeHint(const QStyleOptionViewItem &option,
                                      const QModelIndex &) const
{
    QSize size = option.rect.size();
    size.setHeight(25);
    return size;
}

void WeatherButtonDelegate::paint(QPainter *painter,
                                  const QStyleOptionViewItem &option,
                                  const QModelIndex &index) const
{
    painter->save();
    int minSize = qMin(option.rect.width(), option.rect.height());
    m_pushButton->resize(minSize, minSize);
//    /*m_checkBox->setChecked( index.data(Qt::DisplayRole).toBool() );
    painter->translate((option.rect.width() - 16)/2, 0); // top left
    m_pushButton->render(painter, option.rect.topLeft(), QRegion(),
                         QWidget::DrawChildren);
    painter->restore();
}
