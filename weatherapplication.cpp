#include "weatherapplication.h"
#include "ui_weatherapplication.h"
#include "weatherloadingwidget.h"
#include "weatherqueryfuture.h"
#include "weatheruiobject.h"
#include "weatheritemtablewidget.h"
#include "weatherfutureitemwidget.h"
#include "weathermessagebox.h"

#include <QPainter>

WeatherApplication::WeatherApplication(QWidget *parent) :
    WeatherAbstractMoveWidget(parent),
    ui(new Ui::WeatherApplication)
{
    ui->setupUi(this);

    hide();
    m_loadingWidget = new WeatherLoadingWidget(this);
    m_loadingWidget->show();
}

WeatherApplication::~WeatherApplication()
{
    delete m_loadingWidget;
    delete m_todayItem;
    delete m_futureItem;
    delete ui;
}

void WeatherApplication::initWidget()
{
    QPixmap origin(":/image/background");
    QPixmap afterDeal( size() );
    afterDeal.fill(Qt::transparent);
    QPainter paint(&afterDeal);
    paint.fillRect(0, 0, afterDeal.width(), afterDeal.height(), QColor(255, 255, 255, 222));
    paint.setCompositionMode(QPainter::CompositionMode_SourceIn);
    paint.drawPixmap(0, 0, QPixmap::fromImage(origin.scaled(size(), Qt::KeepAspectRatioByExpanding).toImage()));
    paint.end();
    ui->background->setPixmap(afterDeal);

    QPixmap minPix  = style()->standardPixmap(QStyle::SP_TitleBarMinButton);
    ui->minimization->setIcon(QIcon(minPix.scaled(25, 25)));
    ui->minimization->setStyleSheet(WeatherUIObject::MToolButtonStyle01);
    ui->minimization->setCursor(QCursor(Qt::PointingHandCursor));
    ui->minimization->setToolTip(tr("Minimization"));
    connect(ui->minimization, SIGNAL(clicked()), SLOT(showMinimized()));

    ui->windowClose->setToolTip(tr("Close"));
    ui->windowClose->setCursor(QCursor(Qt::PointingHandCursor));
    ui->windowClose->setStyleSheet(WeatherUIObject::MToolButtonStyle01);
    ui->windowClose->setIcon(QIcon(QPixmap(QString::fromUtf8(":/image/close")).scaled(25,25)));
    connect(ui->windowClose, SIGNAL(clicked()), SLOT(close()));

    ui->windowAbout->setToolTip(tr("About"));
    ui->windowAbout->setCursor(QCursor(Qt::PointingHandCursor));
    ui->windowAbout->setStyleSheet(WeatherUIObject::MToolButtonStyle01);
    ui->windowAbout->setIcon(QIcon(QPixmap(QString::fromUtf8(":/image/about")).scaled(25,25)));
    connect(ui->windowAbout, SIGNAL(clicked()), SLOT(aboutApplication()));


    ui->todayButton->setToolTip(tr("Today"));
    ui->todayButton->setCursor(QCursor(Qt::PointingHandCursor));
    ui->todayButton->setStyleSheet(WeatherUIObject::MPushButtonStyle03);
    connect(ui->todayButton, SIGNAL(clicked()), SLOT(changeStack2Today()));

    ui->futureButton->setToolTip(tr("Future"));
    ui->futureButton->setCursor(QCursor(Qt::PointingHandCursor));
    ui->futureButton->setStyleSheet(WeatherUIObject::MPushButtonStyle03);
    connect(ui->futureButton, SIGNAL(clicked()), SLOT(changeStack2Future()));

    ui->addCityButton->setToolTip(tr("AddCity"));
    ui->addCityButton->setCursor(QCursor(Qt::PointingHandCursor));
    ui->addCityButton->setStyleSheet(WeatherUIObject::MPushButtonStyle03);
    connect(ui->addCityButton, SIGNAL(clicked()), ui->addItemTableWidget, SLOT(addCityClicked()));
    connect(ui->addItemTableWidget, SIGNAL(listCellClickedByText(QString)),
                                    SLOT(listCellClickedByText(QString)));

    m_todayItem = new WeatherItemTableWidget(this);
    m_futureItem = new WeatherFutureItemWidget(this);
    ui->stackedWidget->addWidget(m_todayItem);
    ui->stackedWidget->addWidget(m_futureItem);

    m_todayItem->createItem(Weather());
}

void WeatherApplication::loadingFinished()
{
    m_queryCity = m_loadingWidget->getQueryCity();
    m_loadingWidget->close();

    setAttribute(Qt::WA_TranslucentBackground, true);
    drawWindowRoundedRect(this);
    initWidget();
    show();
}

void WeatherApplication::changeStack2Today()
{
    ui->stackedWidget->setCurrentIndex(0);
    !m_currentItemId.isEmpty() ? m_todayItem->setItemName(m_currentItemId, 0)
                               : m_todayItem->createItem(Weather());
}

void WeatherApplication::changeStack2Future()
{
    ui->stackedWidget->setCurrentIndex(1);
    !m_currentItemId.isEmpty() ? m_futureItem->setItemName(m_currentItemId)
                               : m_futureItem->createItem(Weather());
}

void WeatherApplication::listCellClickedByText(const QString &name)
{
    m_currentItemId = m_queryCity->getCityCode(name);
    changeStack2Today();
}

void WeatherApplication::loadingIconFinished(const QStringList &icons)
{
    ui->addItemTableWidget->loadingIconFinished(icons);
}

void WeatherApplication::aboutApplication()
{
    WeatherMessageBox message;
    message.setText(tr("QWeather") + QString("\n\n") +
                    tr("Directed By Greedysky") +
                    QString("\nCopyright© 2014-2015") +
                    QString("\nMail:Greedysky@163.com"));
    message.exec();
}
