#ifndef GRAPHICSSCENE_H
#define GRAPHICSSCENE_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QObject>
#include <QPainter>
#include <QDebug>
#include <QEvent>
#include <QGraphicsSceneMouseEvent>
#include <QMouseEvent>
#include <QKeyEvent>

#include "graphicsitem.h"

class GraphicsScene : public QGraphicsScene
{
    Q_OBJECT
public:
    GraphicsScene(QGraphicsView *parent = NULL);
protected:
    void drawBackground(QPainter *painter, const QRectF &exposed);
    void mouseMoveEvent ( QGraphicsSceneMouseEvent * event );
private:
    QGraphicsView *_parent_widget;

    QRectF *_rect;
};

#endif // GRAPHICSSCENE_H
