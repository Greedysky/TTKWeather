#include "weatherabstracttablewidget.h"

WeatherAbstractTableWidget::WeatherAbstractTableWidget(QWidget *parent)
    : QTableWidget(parent),
      m_previousColorRow(-1),
      m_previousClickRow(-1),
      m_backgroundColor(255, 255, 255, 0)
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
    setStyleSheet(WeatherUIObject::MTableWidgetStyle01 + WeatherUIObject::MScrollBarStyle01);
    //Set the color of selected row
    setFrameShape(QFrame::NoFrame);//Set No Border
    setEditTriggers(QAbstractItemView::NoEditTriggers);//No edit
    setSelectionBehavior(QAbstractItemView::SelectRows);
    //Multi-line election
    setSelectionMode(QAbstractItemView::SingleSelection);
    setFocusPolicy(Qt::NoFocus);

    QPalette plt = palette();
    plt.setBrush(QPalette::Base, QBrush(QColor(255, 255, 255, 150)));
#if defined Q_OS_UNIX && !TTK_QT_VERSION_CHECK(5,7,0) //Fix linux selection-background-color stylesheet bug
    plt.setBrush(QPalette::Highlight, QColor(20, 20, 20, 20));
#endif
    setPalette(plt);

    connect(this, SIGNAL(cellEntered(int,int)), SLOT(itemCellEntered(int,int)));
    connect(this, SIGNAL(cellClicked(int,int)), SLOT(itemCellClicked(int,int)));
}

WeatherAbstractTableWidget::~WeatherAbstractTableWidget()
{

}

void WeatherAbstractTableWidget::itemCellEntered(int row, int column)
{
    if(item(m_previousColorRow, 0))
    {
       setRowColor(m_previousColorRow, m_backgroundColor);
    }

    if(item(row, column))
    {
       setRowColor(row, QColor(20, 20, 20, 20));
    }

    m_previousColorRow = row;
}

void WeatherAbstractTableWidget::itemCellClicked(int row, int column)
{
    Q_UNUSED(row);
    Q_UNUSED(column);
}

void WeatherAbstractTableWidget::removeItems()
{
    clearContents();
    setRowCount(0);

    m_previousColorRow = -1;
    m_previousClickRow = -1;
    m_backgroundColor = Qt::transparent;
}

void WeatherAbstractTableWidget::setRowColor(int row, const QColor &color) const
{
    for(int i = 0; i < columnCount(); ++i)
    {
        QTableWidgetItem *it = item(row, i);
        if(it)
        {
            QtItemSetBackgroundColor(it, color);
        }
    }
}
