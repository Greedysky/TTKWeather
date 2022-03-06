#include "weatherabstractmovewidget.h"

WeatherAbstractMoveWidget::WeatherAbstractMoveWidget(QWidget *parent)
    : QWidget(parent)
{
    setWindowFlags( Qt::Window | Qt::FramelessWindowHint );
    m_leftButtonPress = false;
}

WeatherAbstractMoveWidget::~WeatherAbstractMoveWidget()
{

}

void WeatherAbstractMoveWidget::mousePressEvent(QMouseEvent *event)
{
    QWidget::mousePressEvent(event);
    if( event->button() == Qt::LeftButton )///Press the left key
    {
        m_leftButtonPress = true;
    }
#if TTK_QT_VERSION_CHECK(6,0,0)
    m_pressAt = event->globalPosition().toPoint();
#else
    m_pressAt = event->globalPos();
#endif
}

void WeatherAbstractMoveWidget::mouseMoveEvent(QMouseEvent *event)
{
    QWidget::mouseMoveEvent(event);
    if( !m_leftButtonPress )///Not press the left key
    {
        event->ignore();
        return;
    }
#if TTK_QT_VERSION_CHECK(6,0,0)
    const QPoint &globalPos = event->globalPosition().toPoint();
    const int xpos = globalPos.x() - m_pressAt.x();
    const int ypos = globalPos.y() - m_pressAt.y();
    m_pressAt = globalPos;
#else
    const int xpos = event->globalX() - m_pressAt.x();
    const int ypos = event->globalY() - m_pressAt.y();
    m_pressAt = event->globalPos();
#endif
    move( this->x()+xpos, this->y()+ypos);
}

void WeatherAbstractMoveWidget::mouseReleaseEvent(QMouseEvent *event)
{
    QWidget::mouseReleaseEvent(event);
#if TTK_QT_VERSION_CHECK(6,0,0)
    m_pressAt = event->globalPosition().toPoint();
#else
    m_pressAt = event->globalPos();
#endif
    m_leftButtonPress = false;
}
