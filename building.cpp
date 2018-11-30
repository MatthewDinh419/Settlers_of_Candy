#include "building.h"
#include <cstdlib>
#include <ctime>
#include <QColor>
#include <cmath>
#include <iostream>
#include <QtWidgets>
#include "hexagon.h"
#include <vector>

Building::Building(std::vector<resource> needed_resources, const int points, const int x, const int y, QColor color)
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


