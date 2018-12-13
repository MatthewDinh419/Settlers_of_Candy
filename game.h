#ifndef GAME_H
#define GAME_H
#include "player.h"
#include <vector>

class Game{
public:
    Game();
    static void AddCorner(pair<int,int> pair_to_add);
    static bool get_place_mode(){return place_mode;} // Place mode when you click add a building
    static void set_place_mode(bool mode_to_set){place_mode = mode_to_set;}
    static std::vector<pair<int,int>> get_all_corners(){return all_corners;} // ever corner point of all hexagons
    static void set_building_string(std::string string_to_set){place_building_string = string_to_set;} // takes string which idents type of building adding
    static std::string get_building_string(){return place_building_string;}
    void CreatePlayers(std::vector<int> player_order);
    void CollectResources(Player *player);
    void AddHexagon(Hexagon *hexagon_to_add){hexagon_list_.push_back(hexagon_to_add);} // add hexagon to vector
    void set_next_player(Player *curr_player);
    void AddToTotalResourcesDist(resource resource_to_add, int quantity){total_resources_distributed[resource_to_add] += quantity;} // self explanatory
    void UpdateTurnToPoints();
    bool GameOver();
    std::map<Player *, int> PlayerPoints();
    std::map<std::string, Player *> Records();
    std::map<resource,int> get_total_resources_dist(){return total_resources_distributed;} // getters
    std::vector<Player*> get_player_list(){return player_list;}
    Player *get_current_player(){return current_player;}
    std::pair<std::pair<int,int>,Building *> AITurn();

private:
    Player *current_player; //Current player's turn
    std::map<resource,int> total_resources_distributed;
    std::vector<Player*> player_list; //Vector containing all the players in the game
    static std::vector<pair<int,int>> all_corners; //Contains all the points of the hexagons
    std::vector<Hexagon*> hexagon_list_;
    int turn_rotations = 0; //how many turns have happened -> 3 = full round
    static std::string place_building_string; //String of the building to place
    static bool place_mode; //If a place building button is pressed then it will be in place mode or exit out of it
    std::vector<std::pair<int, int>> taken_vec; // for ai to know if a point is taken
};
#endif // GAME_H
