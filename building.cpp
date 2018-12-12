#include "building.h"
#include <cstdlib>
#include <ctime>
#include <QColor>
#include <cmath>
#include <iostream>
#include <QtWidgets>
#include "hexagon.h"
#include <vector>

/*
    Base Building Constructor.
*/
Building::Building(const int x, const int y)
{
    x_ = x;
    y_ = y;
}

/*
    creates the bound of the building object on UI
*/
QRectF Building::boundingRect() const
{
    return QRectF(x_, y_, width_, width_);
}

/*
    @return the shape of the building this case a circle
*/
QPainterPath Building::shape() const
{
    QPainterPath path;
    path.addEllipse(x_, y_, width_, width_);
    return path;
}

/*
    Set the brush we will use to color in the shape
*/
void Building::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);


    QBrush b = painter->brush();
    painter->setBrush(QBrush(color_.dark(option->state & QStyle::State_Sunken ? 120 : 100)));

    painter->drawEllipse(QRect(this->x_, this->y_, this->width_, this->width_));
    painter->setBrush(b);
}

/*
    Sets the need resources, points awarded and coordinate of Chocolate House
*/
ChocolateHouse::ChocolateHouse(int x, int y) : Building(x, y){
    needed_resources_[resource::money] = 2;
    needed_resources_[resource::sugar] = 2;
    needed_resources_[resource::water] = 2;
    x_ = x;
    y_ = y;
    points_ = 2;
}

/*
    Sets the need resources, points awarded and coordinate of Chocolate Mansion
*/
ChocolateMansion::ChocolateMansion(int x, int y) : Building(x, y){
    needed_resources_[resource::money] = 3;
    needed_resources_[resource::sugar] = 3;
    needed_resources_[resource::water] = 3;
    x_ = x;
    y_ = y;
    points_ = 3;
}

/*
    @return shape of mansion which is a rectangle
*/
QPainterPath ChocolateMansion::shape() const
{
    QPainterPath path;
    path.addRect(x_, y_, width_, width_);
    return path;
}

/*
    paint the actual rect with color_ which is a player's specific color
*/
void ChocolateMansion::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QBrush b = painter->brush();
    painter->setBrush(QBrush(color_.dark(option->state & QStyle::State_Sunken ? 120 : 100)));

    painter->drawRect(QRect(this->x_, this->y_, this->width_, this->width_));
    painter->setBrush(b);
}

/*
    Sets needed resource, points awarded, and points for a Candy Road
*/
Road::Road(int x1, int y1,int x2, int y2) : Building(x1, y1)
{
    needed_resources_[resource::money] = 1;
    needed_resources_[resource::sugar] = 1;
    needed_resources_[resource::water] = 1;
    points_ = 0;
    x1_ = x1;
    y1_ = y1;
    x2_ = x2;
    y2_ = y2;
}

/*
    Bounds the candy road on UI
*/
QRectF Road::boundingRect() const
{
    return QRectF(x_, y_, width_, width_);
}

/*
    @return shape of road which is a line
*/
QPainterPath Road::shape() const
{
    QPainterPath path;
    path.addEllipse(x_, y_, width_, width_);
    return path;
}

/*
    Draws the road and pains it in with player's color
*/
void Road::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);
    QBrush b = painter->brush();
    painter->setBrush(QBrush(color_.dark(option->state & QStyle::State_Sunken ? 120 : 100)));

    painter->setPen(QPen(color_, 7, Qt::SolidLine, Qt::SquareCap));
    painter->drawLine(x1_, y1_, x2_, y2_);
    painter->setBrush(b);
}


