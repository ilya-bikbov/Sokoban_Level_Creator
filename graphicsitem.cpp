#include "graphicsitem.h"

GraphicsItem::GraphicsItem()
{
    rect_pos_x = 0;
    rect_pos_y = 0;
    rect_width = 100;
    rect_height = 100;
    rect_pen_width = 10;

    QPointF ptPosition(rect_pos_x - rect_pen_width, rect_pos_y - rect_pen_width);
    QSizeF size(rect_width + rect_pen_width * 2, rect_height + rect_pen_width * 2);

    rect_pixmap = new QPixmap(":/sprites/ground.png");
    type = 1;

    new_pixmap_name = ":/sprites/player.png";

    rect = new QRectF(ptPosition, size);
}

void GraphicsItem::set_pixmap()
{
    rect_pixmap->load(new_pixmap_name);
    type = new_type;
    this->update();
}

QRectF GraphicsItem::boundingRect() const
{
    return QRectF(*rect);
}

void GraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(Qt::black, rect_pen_width));
    painter->setBrush(QColor(255,0,0,255));
    painter->drawRect(*rect);
    //painter->drawPixmap(*rect, *rect_pixmap, *rect);
    //painter->drawPixmap(rect->x()+rect_pen_width, rect->y()+rect_pen_width, rect->width()-rect_pen_width, rect->height()-rect_pen_width, *rect_pixmap);
    painter->drawPixmap(rect->x(), rect->y(), rect->width(), rect->height(), *rect_pixmap);

}

void GraphicsItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << id;
    if(event->button() == Qt::LeftButton && event->modifiers() != Qt::KeypadModifier)
    {
        rect_pixmap->load(new_pixmap_name);
        type = new_type;
        this->update();
    }
    else
    {
        QGraphicsItem::mousePressEvent(event);
    }

}

void GraphicsItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mouseMoveEvent(event);
}

void GraphicsItem::slot_set_pixmap(int item_num)
{
    switch(item_num)
    {
    case 0:
        new_pixmap_name = ":/sprites/player.png";
        break;
    case 1:
        new_pixmap_name = ":/sprites/ground.png";
        break;
    case 2:
        new_pixmap_name = ":/sprites/wall_brick.png";
        break;
    case 3:
        new_pixmap_name = ":/sprites/box.png";
        break;
    case 4:
        new_pixmap_name = ":/sprites/target.png";
        break;
    case 5:
        new_pixmap_name = ":/sprites/box_target.png";
        break;
    case 6:
        new_pixmap_name = ":/sprites/player_target.png";
        break;
    default:
        ;
    }
    new_type = item_num;
}
