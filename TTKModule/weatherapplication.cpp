#include "weatherapplication.h"
#include "ui_weatherapplication.h"
#include "weatherloadingwidget.h"
#include "weatherqueryfuture.h"
#include "weatheruiobject.h"
#include "weatheritemtablewidget.h"
#include "weatherfutureitemwidget.h"
#include "weathermessagebox.h"
#include "weatherversion.h"

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
    delete m_futureItem;
    delete ui;
}

void WeatherApplication::initialize()
{
    QPixmap pix(1, 1);
    pix.fill(QColor(73, 166, 253));
    ui->background->setPixmap(pix.scaled(size()));

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

    connect(ui->addItemTableWidget, SIGNAL(listCellClickedByText(QString)), SLOT(listCellClickedByText(QString)));

    m_futureItem = new WeatherFutureItemWidget(this);
    ui->stackedWidget->addWidget(m_futureItem);
}

void WeatherApplication::loadingFinished()
{
    m_queryCity = m_loadingWidget->getQueryCity();
    m_loadingWidget->close();

    setAttribute(Qt::WA_TranslucentBackground, true);
    initialize();
    show();
}

void WeatherApplication::changeStack2Today()
{
    ui->stackedWidget->setCurrentIndex(0);
    !m_currentItemId.isEmpty() ? m_futureItem->setItemName(m_currentItemId)
                               : m_futureItem->createItem( WeatherObject::Weather() );
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
    message.setText(tr(TTK_APP_STR) + QString("\n\n") +
                    tr("Directed By Greedysky") +
                    QString("\nCopyright© 2015-2022") +
                    QString("\nMail:Greedysky@163.com"));
    message.exec();
}
