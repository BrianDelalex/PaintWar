/*
** EPITECH PROJECT, 2019
** init_game.cpp
** File description:
** initialisation of display comp
*/

#include "SFML/Graphics.hpp"

sf::RenderWindow *wd;

sf::RenderWindow *create_window(unsigned int width, unsigned int height, const std::string &name)
{
    sf::RenderWindow *wd = new sf::RenderWindow(sf::VideoMode(width, height), name);
    //wd->setFramerateLimit(33);

    return (wd);
}

void init()
{
    wd = create_window(1920, 1080, "PaintWar");
}