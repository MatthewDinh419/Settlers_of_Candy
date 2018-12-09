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
    void RemoveResource(resource resource_to_remove);
    int get_id(){return player_id_;}
private:
    int player_id_;
    std::vector<resource> current_resources; //Player's current resources
};

#endif // PLAYER_H
