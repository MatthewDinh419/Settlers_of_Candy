#include "player.h"

Player::Player(int player_id){
    player_id_ = player_id;
    total_points = 0;
    dice_roll_sum = 0;
}

void Player::RemoveResource(resource resource_to_remove, int quantity){
    current_resources[resource_to_remove] -= quantity;
}

int Player::CountRoads(){
    int counter = 0;
    for(const auto it : buildings_){
        if(it.second->get_building_type() == "candy road"){
            counter += 1;
        }
    }
    return counter;
}

int Player::CountResources(){
    int counter = 0;
    for(const auto it : current_resources){
        counter += it.second;
    }
    return counter;
}
