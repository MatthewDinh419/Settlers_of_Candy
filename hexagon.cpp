#include "hexagon.h"
#include <QtWidgets>
#include <QColor>
#include <utility>
#include <QDebug>
using namespace std;

Hexagon::Hexagon(QColor color, const pair <int, int> p1, const pair <int, int> p2, const pair <int, int> p3,
                 const pair <int, int> p4, const pair <int, int> p5, const pair <int, int> p6, int id, resource resource_of_tile)
{
    color_ = color;
    p1_ = p1;
    p2_ = p2;
    p3_ = p3;
    p4_ = p4;
    p5_ = p5;
    p6_ = p6;
    id_ = id;
    resource_tile = resource_of_tile;
}

//hitbox for hex is the rect in middle
QRectF Hexagon::boundingRect() const
{
    QPainterPath path = shape();
    return path.boundingRect();
}

QPainterPath Hexagon::shape() const{
    QPainterPath path;
    QPolygon poly;
    poly << QPoint(this->p1_.first, this->p1_.second);
    poly << QPoint(this->p2_.first, this->p2_.second);
    poly << QPoint(this->p3_.first, this->p3_.second);
    poly << QPoint(this->p4_.first, this->p4_.second);
    poly << QPoint(this->p5_.first, this->p5_.second);
    poly << QPoint(this->p6_.first, this->p6_.second);
    path.addPolygon(poly);

    return path;
}
void Hexagon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);

    //set poly points
    QPolygon poly;
    poly << QPoint(this->p1_.first, this->p1_.second);
    poly << QPoint(this->p2_.first, this->p2_.second);
    poly << QPoint(this->p3_.first, this->p3_.second);
    poly << QPoint(this->p4_.first, this->p4_.second);
    poly << QPoint(this->p5_.first, this->p5_.second);
    poly << QPoint(this->p6_.first, this->p6_.second);

    //make pen
    QPen p;
    p.setWidth(2);
    p.setColor(Qt::black);
    p.setJoinStyle(Qt::RoundJoin);
    painter->setPen(p);

    //draw in the poly
    QBrush b = painter->brush();
    painter->setBrush(QBrush(color_));
    QPainterPath path;

    //draw poly
    painter->drawPolygon(poly);

    painter->fillPath(path, b);
    painter->setBrush(b);
}

void Hexagon::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << event->pos();
    update();
}

