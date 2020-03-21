/*
** EPITECH PROJECT, 2019
**  graphics.hpp
** File description:
** 
*/

#ifndef GRAPHIC_HPP_
#define GRAPHIC_HPP_

#include <iostream>
#include <vector>
#include "client/graphic/Game.hpp"

std::vector<std::string> load_map();
void init();
int draw_game(game_s game);

#endif