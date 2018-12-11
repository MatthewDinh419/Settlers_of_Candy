#ifndef PLAYER_H
#define PLAYER_H
#include <map>
#include "hexagon.h"
#include "building.h"

class Player{
public:
    Player(int player_id, QColor player_color);
    std::map<resource,int> get_current_resources(){return current_resources;}
    void AddResource(resource resource_to_add, int quantity){current_resources[resource_to_add] += quantity;}
    void AddBuilding(std::pair <int,int> point, Building *b);
    void RemoveResource(resource resource_to_remove, int quantity);
    int get_id(){return player_id_;}
    std::map<std::pair<int,int>, std::vector<Building *>> get_buildings(){return buildings_;}
    void AddToTotalPoints(int quantity){total_points += quantity;}
    void ResetTotalPoints(){total_points = 0;}
    int get_total_points(){return total_points;}
    void RemoveBuilding(std::pair <int,int> point, Building *b);
    void set_first_turn(){first = false;}
    bool get_first_turn(){return first;}
    int CountRoads();
    int CountResources();
    int get_dice_roll_sum(){return dice_roll_sum;}
    QColor get_player_color() {return player_color_;}

private:
    bool first = true;
    int player_id_;
    int total_points;
    std::map<resource,int> current_resources; //Player's current resources
    std::map<std::pair<int,int>, std::vector<Building *>> buildings_; // players buildings
    int dice_roll_sum;
    QColor player_color_;
};

#endif // PLAYER_H
