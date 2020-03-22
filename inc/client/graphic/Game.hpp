#ifndef _GAME_
#define _GAME_

#include "Player.hpp"

enum Team
{
    BLUE,
    RED
};

struct vec_s
{
    int x;
    int y;
};

typedef struct vec_s vec_t;

struct player_s
{
    vec_s pos;
    Team team;
    Direction direction;
};

typedef struct player_s player_t;

struct str_s
{
    std::string str;
    vec_s vec;
    long timepoint;
};

typedef struct str_s str_t;

struct game_s
{
    std::vector<player_s> players;
    uint me;
    std::vector<std::string> map;
    std::vector<str_s> texts;
};

typedef struct game_s game_t;


#endif