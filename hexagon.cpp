#include "hexagon.h"
#include <QtWidgets>
#include <QColor>

Hexagon::Hexagon(QColor color, const int x, const int y, int id)
{
    color_ = color;
    x_ = x;
    y_ = y;
    id_ = id;
}

QRectF Hexagon::boundingRect() const
{
    return QRectF(x_, y_, width_, width_);
}

QPainterPath Hexagon::shape() const
{
    QPainterPath path;
    path.addRect(x_, y_, width_, width_);
    return path;
}

void Hexagon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);

    //set poly points
    QPolygon poly;
    poly << QPoint(25, 0);
    poly << QPoint(0,25);
    poly << QPoint(0, 75);
    poly << QPoint(25, 100);
    poly << QPoint(75, 100);
    poly << QPoint(100, 75);
    poly << QPoint(100, 25);
    poly << QPoint(75, 0);

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
    path.addPolygon(poly);

    //draw poly
    painter->drawPolygon(poly);

    painter->fillPath(path, b);
    painter->setBrush(b);
}
