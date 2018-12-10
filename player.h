#ifndef PLAYER_H
#define PLAYER_H
#include <map>
#include "hexagon.h"
#include "building.h"

class Player{
public:
    Player(int player_id);
    std::map<resource,int> get_current_resources(){return current_resources;}
    void AddResource(resource resource_to_add, int quantity){current_resources[resource_to_add] += quantity;}
    void AddBuilding(std::pair <int,int> point, Building *b){buildings_.insert({point,b});}
    void RemoveResource(resource resource_to_remove, int quantity);
    int get_id(){return player_id_;}
    std::map<std::pair <int,int>, Building *> get_buildings(){return buildings_;}
private:
    int player_id_;
    std::map<resource,int> current_resources; //Player's current resources
    std::map<std::pair<int,int>, Building *> buildings_; // players buildings
};

#endif // PLAYER_H
