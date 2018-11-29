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


    QBrush b = painter->brush();
    painter->setBrush(QBrush(color_));

    painter->drawRect(QRect(this->x_, this->y_, this->width_, this->width_));
    painter->setBrush(b);
}
