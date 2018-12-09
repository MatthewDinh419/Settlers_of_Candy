#ifndef HEXAGON_H
#define HEXAGON_H
#include <QGraphicsItem>
#include <QColor>
#include "building.h"
using namespace std;
class Hexagon : public QObject, public QGraphicsItem {
    Q_OBJECT

public:
    Hexagon(QColor color, const pair <int, int> p1, const pair <int, int> p2, const pair <int, int> p3,
                     const pair <int, int> p4, const pair <int, int> p5, const pair <int, int> p6, int id, resource resource_of_tile);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget) override;
    QPainterPath shape() const override;
    pair <int, int> get_p1() const {return p1_;}
    pair <int, int> get_p2() const {return p2_;}
    pair <int, int> get_p3() const {return p3_;}
    pair <int, int> get_p4() const {return p4_;}
    pair <int, int> get_p5() const {return p5_;}
    pair <int, int> get_p6() const {return p6_;}
    int get_x() const {return x_;}
    int get_y() const {return y_;}
    int get_id() {return id_;}

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

signals:
    void AddBuilding(Building *building_to_add, std::pair<int,int> p);

private:
    int x_; //x-coordinate of the hexagon
    int y_; //y-coordinate of the hexagon
    int id_; //id of the hexagon
    resource resource_tile; //Resource of the hexagon
    static const int width_ = 20; //Width of the hexagon
    QColor color_; //color of the hexagon
    //The corners of the hexagon:
    pair <int, int> p1_;
    pair <int, int> p2_;
    pair <int, int> p3_;
    pair <int, int> p4_;
    pair <int, int> p5_;
    pair <int, int> p6_;
    static pair<int,int> prev_corner_clicked;
};

#endif // HEXAGON_H
