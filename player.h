#ifndef PLAYER_H
#define PLAYER_H
#include <map>
#include "hexagon.h"
#include "building.h"

class Player{
public:
    Player(int player_id, QColor player_color);
    std::map<resource,int> get_current_resources(){return current_resources;}
    static int get_turn_count(){return turn_count;}
    static void IncrementTurnCount(){turn_count += 1;}
    void AddResource(resource resource_to_add, int quantity){current_resources[resource_to_add] += quantity;}
    void AddBuilding(std::pair <int,int> point, Building *b);
    void RemoveResource(resource resource_to_remove, int quantity);
    void AddToTotalResources(resource resource_to_add, int quantity){total_resources[resource_to_add] += quantity;}
    void AddToResourcesUsed(resource resource_to_add, int quantity){resources_used[resource_to_add] += quantity;}
    void AddToTotalPoints(int quantity){total_points += quantity;}
    void ResetTotalPoints(){total_points = 0;}
    void RemoveBuilding(std::pair <int,int> point, Building *b);
    void set_first_turn(){first = false;}
    void SetTurnToPoints(int turn, int points){turn_to_points[turn] = points;}
    void set_ai(){is_ai = true;}
    bool get_first_turn(){return first;}
    bool get_ai(){return is_ai;}
    int get_id(){return player_id_;}
    int get_total_points(){return total_points;}
    int CountRoads();
    int CountResources();
    int get_dice_roll_sum(){return dice_roll_sum;}
    QColor get_player_color() {return player_color_;}
    std::map<resource,int> get_total_resources(){return total_resources;}
    std::map<resource,int> get_resources_used(){return resources_used;}
    std::map<int,int> get_turn_to_points(){return turn_to_points;}
    std::map<std::pair<int,int>, std::vector<Building *>> get_buildings(){return buildings_;}

private:
    bool is_ai = false;
    bool first = true;
    int player_id_;
    int dice_roll_sum;
    static int turn_count;
    int total_points;
    std::map<resource,int> current_resources; //Player's current resources
    std::map<std::pair<int,int>, std::vector<Building *>> buildings_; // players buildings
    std::map<int,int> turn_to_points;
    std::map<resource,int> total_resources;
    std::map<resource,int> resources_used;
    QColor player_color_;
};

#endif // PLAYER_H
