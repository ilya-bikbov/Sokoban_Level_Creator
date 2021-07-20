#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>

#include "graphicsview.h"
#include "graphicsscene.h"
#include "graphicsitemgroup.h"
#include "graphicsitem.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = NULL);
    ~MainWindow();

    GraphicsView *view;
    GraphicsScene *scene;
    GraphicsItemGroup *item_group;
    GraphicsItem *item;
    GraphicsItem *item2;

    void draw_grid(int x_count, int y_count);

public slots:
    void draw_grid();
    void slot_level_save();

private:
    Ui::MainWindow *ui;

    void add_items();
    QList<int> get_items_types();
};
#endif // MAINWINDOW_H
