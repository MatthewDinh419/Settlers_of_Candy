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
        if(player->get_buildings().size() > 1){
            for(const auto it : player->get_buildings()){ //Iterate through all of the player's buildings
                for(Hexagon *hexagon : hexagon_list_){ //Iterate through every single hexagon
                    //If point of the building matches that of a hexagon then update the variables above
                    if(hexagon->get_p1() == it.first){
                        building_to_hex[it.second] = hexagon;
                        hexagon_contains.push_back(building_to_hex);
                    }
                    else if(hexagon->get_p2() == it.first){
                        building_to_hex[it.second] = hexagon;
                        hexagon_contains.push_back(building_to_hex);
                    }
                    else if(hexagon->get_p3() == it.first){
                        building_to_hex[it.second] = hexagon;
                        hexagon_contains.push_back(building_to_hex);
                    }
                    else if(hexagon->get_p4() == it.first){
                        building_to_hex[it.second] = hexagon;
                        hexagon_contains.push_back(building_to_hex);
                    }
                    else if(hexagon->get_p5() == it.first){
                        building_to_hex[it.second] = hexagon;
                        hexagon_contains.push_back(building_to_hex);
                    }
                    else if(hexagon->get_p6() == it.first){
                        building_to_hex[it.second] = hexagon;
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
    std::map<Player *, int> players_points;
    for(Player *player : player_list){
        players_points[player] = 0;
        for(const auto it : player->get_buildings()){
            qDebug() << it.second->get_points();
            players_points[player] += it.second->get_points();
        }
    }
    return players_points;
}
