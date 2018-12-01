#ifndef BUILDING_H
#define BUILDING_H
#include <QGraphicsItem>
#include <QColor>
#include <vector>

enum class resource {sugar,water,money}; //Resource enums

class Building : public QObject, public QGraphicsItem {
    Q_OBJECT

public:
    Building(std::vector<resource> needed_resources, int points, int x, int y, QColor color);
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget) override;

private:
    std::vector<resource> needed_resources_; //Vector that contains the amount of resources needed to build this building
    int points_; //Points awarded for having this building
    int x_; //X-coordinate of the building
    int y_; //y-coordinate of the building
    QColor color_; //Color of the building
    static const int width_ = 20; //Width of the building
};

//class Road : public QObject, public QGraphicsItem{
//    Q_OBJECT
//public:
//    QRectF boundingRect() const override;
//    QPainterPath shape() const override;
//    void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget) override;
//private:
//};

#endif // BUILDING_H
