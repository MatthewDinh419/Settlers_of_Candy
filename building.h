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
    Building(int x, int y);
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget) override;
    std::map<resource,int> get_needed_resources(){return needed_resources_;} // gets the needed resources of a particular buidling based on type string
    virtual std::string get_building_type(){return "";} // returns string of what building subclass a building is
    virtual std::pair<int,int> get_x_y(){return std::make_pair(x_,y_);} // returns the xy cord of a building
    int get_points(){return points_;} // gets the points a specific building awards
    void set_color(QColor player_color){color_ = player_color;} // sets each building to a single color depending on player's color
protected:
    std::map<resource,int> needed_resources_;//Vector that contains the amount of resources needed to build this building
    int points_; //Points awarded for having this building
    int x_; //X-coordinate of the building
    int y_; //y-coordinate of the building
    QColor color_; //Color of the building
    static const int width_ = 20; //Width of the building
};

class ChocolateHouse : public  Building{
public:
    ChocolateHouse(int x, int y);
    std::string get_building_type(){return "choco house";}
};

class ChocolateMansion : public Building{
public:
    ChocolateMansion(int x, int y);
    QPainterPath shape() const override; // change shape to square for mansion
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget) override;
    std::string get_building_type(){return "choco mansion";}
};

class Road : public Building{
public:
    Road(int x1, int y1, int x2, int y2);
    QRectF boundingRect() const override;
    QPainterPath shape() const override; // change shape to line to go over hexagon edge for road
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget) override;
    std::string get_building_type(){return "candy road";}
    virtual std::pair<int,int> get_x_y(){return std::make_pair(x2_,y2_);} // changed to return the second point of road (end point)

private:
    int x1_; // for the two ends of the road which extends between two lines
    int y1_;
    int x2_;
    int y2_;
};

#endif // BUILDING_H
