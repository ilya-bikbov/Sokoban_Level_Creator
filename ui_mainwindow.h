/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDockWidget>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMdiArea>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>
#include "graphicsview.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QMdiArea *mdiArea;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    GraphicsView *graphicsView;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents;
    QGridLayout *gridLayout;
    QPushButton *btn_zoom_in;
    QSpacerItem *verticalSpacer;
    QListWidget *lW_items;
    QFrame *line_3;
    QSpinBox *spnB_matrix_y;
    QSpinBox *spnB_matrix_x;
    QPushButton *btn_zoom_out;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QFrame *line;
    QFrame *line_2;
    QPushButton *btn_level_save;
    QPushButton *pushButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1037, 695);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        mdiArea = new QMdiArea(centralwidget);
        mdiArea->setObjectName(QString::fromUtf8("mdiArea"));
        mdiArea->setGeometry(QRect(6, 6, 618, 605));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(670, 190, 288, 204));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        graphicsView = new GraphicsView(widget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        horizontalLayout->addWidget(graphicsView);

        MainWindow->setCentralWidget(centralwidget);
        dockWidget = new QDockWidget(MainWindow);
        dockWidget->setObjectName(QString::fromUtf8("dockWidget"));
        dockWidget->setFeatures(QDockWidget::DockWidgetFloatable|QDockWidget::DockWidgetMovable);
        dockWidget->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        gridLayout = new QGridLayout(dockWidgetContents);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetMaximumSize);
        btn_zoom_in = new QPushButton(dockWidgetContents);
        btn_zoom_in->setObjectName(QString::fromUtf8("btn_zoom_in"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btn_zoom_in->sizePolicy().hasHeightForWidth());
        btn_zoom_in->setSizePolicy(sizePolicy);

        gridLayout->addWidget(btn_zoom_in, 0, 3, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 7, 1, 1, 1);

        lW_items = new QListWidget(dockWidgetContents);
        lW_items->setObjectName(QString::fromUtf8("lW_items"));

        gridLayout->addWidget(lW_items, 4, 0, 1, 4);

        line_3 = new QFrame(dockWidgetContents);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_3, 5, 0, 1, 4);

        spnB_matrix_y = new QSpinBox(dockWidgetContents);
        spnB_matrix_y->setObjectName(QString::fromUtf8("spnB_matrix_y"));
        spnB_matrix_y->setMinimum(1);
        spnB_matrix_y->setMaximum(999999999);
        spnB_matrix_y->setValue(5);

        gridLayout->addWidget(spnB_matrix_y, 2, 3, 1, 1);

        spnB_matrix_x = new QSpinBox(dockWidgetContents);
        spnB_matrix_x->setObjectName(QString::fromUtf8("spnB_matrix_x"));
        spnB_matrix_x->setMinimum(1);
        spnB_matrix_x->setMaximum(999999999);
        spnB_matrix_x->setValue(5);

        gridLayout->addWidget(spnB_matrix_x, 2, 1, 1, 1);

        btn_zoom_out = new QPushButton(dockWidgetContents);
        btn_zoom_out->setObjectName(QString::fromUtf8("btn_zoom_out"));
        sizePolicy.setHeightForWidth(btn_zoom_out->sizePolicy().hasHeightForWidth());
        btn_zoom_out->setSizePolicy(sizePolicy);

        gridLayout->addWidget(btn_zoom_out, 0, 1, 1, 1);

        label = new QLabel(dockWidgetContents);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(dockWidgetContents);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        label_3 = new QLabel(dockWidgetContents);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 2, 1, 1);

        line = new QFrame(dockWidgetContents);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 1, 0, 1, 4);

        line_2 = new QFrame(dockWidgetContents);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_2, 3, 0, 1, 4);

        btn_level_save = new QPushButton(dockWidgetContents);
        btn_level_save->setObjectName(QString::fromUtf8("btn_level_save"));

        gridLayout->addWidget(btn_level_save, 6, 3, 1, 1);

        pushButton = new QPushButton(dockWidgetContents);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 6, 1, 1, 1);

        dockWidget->setWidget(dockWidgetContents);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), dockWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "SOKOBAN LEVEL DESIGNER", 0, QApplication::UnicodeUTF8));
        dockWidget->setWindowTitle(QApplication::translate("MainWindow", "DO THINGS                      vvv", 0, QApplication::UnicodeUTF8));
        btn_zoom_in->setText(QApplication::translate("MainWindow", "+", 0, QApplication::UnicodeUTF8));
        btn_zoom_out->setText(QApplication::translate("MainWindow", "-", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Zoom:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Matrix size:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "x", 0, QApplication::UnicodeUTF8));
        btn_level_save->setText(QApplication::translate("MainWindow", "Save >", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "Load <", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
