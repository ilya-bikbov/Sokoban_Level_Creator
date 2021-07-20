#include "graphicsview.h"

GraphicsView::GraphicsView(QWidget *parent)
{
    this->setParent(parent);

    timer_zooming = new QTimer();
    timer_zooming->setInterval(150);

    is_zooming = false;
}

void GraphicsView::slot_zoom_in()
{
    is_zooming = true;
    connect(timer_zooming, SIGNAL(timeout()), this, SLOT(zoom_in()),Qt::DirectConnection);
    timer_zooming->start();

    scale(1.1, 1.1);
}
void GraphicsView::zoom_in()
{
    scale(1.1, 1.1);
}

void GraphicsView::slot_zoom_out()
{
    is_zooming = true;
    connect(timer_zooming, SIGNAL(timeout()), this, SLOT(zoom_out()),Qt::DirectConnection);
    timer_zooming->start();

    scale(1 / 1.1, 1 / 1.1);
}
void GraphicsView::zoom_out()
{
    scale(1 / 1.1, 1 / 1.1);
}

void GraphicsView::slot_zoom_stop()
{
    is_zooming = false;
    timer_zooming->stop();
    disconnect(timer_zooming, 0, 0, 0);
}

void GraphicsView::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::RightButton)
    {
        setDragMode(QGraphicsView::ScrollHandDrag);

        QMouseEvent* pressEvent = new QMouseEvent(QEvent::GraphicsSceneMousePress,
                                            event->pos(), Qt::LeftButton,
                                            Qt::LeftButton, Qt::KeypadModifier);

        this->mousePressEvent(pressEvent);
    }
    else
    {
        QGraphicsView::mousePressEvent(event);
    }
}

void GraphicsView::mouseReleaseEvent(QMouseEvent *event)
{
    setDragMode(QGraphicsView::NoDrag);

    QGraphicsView::mouseReleaseEvent(event);
}

void GraphicsView::wheelEvent(QWheelEvent *event)
{
    if (event->modifiers() & Qt::ControlModifier)
    {
        const ViewportAnchor anchor = transformationAnchor();
        setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
        int angle = event->delta();
        qreal factor;
        if (angle > 0) {
            factor = 1.1;
        } else {
            factor = 1 / 1.1;
        }
        scale(factor, factor);
        setTransformationAnchor(anchor);
    }
    else
    {
        QGraphicsView::wheelEvent(event);
    }
}
