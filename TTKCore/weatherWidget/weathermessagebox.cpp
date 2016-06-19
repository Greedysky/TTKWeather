#include "weathermessagebox.h"
#include "ui_weathermessagebox.h"
#include "weatheruiobject.h"

#include <QButtonGroup>

WeatherMessageBox::WeatherMessageBox(QWidget *parent)
    : WeatherAbstractMoveDialog(parent),
    ui(new Ui::WeatherMessageBox)
{
    ui->setupUi(this);
    drawWindowRoundedRect(this);
    //set window radius

    m_status = 0;
    ui->background->setPixmap(QPixmap(":/image/background").scaled(size()));
    ////////////////////////////////////////////////
    ui->topTitleCloseButton->setIcon(QIcon(":/image/close1"));
    ui->topTitleCloseButton->setStyleSheet(WeatherUIObject::MToolButtonStyle01);
    ui->topTitleCloseButton->setCursor(QCursor(Qt::PointingHandCursor));
    ui->topTitleCloseButton->setToolTip(tr("Close"));

    ui->confirmButton->setStyleSheet(WeatherUIObject::MPushButtonStyle04);
    ui->cancelButton->setStyleSheet(WeatherUIObject::MPushButtonStyle04);
    ui->confirmButton->setCursor(QCursor(Qt::PointingHandCursor));
    ui->cancelButton->setCursor(QCursor(Qt::PointingHandCursor));

    QButtonGroup *groupButton = new QButtonGroup(this);
    groupButton->addButton(ui->topTitleCloseButton, 0);
    groupButton->addButton(ui->confirmButton, 1);
    groupButton->addButton(ui->cancelButton, 2);
    connect(groupButton, SIGNAL(buttonClicked(int)), SLOT(buttonClicked(int)));

}

WeatherMessageBox::~WeatherMessageBox()
{
    delete ui;
}

void WeatherMessageBox::setText(const QString &text) const
{
    ui->textLabel->setText(text);
}

void WeatherMessageBox::buttonClicked(int index)
{
    switch(index)
    {
        case 0: case 2: m_status = 1; break;
        case 1: m_status = 0; break;
    }
    close();
}
