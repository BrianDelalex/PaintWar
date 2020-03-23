/*
** EPITECH PROJECT, 2019
** ServerPlayer.hpp
** File description:
** ServerPlayer
*/

#ifndef SERVERPLAYER_HPP
#define SERVERPLAYER_HPP

#include "iostream"

enum Direction
{
    DOWN,
    LEFT,
    RIGHT,
    UP
};

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

struct player_s
{
    Vec pos;
    Team team;
    uint id;
    std::string name;
};

typedef struct player_s Ply;

#endif