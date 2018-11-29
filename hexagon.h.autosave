#ifndef HEXAGON_H
#define HEXAGON_H
#include <QGraphicsItem>
#include <QColor>
#include <utility>

using namespace std;

class Hexagon : public QObject, public QGraphicsItem {
    Q_OBJECT

public:
    Hexagon(QColor color, const pair <int, int> p1, const pair <int, int> p2, const pair <int, int> p3,
                     const pair <int, int> p4, const pair <int, int> p5, const pair <int, int> p6, int id);
    QRectF boundingRect() const override;
//    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget) override;
    pair <int, int> get_p1() const {return p1_;}
    pair <int, int> get_p2() const {return p2_;}
    pair <int, int> get_p3() const {return p3_;}
    pair <int, int> get_p4() const {return p4_;}
    pair <int, int> get_p5() const {return p5_;}
    pair <int, int> get_p6() const {return p6_;}
    int get_id() {return id_;}

private:
    pair <int, int> p1_;
    pair <int, int> p2_;
    pair <int, int> p3_;
    pair <int, int> p4_;
    pair <int, int> p5_;
    pair <int, int> p6_;
    int id_;
    QColor color_;
};

#endif // HEXAGON_H
