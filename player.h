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
    void AddResource(resource resource_to_add, int quantity){current_resources[resource_to_add] += quantity;} //Adds resoure by quantity amount to player's owned resources
    void AddBuilding(std::pair <int,int> point, Building *b);
    void RemoveResource(resource resource_to_remove, int quantity);
    void AddToTotalResources(resource resource_to_add, int quantity){total_resources[resource_to_add] += quantity;} //Adds resource by quantity to player's total amount of resources in the game
    void AddToResourcesUsed(resource resource_to_add, int quantity){resources_used[resource_to_add] += quantity;} //Adds resource by quantity that the player has used
    void AddToTotalPoints(int quantity){total_points += quantity;} //Adds the player's total amount of points by quantity amount
    void ResetTotalPoints(){total_points = 0;} //Resets the player's total points to zero
    void RemoveBuilding(std::pair <int,int> point, Building *b);
    void set_first_turn(){first = false;} //Changes first turn to false
    void SetTurnToPoints(int turn, int points){turn_to_points[turn] = points;} //Player's amount of points at a given turn
    void set_ai(){is_ai = true;} //Sets the player to an AI player or not
    bool get_first_turn(){return first;} //Gets if it is the first turn
    bool get_ai(){return is_ai;} //Gets the ai variable
    int get_id(){return player_id_;} //Gets the player ID
    int get_total_points(){return total_points;} //Gets the player's total amount of points
    int CountRoads();
    int CountResources();
    int get_dice_roll_sum(){return dice_roll_sum;} //Gets the dice roll of the player
    QColor get_player_color() {return player_color_;} //Gets the player color
    std::map<resource,int> get_total_resources(){return total_resources;}
    std::map<resource,int> get_resources_used(){return resources_used;}
    std::map<int,int> get_turn_to_points(){return turn_to_points;}
    std::map<std::pair<int,int>, std::vector<Building *>> get_buildings(){return buildings_;}

private:
    bool is_ai = false; //Variable for if the player is an AI or not
    bool first = true; //If it is the first turn for the player or not
    int player_id_; //The ID of the player
    int dice_roll_sum; //The sum of all the player's dice rolls throughout the game
    static int turn_count; //The turn count of the player
    int total_points; //The total amount of points that the player has
    std::map<resource,int> current_resources; //Player's current resources
    std::map<std::pair<int,int>, std::vector<Building *>> buildings_; // players buildings
    std::map<int,int> turn_to_points; //Player's turn number to their amount of points that turn
    std::map<resource,int> total_resources; //Total amount of resources that the player has had
    std::map<resource,int> resources_used; //Total amount of resources that the player has spent
    QColor player_color_; //The color of the player's objects
};

#endif // PLAYER_H
