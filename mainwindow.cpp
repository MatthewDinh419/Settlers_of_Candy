#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "hexagon.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QColor>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene;
    QGraphicsView * view = ui->graphicsView;
    view->setScene(scene);
    view->setSceneRect(0,0,view->frameSize().width(),view->frameSize().height());
    Hexagon *h = new Hexagon(QColor(255,255,255), 10, 10, 1);
    scene->addItem(h);
}

MainWindow::~MainWindow()
{
    delete ui;
}
