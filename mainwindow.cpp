#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QColor>
#include <QDebug>
#include <vector>
#include <iostream>
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
    scene_dice = new QGraphicsScene;
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
        rand_resource_num = rand() % 3 + 0; //Generate a random number for what resource
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
    new_game->get_current_player()->AddResource(resource::money);
    new_game->get_current_player()->AddResource(resource::money);
    new_game->get_current_player()->AddResource(resource::sugar);
    new_game->get_current_player()->AddResource(resource::sugar);
    new_game->get_current_player()->AddResource(resource::water);
    new_game->get_current_player()->AddResource(resource::water);
    UpdateResources();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_houseButton_clicked()
{
    Game::set_place_mode(!Game::get_place_mode()); //If in delete mode and trying to change to not delete mode
    if(!Game::get_place_mode()){
        ui->centralWidget->setCursor(Qt::ArrowCursor); //Reset to arrow cursor
    }
    else{
        ChocolateHouse temp_house(QColor(0,0,0),0,0);
        std::vector<resource> needed_resources = temp_house.get_needed_resources(); //Gets the required resources
        if(!new_game->get_current_player()->get_current_resources().empty()){
            for(resource current_resources : new_game->get_current_player()->get_current_resources()){
                //Tries to find the required resource from players resource and then delete it from players resource
                if(std::find(needed_resources.begin(),needed_resources.end(),current_resources)!=needed_resources.end()){
                    auto iter = std::find(needed_resources.begin(),needed_resources.end(),current_resources);
                    needed_resources.erase(iter);
                    new_game->get_current_player()->RemoveResource(current_resources);
                }
            }
        }
        QFont font = ui->status_label->font();
        font.setBold(true);
        ui->status_label->setFont(font);
        if(needed_resources.empty() && Game::get_place_mode()){
            ui->status_label->setText(QString("Pick a hexagon corner to place chocolate house"));
            Game::set_building_string("choco house");
            ui->centralWidget->setCursor(Qt::CrossCursor);
        }
        else{
            ui->status_label->setText(QString("Not enough resources!"));
        }
    }
}

void MainWindow::on_roadButton_clicked()
{
    Game::set_place_mode(!Game::get_place_mode()); //If in delete mode and trying to change to not delete mode
    if(!Game::get_place_mode()){
        ui->centralWidget->setCursor(Qt::ArrowCursor); //Reset to arrow cursor
    }
    else{
        Road temp_road(QColor(0,0,0),0,0,0,0);
        std::vector<resource> needed_resources = temp_road.get_needed_resources(); //Gets the required resources for building
        if(!new_game->get_current_player()->get_current_resources().empty()){
            for(resource current_resources : new_game->get_current_player()->get_current_resources()){
                //Tries to find the required resource from players resource and then delete it from players resource
                if(std::find(needed_resources.begin(),needed_resources.end(),current_resources)!=needed_resources.end()){
                    auto iter = std::find(needed_resources.begin(),needed_resources.end(),current_resources);
                    needed_resources.erase(iter);
                    new_game->get_current_player()->RemoveResource(current_resources);
                }
            }
        }
        QFont font = ui->status_label->font();
        font.setBold(true);
        ui->status_label->setFont(font);
        if(needed_resources.empty() && Game::get_place_mode()){
            ui->status_label->setText(QString("Pick two adjacent hexagon corners to place road"));
            Game::set_building_string("candy road");
            ui->centralWidget->setCursor(Qt::CrossCursor);
        }
        else{
            ui->status_label->setText(QString("Not enough resources!"));
        }
    }
}

void MainWindow::on_mansionButton_clicked()
{
    Game::set_place_mode(!Game::get_place_mode());
    if(!Game::get_place_mode()){
        ui->centralWidget->setCursor(Qt::ArrowCursor);
    }
    else{
        ChocolateMansion temp_mansion(QColor(0,0,0),0,0);
        std::vector<resource> needed_resources = temp_mansion.get_needed_resources();
        if(!new_game->get_current_player()->get_current_resources().empty()){
            for(resource current_resources : new_game->get_current_player()->get_current_resources()){
                if(std::find(needed_resources.begin(),needed_resources.end(),current_resources)!=needed_resources.end()){
                    auto iter = std::find(needed_resources.begin(),needed_resources.end(),current_resources);
                    needed_resources.erase(iter);
                    new_game->get_current_player()->RemoveResource(current_resources);
                }
            }
        }
        QFont font = ui->status_label->font();
        font.setBold(true);
        ui->status_label->setFont(font);
        if(needed_resources.empty() && Game::get_place_mode()){
            ui->status_label->setText(QString("Pick a hexagon corner to place chocolate mansion"));
            Game::set_building_string("choco mansion");
            ui->centralWidget->setCursor(Qt::CrossCursor);
        }
        else{
            ui->status_label->setText(QString("Not enough resources!"));
        }
    }
}
void MainWindow::AddBuildingSlot(Building *building_to_add)
{
    Game::set_place_mode(false);
    ui->centralWidget->setCursor(Qt::ArrowCursor);
    UpdateResources();
    scene->addItem(building_to_add);
    scene->update();
}

void MainWindow::UpdateResources()
{
    qDebug() << "test";
    std::map<resource,int> resource_quantity;
    for(Player *player : new_game->get_player_list()){
        if(player->get_current_resources().empty()){
            resource_quantity[resource::money] = 0;
            resource_quantity[resource::sugar] = 0;
            resource_quantity[resource::water] = 0;
        }
        for(resource current_resource : player->get_current_resources()){
            resource_quantity[current_resource] = resource_quantity[current_resource] + 1;
        }
        if(player->get_id() == 1){
            ui->p1Money->setText(QString::number(resource_quantity[resource::money]));
            ui->p1Sugar->setText(QString::number(resource_quantity[resource::sugar]));
            ui->p1Water->setText(QString::number(resource_quantity[resource::water]));
        }
        else if(player->get_id() == 2){
            ui->p2Money->setText(QString::number(resource_quantity[resource::money]));
            ui->p2Sugar->setText(QString::number(resource_quantity[resource::sugar]));
            ui->p2Water->setText(QString::number(resource_quantity[resource::water]));
        }
        else if(player->get_id() == 3){
            ui->p3Money->setText(QString::number(resource_quantity[resource::money]));
            ui->p3Sugar->setText(QString::number(resource_quantity[resource::sugar]));
            ui->p3Water->setText(QString::number(resource_quantity[resource::water]));
        }
    }
}

void MainWindow::on_diceButton_clicked()
{
    scene_dice->clear();
    QGraphicsView * view_dice = ui->diceView;
    view_dice->setScene(scene_dice);
    view_dice->setSceneRect(0,0,view_dice->frameSize().width(),view_dice->frameSize().height());
    std::vector<QGraphicsEllipseItem*> all_dots;
    int dice_roll_1 = rand() % 6 + 1;
    int dice_roll_2 = rand() % 6 + 1;
    QGraphicsEllipseItem *dot_one;
    switch(dice_roll_1){
        /* Getting the dots in the correct position
         * width / 4 + 5 and height / 4 - 5 will get the dot to the center of the dice view
         * Adjusting the width will get the position of the dots for dice rolls 1-3
         * Adjusting the appropriate width and height will get the positions for dice rolls 4-6
         */
        case 1:
            dot_one = new QGraphicsEllipseItem(view_dice->width()/4-5,view_dice->height()/4+5,5,5);
            all_dots.push_back(dot_one);
            break;
        case 2:
            dot_one = new QGraphicsEllipseItem(view_dice->width()/4,view_dice->height()/4+5,5,5);
            all_dots.push_back(dot_one);
            dot_one = new QGraphicsEllipseItem(view_dice->width()/4-10,view_dice->height()/4+5,5,5);
            all_dots.push_back(dot_one);
            break;
        case 3:
            dot_one = new QGraphicsEllipseItem(view_dice->width()/4+10,view_dice->height()/4+5,5,5);
            all_dots.push_back(dot_one);
            dot_one = new QGraphicsEllipseItem(view_dice->width()/4-5,view_dice->height()/4+5,5,5);
            all_dots.push_back(dot_one);
            dot_one = new QGraphicsEllipseItem(view_dice->width()/4-20,view_dice->height()/4+5,5,5);
            all_dots.push_back(dot_one);
            break;
        case 4:
            dot_one = new QGraphicsEllipseItem(view_dice->width()/4,view_dice->height()/4,5,5);
            all_dots.push_back(dot_one);
            dot_one = new QGraphicsEllipseItem(view_dice->width()/4-10,view_dice->height()/4,5,5);
            all_dots.push_back(dot_one);
            dot_one = new QGraphicsEllipseItem(view_dice->width()/4,view_dice->height()/4+10,5,5);
            all_dots.push_back(dot_one);
            dot_one = new QGraphicsEllipseItem(view_dice->width()/4-10,view_dice->height()/4+10,5,5);
            all_dots.push_back(dot_one);
            break;
        case 5:
            dot_one = new QGraphicsEllipseItem(view_dice->width()/4,view_dice->height()/4,5,5);
            all_dots.push_back(dot_one);
            dot_one = new QGraphicsEllipseItem(view_dice->width()/4-10,view_dice->height()/4,5,5);
            all_dots.push_back(dot_one);
            dot_one = new QGraphicsEllipseItem(view_dice->width()/4-5,view_dice->height()/4+5,5,5);
            all_dots.push_back(dot_one);
            dot_one = new QGraphicsEllipseItem(view_dice->width()/4,view_dice->height()/4+10,5,5);
            all_dots.push_back(dot_one);
            dot_one = new QGraphicsEllipseItem(view_dice->width()/4-10,view_dice->height()/4+10,5,5);
            all_dots.push_back(dot_one);
            break;
        case 6:
            dot_one = new QGraphicsEllipseItem(view_dice->width()/4-15,view_dice->height()/4-5,5,5);
            all_dots.push_back(dot_one);
            dot_one = new QGraphicsEllipseItem(view_dice->width()/4-15,view_dice->height()/4+5,5,5);
            all_dots.push_back(dot_one);
            dot_one = new QGraphicsEllipseItem(view_dice->width()/4-15,view_dice->height()/4+15,5,5);
            all_dots.push_back(dot_one);
            dot_one = new QGraphicsEllipseItem(view_dice->width()/4+5,view_dice->height()/4-5,5,5);
            all_dots.push_back(dot_one);
            dot_one = new QGraphicsEllipseItem(view_dice->width()/4+5,view_dice->height()/4+5,5,5);
            all_dots.push_back(dot_one);
            dot_one = new QGraphicsEllipseItem(view_dice->width()/4+5,view_dice->height()/4+15,5,5);
            all_dots.push_back(dot_one);
            break;
    }
    for(QGraphicsEllipseItem *dot : all_dots){
        dot->setBrush(QBrush(Qt::black));
        scene_dice->addItem(dot);
    }
    all_dots.clear();
    switch(dice_roll_2){
        /* Getting the dots in the correct position
         * 3*width / 2 + 5 and 3*height / 2 - 5 will get the dot to the center of the dice view
         * Adjusting the width will get the position of the dots for dice rolls 1-3
         * Adjusting the appropriate width and height will get the positions for dice rolls 4-6
         */
        case 1:
            dot_one = new QGraphicsEllipseItem(3*view_dice->width()/4-5,view_dice->height()/4+5,5,5);
            all_dots.push_back(dot_one);
            break;
        case 2:
            dot_one = new QGraphicsEllipseItem(3*view_dice->width()/4,view_dice->height()/4+5,5,5);
            all_dots.push_back(dot_one);
            dot_one = new QGraphicsEllipseItem(3*view_dice->width()/4-10,view_dice->height()/4+5,5,5);
            all_dots.push_back(dot_one);
            break;
        case 3:
            dot_one = new QGraphicsEllipseItem(3*view_dice->width()/4+10,view_dice->height()/4+5,5,5);
            all_dots.push_back(dot_one);
            dot_one = new QGraphicsEllipseItem(3*view_dice->width()/4-5,view_dice->height()/4+5,5,5);
            all_dots.push_back(dot_one);
            dot_one = new QGraphicsEllipseItem(3*view_dice->width()/4-20,view_dice->height()/4+5,5,5);
            all_dots.push_back(dot_one);
            break;
        case 4:
            dot_one = new QGraphicsEllipseItem(3*view_dice->width()/4,view_dice->height()/4,5,5);
            all_dots.push_back(dot_one);
            dot_one = new QGraphicsEllipseItem(3*view_dice->width()/4-10,view_dice->height()/4,5,5);
            all_dots.push_back(dot_one);
            dot_one = new QGraphicsEllipseItem(3*view_dice->width()/4,view_dice->height()/4+10,5,5);
            all_dots.push_back(dot_one);
            dot_one = new QGraphicsEllipseItem(3*view_dice->width()/4-10,view_dice->height()/4+10,5,5);
            all_dots.push_back(dot_one);
            break;
        case 5:
            dot_one = new QGraphicsEllipseItem(3*view_dice->width()/4,view_dice->height()/4,5,5);
            all_dots.push_back(dot_one);
            dot_one = new QGraphicsEllipseItem(3*view_dice->width()/4-10,view_dice->height()/4,5,5);
            all_dots.push_back(dot_one);
            dot_one = new QGraphicsEllipseItem(3*view_dice->width()/4-5,view_dice->height()/4+5,5,5);
            all_dots.push_back(dot_one);
            dot_one = new QGraphicsEllipseItem(3*view_dice->width()/4,view_dice->height()/4+10,5,5);
            all_dots.push_back(dot_one);
            dot_one = new QGraphicsEllipseItem(3*view_dice->width()/4-10,view_dice->height()/4+10,5,5);
            all_dots.push_back(dot_one);
            break;
        case 6:
            dot_one = new QGraphicsEllipseItem(3*view_dice->width()/4-15,view_dice->height()/4-5,5,5);
            all_dots.push_back(dot_one);
            dot_one = new QGraphicsEllipseItem(3*view_dice->width()/4-15,view_dice->height()/4+5,5,5);
            all_dots.push_back(dot_one);
            dot_one = new QGraphicsEllipseItem(3*view_dice->width()/4-15,view_dice->height()/4+15,5,5);
            all_dots.push_back(dot_one);
            dot_one = new QGraphicsEllipseItem(3*view_dice->width()/4+5,view_dice->height()/4-5,5,5);
            all_dots.push_back(dot_one);
            dot_one = new QGraphicsEllipseItem(3*view_dice->width()/4+5,view_dice->height()/4+5,5,5);
            all_dots.push_back(dot_one);
            dot_one = new QGraphicsEllipseItem(3*view_dice->width()/4+5,view_dice->height()/4+15,5,5);
            all_dots.push_back(dot_one);
            break;
    }
    for(QGraphicsEllipseItem *dot : all_dots){
        dot->setBrush(QBrush(Qt::black));
        scene_dice->addItem(dot);
    }
}
