#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "hexagon.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QColor>
#include <QDebug>
#include <utility>
using namespace std;
#include "building.h"
#include <vector>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene;
    QGraphicsView * view = ui->gameBoard;
    view->setScene(scene);
    view->setSceneRect(0,0,view->frameSize().width(),view->frameSize().height());
    pair <int, int> p1 (50, 0);
    pair <int, int> p2 (0, 50);
    pair <int, int> p3 (0, 100);
    pair <int, int> p4 (50, 150);
    pair <int, int> p5 (100, 100);
    pair <int, int> p6 (100, 50);
    Hexagon *h = new Hexagon(QColor(255,255,255), p1, p2, p3, p4, p5, p6, 1);
    scene->addItem(h);
    
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
