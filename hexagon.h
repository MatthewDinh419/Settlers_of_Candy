#ifndef HEXAGON_H
#define HEXAGON_H
#include <QGraphicsItem>
#include <QColor>
#include <vector>

enum class resource {sugar,water,money};

class Hexagon : public QObject, public QGraphicsItem {
    Q_OBJECT

public:
    Hexagon(QColor color, const int x, const int y, int id);
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget) override;
    int get_x() const {return x_;}
    int get_y() const {return y_;}
    int get_id() {return id_;}

private:
    int x_;
    int y_;
    int id_;
    static const int width_ = 20; //Width of the square
    QColor color_;
};

#endif // HEXAGON_H
