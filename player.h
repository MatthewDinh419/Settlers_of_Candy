#ifndef PLAYER_H
#define PLAYER_H
#include <map>
#include "hexagon.h"
#include "building.h"

class Player{
public:
    Player();
private:
    std::map<Building,Hexagon> current_buildings; //Player's current buildings relative to the hexagon
    std::vector<resource> current_resources; //Player's current resources
};

#endif // PLAYER_H
