#include "game.h"
#include "player.h"

Game::Game(){

}

void Game::AddCorner(pair<int,int> pair_to_add){
    all_corners.push_back(pair_to_add);
}
