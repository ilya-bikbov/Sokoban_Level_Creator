#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    add_items();

    view = ui->graphicsView;

    ui->widget->setParent(ui->mdiArea);
    setCentralWidget(ui->mdiArea);
    ui->mdiArea->addSubWindow(ui->widget);
    ui->mdiArea->setTabsClosable(false);

    //ui->graphicsView->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    scene = new GraphicsScene(ui->graphicsView);
    ui->graphicsView->setScene(scene);

    item_group = new GraphicsItemGroup();


    draw_grid(ui->spnB_matrix_x->value(), ui->spnB_matrix_y->value());

    connect(ui->btn_zoom_in, SIGNAL(pressed()), view, SLOT(slot_zoom_in()));
    connect(ui->btn_zoom_out, SIGNAL(pressed()), view, SLOT(slot_zoom_out()));
    connect(ui->btn_zoom_in, SIGNAL(released()), view, SLOT(slot_zoom_stop()),Qt::DirectConnection);
    connect(ui->btn_zoom_out, SIGNAL(released()), view, SLOT(slot_zoom_stop()),Qt::DirectConnection);

    connect(ui->spnB_matrix_x, SIGNAL(valueChanged(int)), this, SLOT(draw_grid()));
    connect(ui->spnB_matrix_y, SIGNAL(valueChanged(int)), this, SLOT(draw_grid()));

    for (int x = 0; x < scene->items().count(); ++x)
    {
        GraphicsItem *test = static_cast<GraphicsItem*>(scene->items(Qt::AscendingOrder).at(x));
        qDebug() << test->get_id();
    }

    connect(ui->btn_level_save, SIGNAL(clicked()), this, SLOT(slot_level_save()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::draw_grid(int x_count, int y_count)
{
    scene->clear();
    int id = 0;
    qreal rect_pos_x_tmp = 0;
    qreal rect_pos_y_tmp = 0;
    qreal rect_width_tmp = GraphicsItem().get_width();
    qreal rect_height_tmp = GraphicsItem().get_height();
    for (int y = 0; y < y_count; ++y, rect_pos_y_tmp+=rect_height_tmp, rect_pos_x_tmp=0)
    {
        for (int x = 0; x < x_count; ++x, rect_pos_x_tmp+=rect_width_tmp)
        {
            GraphicsItem *new_item = new GraphicsItem();
            scene->addItem(new_item);
            new_item->setPos(rect_pos_x_tmp, rect_pos_y_tmp);
            new_item->set_id(id++);

            connect(ui->lW_items, SIGNAL(currentRowChanged(int)), new_item, SLOT(slot_set_pixmap(int)));
        }
    }
}

void MainWindow::draw_grid()
{
    draw_grid(ui->spnB_matrix_x->value(), ui->spnB_matrix_y->value());
}

void MainWindow::slot_level_save()
{
    QString fileName = QFileDialog::getSaveFileName(this,
             tr("Save Address Book"), "",
             tr("Sokoban level (*.skb);;All Files (*)"));
    if (fileName.isEmpty())
    {
        return;
    }
    else
    {
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly))
        {
            QMessageBox::information(this, tr("Unable to open file"),
                file.errorString());
            return;
        }
        QList<int> items_types = get_items_types();
        QTextStream out(&file);
        for(int i = 0; i < items_types.count(); ++i)
        {
            if (items_types.at(i) == -1)
            {
                out << "\n";
                continue;
            }
            out << items_types.at(i);
        }
        file.close();
    }
}

void MainWindow::add_items()
{
    ui->lW_items->addItem(new QListWidgetItem(QIcon(":/sprites/player.png"), QString("Player " + QString::number(ui->lW_items->count()))));
    ui->lW_items->addItem(new QListWidgetItem(QIcon(":/sprites/ground.png"), QString("Ground "+ QString::number(ui->lW_items->count()))));
    ui->lW_items->addItem(new QListWidgetItem(QIcon(":/sprites/wall_brick.png"), QString("Wall "+ QString::number(ui->lW_items->count()))));
    ui->lW_items->addItem(new QListWidgetItem(QIcon(":/sprites/box.png"), QString("Box "+ QString::number(ui->lW_items->count()))));
    ui->lW_items->addItem(new QListWidgetItem(QIcon(":/sprites/target.png"), QString("Target ")+ QString::number(ui->lW_items->count())));
    ui->lW_items->addItem(new QListWidgetItem(QIcon(":/sprites/box_target.png"), QString("Box_Target "+ QString::number(ui->lW_items->count()))));
    ui->lW_items->addItem(new QListWidgetItem(QIcon(":/sprites/player_target.png"), QString("Player_Target "+ QString::number(ui->lW_items->count()))));
    ui->lW_items->setIconSize(QSize(50,50));
    ui->lW_items->setCurrentRow(0);
}

QList<int> MainWindow::get_items_types()
{
/*
 *  -1 -- new line
 */
    QList<int> items_types;
    QList<GraphicsItem*> items;
    for (int x = 0; x < scene->items().count(); ++x)
    {
        GraphicsItem *test = static_cast<GraphicsItem*>(scene->items(Qt::AscendingOrder).at(x));
        items.append(test);

    }
    int x_count = ui->spnB_matrix_x->value() + 2; //
    int y_count = ui->spnB_matrix_y->value() + 2; // +2 -- empty field around level

    for (int y = 0; y < y_count; ++y)
    {
        for (int x = 0; x < x_count; ++x)
        {
            if (x == 0 || x == (x_count-1) || y == 0 || y == (y_count-1))
            {
                items_types.append(1);
                continue;
            }
            items_types.append(items.takeFirst()->get_type());
        }
        items_types.append(-1);
    }
    qDebug() << items_types;
    return items_types;
}

