#include "weatherapplication.h"
#include "ui_weatherapplication.h"
#include "weatherloadingwidget.h"
#include "weatherqueryfuture.h"
#include "weatheruiobject.h"
#include "weatheritemtablewidget.h"
#include "weatherfutureitemwidget.h"
#include "weathermessagebox.h"
#include "weatherwidgetutils.h"

#include <QPainter>

WeatherApplication::WeatherApplication(QWidget *parent)
    : WeatherAbstractMoveWidget(parent),
      ui(new Ui::WeatherApplication)
{
    ui->setupUi(this);

    hide();

#ifndef QT_NO_SSL
    // ssl support check
    TTK_INFO_STREAM("Application network support ssl:" << (QSslSocket::supportsSsl() ? "true" : "false"));
#  if TTK_QT_VERSION_CHECK(5,0,0)
#    if TTK_QT_VERSION_CHECK(5,4,0)
    TTK_INFO_STREAM("Application network ssl build version:" << QSslSocket::sslLibraryBuildVersionString());
#    endif
    TTK_INFO_STREAM("Application network ssl runtime version:" << QSslSocket::sslLibraryVersionString());
#  endif
#endif

    m_loadingWidget = new WeatherLoadingWidget(this);
    m_loadingWidget->show();

    TTK::Widget::adjustWidgetPosition(this);
    TTK::Widget::adjustWidgetPosition(m_loadingWidget);
}

WeatherApplication::~WeatherApplication()
{
    Q_CLEANUP_RESOURCE(TTKModule);
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
    ui->minimization->setStyleSheet(TTK::UI::ToolButtonStyle01);
    ui->minimization->setCursor(QCursor(Qt::PointingHandCursor));
    ui->minimization->setToolTip(tr("Minimization"));
    connect(ui->minimization, SIGNAL(clicked()), SLOT(showMinimized()));

    ui->windowClose->setToolTip(tr("Close"));
    ui->windowClose->setCursor(QCursor(Qt::PointingHandCursor));
    ui->windowClose->setStyleSheet(TTK::UI::ToolButtonStyle01);
    ui->windowClose->setIcon(QIcon(QPixmap(QString::fromUtf8(":/image/close")).scaled(25,25)));
    connect(ui->windowClose, SIGNAL(clicked()), SLOT(close()));

    ui->windowAbout->setToolTip(tr("About"));
    ui->windowAbout->setCursor(QCursor(Qt::PointingHandCursor));
    ui->windowAbout->setStyleSheet(TTK::UI::ToolButtonStyle01);
    ui->windowAbout->setIcon(QIcon(QPixmap(QString::fromUtf8(":/image/about")).scaled(25,25)));
    connect(ui->windowAbout, SIGNAL(clicked()), SLOT(aboutApplication()));

    connect(ui->addItemTableWidget, SIGNAL(itemCellClickedByText(QString)), SLOT(itemCellClickedByText(QString)));

    m_futureItem = new WeatherFutureItemWidget(this);
    ui->stackedWidget->addWidget(m_futureItem);
}

void WeatherApplication::loadingFinished()
{
    m_queryCity = m_loadingWidget->queryCity();
    m_loadingWidget->close();

    setAttribute(Qt::WA_TranslucentBackground);
    initialize();
    show();
}

void WeatherApplication::changeStack2Today()
{
    ui->stackedWidget->setCurrentIndex(0);
    !m_currentItemId.isEmpty() ? m_futureItem->setItemName(m_currentItemId) : m_futureItem->createItem(TTK::Weather());
}

void WeatherApplication::itemCellClickedByText(const QString &name)
{
    m_currentItemId = m_queryCity->cityCode(name);
    changeStack2Today();
}

void WeatherApplication::loadingIconFinished(const QStringList &icons)
{
    ui->addItemTableWidget->loadingIconFinished(icons);
}

void WeatherApplication::aboutApplication()
{
    WeatherMessageBox message;
    message.setText(tr(TTK_APP_NAME) + QString("\n\n") +
                    tr("Directed By Greedysky") +
                    QString("\nCopyright© 2015 - 2026") +
                    QString("\nMail:Greedysky@163.com"));
    message.exec();
}
