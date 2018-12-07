#include "player.h"

Player::Player(int player_id){
    player_id_ = player_id;
}

void Player::RemoveResource(resource resource_to_remove){
    if(std::find(current_resources.begin(),current_resources.end(),resource_to_remove)!=current_resources.end()){
        auto iter = std::find(current_resources.begin(),current_resources.end(),resource_to_remove);
        current_resources.erase(iter);
    }
}
