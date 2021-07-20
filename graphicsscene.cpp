#include "graphicsscene.h"

GraphicsScene::GraphicsScene(QGraphicsView *parent)
{
    _parent_widget = parent;


    _rect = new QRectF(sceneRect());
}

void GraphicsScene::drawBackground(QPainter *painter, const QRectF &exposed)
{
    painter->setPen(QPen(Qt::black, 3));
    painter->setBrush(QColor("grey"));


    painter->drawRect(QRectF(_parent_widget->x() - 8000, _parent_widget->y()-8000, _parent_widget->width() + 16000, _parent_widget->height() + 16000));


    _rect->setTopLeft(QPointF(_parent_widget->x() - 8000, _parent_widget->y()-8000));
    _rect->setSize(QSizeF(_parent_widget->width() + 16000, _parent_widget->height() + 16000));


    setSceneRect(*_rect);

}

void GraphicsScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->buttons() == 0x1)
    {
        QPointF mousePosition = event->scenePos();
        GraphicsItem* pItem =  static_cast<GraphicsItem*>(itemAt(mousePosition.x(), mousePosition.y()));
        if (pItem)
            pItem->set_pixmap();
   }
   QGraphicsScene::mouseMoveEvent(event);
}

