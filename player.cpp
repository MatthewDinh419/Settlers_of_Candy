#include "player.h"
int Player::turn_count = 1;
using namespace std;

Player::Player(int player_id, QColor player_color){
    player_id_ = player_id;
    total_points = 0;
    dice_roll_sum = 0;
    player_color_ = player_color;
}

/*
 * Remove the specificed resource off the player's current resources by a specified quantity
 *
 * @resource_to_remove the resource to remove off the player's current resources
 * @quantity the amount to remove off the player's current resources
 */
void Player::RemoveResource(resource resource_to_remove, int quantity){
    current_resources[resource_to_remove] -= quantity;
}

/*
 * Adds a building to the player's owned buildings
 *
 * @point the point at which the building is at
 * @b the building that the player owns
 */
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

/*
 * Remove the building from the player's owned buildings
 *
 * @point the point from where the building is. Also used as the key.
 * @b the building which is being removed. Also the value.
 */
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

/*
 * Counts the amount of roads there are that the player owns. Used for longest road record.
 */
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

/*
 * Counts the total amount of resources that the  player has
 */
 int Player::CountResources(){
    int counter = 0;
    for(const auto it : current_resources){
        counter += it.second;
    }
    return counter;
}
