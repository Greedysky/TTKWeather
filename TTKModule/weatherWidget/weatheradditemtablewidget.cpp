#include "weatheradditemtablewidget.h"
#include "weatherversion.h"

#include <QMenu>
#include <QInputDialog>

WeatherAddItemTableWidget::WeatherAddItemTableWidget(QWidget *parent)
    : WeatherAbstractTableWidget(parent)
{
    setColumnCount(6);
    QHeaderView *headerview = horizontalHeader();
    headerview->resizeSection(0, 20);
    headerview->resizeSection(1, 130);
    headerview->resizeSection(2, 35);
    headerview->resizeSection(3, 20);
    headerview->resizeSection(4, 35);
    headerview->resizeSection(5, 15);
    setIconSize(QSize(28, 20));
}

WeatherAddItemTableWidget::~WeatherAddItemTableWidget()
{
    clear();
}

void WeatherAddItemTableWidget::contextMenuEvent(QContextMenuEvent *event)
{
    WeatherAbstractTableWidget::contextMenuEvent(event);

    QMenu menu(this);
    menu.setStyleSheet(WeatherUIObject::MMenuStyle01);
    menu.addAction(tr("Add"), this, SLOT(addCityClicked()));
    menu.addAction(tr("Delete"), this, SLOT(deleteCityClicked()));
    menu.exec(QCursor::pos());
}

void WeatherAddItemTableWidget::listCellClicked(int row, int)
{
    emit listCellClickedByText( item(row, 1)->text() );
}

void WeatherAddItemTableWidget::addCityClicked()
{
    QString text = QInputDialog::getText(nullptr, TTKWEATHER_STR, tr("Input address!"));
    if(!text.isEmpty())
    {
        int index = rowCount();
        setRowCount(index + 1);
        setRowHeight(index, 35);

        QTableWidgetItem *item = new QTableWidgetItem;
        setItem(index, 0, item);

                          item = new QTableWidgetItem;
        item->setText( text );
        item->setTextAlignment(Qt::AlignCenter);
        setItem(index, 1, item);

                          item = new QTableWidgetItem;
        item->setText( "-" );
        setItem(index, 2, item);

        setItem(index, 3, new QTableWidgetItem);

                          item = new QTableWidgetItem;
        item->setText( "-" );
        setItem(index, 4, item);

        setItem(index, 5, new QTableWidgetItem);
    }
}

void WeatherAddItemTableWidget::deleteCityClicked()
{
    if( currentRow() > -1)
    {
        removeRow( currentRow() );
        emit listCellClickedByText( QString() );
    }
}

void WeatherAddItemTableWidget::loadingIconFinished(const QStringList &icons)
{
    Q_ASSERT(icons.count() == 2);
    int index = currentRow();
    if(index < 0)
    {
        return;
    }

    QString str = icons.first();
    str = ":" + str.right(str.length() - str.lastIndexOf("/") + 2);
    item(index, 2)->setIcon(QIcon( str ));

    str = icons.last();
    str = ":" + str.right(str.length() - str.lastIndexOf("/") + 2);
    item(index, 4)->setIcon(QIcon( str ));
}
