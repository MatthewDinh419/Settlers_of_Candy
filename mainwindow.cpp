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
    pair <int, int> p1;
    pair <int, int> p2;
    pair <int, int> p3;
    pair <int, int> p4;
    pair <int, int> p5;
    pair <int, int> p6;
    int id = 1;
    for(int x = 0; x < 300; x += 100) //Top 3 hexagons, add 20 to y-coord to center the gameboard
    {
        p1 = std::make_pair(view->width() / 2 - 100 + x,0+20);
        p2 = std::make_pair(view->width() / 2 - 150 + x,25+20);
        p3 = std::make_pair(view->width() / 2 - 150 + x,75+20);
        p4 = std::make_pair(view->width() / 2 - 100 + x,100+20);
        p5 = std::make_pair(view->width() / 2 - 50 + x,75+20);
        p6 = std::make_pair(view->width() / 2 - 50 + x,25+20);
        Hexagon *h = new Hexagon(QColor(255,255,255), p1, p2, p3, p4, p5, p6, id);
        id += 1;
        scene->addItem(h);

    }
    for(int x = 0; x <= 300; x += 100){ //Middle 4 Hexagons, -50 to x-coord, +75 to y-coord to align hexagons correctly with top 3
        p1 = std::make_pair(view->width() / 2 - 100 + x-50,0+75+20);
        p2 = std::make_pair(view->width() / 2 - 150 + x-50,25+75+20);
        p3 = std::make_pair(view->width() / 2 - 150 + x-50,75+75+20);
        p4 = std::make_pair(view->width() / 2 - 100 + x-50,100+75+20);
        p5 = std::make_pair(view->width() / 2 - 50 + x-50,75+75+20);
        p6 = std::make_pair(view->width() / 2 - 50 + x-50,25+75+20);
        Hexagon *h = new Hexagon(QColor(255,255,255), p1, p2, p3, p4, p5, p6, id);
        id += 1;
        scene->addItem(h);

    }
    for(int x = 0; x <= 400; x += 100){ //Middle 5 Hexagons, basically decrement x-coord by 50 and increment y-coord by 75 per level of hexagons
        p1 = std::make_pair(view->width() / 2 - 100 + x-50-50,0+75+75+20);
        p2 = std::make_pair(view->width() / 2 - 150 + x-50-50,25+75+75+20);
        p3 = std::make_pair(view->width() / 2 - 150 + x-50-50,75+75+75+20);
        p4 = std::make_pair(view->width() / 2 - 100 + x-50-50,100+75+75+20);
        p5 = std::make_pair(view->width() / 2 - 50 + x-50-50,75+75+75+20);
        p6 = std::make_pair(view->width() / 2 - 50 + x-50-50,25+75+75+20);
        Hexagon *h = new Hexagon(QColor(255,255,255), p1, p2, p3, p4, p5, p6, id);
        id += 1;
        scene->addItem(h);

    }
    for(int x = 0; x <= 300; x += 100){ //Bottom 4 Hexagons, basically decrement x-coord by 50 and increment y-coord by 75 per level of hexagons
        p1 = std::make_pair(view->width() / 2 - 100 + x-50,0+75+75+75+20);
        p2 = std::make_pair(view->width() / 2 - 150 + x-50,25+75+75+75+20);
        p3 = std::make_pair(view->width() / 2 - 150 + x-50,75+75+75+75+20);
        p4 = std::make_pair(view->width() / 2 - 100 + x-50,100+75+75+75+20);
        p5 = std::make_pair(view->width() / 2 - 50 + x-50,75+75+75+75+20);
        p6 = std::make_pair(view->width() / 2 - 50 + x-50,25+75+75+75+20);
        Hexagon *h = new Hexagon(QColor(255,255,255), p1, p2, p3, p4, p5, p6, id);
        id += 1;
        scene->addItem(h);

    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
