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
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

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
    ui->endButton->setEnabled(false);
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
        new_game->AddHexagon(h);
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
        new_game->AddHexagon(h);
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
        new_game->AddHexagon(h);
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
        new_game->AddHexagon(h);
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

    //First Turn
    ui->status_label->setText(QString("Roll Dice to see who goes first!"));
    ui->houseButton->setEnabled(false);
    ui->mansionButton->setEnabled(false);
    ui->roadButton->setEnabled(false);
    ui->endButton->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::EnoughResources(Building *building_to_check){
    std::map<resource,int> current_players_resources = new_game->get_current_player()->get_current_resources();
    for(const auto it : building_to_check->get_needed_resources()){
        if(current_players_resources[it.first] < it.second){
            return false;
        }
    }
    return true;
}

void MainWindow::on_houseButton_clicked()
{
    if(Game::get_place_mode()){ //If in place mode and want to reset
        ui->infoBrowser->setText(QString(""));
        Game::set_place_mode(!Game::get_place_mode()); //Set to false
        ui->centralWidget->setCursor(Qt::ArrowCursor); //Reset to arrow cursor
    }
    else{ //Not in place mode
        ChocolateHouse *temp_house = new ChocolateHouse(0,0);
        bool enough_resources = EnoughResources(temp_house);
        if(enough_resources){
            Game::set_place_mode(!Game::get_place_mode());
            Game::set_building_string("choco house");
            ui->centralWidget->setCursor(Qt::CrossCursor);
            QFile file(":/infoResources/InfoText/choco_house.txt");
            if(!file.open(QIODevice::ReadOnly)){
                QMessageBox::information(0,"Info",file.errorString());
            }
            QTextStream in(&file);
            ui->infoBrowser->setText(in.readAll());
        }
        else{
            ui->infoBrowser->setText(QString("Not Enough Resources!"));
        }
    }
}

void MainWindow::on_roadButton_clicked()
{
    if(Game::get_place_mode()){ //If in place mode and want to reset
        ui->infoBrowser->setText(QString(""));
        Game::set_place_mode(!Game::get_place_mode()); //Set to false
        ui->centralWidget->setCursor(Qt::ArrowCursor); //Reset to arrow cursor
    }
    else{ //Not in place mode
        Road *temp_road = new Road(0,0,0,0);
        bool enough_resources = EnoughResources(temp_road);
        if(enough_resources){
            Game::set_place_mode(!Game::get_place_mode());
            Game::set_building_string("candy road");
            ui->centralWidget->setCursor(Qt::CrossCursor);
            QFile file(":/infoResources/InfoText/candy_road.txt");
            if(!file.open(QIODevice::ReadOnly)){
                QMessageBox::information(0,"Info",file.errorString());
            }
            QTextStream in(&file);
            ui->infoBrowser->setText(in.readAll());
        }
        else{
            ui->infoBrowser->setText(QString("Not Enough Resources!"));
        }
    }
}

void MainWindow::on_mansionButton_clicked()
{
    if(Game::get_place_mode()){ //If in place mode and want to reset
        ui->infoBrowser->setText(QString(""));
        Game::set_place_mode(!Game::get_place_mode()); //Set to false
        ui->centralWidget->setCursor(Qt::ArrowCursor); //Reset to arrow cursor
    }
    else{ //Not in place mode
        ChocolateMansion *temp_house = new ChocolateMansion(0,0);
        bool enough_resources = EnoughResources(temp_house);
        if(enough_resources){
            Game::set_place_mode(!Game::get_place_mode());
            Game::set_building_string("choco mansion");
            ui->centralWidget->setCursor(Qt::CrossCursor);
            QFile file(":/infoResources/InfoText/choco_mansion.txt");
            if(!file.open(QIODevice::ReadOnly)){
                QMessageBox::information(0,"Info",file.errorString());
            }
            QTextStream in(&file);
            ui->infoBrowser->setText(in.readAll());
        }
        else{
            ui->infoBrowser->setText(QString("Not Enough Resources!"));
        }
    }
}
void MainWindow::AddBuildingSlot(Building *building_to_add, std::pair<int,int> p)
{
    //check if point is owned by another player owns a point already
    if(taken_map.count(p)){
        if(taken_map.at(p) == new_game->get_current_player()){
            building_to_add->set_color(new_game->get_current_player()->get_player_color());
            //cond for valid building placement
            if(building_to_add->get_building_type() == "choco mansion"){
                //checks for if house in map
                bool house = false;
                Building *building_to_remove = new Building(-1, -1);
                //must be upgrade of a house
                if(new_game->get_current_player()->get_buildings().count(p)){
                    //point in map, check if house
                    for(unsigned int i = 0; i < new_game->get_current_player()->get_buildings().at(p).size(); i++){// ugly but works
                        if(new_game->get_current_player()->get_buildings().at(p)[i]->get_building_type() == "choco house"){
                            building_to_remove = new_game->get_current_player()->get_buildings().at(p)[i];
                            house = true;
                            break;
                        }
                    }
                    if(house){
                        Game::set_place_mode(false);
                        ui->centralWidget->setCursor(Qt::ArrowCursor);
                        for(const auto it : building_to_add->get_needed_resources()){
                            new_game->get_current_player()->RemoveResource(it.first,it.second);
                        }
                        new_game->get_current_player()->RemoveBuilding(p, building_to_remove);
                        new_game->get_current_player()->AddBuilding(p, building_to_add);
                        taken_map[p] = new_game->get_current_player();
                        scene->addItem(building_to_add);
                        scene->update();
                        UpdateResources();
                        UpdatePoints();
                        ui->infoBrowser->setText(QString(""));
                    }
                    else{
                        //otherwise don't do building addition
                        ui->infoBrowser->setText(QString("Invalid Placement; Upgrade A Chocolate House."));
                    }
                }
                else{
                    //point not in map void building addition
                    ui->infoBrowser->setText(QString("Invalid Placement; Upgrade A Chocolate House."));
                }
                house = false;
            }
            else if(building_to_add->get_building_type() == "candy road"){
                pair<int,int> other_p = building_to_add->get_x_y();
                if(taken_map.count(other_p)){
                    if(taken_map.at(other_p) == new_game->get_current_player()){
                        //must connect to road or house or mansion
                        bool house = false;
                        //something at point you want to add road -> check if house or mansion or road
                        if(new_game->get_current_player()->get_buildings().count(p)){

//                            for(unsigned int i = 0; i < new_game->get_current_player()->get_buildings().at(p).size(); i++){// ugly but works
//                                if(new_game->get_current_player()->get_buildings().at(p)[i]->get_building_type() == "choco house"
//                                        || new_game->get_current_player()->get_buildings().at(p)[i]->get_building_type() == "choco mansion"){
//                                    house = true;
//                                    break;
//                                }
//                            }
//                            if(house){
                                Game::set_place_mode(false);
                                ui->centralWidget->setCursor(Qt::ArrowCursor);
                                for(const auto it : building_to_add->get_needed_resources()){
                                    new_game->get_current_player()->RemoveResource(it.first,it.second);
                                }
                                //add to vector at key p
                                new_game->get_current_player()->AddBuilding(p, building_to_add);
                                //also add second point of road to map to aid house placement checks
                                new_game->get_current_player()->AddBuilding(other_p, building_to_add);
                                taken_map[p] = new_game->get_current_player();
                                taken_map[other_p] = new_game->get_current_player();
                                scene->addItem(building_to_add);
                                scene->update();
                                UpdateResources();
                                UpdatePoints();
                                ui->infoBrowser->setText(QString(""));
//                            }
//                            else{
//                                //otherwise don't do road addition
//                                ui->infoBrowser->setText(QString("Invalid Placement; First Select Point With Chocolate House/Mansion Then Point Across Desired Edge."));
//                            }
                        }
                        else{
                            //nothing at point you want to add road
                            ui->infoBrowser->setText(QString("Invalid Placement; First Select Point With Chocolate House/Mansion Then Point Across Desired Edge."));
                        }
                        house = false;
                    }
                    else{
                        ui->infoBrowser->setText(QString("Point Already Taken"));
                    }
                }
                else{
                    //must connect to road or house or mansion
                    bool house = false;
                    //something at point you want to add road -> check if house or mansion or road
                    if(new_game->get_current_player()->get_buildings().count(p)){

//                        for(unsigned int i = 0; i < new_game->get_current_player()->get_buildings().at(p).size(); i++){// ugly but works
//                            if(new_game->get_current_player()->get_buildings().at(p)[i]->get_building_type() == "choco house"
//                                    || new_game->get_current_player()->get_buildings().at(p)[i]->get_building_type() == "choco mansion"){
//                                house = true;
//                                break;
//                            }
//                        }
//                        if(house){
                            Game::set_place_mode(false);
                            ui->centralWidget->setCursor(Qt::ArrowCursor);
                            for(const auto it : building_to_add->get_needed_resources()){
                                new_game->get_current_player()->RemoveResource(it.first,it.second);
                            }
                            //add to vector at key p
                            new_game->get_current_player()->AddBuilding(p, building_to_add);
                            //also add second point of road to map to aid house placement checks
                            new_game->get_current_player()->AddBuilding(other_p, building_to_add);
                            taken_map[p] = new_game->get_current_player();
                            taken_map[other_p] = new_game->get_current_player();
                            scene->addItem(building_to_add);
                            scene->update();
                            UpdateResources();
                            UpdatePoints();
                            ui->infoBrowser->setText(QString(""));
//                        }
//                        else{
//                            //otherwise don't do road addition
//                            ui->infoBrowser->setText(QString("Invalid Placement; First Select Point With Chocolate House/Mansion Then Point Across Desired Edge."));
//                        }
                    }
                    else{
                        //nothing at point you want to add road
                        ui->infoBrowser->setText(QString("Invalid Placement; First Select Point With Chocolate House/Mansion Then Point Across Desired Edge."));
                    }
                    house = false;
                }
            }
            else{
                //must connect to road and p in this case is the prev point so we have to manually access its second points
                bool house = false;
                bool exist = false;
                if(new_game->get_current_player()->get_buildings().count(p)){
                    for(unsigned int i = 0; i < new_game->get_current_player()->get_buildings().at(p).size(); i++){// ugly but works
                        if(new_game->get_current_player()->get_buildings().at(p)[i]->get_building_type() == "candy road"){
                            house = true;
                        }
                        else{
                            exist = true;
                        }
                    }
                    //something at point you want to add road -> check if house or mansion
                    if(house && !exist){
                        Game::set_place_mode(false);
                        ui->centralWidget->setCursor(Qt::ArrowCursor);
                        for(const auto it : building_to_add->get_needed_resources()){
                            new_game->get_current_player()->RemoveResource(it.first,it.second);
                        }
                        new_game->get_current_player()->AddBuilding(p, building_to_add);
                        taken_map[p] = new_game->get_current_player();
                        scene->addItem(building_to_add);
                        scene->update();
                        UpdateResources();
                        UpdatePoints();
                        ui->infoBrowser->setText(QString(""));
                    }
                    else{
                        //otherwise don't do road addition
                        ui->infoBrowser->setText(QString("Invalid Placement; First Select Point With Chocolate House/Mansion Then Point Across Desired Edge."));
                    }
                }
                exist = false;
                house = false;
            }
        }
        else{
            ui->infoBrowser->setText(QString("Point Already Taken"));
        }
    }
    else{
        building_to_add->set_color(new_game->get_current_player()->get_player_color());
        //cond for valid building placement
        if(building_to_add->get_building_type() == "choco mansion"){
            //checks for if house in map
            bool house = false;
            Building *building_to_remove = new Building(-1, -1);
            //must be upgrade of a house
            if(new_game->get_current_player()->get_buildings().count(p)){
                //point in map, check if house
                for(unsigned int i = 0; i < new_game->get_current_player()->get_buildings().at(p).size(); i++){// ugly but works
                    if(new_game->get_current_player()->get_buildings().at(p)[i]->get_building_type() == "choco house"){
                        building_to_remove = new_game->get_current_player()->get_buildings().at(p)[i];
                        house = true;
                        break;
                    }
                }
                if(house){
                    Game::set_place_mode(false);
                    ui->centralWidget->setCursor(Qt::ArrowCursor);
                    for(const auto it : building_to_add->get_needed_resources()){
                        new_game->get_current_player()->RemoveResource(it.first,it.second);
                    }
                    new_game->get_current_player()->RemoveBuilding(p, building_to_remove);
                    new_game->get_current_player()->AddBuilding(p, building_to_add);
                    taken_map[p] = new_game->get_current_player();
                    scene->addItem(building_to_add);
                    scene->update();
                    UpdateResources();
                    UpdatePoints();
                    ui->infoBrowser->setText(QString(""));
                }
                else{
                    //otherwise don't do building addition
                    ui->infoBrowser->setText(QString("Invalid Placement; Upgrade A Chocolate House."));
                }
            }
            else{
                //point not in map void building addition
                ui->infoBrowser->setText(QString("Invalid Placement; Upgrade A Chocolate House."));
            }
            house = false;
        }
        else if(building_to_add->get_building_type() == "candy road"){
            pair<int,int> other_p = building_to_add->get_x_y();
            if(taken_map.count(other_p)){
                if(taken_map.at(other_p) == new_game->get_current_player()){
                    //must connect to road or house or mansion
                    bool house = false;
                     //something at point you want to add road -> check if house or mansion or road
                    if(new_game->get_current_player()->get_buildings().count(p)){

//                        for(unsigned int i = 0; i < new_game->get_current_player()->get_buildings().at(p).size(); i++){// ugly but works
//                            if(new_game->get_current_player()->get_buildings().at(p)[i]->get_building_type() == "choco house"
//                                    || new_game->get_current_player()->get_buildings().at(p)[i]->get_building_type() == "choco mansion"){
//                                house = true;
//                                break;
//                            }
//                        }
//                        if(house){
                            Game::set_place_mode(false);
                            ui->centralWidget->setCursor(Qt::ArrowCursor);
                            for(const auto it : building_to_add->get_needed_resources()){
                                new_game->get_current_player()->RemoveResource(it.first,it.second);
                            }
                            //add to vector at key p
                            new_game->get_current_player()->AddBuilding(p, building_to_add);
                            //also add second point of road to map to aid house placement checks
                            new_game->get_current_player()->AddBuilding(other_p, building_to_add);
                            taken_map[p] = new_game->get_current_player();
                            taken_map[other_p] = new_game->get_current_player();
                            scene->addItem(building_to_add);
                            scene->update();
                            UpdateResources();
                            UpdatePoints();
                            ui->infoBrowser->setText(QString(""));
//                        }
//                        else{
//                            //otherwise don't do road addition
//                            ui->infoBrowser->setText(QString("Invalid Placement; First Select Point With Chocolate House/Mansion Then Point Across Desired Edge."));
//                        }
                    }
                    else{
                        //nothing at point you want to add road
                        ui->infoBrowser->setText(QString("Invalid Placement; First Select Point With Chocolate House/Mansion Then Point Across Desired Edge."));
                    }
                    house = false;
                }
                else{
                    ui->infoBrowser->setText(QString("Point Already Taken"));
                }
            }
            else{
                //must connect to road or house or mansion
                bool house = false;
                //something at point you want to add road -> check if house or mansion or road
                if(new_game->get_current_player()->get_buildings().count(p)){

//                    for(unsigned int i = 0; i < new_game->get_current_player()->get_buildings().at(p).size(); i++){// ugly but works
//                        if(new_game->get_current_player()->get_buildings().at(p)[i]->get_building_type() == "choco house"
//                                || new_game->get_current_player()->get_buildings().at(p)[i]->get_building_type() == "choco mansion"){
//                            house = true;
//                            break;
//                        }
//                    }
//                    if(house){
                        Game::set_place_mode(false);
                        ui->centralWidget->setCursor(Qt::ArrowCursor);
                        for(const auto it : building_to_add->get_needed_resources()){
                            new_game->get_current_player()->RemoveResource(it.first,it.second);
                        }
                        //add to vector at key p
                        new_game->get_current_player()->AddBuilding(p, building_to_add);
                        //also add second point of road to map to aid house placement checks
                        new_game->get_current_player()->AddBuilding(other_p, building_to_add);
                        taken_map[p] = new_game->get_current_player();
                        taken_map[other_p] = new_game->get_current_player();
                        scene->addItem(building_to_add);
                        scene->update();
                        UpdateResources();
                        UpdatePoints();
                        ui->infoBrowser->setText(QString(""));
//                    }
//                    else{
//                        //otherwise don't do road addition
//                        ui->infoBrowser->setText(QString("Invalid Placement; First Select Point With Chocolate House/Mansion Then Point Across Desired Edge."));
//                    }
                }
                else{
                    //nothing at point you want to add road
                    ui->infoBrowser->setText(QString("Invalid Placement; First Select Point With Chocolate House/Mansion Then Point Across Desired Edge."));
                }
                house = false;
            }
        }
        else{
            //must connect to road and p in this case is the prev point so we have to manually access its second points
            bool house = false;
            bool exist = false;
            if(new_game->get_current_player()->get_buildings().count(p)){
                for(unsigned int i = 0; i < new_game->get_current_player()->get_buildings().at(p).size(); i++){// ugly but works
                    if(new_game->get_current_player()->get_buildings().at(p)[i]->get_building_type() == "candy road"){
                        house = true;
                    }
                    else{
                        exist = true;
                    }
                }
                //something at point you want to add road -> check if house or mansion
                if(house && !exist){
                    Game::set_place_mode(false);
                    ui->centralWidget->setCursor(Qt::ArrowCursor);
                    for(const auto it : building_to_add->get_needed_resources()){
                        new_game->get_current_player()->RemoveResource(it.first,it.second);
                    }
                    new_game->get_current_player()->AddBuilding(p, building_to_add);
                    taken_map[p] = new_game->get_current_player();
                    scene->addItem(building_to_add);
                    scene->update();
                    UpdateResources();
                    UpdatePoints();
                    ui->infoBrowser->setText(QString(""));
                }
                else{
                    //otherwise don't do road addition
                    ui->infoBrowser->setText(QString("Invalid Placement; First Select Point With Chocolate House/Mansion Then Point Across Desired Edge."));
                }
            }
            else{
                if(!new_game->get_current_player()->get_first_turn()){
                    //nothing at point you want to add road
                    ui->infoBrowser->setText(QString("Invalid Placement; First Select Point With Road."));
                }
                else{//players first turn they get to place one house free of charge
                    ui->houseButton->setEnabled(false);
                    ui->mansionButton->setEnabled(false);
                    ui->roadButton->setEnabled(false);
                    Game::set_place_mode(false);
                    ui->centralWidget->setCursor(Qt::ArrowCursor);
                    new_game->get_current_player()->AddBuilding(p, building_to_add);
                    taken_map[p] = new_game->get_current_player();
                    scene->addItem(building_to_add);
                    scene->update();
                    ui->infoBrowser->setText(QString(""));
                    //set to false
                    new_game->get_current_player()->set_first_turn();
                    //turn buttons back on
                    ui->houseButton->setEnabled(true);
                    ui->mansionButton->setEnabled(true);
                    ui->roadButton->setEnabled(true);
                }
            }
            exist = false;
            house = false;
        }
    }
}

void MainWindow::UpdateResources()
{
    for(Player *player : new_game->get_player_list()){
        if(player->get_id() == 1){
            ui->p1Money->setText(QString::number(player->get_current_resources()[resource::money]));
            ui->p1Sugar->setText(QString::number(player->get_current_resources()[resource::sugar]));
            ui->p1Water->setText(QString::number(player->get_current_resources()[resource::water]));
        }
        else if(player->get_id() == 2){
            ui->p2Money->setText(QString::number(player->get_current_resources()[resource::money]));
            ui->p2Sugar->setText(QString::number(player->get_current_resources()[resource::sugar]));
            ui->p2Water->setText(QString::number(player->get_current_resources()[resource::water]));
        }
        else if(player->get_id() == 3){
            ui->p3Money->setText(QString::number(player->get_current_resources()[resource::money]));
            ui->p3Sugar->setText(QString::number(player->get_current_resources()[resource::sugar]));
            ui->p3Water->setText(QString::number(player->get_current_resources()[resource::water]));
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
    if(first_turn){
        std::vector<int> player_order;
        int sum_player = dice_roll_1 + dice_roll_2;
        int sum_ai_two = (rand() % 6 + 1) + (rand() % 6 + 1);
        int sum_ai_three = (rand() % 6 + 1) + (rand() % 6 + 1);
        if(sum_player >= sum_ai_two && sum_player >= sum_ai_three){ //Player One is first
            player_order.push_back(1);
            if(sum_ai_two > sum_ai_three){ //Player two is second and Player three is third
                player_order.push_back(2);
                player_order.push_back(3);
            }
            else{ //Player 3 is second and Player 2 is third
                player_order.push_back(3);
                player_order.push_back(2);
            }
        }
        else if(sum_ai_two > sum_player && sum_ai_two >= sum_ai_three){ //Player two is first
            qDebug() << "test2";
            player_order.push_back(2);
            if(sum_player > sum_ai_three){ //Player one is second and Player three is third
                player_order.push_back(1);
                player_order.push_back(3);
            }
            else{ //Player three is second and Player one is third
                player_order.push_back(3);
                player_order.push_back(1);
            }
        }
        else if(sum_ai_three > sum_player && sum_ai_three > sum_ai_two){ //Player 3 is first
            qDebug() << "test3";
            player_order.push_back(3);
            if(sum_player > sum_ai_two){ //Player 1 is second and Player 2 is third
                player_order.push_back(1);
                player_order.push_back(2);
            }
            else{ //Player 2 is second and Player 1 is third
                player_order.push_back(2);
                player_order.push_back(1);
            }
        }
        first_turn = false;
        new_game->CreatePlayers(player_order);
        UpdateResources();
        ui->houseButton->setEnabled(true);
        ui->mansionButton->setEnabled(true);
        ui->roadButton->setEnabled(true);
        ui->endButton->setEnabled(true);
    }
    ui->diceButton->setEnabled(false);
    ui->endButton->setEnabled(true);
    ui->status_label->setText(QString("Player " +QString::number(new_game->get_current_player()->get_id()) +QString("'s turn")));

    if(new_game->get_current_player()->get_first_turn()){
        Game::set_place_mode(!Game::get_place_mode());
        Game::set_building_string("choco house");
        ui->centralWidget->setCursor(Qt::CrossCursor);
        QFile file(":/infoResources/InfoText/choco_house.txt");
        if(!file.open(QIODevice::ReadOnly)){
            QMessageBox::information(0,"Info",file.errorString());
        }
        QTextStream in(&file);
        ui->infoBrowser->setText(in.readAll());
    }
}

void MainWindow::UpdatePoints(){
    std::map<Player *, int> player_pts = new_game->PlayerPoints();
    std::map<std::string, Player*> record_holders = UpdateRecords();
    for(Player *player : new_game->get_player_list()){
        if(player->get_id() == 1){
            ui->p1Points->setText(QString::number(player->get_total_points()));
            ui->p1Breakdown->setText(QString("Point Breakdown\n\n")+QString("Buildings: ") + QString::number(player_pts[player]));
        }
        else if(player->get_id() == 2){
            ui->p2Points->setText(QString::number(player->get_total_points()));
            ui->p2Breakdown->setText(QString("Point Breakdown\n\n")+QString("Buildings: ") + QString::number(player_pts[player]));
        }
        else if(player->get_id() == 3){
            ui->p3Points->setText(QString::number(player->get_total_points()));
            ui->p3Breakdown->setText(QString("Point Breakdown\n\n")+QString("Buildings: ") + QString::number(player_pts[player]));
        }
    }
    for(const auto it : record_holders){
        if(it.second->get_id() == 1){
            if(it.first == "Longest Road"){
                ui->p1Breakdown->append(QString::fromStdString(it.first) + QString(": 1"));
            }
            else if(it.first == "Largest Dice Sum"){
                ui->p1Breakdown->append(QString::fromStdString(it.first) + QString(": 1"));
            }
            else if(it.first == "Most Resources"){
                ui->p1Breakdown->append(QString::fromStdString(it.first) + QString(": 2"));
            }
        }
        else if(it.second->get_id() == 2){
            if(it.first == "Longest Road"){
                 ui->p2Breakdown->append(QString::fromStdString(it.first) + QString(": 1"));
            }
            else if(it.first == "Largest Dice Sum"){
                ui->p2Breakdown->append(QString::fromStdString(it.first) + QString(": 1"));
            }
            else if(it.first == "Most Resources"){
                ui->p2Breakdown->append(QString::fromStdString(it.first) + QString(": 2"));
            }
        }
        else if(it.second->get_id() == 3){
            if(it.first == "Longest Road"){
                ui->p3Breakdown->append(QString::fromStdString(it.first) + QString(": 1"));
            }
            else if(it.first == "Largest Dice Sum"){
                ui->p3Breakdown->append(QString::fromStdString(it.first) + QString(": 1"));
            }
            else if(it.first == "Most Resources"){
                ui->p3Breakdown->append(QString::fromStdString(it.first) + QString(": 2"));
            }
        }
    }
}

void MainWindow::on_endButton_clicked()
{
    new_game->set_next_player(new_game->get_current_player());
    ui->status_label->setText(QString("Player " +QString::number(new_game->get_current_player()->get_id()) +QString("'s turn")));
    ui->endButton->setEnabled(false);
    ui->diceButton->setEnabled(true);
}

std::map<std::string, Player*> MainWindow::UpdateRecords(){
    std::map<std::string, Player*> record_holders = new_game->Records();
    //Updating the UI
    ui->currRecord->setText(QString("Current Records\n\n") + QString("Longest Road (+1):") + QString(" Player ")
                            + QString::number(record_holders["Longest Road"]->get_id()) + QString("\n")
                            + QString("Largest Dice Sum (+1): ") + QString("Player ") +QString::number(record_holders["Largest Dice Sum"]->get_id()) + QString("\n")
                            + QString("Most Resources (+2): ") +QString("Player ") + QString::number(record_holders["Most Resources"]->get_id()));
    return record_holders;
}
