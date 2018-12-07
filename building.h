#ifndef BUILDING_H
#define BUILDING_H
#include <QGraphicsItem>
#include <QColor>
#include <vector>
#include <QDebug>

enum class resource {sugar,water,money}; //Resource enums

class Building : public QObject, public QGraphicsItem {
    Q_OBJECT

public:
    Building(QColor color, int x, int y);
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget) override;

protected:
    std::vector<resource> needed_resources_; //Vector that contains the amount of resources needed to build this building
    int points_; //Points awarded for having this building
    int x_; //X-coordinate of the building
    int y_; //y-coordinate of the building
    QColor color_; //Color of the building
    static const int width_ = 20; //Width of the building
};

class ChocolateHouse : public  Building{
public:
    ChocolateHouse(QColor color, int x, int y);
};

class ChocolateMansion : public Building{
public:
    ChocolateMansion(QColor color, int x, int y);
};

class Road : public Building{
public:
    Road(QColor color,int x1, int y1, int x2, int y2);
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget) override;
    void print_values(){qDebug() << x1_ << y1_ << x2_ << y2_;}
private:
    int x1_;
    int y1_;
    int x2_;
    int y2_;
};

#endif // BUILDING_H
