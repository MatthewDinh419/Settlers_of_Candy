#ifndef GAMEBOARD_H
#define GAMEBOARD_H
#include <vector>
#include "hexagon.h"
#endif // GAMEBOARD_H

class Gameboard{
public:
    static Gameboard& GetInstance() {
            // gets instantiated the first time
            static Gameboard instance; // guaranteed to be destroyed
            return instance;
        }
    void operator=(Gameboard const&) = delete;
private:
    std::vector<Hexagon> game_board;
    Gameboard(){};
};
