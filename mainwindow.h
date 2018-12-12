#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QWidget>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "game.h"
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void UpdateResources();
    std::map<std::string, Player*> UpdateRecords();
    void UpdatePoints();
    bool EnoughResources(Building *building_to_check);
    void DrawGraphs();
    void set_ai_players();

private slots: // slots for buttons and for adding building on a players turn
    void on_houseButton_clicked();
    void on_roadButton_clicked();
    void on_mansionButton_clicked();
    void AddBuildingSlot(Building *building_to_add, std::pair<int,int> p);
    void on_diceButton_clicked();
    void on_endButton_clicked();
    void on_p1_graph_button_clicked();
    void on_p2_graph_button_clicked();
    void on_p3_graph_button_clicked();
    void on_start_button_clicked();

private:
    Ui::MainWindow *ui;
    Game *new_game; //Game instance
    std::map<std::pair<int,int>, Player *> taken_map;
    QGraphicsScene *scene;
    QGraphicsScene *scene_dice;
    QGraphicsScene *p1_scene_bar; //Scene of the bar graph
    QGraphicsView *p1_view_graph; //View with the bar graph
    QGraphicsScene *p2_scene_bar; //Scene of the bar graph
    QGraphicsView *p2_view_graph; //View with the bar graph
    QGraphicsScene *p3_scene_bar; //Scene of the bar graph
    QGraphicsView *p3_view_graph; //View with the bar graph
    bool p1_graph_button_clicked = false; // bools to help with point graph pop up
    bool p2_graph_button_clicked = false;
    bool p3_graph_button_clicked = false;
    QTimer *timer = new QTimer(this);
    bool first_turn = true; // bool to aid with knowing if its the first turn of game
    int ai_amount = 0; // input var that will let us know how many AI players to have (0 to 3)
    float current_width = 0.0; //The current x position of the bar graph

};

#endif // MAINWINDOW_H
