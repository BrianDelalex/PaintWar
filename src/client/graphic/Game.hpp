#ifndef _GAME_
#define _GAME_

#include "Player.hpp"

typedef struct game_s
{
    std::vector<Player> players;
    std::vector<std::string> map;
}game_t;

#endif