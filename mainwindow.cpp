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
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QChart>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QChartView>
#include <QTimer>
using namespace QtCharts;

/*
    MainWindow constructor to initalize everything and get ready to start game
*/
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    new_game = new Game();
    new_game->set_place_mode(false);
    srand (time(NULL));
    ui->setupUi(this);
    //Setup the font for status label
    QFont font = ui->status_label->font();
    font.setBold(true);
    ui->status_label->setFont(font);
    ui->endButton->setEnabled(false);
    ui->gameBoard->setBackgroundBrush(QBrush(QColor(85,85,85), Qt::SolidPattern)); //Sets the background color to gameboard
    this->setWindowTitle(QString("Settlers of Candy"));
    //Scene and view of the gameboard and dice
    scene = new QGraphicsScene;
    scene_dice = new QGraphicsScene;
    QGraphicsView * view = ui->gameBoard;
    view->setScene(scene);
    view->setSceneRect(0,0,view->frameSize().width(),view->frameSize().height());
    //Scene and view of the player graphs
    p1_scene_bar = new QGraphicsScene;
    QGraphicsView *p1_view_graph = ui->p1Graph;
    p1_view_graph->setScene(p1_scene_bar);
    p1_view_graph->setSceneRect(0,0,p1_view_graph->frameSize().width(),p1_view_graph->frameSize().height());
    p2_scene_bar = new QGraphicsScene;
    QGraphicsView *p2_view_graph = ui->p2Graph;
    p2_view_graph->setScene(p2_scene_bar);
    p2_view_graph->setSceneRect(0,0,p2_view_graph->frameSize().width(),p2_view_graph->frameSize().height());
    p3_scene_bar = new QGraphicsScene;
    QGraphicsView *p3_view_graph = ui->p3Graph;
    p3_view_graph->setScene(p3_scene_bar);
    p3_view_graph->setSceneRect(0,0,p3_view_graph->frameSize().width(),p3_view_graph->frameSize().height());
    pair <int, int> p1;
    pair <int, int> p2;
    pair <int, int> p3;
    pair <int, int> p4;
    pair <int, int> p5;
    pair <int, int> p6;
    int rand_resource_num;
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
        Hexagon *h = Hexagon::CreateHexagon(p1, p2, p3, p4, p5, p6,rand_resource_num);
        new_game->AddHexagon(h);
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
        Hexagon *h = Hexagon::CreateHexagon(p1, p2, p3, p4, p5, p6,rand_resource_num);
        new_game->AddHexagon(h);
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
        Hexagon *h = Hexagon::CreateHexagon(p1, p2, p3, p4, p5, p6,rand_resource_num);
        new_game->AddHexagon(h);
        new_game->AddHexagon(h);
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
        Hexagon *h = Hexagon::CreateHexagon(p1, p2, p3, p4, p5, p6,rand_resource_num);
        new_game->AddHexagon(h);
        new_game->AddHexagon(h);
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
    ui->status_label->setText(QString("Enter The Amount Of AI Players (0-3)"));
    ui->diceButton->setEnabled(false);
    ui->houseButton->setEnabled(false);
    ui->mansionButton->setEnabled(false);
    ui->roadButton->setEnabled(false);
    ui->endButton->setEnabled(false);
    ui->p1Graph->setVisible(false);
    ui->p2Graph->setVisible(false);
    ui->p3Graph->setVisible(false);
}

/*
    deconstructor
*/
MainWindow::~MainWindow()
{
    delete ui;
}

/*
 * Check if player has resources to add a building
 *
 * @param Takes the building wanted to be added by a player
    @return bool on whether a player has enough resources for a building addition
*/
bool MainWindow::EnoughResources(Building *building_to_check){
    std::map<resource,int> current_players_resources = new_game->get_current_player()->get_current_resources();
    for(const auto it : building_to_check->get_needed_resources()){
        if(current_players_resources[it.first] < it.second){
            return false;
        }
    }
    return true;
}

/*
    When add House button clikced
*/
void MainWindow::on_houseButton_clicked()
{
    if(Game::get_place_mode()){ //If in place mode and want to reset
        ui->infoBrowser->setText(QString(""));
        Game::set_place_mode(!Game::get_place_mode()); //Set to false
        ui->centralWidget->setCursor(Qt::ArrowCursor); //Reset to arrow cursor
    }
    else{ //Not in place mode, put in place mode
        ChocolateHouse *temp_house = new ChocolateHouse(0,0);
        bool enough_resources = EnoughResources(temp_house);
        if(enough_resources){ // check if enough resources to place
            Game::set_place_mode(!Game::get_place_mode());
            Game::set_building_string("choco house");
            ui->centralWidget->setCursor(Qt::CrossCursor);
            QFile file(":/infoResources/InfoText/choco_house.txt"); // display instructions on what to do
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

/*
    When add Road button clikced
*/
void MainWindow::on_roadButton_clicked()
{
    if(Game::get_place_mode()){ //If in place mode and want to reset
        ui->infoBrowser->setText(QString(""));
        Game::set_place_mode(!Game::get_place_mode()); //Set to false
        ui->centralWidget->setCursor(Qt::ArrowCursor); //Reset to arrow cursor
    }
    else{ //Not in place mode, put in place mode
        Road *temp_road = new Road(0,0,0,0);
        bool enough_resources = EnoughResources(temp_road);
        if(enough_resources){ // check if enough resources to place building
            Game::set_place_mode(!Game::get_place_mode());
            Game::set_building_string("candy road");
            ui->centralWidget->setCursor(Qt::CrossCursor);
            QFile file(":/infoResources/InfoText/candy_road.txt"); // display instructions on what to do
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

/*
    When add Mansion button clikced
*/
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
            QFile file(":/infoResources/InfoText/choco_mansion.txt"); // display instructions on what to do
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

/*
 * slot that will take in a desired building to add and where to be added
 * and checks valid placement
 *
 * @param p is point a buidling is to be added
 * @param building_to_add is the building in question to be added
*/
void MainWindow::AddBuildingSlot(Building *building_to_add, std::pair<int,int> p)
{
    //check if point is owned by another player owns a point already
    if(taken_map.count(p)){
        if(taken_map.at(p) == new_game->get_current_player()){ // if point is taken make sure it is taken by the current player
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
                    if(house){ // if there is a house there we can upgrade it
                        Game::set_place_mode(false);
                        ui->centralWidget->setCursor(Qt::ArrowCursor);
                        for(const auto it : building_to_add->get_needed_resources()){ // remove resources and update game stats
                            new_game->get_current_player()->RemoveResource(it.first,it.second);
                            new_game->get_current_player()->AddToResourcesUsed(it.first,it.second);
                        }
                        new_game->get_current_player()->RemoveBuilding(p, building_to_remove); // remove the house and add the mansion
                        new_game->get_current_player()->AddBuilding(p, building_to_add);
                        taken_map[p] = new_game->get_current_player(); // add to taken map to keep track of who owns what
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
                        //something at point you want to add road -> check if house or mansion or road
                        if(new_game->get_current_player()->get_buildings().count(p)){
                                Game::set_place_mode(false);
                                ui->centralWidget->setCursor(Qt::ArrowCursor);
                                for(const auto it : building_to_add->get_needed_resources()){ // remove resources and update game stats
                                    new_game->get_current_player()->RemoveResource(it.first,it.second);
                                    new_game->get_current_player()->AddToResourcesUsed(it.first,it.second);
                                }
                                //add to vector at key p
                                new_game->get_current_player()->AddBuilding(p, building_to_add); // adding to players building map
                                //also add second point of road to map to aid house placement checks
                                new_game->get_current_player()->AddBuilding(other_p, building_to_add);
                                taken_map[p] = new_game->get_current_player();
                                taken_map[other_p] = new_game->get_current_player(); // add to taken map to keep track of who owns what
                                scene->addItem(building_to_add);
                                scene->update();
                                UpdateResources();
                                UpdatePoints();
                                ui->infoBrowser->setText(QString(""));
                        }
                        else{
                            //nothing at point you want to add road
                            ui->infoBrowser->setText(QString("Invalid Placement; First Select Point With Chocolate House/Mansion Then Point Across Desired Edge."));
                        }
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
                            Game::set_place_mode(false);
                            ui->centralWidget->setCursor(Qt::ArrowCursor);
                            for(const auto it : building_to_add->get_needed_resources()){
                                new_game->get_current_player()->RemoveResource(it.first,it.second);
                                new_game->get_current_player()->AddToResourcesUsed(it.first,it.second);
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
                    }
                    else{
                        //nothing at point you want to add road
                        ui->infoBrowser->setText(QString("Invalid Placement; First Select Point With Chocolate House/Mansion Then Point Across Desired Edge."));
                    }
                    house = false;
                }
            }
            else{ // house
                //must connect to road and p in this case is the prev point so we have to manually access its second points
                bool house = false;
                bool exist = false;
                if(new_game->get_current_player()->get_buildings().count(p)){
                    for(unsigned int i = 0; i < new_game->get_current_player()->get_buildings().at(p).size(); i++){// ugly but works
                        if(new_game->get_current_player()->get_buildings().at(p)[i]->get_building_type() == "candy road"){ // make sure its on a connected with a candy road
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
                            new_game->get_current_player()->AddToResourcesUsed(it.first,it.second);
                        }
                        new_game->get_current_player()->AddBuilding(p, building_to_add); // add the house to players map of buildings
                        taken_map[p] = new_game->get_current_player(); // add to taken map
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
                exist = false; // reset vars
                house = false;
            }
        }
        else{ // point taken by another player
            ui->infoBrowser->setText(QString("Point Already Taken"));
        }
    }
    else{ // if its not in the taken map its free for grabs
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
                    if(new_game->get_current_player()->get_buildings().at(p)[i]->get_building_type() == "choco house"){ // if the players building at point is a house
                        building_to_remove = new_game->get_current_player()->get_buildings().at(p)[i];
                        house = true;
                        break;
                    }
                }
                if(house){
                    Game::set_place_mode(false);
                    ui->centralWidget->setCursor(Qt::ArrowCursor);
                    for(const auto it : building_to_add->get_needed_resources()){ // take away the require resource
                        new_game->get_current_player()->RemoveResource(it.first,it.second);
                        new_game->get_current_player()->AddToResourcesUsed(it.first,it.second);
                    }
                    new_game->get_current_player()->RemoveBuilding(p, building_to_remove); // remove house and add mansion
                    new_game->get_current_player()->AddBuilding(p, building_to_add);
                    taken_map[p] = new_game->get_current_player(); // update taken map
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
            pair<int,int> other_p = building_to_add->get_x_y(); // gets the other point of the road
             //something at point you want to add road -> check if house or mansion or road
            if(new_game->get_current_player()->get_buildings().count(p)){
                    Game::set_place_mode(false);
                    ui->centralWidget->setCursor(Qt::ArrowCursor);
                    for(const auto it : building_to_add->get_needed_resources()){ // take away needed resources
                        new_game->get_current_player()->RemoveResource(it.first,it.second);
                        new_game->get_current_player()->AddToResourcesUsed(it.first,it.second);
                    }
                    //add to vector at key p
                    new_game->get_current_player()->AddBuilding(p, building_to_add);
                    //also add second point of road to map to aid house placement checks
                    new_game->get_current_player()->AddBuilding(other_p, building_to_add);
                    taken_map[p] = new_game->get_current_player();
                    taken_map[other_p] = new_game->get_current_player(); // update taken map
                    scene->addItem(building_to_add);
                    scene->update();
                    UpdateResources();
                    UpdatePoints();
                    ui->infoBrowser->setText(QString(""));
            }
            else{
                //nothing at point you want to add road
                ui->infoBrowser->setText(QString("Invalid Placement; First Select Point With Chocolate House/Mansion Then Point Across Desired Edge."));
            }
        }
        else{ // house
            //must connect to road and p in this case is the prev point so we have to manually access its second points
            bool house = false;
            bool exist = false;
            if(new_game->get_current_player()->get_buildings().count(p)){
                for(unsigned int i = 0; i < new_game->get_current_player()->get_buildings().at(p).size(); i++){// ugly but works
                    if(new_game->get_current_player()->get_buildings().at(p)[i]->get_building_type() == "candy road"){ // check its connected to road
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
                    for(const auto it : building_to_add->get_needed_resources()){ // take away needed resources
                        new_game->get_current_player()->RemoveResource(it.first,it.second);
                        new_game->get_current_player()->AddToResourcesUsed(it.first,it.second);
                    }
                    new_game->get_current_player()->AddBuilding(p, building_to_add); // update players buildings map
                    taken_map[p] = new_game->get_current_player();// update taken map
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
            else{// if doesnt have anything at point p
                if(!new_game->get_current_player()->get_first_turn()){ // if nothing at this point cant play house
                    //nothing at point you want to add road
                    ui->infoBrowser->setText(QString("Invalid Placement; First Select Point With Road."));
                }
                else{// players first turn they get to place one house free of charge
                    ui->houseButton->setEnabled(false);
                    ui->mansionButton->setEnabled(false);
                    ui->roadButton->setEnabled(false);
                    Game::set_place_mode(false);
                    ui->centralWidget->setCursor(Qt::ArrowCursor);
                    new_game->get_current_player()->AddBuilding(p, building_to_add); // house to add
                    taken_map[p] = new_game->get_current_player();// update taken map
                    scene->addItem(building_to_add);
                    scene->update();
                    UpdateResources();
                    UpdatePoints();
                    ui->infoBrowser->setText(QString(""));
                    //set to false
                    new_game->get_current_player()->set_first_turn();
                    //turn buttons back on
                    ui->houseButton->setEnabled(true);
                    ui->mansionButton->setEnabled(true);
                    ui->roadButton->setEnabled(true);
                }
            }
            exist = false; // reset vars
            house = false;
        }
    }
}

/*
    label updates for players resources
*/
void MainWindow::UpdateResources()
{
    for(Player *player : new_game->get_player_list()){
        if(player->get_id() == 1){ // player 1
            ui->p1Money->setText(QString::number(player->get_current_resources()[resource::money]));
            ui->p1Sugar->setText(QString::number(player->get_current_resources()[resource::sugar]));
            ui->p1Water->setText(QString::number(player->get_current_resources()[resource::water]));
            std::map<resource,int> total_resources = player->get_total_resources();
            ui->p1TotMoney->setText(QString::number(total_resources[resource::money]));
            ui->p1TotSugar->setText(QString::number(total_resources[resource::sugar]));
            ui->p1TotWater->setText(QString::number(total_resources[resource::water]));
            std::map<resource,int> used_resources = player->get_resources_used();
            ui->p1UsedMoney->setText(QString::number(used_resources[resource::money]));
            ui->p1UsedSugar->setText(QString::number(used_resources[resource::sugar]));
            ui->p1UsedWater->setText(QString::number(used_resources[resource::water]));
        }
        else if(player->get_id() == 2){ // palyer 2
            ui->p2Money->setText(QString::number(player->get_current_resources()[resource::money]));
            ui->p2Sugar->setText(QString::number(player->get_current_resources()[resource::sugar]));
            ui->p2Water->setText(QString::number(player->get_current_resources()[resource::water]));
            std::map<resource,int> total_resources = player->get_total_resources();
            ui->p2TotMoney->setText(QString::number(total_resources[resource::money]));
            ui->p2TotSugar->setText(QString::number(total_resources[resource::sugar]));
            ui->p2TotWater->setText(QString::number(total_resources[resource::water]));
            std::map<resource,int> used_resources = player->get_resources_used();
            ui->p2UsedMoney->setText(QString::number(used_resources[resource::money]));
            ui->p2UsedSugar->setText(QString::number(used_resources[resource::sugar]));
            ui->p2UsedWater->setText(QString::number(used_resources[resource::water]));
        }
        else if(player->get_id() == 3){// player 3
            ui->p3Money->setText(QString::number(player->get_current_resources()[resource::money]));
            ui->p3Sugar->setText(QString::number(player->get_current_resources()[resource::sugar]));
            ui->p3Water->setText(QString::number(player->get_current_resources()[resource::water]));
            std::map<resource,int> total_resources = player->get_total_resources();
            ui->p3TotMoney->setText(QString::number(total_resources[resource::money]));
            ui->p3TotSugar->setText(QString::number(total_resources[resource::sugar]));
            ui->p3TotWater->setText(QString::number(total_resources[resource::water]));
            std::map<resource,int> used_resources = player->get_resources_used();
            ui->p3UsedMoney->setText(QString::number(used_resources[resource::money]));
            ui->p3UsedSugar->setText(QString::number(used_resources[resource::sugar]));
            ui->p3UsedWater->setText(QString::number(used_resources[resource::water]));
        }
    }
    ui->totMoneyLabel->setText(QString::number(new_game->get_total_resources_dist()[resource::money]));
    ui->totSugarLabel->setText(QString::number(new_game->get_total_resources_dist()[resource::sugar]));
    ui->totWaterLabel->setText(QString::number(new_game->get_total_resources_dist()[resource::water]));
}

/*
    When the dice button is clicked
*/
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
    for(QGraphicsEllipseItem *dot : all_dots){ // make the dots black
        dot->setBrush(QBrush(Qt::black));
        scene_dice->addItem(dot);
    }
    if(first_turn){ // if its the first turn we decide the order with dice rolls
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
        //set colors for players label
        QString player_style = "QLabel {  color : %1; }"; // set players text color to their corresponding player color/building color
        for(unsigned int i = 0; i < new_game->get_player_list().size(); i++){
            if(new_game->get_player_list()[i]->get_id() == 1){
                ui->player1_label->setStyleSheet(player_style.arg(new_game->get_player_list()[i]->get_player_color().name()));
            }
            else if(new_game->get_player_list()[i]->get_id() == 2){
                ui->player2_label->setStyleSheet(player_style.arg(new_game->get_player_list()[i]->get_player_color().name()));
            }
            else{
                ui->player3_label->setStyleSheet(player_style.arg(new_game->get_player_list()[i]->get_player_color().name()));
            }
        }
        set_ai_players(); // set the AI players specified before
    }
    ui->diceButton->setEnabled(false);
    ui->endButton->setEnabled(true);
    ui->status_label->setText(QString("Player " +QString::number(new_game->get_current_player()->get_id()) +QString("'s turn")));

    if(new_game->get_current_player()->get_first_turn()){ // if first turn we go into letting them place a house
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
    ui->houseButton->setEnabled(true);
    ui->mansionButton->setEnabled(true);
    ui->roadButton->setEnabled(true);
    ui->endButton->setEnabled(true);
}

/*
    Updates point breakdown for the players and their total points labels
*/
void MainWindow::UpdatePoints(){
    std::map<Player *, int> player_pts = new_game->PlayerPoints();
    std::map<std::string, Player*> record_holders = UpdateRecords();
    for(Player *player : new_game->get_player_list()){ // go through all players
        //sets label to show players points and their point breakdown
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
    for(const auto it : record_holders){// goes through records
        // figure our which player has a current record we are at and update their point breakdown
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
    new_game->UpdateTurnToPoints();
}

/*
    When end button to end turn is clicked
*/
void MainWindow::on_endButton_clicked()
{
    new_game->set_next_player(new_game->get_current_player()); //Get the next player
    ui->status_label->setText(QString("Player " +QString::number(new_game->get_current_player()->get_id()) +QString("'s turn")));
    if(new_game->GameOver()){ //Checks if the game is over
        for(Player *player : new_game->get_player_list()){
            if(player->get_total_points() >= 13){ //If there is a player who has greater than 13 points
                qDebug() << "Player " << player->get_id() <<" won!!!"; //Write to console that that player won
                break;
            }
        }
        QApplication::quit(); //Exit application
    }
    new_game->CollectResources(new_game->get_current_player());
    if(new_game->get_current_player()->get_ai()){ //If the current player is an AI
        std::pair<std::pair<int,int>,Building *> ai_map = new_game->AITurn(); //Get the building to add
        connect(timer,SIGNAL(timeout()),this,SLOT(on_endButton_clicked())); //Connect the timer to the end game function
        AddBuildingSlot(ai_map.second,ai_map.first); //Add the building to the UI
        UpdateResources();
        DrawGraphs();
        timer->start(1500); //End Turn with a delay
    }
    ui->endButton->setEnabled(false); // reset button to ensure next turn is done correctly
    ui->diceButton->setEnabled(true);
    ui->houseButton->setEnabled(false);
    ui->mansionButton->setEnabled(false);
    ui->roadButton->setEnabled(false);
    UpdateResources();
    DrawGraphs();
}

/*
    updates the records info at the bottom right
*/
std::map<std::string, Player*> MainWindow::UpdateRecords(){
    std::map<std::string, Player*> record_holders = new_game->Records(); // gets all the recrods into a map of record and the player that has it
    //Updating the UI
    ui->currRecord->setText(QString("Current Records\n\n") + QString("Longest Road (+1):") + QString(" Player ")
                            + QString::number(record_holders["Longest Road"]->get_id()) + QString("\n")
                            + QString("Largest Dice Sum (+1): ") + QString("Player ") +QString::number(record_holders["Largest Dice Sum"]->get_id()) + QString("\n")
                            + QString("Most Resources (+2): ") +QString("Player ") + QString::number(record_holders["Most Resources"]->get_id()));
    return record_holders;
}

/*
    Does graph drawing for each players graph after a whole round of turns
*/
void MainWindow::DrawGraphs(){
    //Initialization of variables for the graphs
    QBarSeries *series_p1 = new QBarSeries();
    QBarSeries *series_p2 = new QBarSeries();
    QBarSeries *series_p3 = new QBarSeries();
    QBarSet *set1 = new QBarSet("Player 1");
    QBarSet *set2 = new QBarSet("Player 2");
    QBarSet *set3 = new QBarSet("Player 3");
    QStringList p1_categories;
    QStringList p2_categories;
    QStringList p3_categories;
    for(Player *player : new_game->get_player_list()){ //For each player
        for(const auto turn_to_points : player->get_turn_to_points()){ //turn -> points of the player object
            if(player->get_id() == 1){
                *set1 << turn_to_points.second; //Append amount of points to the set
                p1_categories << QString("Turn: ") + QString::number(turn_to_points.first); //Used for the x-axis which displays turn count
            }
            else if(player->get_id() == 2){
                *set2 << turn_to_points.second; //Append amount of points to the set
                p2_categories <<  QString("Turn: ") + QString::number(turn_to_points.first); //Used for the x-axis which displays turn count
            }
            else if(player->get_id() == 3){
                *set3 << turn_to_points.second; //Append amount of points to the set
                p3_categories <<  QString("Turn: ") + QString::number(turn_to_points.first); //Used for the x-axis which displays turn count
            }
        }
    }
    series_p1->append(set1);
    series_p2->append(set2);
    series_p3->append(set3);

    QBarCategoryAxis *p1_axis = new QBarCategoryAxis();
    p1_axis->append(p1_categories);
    QBarCategoryAxis *p2_axis = new QBarCategoryAxis();
    p2_axis->append(p2_categories);
    QBarCategoryAxis *p3_axis = new QBarCategoryAxis();
    p3_axis->append(p3_categories);

    //Player 1 Chart
    QChart *chart_p1 = new QChart();
    chart_p1->addSeries(series_p1);
    chart_p1->setTitle("Points Over Turns");
    chart_p1->setAnimationOptions(QChart::AllAnimations);
    chart_p1->legend()->setVisible(true);
    chart_p1->legend()->setAlignment(Qt::AlignBottom);
    chart_p1->createDefaultAxes();
    chart_p1->setAxisX(p1_axis,series_p1);


    //Player 2 Chart
    QChart *chart_p2 = new QChart();
    chart_p2->addSeries(series_p2);
    chart_p2->setTitle("Points Over Turns");
    chart_p2->setAnimationOptions(QChart::AllAnimations);
    chart_p2->legend()->setVisible(true);
    chart_p2->legend()->setAlignment(Qt::AlignBottom);
    chart_p2->createDefaultAxes();
    chart_p2->setAxisX(p2_axis,series_p2);

    //Player 3 Chart
    QChart *chart_p3 = new QChart();
    chart_p3->addSeries(series_p3);
    chart_p3->setTitle("Points Over Turns");
    chart_p3->setAnimationOptions(QChart::AllAnimations);
    chart_p3->legend()->setVisible(true);
    chart_p3->legend()->setAlignment(Qt::AlignBottom);
    chart_p3->createDefaultAxes();
    chart_p3->setAxisX(p3_axis,series_p3);

    QChartView *chartview_p1 = new QChartView(chart_p1);
    chartview_p1->setContentsMargins(QMargins(0,0,0,0));
    chartview_p1->setRenderHint(QPainter::Antialiasing);
    chartview_p1->setFixedSize(ui->p1Graph->width(),ui->p1Graph->height());
    p1_scene_bar->addWidget(chartview_p1);

    QChartView *chartview_p2 = new QChartView(chart_p2);
    chartview_p2->setContentsMargins(QMargins(0,0,0,0));
    chartview_p2->setRenderHint(QPainter::Antialiasing);
    chartview_p2->setFixedSize(ui->p2Graph->width(),ui->p2Graph->height());
    p2_scene_bar->addWidget(chartview_p2);

    QChartView *chartview_p3 = new QChartView(chart_p3);
    chartview_p3->setContentsMargins(QMargins(0,0,0,0));
    chartview_p3->setRenderHint(QPainter::Antialiasing);
    chartview_p3->setFixedSize(ui->p3Graph->width(),ui->p3Graph->height());
    p3_scene_bar->addWidget(chartview_p3);

    p1_scene_bar->update();
    p2_scene_bar->update();
    p3_scene_bar->update();
}

/*
    When player 1's graph button is clicked show the graph
*/
void MainWindow::on_p1_graph_button_clicked()
{
    if(p1_graph_button_clicked){
        p1_graph_button_clicked = false;
        ui->p1Graph->setVisible(false);
    }
    else{
        p1_graph_button_clicked = true;
        ui->p1Graph->setVisible(true);
    }
}

/*
    When player 2's graph button is clicked show the graph
*/
void MainWindow::on_p2_graph_button_clicked()
{
    if(p2_graph_button_clicked){
        p2_graph_button_clicked = false;
        ui->p2Graph->setVisible(false);
    }
    else{
        p2_graph_button_clicked = true;
        ui->p2Graph->setVisible(true);
    }
}

/*
    When player 3's graph button is clicked show the graph
*/
void MainWindow::on_p3_graph_button_clicked()
{
    if(p3_graph_button_clicked){
        p3_graph_button_clicked = false;
        ui->p3Graph->setVisible(false);
    }
    else{
        p3_graph_button_clicked = true;
        ui->p3Graph->setVisible(true);
    }
}

/*
    checks that a valid input is given and then sets the amount of ai var to that input
*/
void MainWindow::on_start_button_clicked()
{
    if(ui->start_input->text() != "3" && ui->start_input->text() != "2" && ui->start_input->text() != "1" && ui->start_input->text() != "0"){ // ensure input is within bounds
        ui->status_label->setText(QString("Invalid! Please Enter AI Amount, (0-3)"));
    }
    else{
        ai_amount = ui->start_input->text().toInt();
        //change players ai bools
        ui->start_button->hide();
        ui->start_input->hide(); // labels no longer needed get hidden
        ui->diceButton->setEnabled(true); // start game
        ui->status_label->setText(QString("Roll Dice To See Who Goes First!"));
    }
}

/*
    takes the amount of ai var and sets player objects ai varable depending
*/
void MainWindow::set_ai_players()
{
    if(ai_amount == 3){ // 3 ai make all ai
        for(unsigned int i = 0; i < new_game->get_player_list().size(); i++){
            new_game->get_player_list()[i]->set_ai();
        }
    }
    else if (ai_amount == 2){ // 2 ai make player 3 and 2 ai
        for(unsigned int i = 0; i < new_game->get_player_list().size(); i++){
            if(new_game->get_player_list()[i]->get_id() == 3){
                new_game->get_player_list()[i]->set_ai();
            }
            if(new_game->get_player_list()[i]->get_id() == 2){
                new_game->get_player_list()[i]->set_ai();
            }
        }
    }
    else if (ai_amount == 1){ // 1 ai make player 3 an ai
        for(unsigned int i = 0; i < new_game->get_player_list().size(); i++){
            if(new_game->get_player_list()[i]->get_id() == 3){
                new_game->get_player_list()[i]->set_ai();
            }
        }
    } // otherwise no ai's
}
