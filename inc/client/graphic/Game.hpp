#ifndef _GAME_
#define _GAME_

#include <string>
#include <vector>

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

enum Direction
{
    UP = 0,
    DOWN = 1,
    RIGHT = 2,
    LEFT = 3
};

typedef struct player_s
{
    vec_s pos;
    Team team;
    Direction direction;
} player_t;

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
    int blue;
    int red;
    std::vector<str_s> texts;
} game_t;

void draw_map(std::vector<std::string> *map);
void draw_players(std::vector<player_s> *players, uint me);
void draw_texts(std::vector<str_s> *texts);
int draw_game(game_s game);
void draw_score(int blue, int red);

void initGame(void);

#endif