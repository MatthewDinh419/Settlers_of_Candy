#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "hexagon.h"
#include <QWidget>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene; //Scene with all the cells
};

#endif // MAINWINDOW_H
