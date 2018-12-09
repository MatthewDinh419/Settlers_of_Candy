#include "game.h"
#include "player.h"
bool Game::place_mode = false;
std::vector<pair<int,int>> Game::all_corners;
std::string Game::place_building_string = "";

Game::Game(){

}

/*
 *Adds a corner to the vector with all the corners
*/
void Game::AddCorner(pair<int,int> pair_to_add){
    all_corners.push_back(pair_to_add);
}

void Game::CreatePlayers(std::vector<int> player_order){
   Player *first_player = new Player(player_order[0]);
   current_player = first_player;
   player_list.push_back(first_player);
   player_list.push_back(new Player(player_order[1]));
   player_list.push_back(new Player(player_order[2]));
   for(Player *player : player_list){
       for(int i = 0; i < 3; i++){
           player->AddResource(resource::money);
           player->AddResource(resource::sugar);
           player->AddResource(resource::water);
       }
   }
}
