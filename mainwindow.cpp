#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include "building.h"
#include "hexagon.h"
#include <vector>
#include <QColor>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene;
    QGraphicsView * view = ui->graphicsView;
    view->setScene(scene);
    view->setSceneRect(0,0,view->frameSize().width(),view->frameSize().height());
    std::vector<resource> candy_required_resources;
    candy_required_resources.push_back(resource::money);
    candy_required_resources.push_back(resource::sugar);
    candy_required_resources.push_back(resource::water);
    Building *candy = new Building(candy_required_resources,1,25,25,QColor(255,255,255));
    scene->addItem(candy);
}

MainWindow::~MainWindow()
{
    delete ui;
}
