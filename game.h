#ifndef GAME_H
#define GAME_H
#include "player.h"
#include <vector>
#include "gameboard.h"

class Game{
public:
    Game();
    void AddCorner(pair<int,int> pair_to_add);
private:
    Player current_player;
    std::vector<Player> player_list;
    std::vector<pair<int,int>> all_corners;
    Gameboard &new_gameboard = Gameboard::GetInstance();
};
#endif // GAME_H
