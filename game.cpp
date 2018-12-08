#include "game.h"
#include "player.h"
bool Game::place_mode = false;
std::vector<pair<int,int>> Game::all_corners;
std::string Game::place_building_string = "";
Game::Game(){
    current_player = new Player(1);
    Player *player2 = new Player(2);
    Player *player3 = new Player(3);
    player_list.push_back(current_player);
    player_list.push_back(player2);
    player_list.push_back(player3);
}

/*
 *Adds a corner to the vector with all the corners
*/
void Game::AddCorner(pair<int,int> pair_to_add){
    all_corners.push_back(pair_to_add);
}
