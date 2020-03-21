#ifndef _GAME_
#define _GAME_

#include "Player.hpp"

enum Team
{
    BLUE,
    RED
};

typedef struct vec_s
{
    int x;
    int y;
};

typedef struct player_s
{
    vec_s pos;
    Team team;
    Direction direction;
};

typedef struct str_s
{
    std::string str;
    vec_s vec;
    long timepoint;
};

typedef struct game_s
{
    std::vector<player_s> players;
    player_s me;
    std::vector<std::string> map;
    std::vector<str_s> texts;
}game_t;

#endif