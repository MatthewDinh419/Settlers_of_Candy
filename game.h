#ifndef GAME_H
#define GAME_H
#include "player.h"
#include <vector>

class Game{
public:
    Game();
private:
    Player current_player;
    std::vector<Player> player_list;
};
#endif // GAME_H
