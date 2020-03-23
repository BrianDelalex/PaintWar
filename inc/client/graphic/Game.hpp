#ifndef _GAME_
#define _GAME_

#include <string>
#include <vector>
#include "server/ServerPlayer.hpp"

struct vec_s
{
    int x;
    int y;
};

typedef struct str_s
{
    std::string str;
    vec_s vec;
    long timepoint;
} str_t;

typedef struct game_s
{
    std::vector<player_s> players;
    uint me;
    std::vector<std::string> map;
    std::vector<str_s> texts;
} game_t;


#endif