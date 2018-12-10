#include "player.h"

Player::Player(int player_id){
    player_id_ = player_id;
}

void Player::RemoveResource(resource resource_to_remove, int quantity){
    current_resources[resource_to_remove] -= quantity;
}
