#include "player.h"

using namespace std;
Player::Player(int player_id){
    player_id_ = player_id;
    total_points = 0;
    dice_roll_sum = 0;
}

void Player::RemoveResource(resource resource_to_remove, int quantity){
    current_resources[resource_to_remove] -= quantity;
}

void Player::AddBuilding(std::pair <int,int> point, Building *b){
    //if key doesn't exist, new vec at key p and push the building
    if(!buildings_.count(point)){
        buildings_.insert(pair<pair<int,int>, vector<Building *>>(point, vector<Building *>()));
        buildings_[point].push_back(b);
    }
    else{ // if not empty push into the vec
        buildings_[point].push_back(b);
    }
}
void Player::RemoveBuilding(std::pair <int,int> point, Building *b){
    //if empty remove key
    if(buildings_.at(point).empty()){
       buildings_.erase(point);
    }
    else{ // if not just remove the building specified
        for(int i = 0; i < buildings_.at(point).size(); i++){
            if(buildings_.at(point)[i] == b){
                buildings_.at(point).erase(buildings_.at(point).begin() + i);
                break;
            }
        }
    }
}

int Player::CountRoads(){
    int counter = 0;
    for(const auto it : buildings_){
        for(auto const& value: it.second)
        if(value->get_building_type() == "candy road"){
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
