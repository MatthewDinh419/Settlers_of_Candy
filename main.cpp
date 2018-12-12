/*
Eric Kim and Matthew Dinh
Homework 5
This program is a take on Settlers of Catan
called Settlers of Candy
*/

#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
