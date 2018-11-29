#ifndef BUILDING_H
#define BUILDING_H
#include <QGraphicsItem>
#include <QColor>
#include <vector>
#include "hexagon.h"
#endif // BUILDING_H

class Building : public QObject, public QGraphicsItem {
    Q_OBJECT
public:
    building(std::vector<resource> needed_resources, int points);
private:
    std::vector<resource> needed_resources_;
    int points_;
};
