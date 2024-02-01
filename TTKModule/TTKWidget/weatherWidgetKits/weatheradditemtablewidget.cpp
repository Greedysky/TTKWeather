#include "weatheradditemtablewidget.h"

#include <QMenu>
#include <QInputDialog>

WeatherAddItemTableWidget::WeatherAddItemTableWidget(QWidget *parent)
    : WeatherAbstractTableWidget(parent)
{
    setColumnCount(3);

    QHeaderView *headerView = horizontalHeader();
    headerView->resizeSection(0, 151);
    headerView->resizeSection(1, 55);
    headerView->resizeSection(2, 55);
    setIconSize(QSize(28, 20));
}

WeatherAddItemTableWidget::~WeatherAddItemTableWidget()
{
    removeItems();
}

void WeatherAddItemTableWidget::contextMenuEvent(QContextMenuEvent *event)
{
    WeatherAbstractTableWidget::contextMenuEvent(event);

    QMenu menu(this);
    menu.setStyleSheet(TTK::UI::MenuStyle01);
    menu.addAction(tr("Add"), this, SLOT(addCityClicked()));
    menu.addAction(tr("Delete"), this, SLOT(deleteCityClicked()));
    menu.exec(QCursor::pos());
}

void WeatherAddItemTableWidget::itemCellClicked(int row, int)
{
    Q_EMIT itemCellClickedByText(item(row, 0)->text());
}

void WeatherAddItemTableWidget::addCityClicked()
{
    const QString &text = QInputDialog::getText(nullptr, TTK_APP_NAME, tr("Input address"));
    if(!text.isEmpty())
    {
        int index = rowCount();
        setRowCount(index + 1);
        setRowHeight(index, 35);

        QTableWidgetItem *item = new QTableWidgetItem;
        item->setText(text);
        QtItemSetTextAlignment(item, Qt::AlignCenter);
        setItem(index, 0, item);

                          item = new QTableWidgetItem;
        item->setText("-");
        setItem(index, 1, item);

                          item = new QTableWidgetItem;
        item->setText("-");
        setItem(index, 2, item);
    }
}

void WeatherAddItemTableWidget::deleteCityClicked()
{
    if(currentRow() > -1)
    {
        removeRow(currentRow());
        Q_EMIT itemCellClickedByText({});
    }
}

void WeatherAddItemTableWidget::loadingIconFinished(const QStringList &icons)
{
    const int index = currentRow();
    if(index < 0 || icons.count() < 2)
    {
        return;
    }

    item(index, 1)->setText({});
    item(index, 1)->setIcon(QIcon(":/" + icons.front().section("/", -2)));

    item(index, 2)->setText({});
    item(index, 2)->setIcon(QIcon(":/" + icons.back().section("/", -2)));
}
