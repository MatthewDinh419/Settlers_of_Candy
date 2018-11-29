#ifndef BUILDING_H
#define BUILDING_H
#include <QGraphicsItem>
#include <QColor>
#include <vector>
#include "hexagon.h"

class Building : public QObject, public QGraphicsItem {
    Q_OBJECT

public:
    Building(std::vector<resource> needed_resources, int points, int x, int y, QColor color);
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget) override;

private:
    std::vector<resource> needed_resources_;
    int points_;
    int x_;
    int y_;
    QColor color_;
    static const int width_ = 20;
};
#endif // BUILDING_H
