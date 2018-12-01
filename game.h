#ifndef GAME_H
#define GAME_H
#include "player.h"
#include <vector>
#include "gameboard.h"

class Game{
public:
    Game();
    static void AddCorner(pair<int,int> pair_to_add);
    static bool get_place_mode(){return place_mode;}
    static void set_place_mode(bool mode_to_set){place_mode = mode_to_set;}
    static std::vector<pair<int,int>> get_all_corners(){return all_corners;}
    static void set_building_string(std::string string_to_set){place_building_string = string_to_set;}
    static std::string get_building_string(){return place_building_string;}
private:
    Player current_player;
    std::vector<Player> player_list;
    static std::vector<pair<int,int>> all_corners;
    Gameboard &new_gameboard = Gameboard::GetInstance();
    static std::string place_building_string;
    static bool place_mode;
};
#endif // GAME_H
