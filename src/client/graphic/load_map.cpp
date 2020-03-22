/*
** EPITECH PROJECT, 2019
** load_map.cpp
** File description:
** load the map
*/

#include <client/graphic/graphic.hpp>

std::vector<std::string> load_map()
{
    std::vector<std::string> map;
    std::string str;

    for (uint i = 0; i < 80; i++)
        str.push_back('0');
    for (uint i = 0; i < 45; i++)
        map.push_back(str);
    return map;
}