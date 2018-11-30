#ifndef GAMEBOARD_H
#define GAMEBOARD_H
#include <vector>
#include "building.h"

class Gameboard{
public:
    static Gameboard& GetInstance() {
            // gets instantiated the first time
            static Gameboard instance; // guaranteed to be destroyed
            std::vector<resource> temp_required_resources;
            for(int i = 0; i < 3; i++){
                temp_required_resources.push_back(resource::money);
                temp_required_resources.push_back(resource::sugar);
                temp_required_resources.push_back(resource::water);
                if(i == 0){
                    Building *candy_road = new Building(temp_required_resources,1,30,30,QColor(255,255,255));
                }
                else if(i == 1){
                    Building *chocolate_house = new Building(temp_required_resources,1,25,25,QColor(255,255,255));
                }
                else if(i == 2){
                    Building *chocolate_mansion = new Building(temp_required_resources,1,40,40,QColor(255,255,255));
                }
            }
            return instance;
        }
    void operator=(Gameboard const&) = delete;
    void AddBuilding();
    void AddCorner(pair<int,int> pair_to_add);
private:
    std::vector<Hexagon> game_board;
    std::vector<pair<int,int>> all_corners;
    Gameboard(){};
    Building *candy_road;
    Building *chocolate_house;
    Building *chocolate_mansion;
};
#endif // GAMEBOARD_H
