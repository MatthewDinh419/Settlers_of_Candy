#ifndef GAME_H
#define GAME_H
#include "player.h"
#include <vector>
#endif // GAME_H

class Game{
public:
    Game();
private:
    Player current_player;
    std::vector<Player> player_list;
};
