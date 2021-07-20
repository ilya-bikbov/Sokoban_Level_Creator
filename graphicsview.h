#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H

#include <QGraphicsView>
#include <QWidget>
#include <QTimer>
#include <QKeyEvent>
#include <QWheelEvent>
#include <QDebug>
class GraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    GraphicsView(QWidget *parent = NULL);
protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *event);
private:
    bool is_zooming;
    QTimer *timer_zooming;

public slots:
    void slot_zoom_in();
    void slot_zoom_out();
    void slot_zoom_stop();

    void zoom_in();
    void zoom_out();
};

#endif // GRAPHICSVIEW_H
