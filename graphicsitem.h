#ifndef GRAPHICSITEM_H
#define GRAPHICSITEM_H

#include <QGraphicsObject>
#include <QPainter>
#include <QObject>
#include <QDebug>
#include <QGraphicsSceneMouseEvent>


class GraphicsItem : public QGraphicsObject
{
    Q_OBJECT
public:
    GraphicsItem();
    int get_id(){return id;}
    int get_type(){return type;}
    qreal get_width(){return rect->width();}
    qreal get_height(){return rect->height();}

    void set_id(int num){id = num;}
    void set_pixmap();
protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                    QWidget *widget);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent ( QGraphicsSceneMouseEvent * event );

private:
    int id;
    int type;
    int new_type;

    qreal rect_pos_x;
    qreal rect_pos_y;
    qreal rect_width;
    qreal rect_height;
    qreal rect_pen_width;
    QRectF *rect;
    QPixmap *rect_pixmap;
    QString new_pixmap_name;
public slots:
    void slot_set_pixmap(int item_num);
};

#endif // GRAPHICSITEM_H
