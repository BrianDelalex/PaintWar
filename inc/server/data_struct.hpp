/*
** EPITECH PROJECT, 2019
** data_struct.cpp
** File description:
** struct to send over tcp
*/

#ifndef DATA_STRUCT_HPP_
#define DATA_STRUCT_HPP_

#include <SFML/Network.hpp>

struct new_player
{
    int x;
    int y;
    sf::Uint32 c;
    bool stop;
};

struct Movement_s
{
    std::string type;
    int x;
    int y;
    int id;
};

typedef struct new_player playerRegister;
typedef struct Movement_s Movement;

#endif