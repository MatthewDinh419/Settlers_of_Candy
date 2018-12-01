#include "game.h"
#include "player.h"
bool Game::place_mode = false;
std::vector<pair<int,int>> Game::all_corners;
std::string Game::place_building_string = "";
Game::Game(){

}

void Game::AddCorner(pair<int,int> pair_to_add){
    all_corners.push_back(pair_to_add);
}
