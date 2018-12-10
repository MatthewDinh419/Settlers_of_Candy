#ifndef GAME_H
#define GAME_H
#include "player.h"
#include <vector>

class Game{
public:
    Game();
    static void AddCorner(pair<int,int> pair_to_add);
    static bool get_place_mode(){return place_mode;}
    static void set_place_mode(bool mode_to_set){place_mode = mode_to_set;}
    static std::vector<pair<int,int>> get_all_corners(){return all_corners;}
    static void set_building_string(std::string string_to_set){place_building_string = string_to_set;}
    static std::string get_building_string(){return place_building_string;}
    Player *get_current_player(){return current_player;}
    std::vector<Player*> get_player_list(){return player_list;}
    void CreatePlayers(std::vector<int> player_order);
    void CollectResources();
    void AddHexagon(Hexagon *hexagon_to_add){hexagon_list_.push_back(hexagon_to_add);}
    map<Player *, int> PlayerPoints();
private:
    Player *current_player; //Current player's turn
    std::vector<Player*> player_list; //Vector containing all the players in the game
    static std::vector<pair<int,int>> all_corners; //Contains all the points of the hexagons
    std::vector<Hexagon*> hexagon_list_;
    static std::string place_building_string; //String of the building to place
    static bool place_mode; //If a place building button is pressed then it will be in place mode or exit out of it
};
#endif // GAME_H
