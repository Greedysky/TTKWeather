#include "weathermessagebox.h"
#include "ui_weathermessagebox.h"
#include "weatheruiobject.h"

#include <QButtonGroup>

WeatherMessageBox::WeatherMessageBox(QWidget *parent)
    : WeatherAbstractMoveDialog(parent),
      ui(new Ui::WeatherMessageBox)
{
    ui->setupUi(this);

    QPixmap pix(1, 1);
    pix.fill(QColor(73, 166, 253));
    ui->background->setPixmap(pix.scaled(size()));
    
    ui->topTitleCloseButton->setIcon(QIcon(":/image/close"));
    ui->topTitleCloseButton->setStyleSheet(TTK::UI::ToolButtonStyle01);
    ui->topTitleCloseButton->setCursor(QCursor(Qt::PointingHandCursor));
    ui->topTitleCloseButton->setToolTip(tr("Close"));

    ui->confirmButton->setStyleSheet(TTK::UI::PushButtonStyle01);
    ui->cancelButton->setStyleSheet(TTK::UI::PushButtonStyle01);
    ui->confirmButton->setCursor(QCursor(Qt::PointingHandCursor));
    ui->cancelButton->setCursor(QCursor(Qt::PointingHandCursor));

    QButtonGroup *groupButton = new QButtonGroup(this);
    groupButton->addButton(ui->topTitleCloseButton, 0);
    groupButton->addButton(ui->confirmButton, 1);
    groupButton->addButton(ui->cancelButton, 2);
    QtButtonGroupConnect(groupButton, this, buttonClicked);
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
        case 0:
        case 2: reject(); break;
        case 1: accept(); break;
        default: break;
    }
}
