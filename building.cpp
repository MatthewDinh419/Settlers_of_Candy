#include "building.h"
#include <cstdlib>
#include <ctime>
#include <QColor>
#include <cmath>
#include <iostream>
#include <QtWidgets>
#include "hexagon.h"
#include <vector>

Building::Building(std::vector<resource> needed_resources,  int points, QColor color, const int x, const int y)
{
    needed_resources_ = needed_resources;
    points_ = points;
    x_ = x;
    y_ = y;
    this->color_ = color;
}

QRectF Building::boundingRect() const
{
    return QRectF(x_, y_, width_, width_);
}

QPainterPath Building::shape() const
{
    QPainterPath path;
    path.addEllipse(x_, y_, width_, width_);
    return path;
}


void Building::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);


    QBrush b = painter->brush();
    painter->setBrush(QBrush(color_.dark(option->state & QStyle::State_Sunken ? 120 : 100)));

    painter->drawEllipse(QRect(this->x_, this->y_, this->width_, this->width_));
    painter->setBrush(b);
}

Road::Road(std::vector<resource> needed_resources, int points,QColor color,int x1, int y1,int x2, int y2)
    : Building(needed_resources, points, color,x1, y1)
{
    needed_resources_ = needed_resources;
    points_ = points;
    x1_ = x1;
    y1_ = y1;
    x2_ = x2;
    y2_ = y2;
    this->color_ = color;
}

QRectF Road::boundingRect() const
{
    return QRectF(x_, y_, width_, width_);
}

QPainterPath Road::shape() const
{
    QPainterPath path;
    path.addEllipse(x_, y_, width_, width_);
    return path;
}


void Road::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);
    QBrush b = painter->brush();
    painter->setBrush(QBrush(color_.dark(option->state & QStyle::State_Sunken ? 120 : 100)));

    painter->setPen(QPen(Qt::red, 7, Qt::SolidLine, Qt::SquareCap));
    painter->drawLine(x1_, y1_, x2_, y2_);
    painter->setBrush(b);
}


