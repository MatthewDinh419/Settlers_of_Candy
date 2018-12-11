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
   Player *first_player = new Player(player_order[0], Qt::yellow);
   current_player = first_player;
   player_list.push_back(first_player);
   player_list.push_back(new Player(player_order[1], Qt::red));
   player_list.push_back(new Player(player_order[2], Qt::darkBlue));
   for(Player *player : player_list){
       player->AddResource(resource::money,15);
       player->AddResource(resource::sugar,15);
       player->AddResource(resource::water,15);
   }
}

void Game::CollectResources(){
    std::map<std::pair<int,int>, Building *>::iterator it;
    std::vector<std::map<Building *, Hexagon *>> hexagon_contains; //Vector that contains all the buildings to its corresponding hexagon
    std::map<Building *, Hexagon *> building_to_hex; //Map that contains the corresponding building to its hexagons
    //Get all the hexagons that have the player's buildings
    //std::map<std::pair <int,int>, Building *> get_buildings()
    for(Player *player : player_list){ //Iterate through each player
        for(const auto it : player->get_buildings()){ //Iterate through all of the player's buildings
            for(Hexagon *hexagon : hexagon_list_){ //Iterate through every single hexagon
                for(auto const& value: it.second){
                    //If point of the building matches that of a hexagon then update the variables above
                    if(hexagon->get_p1() == it.first){
                        building_to_hex[value] = hexagon;
                        hexagon_contains.push_back(building_to_hex);
                    }
                    else if(hexagon->get_p2() == it.first){
                        building_to_hex[value] = hexagon;
                        hexagon_contains.push_back(building_to_hex);
                    }
                    else if(hexagon->get_p3() == it.first){
                        building_to_hex[value] = hexagon;
                        hexagon_contains.push_back(building_to_hex);
                    }
                    else if(hexagon->get_p4() == it.first){
                        building_to_hex[value] = hexagon;
                        hexagon_contains.push_back(building_to_hex);
                    }
                    else if(hexagon->get_p5() == it.first){
                        building_to_hex[value] = hexagon;
                        hexagon_contains.push_back(building_to_hex);
                    }
                    else if(hexagon->get_p6() == it.first){
                        building_to_hex[value] = hexagon;
                        hexagon_contains.push_back(building_to_hex);
                    }
                   building_to_hex.clear(); //Reset the map for another hexagon
                }
            }
        }
        for(std::map<Building *, Hexagon *> build_hex : hexagon_contains){
            if(build_hex.begin()->first->get_building_type() == "choco house"){
                player->AddResource(build_hex.begin()->second->get_resource_tile(),2);
            }
            else if(build_hex.begin()->first->get_building_type() == "choco mansion"){
                player->AddResource(build_hex.begin()->second->get_resource_tile(),3);
            }
        }
        hexagon_contains.clear(); //Reset the vector for a new player
    }
}

std::map<Player *, int> Game::PlayerPoints(){
    std::map<Player *, int> player_pts;
    for(Player *player : player_list){
        player_pts[player] = 0;
        for(const auto it : player->get_buildings()){
            for(auto const& value: it.second){
                player_pts[player] += value->get_points();
                player->AddToTotalPoints(value->get_points());
            }
        }
    }
    return player_pts;
}

void Game::set_next_player(Player *curr_player){
    auto it = find(player_list.begin(), player_list.end(), curr_player);
    if(it != player_list.end()){
        auto index = distance(player_list.begin(), it);
        if(index == 2){
            current_player = player_list[0];
        }
        else{
            current_player = player_list[index+1];
        }

    }
}

std::map<std::string,Player *> Game::Records(){
    std::map<std::string, Player*> records;
    //Longest Road
    std::map<Player *, int> max_player_road; //Holder of the longest road
    max_player_road[player_list[0]] = player_list[0]->CountRoads();
    max_player_road[player_list[1]] = player_list[1]->CountRoads();
    max_player_road[player_list[2]] = player_list[2]->CountRoads();
    if(max_player_road[player_list[0]] >= max_player_road[player_list[1]] && max_player_road[player_list[0]] >= max_player_road[player_list[2]]){ //First player longest road
        records["Longest Road"] = player_list[0];
    }
    else if(max_player_road[player_list[1]] > max_player_road[player_list[0]] && max_player_road[player_list[1]] > max_player_road[player_list[2]]){ //Second player longest road
        records["Longest Road"] = player_list[1];
    }
    else if(max_player_road[player_list[2]] > max_player_road[player_list[0]] && max_player_road[player_list[2]] > max_player_road[player_list[1]]){ //Third player longest road
        records["Longest Road"] = player_list[2];
    }
    //Largest dice sum
    Player *current_largest_player = player_list[0]; //Holder of the largest dice roll sums in the game overall
    Player *player_resources = player_list[0]; //Holder of the most resources in the game
    for(Player *player : player_list){
        if(player->get_dice_roll_sum() > current_largest_player->get_dice_roll_sum()){
            current_largest_player = player;
        }
        if(player->CountResources() > player_resources->CountResources()){
            player_resources = player;
        }
    }
    records["Largest Dice Sum"] = current_largest_player;
    records["Most Resources"] = player_resources;
    records["Longest Road"]->AddToTotalPoints(1);
    records["Largest Dice Sum"]->AddToTotalPoints(1);
    records["Most Resources"]->AddToTotalPoints(2);
    return records;
}
