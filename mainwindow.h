#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QWidget>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "game.h"


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
private slots:
    void on_houseButton_clicked();

    void on_roadButton_clicked();

    void on_mansionButton_clicked();

    void AddBuildingSlot(Building *building_to_add, std::pair<int,int> p);

    void on_diceButton_clicked();

    bool EnoughResources(Building *building_to_check);

    void UpdatePoints();

    void on_endButton_clicked();

    std::map<std::string, Player*> UpdateRecords();

    void DrawGraphs();

    void p1GraphHoverEvent(){qDebug() << "test";}

    void on_p1_graph_button_clicked();

    void on_p2_graph_button_clicked();

    void on_p3_graph_button_clicked();

private:
    Ui::MainWindow *ui;
    Game *new_game; //Game instance
    bool first_turn = true;
    std::map<std::pair<int,int>, Player *> taken_map;
    QGraphicsScene *scene;
    QGraphicsScene *scene_dice;
    QGraphicsScene *p1_scene_bar; //Scene of the bar graph
    QGraphicsView *p1_view_graph; //View with the bar graph
    QGraphicsScene *p2_scene_bar; //Scene of the bar graph
    QGraphicsView *p2_view_graph; //View with the bar graph
    QGraphicsScene *p3_scene_bar; //Scene of the bar graph
    QGraphicsView *p3_view_graph; //View with the bar graph
    float current_width = 0.0; //The current x position of the bar graph
    bool p1_graph_button_clicked = false;
    bool p2_graph_button_clicked = false;
    bool p3_graph_button_clicked = false;
};

#endif // MAINWINDOW_H
