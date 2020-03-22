/*
** EPITECH PROJECT, 2019
** 
** File description:
** 
*/

#ifndef SCHEDULER_HPP_
#define SCHEDULER_HPP_

#include "client/graphic/Game.hpp"
#include <client/network/Client.hpp>

Client *connection(std::string ip, unsigned short port, std::string name, game_t game);
#endif