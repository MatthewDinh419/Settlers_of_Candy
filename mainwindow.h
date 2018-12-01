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

private slots:
    void on_houseButton_clicked();

    void on_roadButton_clicked();

    void on_mansionButton_clicked();

    void AddBuildingSlot(Building *building_to_add);
private:
    Ui::MainWindow *ui;
    Game *new_game;
    QGraphicsScene *scene; //Scene with all the cells
};

#endif // MAINWINDOW_H
