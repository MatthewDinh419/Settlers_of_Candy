#include "hexagon.h"
#include <QtWidgets>
#include <QColor>
#include <utility>
#include <QDebug>
#include "game.h"

using namespace std;

//init static vars
pair<int,int> Hexagon::prev_corner_clicked = std::make_pair(-1,-1);
int Hexagon::id_ = 0;

/*
    Hexagon constructor sets its color resource and 6 points
*/
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

/*
    Hexagon Factory

    @return the new Hexagon object depending on tile_chocie
*/
Hexagon *Hexagon::CreateHexagon(const pair <int, int> p1, const pair <int, int> p2, const pair <int, int> p3,
                                const pair <int, int> p4, const pair <int, int> p5, const pair <int, int> p6, int tile_choice){
    switch(tile_choice)
    {
        case 0:
            id_ += 1;
            return new Hexagon(QColor(0,236,46),p1,p2,p3,p4,p5,p6,id_,resource::money);
        case 1:
            id_ += 1;
            return new Hexagon(QColor(241,237,237),p1,p2,p3,p4,p5,p6,id_,resource::sugar);
        case 2:
            id_ += 1;
            return new Hexagon(QColor(0,212,255),p1,p2,p3,p4,p5,p6,id_,resource::water);
    }
}

/*
    Bounding the hexagon based on path returned from shape which
    is a polygon with six poitns
*/
QRectF Hexagon::boundingRect() const
{
    QPainterPath path = shape();
    return path.boundingRect();
}

/*
 * Creates the shape for the hexagon click box
 */
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

/*
    paints the edges between points of hexagon and
    draws hexagon with its specified player_color
*/
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

/*
    runs when a Hexagon point is clicked and emits depending on what place mode we are in
*/
void Hexagon::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    float mouse_press_x = event->pos().x();
    float mouse_press_y = event->pos().y();
    if(Game::get_place_mode()){ //If hexagon is clicked in place mode
        for(pair<int,int>point_pairs : Game::get_all_corners()){ //Goes through all the corners to see if where clicked is a corner
            if(mouse_press_x >= point_pairs.first - 10 && mouse_press_x <= point_pairs.first + 10 &&
                    mouse_press_y >= point_pairs.second - 10 && mouse_press_y <= point_pairs.second + 10){ // opens bounds so that a bit off the point will still click
                if(Game::get_building_string() == "choco house"){ // if in house palce mode
                    ChocolateHouse *temp_building = new ChocolateHouse(point_pairs.first-10,point_pairs.second-10);
                    emit AddBuilding(temp_building, point_pairs); // emit with the building type and the point clicked
                    break;
                }
                else if(Game::get_building_string() == "choco mansion"){ // if in mansion place mode
                    ChocolateMansion *temp_building = new ChocolateMansion(point_pairs.first-10,point_pairs.second-10);
                    emit AddBuilding(temp_building, point_pairs);// emit with the building type and the point clicked
                    break;
                }
                else if(Game::get_building_string() == "candy road"){ // if in candy place mode
                    if(Hexagon::prev_corner_clicked.first == -1 && Hexagon::prev_corner_clicked.second == -1){ // if our prev point var is null current point set as prev point
                        Hexagon::prev_corner_clicked = point_pairs;
                        break; // stop and when another point is clicked this if will skip
                    }
                    else{
                        // temp_prev so I can add that to a point to building map in mainwindow
                        pair<int,int> temp_prev = Hexagon::prev_corner_clicked;
                        //can't be the same point
                        if(Hexagon::prev_corner_clicked != point_pairs){
                           //must be point next to it(an edge) using bounds to check
                           if(point_pairs.first > Hexagon::prev_corner_clicked.first){
                               if(point_pairs.second > Hexagon::prev_corner_clicked.second){
                                   if(point_pairs.first <= Hexagon::prev_corner_clicked.first + 60
                                           && point_pairs.second <= Hexagon::prev_corner_clicked.second + 60){ // height and width bounds
                                       Road *temp_road = new Road(Hexagon::prev_corner_clicked.first,Hexagon::prev_corner_clicked.second,
                                                                  point_pairs.first,point_pairs.second); // set the road to add
                                       Hexagon::prev_corner_clicked = std::make_pair(-1,-1); // reset the prev corner for new road
                                       emit AddBuilding(temp_road, temp_prev);// emit with the road and the first point that was clicked
                                       break;
                                   }
                               }
                               else{ // y is init smaller
                                   if(point_pairs.first <= Hexagon::prev_corner_clicked.first + 60
                                           && point_pairs.second >= Hexagon::prev_corner_clicked.second - 60){
                                       Road *temp_road = new Road(Hexagon::prev_corner_clicked.first,Hexagon::prev_corner_clicked.second,
                                                                  point_pairs.first,point_pairs.second);
                                       Hexagon::prev_corner_clicked = std::make_pair(-1,-1);
                                       emit AddBuilding(temp_road, temp_prev);
                                       break;
                                   }
                               }
                           }
                           else{ // x is init smaller
                               if(point_pairs.second > Hexagon::prev_corner_clicked.second){
                                   if(point_pairs.first >= Hexagon::prev_corner_clicked.first - 60
                                           && point_pairs.second <= Hexagon::prev_corner_clicked.second + 60){
                                       Road *temp_road = new Road(Hexagon::prev_corner_clicked.first,Hexagon::prev_corner_clicked.second,
                                                                  point_pairs.first,point_pairs.second);
                                       Hexagon::prev_corner_clicked = std::make_pair(-1,-1);
                                       emit AddBuilding(temp_road, temp_prev);
                                       break;
                                   }
                               }
                               else{
                                   if(point_pairs.first >= Hexagon::prev_corner_clicked.first - 60
                                           && point_pairs.second >= Hexagon::prev_corner_clicked.second - 60){
                                       Road *temp_road = new Road(Hexagon::prev_corner_clicked.first,Hexagon::prev_corner_clicked.second,
                                                                  point_pairs.first,point_pairs.second);
                                       Hexagon::prev_corner_clicked = std::make_pair(-1,-1);
                                       emit AddBuilding(temp_road, temp_prev);
                                       break;
                                   }
                               }
                           }
                       }
                    }
                }
            }
        }
    }
}

