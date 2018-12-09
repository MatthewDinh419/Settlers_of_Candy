#ifndef PLAYER_H
#define PLAYER_H
#include <map>
#include "hexagon.h"
#include "building.h"

class Player{
public:
    Player(int player_id);
    std::vector<resource> get_current_resources(){return current_resources;}
    void AddResource(resource resource_to_add){current_resources.push_back(resource_to_add);}
    void AddBuilding(std::pair <int,int> point, Building *b){buildings_.insert({point,b});}
    void RemoveResource(resource resource_to_remove);
    int get_id(){return player_id_;}
    std::map<std::pair <int,int>, Building *> get_buildings(){return buildings_;}
private:
    int player_id_;
    std::vector<resource> current_resources; //Player's current resources
    std::map<std::pair<int,int>, Building *> buildings_; // players buildings
};

#endif // PLAYER_H
