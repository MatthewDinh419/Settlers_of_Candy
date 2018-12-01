#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QColor>
#include <QDebug>
#include <vector>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    new_game = new Game();
    new_game->set_place_mode(false);
    srand (time(NULL));
    ui->setupUi(this);
    QFont font = ui->status_label->font();
    font.setBold(true);
    ui->status_label->setFont(font);
    ui->status_label->setText(QString("Start of Player 1's turn..."));
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
    int rand_resource_num;
    resource rand_resource;
    QColor resource_color;
    for(int x = 0; x < 300; x += 100) //Top 3 hexagons, add 20 to y-coord to center the gameboard
    {
        p1 = std::make_pair(view->width() / 2 - 100 + x,0+20);
        p2 = std::make_pair(view->width() / 2 - 150 + x,25+20);
        p3 = std::make_pair(view->width() / 2 - 150 + x,75+20);
        p4 = std::make_pair(view->width() / 2 - 100 + x,100+20);
        p5 = std::make_pair(view->width() / 2 - 50 + x,75+20);
        p6 = std::make_pair(view->width() / 2 - 50 + x,25+20);
        rand_resource_num = rand() % 3 + 0;
        switch(rand_resource_num){
            case 0:
                rand_resource = resource::money;
                resource_color = QColor(0,236,46);
                break;
            case 1:
                rand_resource = resource::sugar;
                resource_color = QColor(241,237,237);
                break;
            case 2:
                rand_resource = resource::water;
                resource_color = QColor(0,212,255);
                break;
        }
        Hexagon *h = new Hexagon(resource_color, p1, p2, p3, p4, p5, p6, id,rand_resource);
        id += 1;
        scene->addItem(h);
        new_game->AddCorner(p1);
        new_game->AddCorner(p2);
        new_game->AddCorner(p3);
        new_game->AddCorner(p4);
        new_game->AddCorner(p5);
        new_game->AddCorner(p6);
        connect(h, &Hexagon::AddBuilding, this, &MainWindow::AddBuildingSlot);
    }
    for(int x = 0; x <= 300; x += 100){ //Middle 4 Hexagons, -50 to x-coord, +75 to y-coord to align hexagons correctly with top 3
        p1 = std::make_pair(view->width() / 2 - 100 + x-50,0+75+20);
        p2 = std::make_pair(view->width() / 2 - 150 + x-50,25+75+20);
        p3 = std::make_pair(view->width() / 2 - 150 + x-50,75+75+20);
        p4 = std::make_pair(view->width() / 2 - 100 + x-50,100+75+20);
        p5 = std::make_pair(view->width() / 2 - 50 + x-50,75+75+20);
        p6 = std::make_pair(view->width() / 2 - 50 + x-50,25+75+20);
        rand_resource_num = rand() % 3 + 0;
        switch(rand_resource_num){
            case 0:
                rand_resource = resource::money;
                resource_color = QColor(0,236,46);
                break;
            case 1:
                rand_resource = resource::sugar;
                resource_color = QColor(241,237,237);
                break;
            case 2:
                rand_resource = resource::water;
                resource_color = QColor(0,212,255);
                break;
        }
        Hexagon *h = new Hexagon(resource_color, p1, p2, p3, p4, p5, p6, id, rand_resource);
        id += 1;
        scene->addItem(h);
        new_game->AddCorner(p1);
        new_game->AddCorner(p2);
        new_game->AddCorner(p3);
        new_game->AddCorner(p4);
        new_game->AddCorner(p5);
        new_game->AddCorner(p6);
        connect(h, &Hexagon::AddBuilding, this, &MainWindow::AddBuildingSlot);
    }
    for(int x = 0; x <= 400; x += 100){ //Middle 5 Hexagons, basically decrement x-coord by 50 and increment y-coord by 75 per level of hexagons
        p1 = std::make_pair(view->width() / 2 - 100 + x-50-50,0+75+75+20);
        p2 = std::make_pair(view->width() / 2 - 150 + x-50-50,25+75+75+20);
        p3 = std::make_pair(view->width() / 2 - 150 + x-50-50,75+75+75+20);
        p4 = std::make_pair(view->width() / 2 - 100 + x-50-50,100+75+75+20);
        p5 = std::make_pair(view->width() / 2 - 50 + x-50-50,75+75+75+20);
        p6 = std::make_pair(view->width() / 2 - 50 + x-50-50,25+75+75+20);
        rand_resource_num = rand() % 3 + 0;
        switch(rand_resource_num){
            case 0:
                rand_resource = resource::money;
                resource_color = QColor(0,236,46);
                break;
            case 1:
                rand_resource = resource::sugar;
                resource_color = QColor(241,237,237);
                break;
            case 2:
                rand_resource = resource::water;
                resource_color = QColor(0,212,255);
                break;
        }
        Hexagon *h = new Hexagon(resource_color, p1, p2, p3, p4, p5, p6, id, rand_resource);
        id += 1;
        scene->addItem(h);
        new_game->AddCorner(p1);
        new_game->AddCorner(p2);
        new_game->AddCorner(p3);
        new_game->AddCorner(p4);
        new_game->AddCorner(p5);
        new_game->AddCorner(p6);
        connect(h, &Hexagon::AddBuilding, this, &MainWindow::AddBuildingSlot);
    }
    for(int x = 0; x <= 300; x += 100){ //Bottom 4 Hexagons, basically decrement x-coord by 50 and increment y-coord by 75 per level of hexagons
        p1 = std::make_pair(view->width() / 2 - 100 + x-50,0+75+75+75+20);
        p2 = std::make_pair(view->width() / 2 - 150 + x-50,25+75+75+75+20);
        p3 = std::make_pair(view->width() / 2 - 150 + x-50,75+75+75+75+20);
        p4 = std::make_pair(view->width() / 2 - 100 + x-50,100+75+75+75+20);
        p5 = std::make_pair(view->width() / 2 - 50 + x-50,75+75+75+75+20);
        p6 = std::make_pair(view->width() / 2 - 50 + x-50,25+75+75+75+20);
        rand_resource_num = rand() % 3 + 0;
        switch(rand_resource_num){
            case 0:
                rand_resource = resource::money;
                resource_color = QColor(0,236,46);
                break;
            case 1:
                rand_resource = resource::sugar;
                resource_color = QColor(241,237,237);
                break;
            case 2:
                rand_resource = resource::water;
                resource_color = QColor(0,212,255);
                break;
        }
        Hexagon *h = new Hexagon(resource_color, p1, p2, p3, p4, p5, p6, id, rand_resource);
        id += 1;
        scene->addItem(h);
        new_game->AddCorner(p1);
        new_game->AddCorner(p2);
        new_game->AddCorner(p3);
        new_game->AddCorner(p4);
        new_game->AddCorner(p5);
        new_game->AddCorner(p6);
        connect(h, &Hexagon::AddBuilding, this, &MainWindow::AddBuildingSlot);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_houseButton_clicked()
{
    QFont font = ui->status_label->font();
    font.setBold(true);
    ui->status_label->setFont(font);
    ui->status_label->setText(QString("Pick a hexagon corner to place chocolate house"));
    Game::set_place_mode(!Game::get_place_mode());
    if(Game::get_place_mode()){
        Game::set_building_string("choco house");
        ui->centralWidget->setCursor(Qt::CrossCursor);
    }
    else{
        ui->centralWidget->setCursor(Qt::ArrowCursor);
    }
}

void MainWindow::on_roadButton_clicked()
{
    QFont font = ui->status_label->font();
    font.setBold(true);
    ui->status_label->setFont(font);
    ui->status_label->setText(QString("Pick a hexagon side to place candy road"));
}

void MainWindow::on_mansionButton_clicked()
{
    QFont font = ui->status_label->font();
    font.setBold(true);
    ui->status_label->setFont(font);
    ui->status_label->setText(QString("Pick a hexagon corner to place chocolate mansion"));
    Game::set_place_mode(!Game::get_place_mode());
    if(Game::get_place_mode()){
        Game::set_building_string("choco mansion");
        ui->centralWidget->setCursor(Qt::CrossCursor);
    }
    else{
        ui->centralWidget->setCursor(Qt::ArrowCursor);
    }
}

void MainWindow::AddBuildingSlot(Building *building_to_add)
{
    scene->addItem(building_to_add);
}
