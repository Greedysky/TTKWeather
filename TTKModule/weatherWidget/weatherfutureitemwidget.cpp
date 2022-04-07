#include "weatherfutureitemwidget.h"
#include "weatheritemtablewidget.h"
#include "weatherqueryfuture.h"

#include <QStackedWidget>
#include <QPushButton>
#include <QBoxLayout>
#include <QButtonGroup>

WeatherFutureItemWidget::WeatherFutureItemWidget(QWidget *parent)
    : QWidget(parent)
{
    m_group = new QButtonGroup(this);
    m_statckedWidget = new QStackedWidget(this);

    for(int i = 0; i < COUNT; ++i)
    {
        WeatherItemTableWidget *item = new WeatherItemTableWidget(parent);
        item->createItem( WeatherObject::Weather() );
        m_itemLists << item;
        m_statckedWidget->addWidget(item);
    }
    initialize();
}

WeatherFutureItemWidget::~WeatherFutureItemWidget()
{
    delete m_group;
    while(!m_itemLists.isEmpty())
    {
        delete m_itemLists.takeLast();
    }
    delete m_statckedWidget;
}

void WeatherFutureItemWidget::createButton()
{
    for(int i = 0; i < COUNT; ++i)
    {
        QPushButton *button = new QPushButton(this);
        button->setText(tr("Button%1").arg(i + 1));
        button->setToolTip(tr("Button%1").arg(i + 1));
        button->setFixedSize(65, 30);
        button->setStyleSheet(WeatherUIObject::MPushButtonStyle04);
        m_group->addButton(button, i);
    }
#if TTK_QT_VERSION_CHECK(5,15,0)
    connect(m_group, SIGNAL(idClicked(int)), SLOT(buttonClicked(int)));
#else
    connect(m_group, SIGNAL(buttonClicked(int)), SLOT(buttonClicked(int)));
#endif
}

void WeatherFutureItemWidget::initialize()
{
    createButton();
    QVBoxLayout *vbox = new QVBoxLayout(this);
    vbox->setContentsMargins(0, 0, 0, 0);
    vbox->setSpacing(0);
    QHBoxLayout *hbox = new QHBoxLayout;
    hbox->setContentsMargins(0, 0, 0, 0);
    hbox->setSpacing(0);

    for(int i = 0; i < COUNT; ++i)
    {
        hbox->addWidget(m_group->button(i));
    }
    vbox->addLayout(hbox);
    vbox->addWidget(m_statckedWidget);
    setLayout(vbox);
}

void WeatherFutureItemWidget::buttonClicked(int index)
{
    if(!m_itemId.isEmpty())
    {
        m_itemLists[index]->setItemName(m_itemId, index);
    }
    m_statckedWidget->setCurrentIndex(index);
}

void WeatherFutureItemWidget::setItemName(const QString &name)
{
    m_itemId = name;
    buttonClicked(0);
}

void WeatherFutureItemWidget::createItem(const WeatherObject::Weather &weather)
{
    for(int i = 0; i < COUNT; ++i)
    {
        m_itemLists[i]->createItem(weather);
    }
}
