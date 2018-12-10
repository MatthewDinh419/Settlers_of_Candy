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

private:
    Ui::MainWindow *ui;
    Game *new_game; //Game instance
    bool first_turn = true;
    QGraphicsScene *scene;
    QGraphicsScene *scene_dice;
};

#endif // MAINWINDOW_H
