/*
** EPITECH PROJECT, 2019
** ServerPlayer.hpp
** File description:
** ServerPlayer
*/

#ifndef SERVERPLAYER_HPP
#define SERVERPLAYER_HPP

#include "iostream"

enum Team
{
    BLUE,
    RED
};

struct vector_s
{
    int x;
    int y;
};

typedef struct vector_s Vec;

enum Direction
{
    UP = 0,
    DOWN = 1,
    RIGHT = 2,
    LEFT = 3
};

struct player_s
{
    Vec pos;
    Team team;
    uint id;
    std::string name;
};

typedef struct player_s Ply;

#endif