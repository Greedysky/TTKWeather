#include "weatherabstracttablewidget.h"

WeatherAbstractTableWidget::WeatherAbstractTableWidget(QWidget *parent)
    : QTableWidget(parent),
      m_previousColorRow(-1),
      m_previousClickRow(-1),
      m_defaultBkColor(255, 255, 255, 0)
{
    setAttribute(Qt::WA_TranslucentBackground, true);
    setFont(QtFontInit("Helvetica"));
    setColumnCount(3);
    setRowCount(0);
    setShowGrid(false);//Does not display the grid

    QHeaderView *headerview = horizontalHeader();
    headerview->setVisible(false);
    headerview->resizeSection(0,40);
    headerview->resizeSection(1,257);
    headerview->resizeSection(2,26);
    verticalHeader()->setVisible(false);

    setMouseTracking(true);  //Open the capture mouse function
    setStyleSheet(WeatherUIObject::MTableWidgetStyle01 + \
                  WeatherUIObject::MScrollBarStyle01);
    //Set the color of selected row
    setFrameShape(QFrame::NoFrame);//Set No Border
    setEditTriggers(QTableWidget::NoEditTriggers);//No edit
    setSelectionBehavior(QTableWidget::SelectRows);
    //Multi-line election
    setSelectionMode(QAbstractItemView::SingleSelection);
    setFocusPolicy(Qt::NoFocus);
    setTransparent(150);

    connect(this, SIGNAL(cellEntered(int,int)), SLOT(listCellEntered(int,int)));
    connect(this, SIGNAL(cellClicked(int,int)), SLOT(listCellClicked(int,int)));
}

WeatherAbstractTableWidget::~WeatherAbstractTableWidget()
{

}

void WeatherAbstractTableWidget::clear()
{
    clearContents();
    setRowCount(0);
}

void WeatherAbstractTableWidget::setTransparent(int angle)
{
    QPalette pal = palette();
    pal.setBrush(QPalette::Base, QBrush(QColor(255, 255, 255, angle)));
    setPalette(pal);
}

void WeatherAbstractTableWidget::listCellEntered(int row, int column)
{
    QTableWidgetItem *it = item(m_previousColorRow, 0);
    if(it != 0)
    {
       setRowColor(m_previousColorRow, m_defaultBkColor);
    }

    it = item(row, column);
    if(it != 0 && !it->isSelected() && !it->text().isEmpty())
    {
       setRowColor(row, QColor(20,20,20,10));
    }

    m_previousColorRow = row;
}

void WeatherAbstractTableWidget::setRowColor(int row, const QColor &color) const
{
    for(int col = 0; col < columnCount(); ++col)
    {
        QTableWidgetItem *it = item(row, col);
        QtItemSetBackgroundColor(it, color);
    }
}
