#include "game.h"
#include "player.h"

//init statics
bool Game::place_mode = false;
std::vector<pair<int,int>> Game::all_corners;
std::string Game::place_building_string = "";

Game::Game(){

}

/*
    Adds a corner to the vector with all the corners
*/
void Game::AddCorner(pair<int,int> pair_to_add){
    all_corners.push_back(pair_to_add);
}

/*
    creates Player objects with id and specific colors and pushes
    onto a player list vector to keep track of turns

    @param Takes a vector with the player order
*/
void Game::CreatePlayers(std::vector<int> player_order){
   Player *first_player = new Player(player_order[0], Qt::lightGray);
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

/*
    Checks what hexagons a player has a building on
    then what those building are and if its house
    add 1 of every adjacent resource and mansion 2.

    @param the player collecting resources
*/
void Game::CollectResources(Player *player){
    std::map<std::pair<int,int>, Building *>::iterator it;
    std::vector<std::map<Building *, Hexagon *>> hexagon_contains; //Vector that contains all the buildings to its corresponding hexagon
    std::map<Building *, Hexagon *> building_to_hex; //Map that contains the corresponding building to its hexagons
    //Get all the hexagons that have the player's buildings
    //std::map<std::pair <int,int>, Building *> get_buildings()
    for(const auto it : player->get_buildings()){ //Iterate through all of the player's buildings
        for(Hexagon *hexagon : hexagon_list_){ //Iterate through every single hexagon
            for(auto const& value: it.second){ //value is a building object
                //If point of the building matches that of a hexagon then update the variables above
                if(hexagon->get_p1() == it.first){
                    building_to_hex[value] = hexagon;
                    if(std::find(hexagon_contains.begin(), hexagon_contains.end(), building_to_hex) == hexagon_contains.end()) {
                        hexagon_contains.push_back(building_to_hex);
                    }
                }
                else if(hexagon->get_p2() == it.first){
                    building_to_hex[value] = hexagon;
                    if(std::find(hexagon_contains.begin(), hexagon_contains.end(), building_to_hex) == hexagon_contains.end()) {
                        hexagon_contains.push_back(building_to_hex);
                    }
                }
                else if(hexagon->get_p3() == it.first){
                    building_to_hex[value] = hexagon;
                    if(std::find(hexagon_contains.begin(), hexagon_contains.end(), building_to_hex) == hexagon_contains.end()) {
                        hexagon_contains.push_back(building_to_hex);
                    }
                }
                else if(hexagon->get_p4() == it.first){
                    building_to_hex[value] = hexagon;
                    if(std::find(hexagon_contains.begin(), hexagon_contains.end(), building_to_hex) == hexagon_contains.end()) {
                        hexagon_contains.push_back(building_to_hex);
                    }
                }
                else if(hexagon->get_p5() == it.first){
                    building_to_hex[value] = hexagon;
                    if(std::find(hexagon_contains.begin(), hexagon_contains.end(), building_to_hex) == hexagon_contains.end()) {
                        hexagon_contains.push_back(building_to_hex);
                    }
                }
                else if(hexagon->get_p6() == it.first){
                    building_to_hex[value] = hexagon;
                    if(std::find(hexagon_contains.begin(), hexagon_contains.end(), building_to_hex) == hexagon_contains.end()) {
                        hexagon_contains.push_back(building_to_hex);
                    }
                }
               building_to_hex.clear(); //Reset the map for another hexagon
            }
        }
    }
    //if house add 1 of the tile resource; if mansion 2
    for(std::map<Building *, Hexagon *> build_hex : hexagon_contains){
        if(build_hex.begin()->first->get_building_type() == "choco house"){
            player->AddResource(build_hex.begin()->second->get_resource_tile(),1);
            player->AddToTotalResources(build_hex.begin()->second->get_resource_tile(),1);
            AddToTotalResourcesDist(build_hex.begin()->second->get_resource_tile(),1);
        }
        else if(build_hex.begin()->first->get_building_type() == "choco mansion"){
            player->AddResource(build_hex.begin()->second->get_resource_tile(),2);
            player->AddToTotalResources(build_hex.begin()->second->get_resource_tile(),2);
            AddToTotalResourcesDist(build_hex.begin()->second->get_resource_tile(),2);
        }
    }
    hexagon_contains.clear(); //Reset the vector for a new player
}

/*
    maps each player with the points it calculates they have

    @return new map with players and their points
*/
std::map<Player *, int> Game::PlayerPoints(){
    std::map<Player *, int> player_pts;
    for(Player *player : player_list){ //For each player...
        player->ResetTotalPoints(); //Reset the player's total points
        player_pts[player] = 0; //Initialize their points to zero
        for(const auto it : player->get_buildings()){ //For each pair<points,vector<buildings *>
            for(auto const& value: it.second){ //For each building the player owns...
                player_pts[player] += value->get_points(); //Add the value of the building to it
                player->AddToTotalPoints(value->get_points());
            }
        }
    }
    return player_pts;
}

/*
    sets the current player to the next one in list of players which is in order
    based on dice roll that deteremined order.

    @param the current player (who just ended their turn)
*/
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

/*
    Calculates to see who hold records: longest road, Most resources, largest dice sum

    @return a map of record names and who owns the record
*/
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

/*
    checks if someone has enought points to have won

    @return bool of if game over.
*/
bool Game::GameOver(){
    for(Player *player : player_list){
        if(player->get_total_points() >= 13){
            return true;
        }
    }
    return false;
}

/*
    keeps track of when a full rotation happens
    3 players so 3 times end turn is hit
    Aids the points graph to know when a full turn happens to update the graph per round
*/
void Game::UpdateTurnToPoints(){
    for(Player *player : player_list){
        if(turn_rotations == 3){//reset if full round
            turn_rotations = -1;
            Player::IncrementTurnCount();// add how many turns have occured
        }
        player->SetTurnToPoints(Player::get_turn_count(), player->get_total_points());
    }
    turn_rotations += 1;
}

/*
 * function that handles ai turn in placing buildings
 *
    @return a map of point and building to add
*/
std::pair<std::pair<int,int>,Building *> Game::AITurn(){
    Player *player = current_player;
    if(player->get_ai()){ //If player is an AI
        if(player->get_first_turn()){ //If it is the AI's first turn
            int rand_point_index = rand() % (all_corners.size()-1) + 0; //Get a random index for a corner
            while(std::find(taken_vec.begin(), taken_vec.end(), all_corners[rand_point_index]) != taken_vec.end()){ // until we find a point that isnt taken
                rand_point_index = rand() % (all_corners.size()-1) + 0;
            }
            taken_vec.push_back(all_corners[rand_point_index]); // update taken vec
            std::pair<std::pair<int,int>,Building *> temp_map;
            temp_map = make_pair(all_corners[rand_point_index],new ChocolateHouse(all_corners[rand_point_index].first-10,all_corners[rand_point_index].second-10));
            return temp_map;
        }
        else{ // not AI first turn
            for(const auto it : player->get_buildings()){ //If there are houses then upgrade them
                for(Building *buildings : it.second){ //Iterate through AI's buildings
                    if(buildings->get_building_type() == "choco house"){ //If there is a chocolate house then upgrade to mansion
                        std::pair<std::pair<int,int>,Building *> temp_map;
                        temp_map = make_pair(it.first,new ChocolateMansion(it.first.first-10,it.first.second-10));
                        return temp_map;
                    }
                }
                for(Building *buildings : it.second){ //If there are no houses and there is a road to build on
                    if(buildings->get_building_type() == "candy road"){ //If there is a road
                        if(player->get_buildings()[buildings->get_x_y()].size() == 1){ //If there is no building at the end of the road
                            std::pair<std::pair<int,int>,Building *> temp_map;
                            temp_map = make_pair(it.first,new ChocolateHouse(it.first.first-10,it.first.second-10));
                            return temp_map;
                        }
                    }
                }
                for(Building *buildings : it.second){ //If there is no houses and there is no roads to build on
                    if(buildings->get_building_type() == "choco mansion"){
                        std::pair<std::pair<int,int>,Building *> temp_map;
                        std::vector<pair<int,int>>::iterator first_point_iter = find(all_corners.begin(), all_corners.end(), it.first);
                        size_t index = distance(all_corners.begin(),first_point_iter); //Gets the index of the chocolate mansion
                        for(std::pair<int,int> point : all_corners){
                            if(point.first > all_corners[index].first){
                                if(point.second > all_corners[index].second){
                                    if(point.first <= all_corners[index].first + 60
                                            && point.second <= all_corners[index].second + 60){ // height and width bounds
                                        temp_map = make_pair(it.first,new Road(all_corners[index].first,all_corners[index].second, point.first, point.second)); //Subtract index by one to get the point the is adj. to it
                                        return temp_map;
                                    }
                                }
                                else{ // y is init smaller
                                    if(point.first <= all_corners[index].first + 60
                                            && point.second >= all_corners[index].second - 60){
                                        temp_map = make_pair(it.first,new Road(all_corners[index].first,all_corners[index].second, point.first, point.second)); //Subtract index by one to get the point the is adj. to it
                                        return temp_map;
                                    }
                                }
                            }
                            else{ // x is init smaller
                                if(point.second > all_corners[index].second){
                                    if(point.first >= all_corners[index].first - 60
                                            && point.second <= all_corners[index].second + 60){
                                        temp_map = make_pair(it.first,new Road(all_corners[index].first,all_corners[index].second, point.first, point.second)); //Subtract index by one to get the point the is adj. to it
                                        return temp_map;
                                    }
                                }
                                else{
                                    if(point.first >= all_corners[index].first - 60
                                            && point.second >= all_corners[index].second - 60){
                                        temp_map = make_pair(it.first,new Road(all_corners[index].first,all_corners[index].second, point.first, point.second)); //Subtract index by one to get the point the is adj. to it
                                        return temp_map;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        //return;
    }
}
