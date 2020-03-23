/*
** EPITECH PROJECT, 2019
** init_game.cpp
** File description:
** initialisation of display comp
*/

#include "SFML/Graphics.hpp"
#include "client/graphic/graphic.hpp"

sf::RenderWindow *wd;

sf::RenderWindow *create_window(unsigned int, unsigned int, const std::string &);

sf::RenderWindow *create_window(unsigned int width, unsigned int height, const std::string &name)
{
    sf::RenderWindow *win = new sf::RenderWindow(sf::VideoMode(width, height), name);
    //wd->setFramerateLimit(33);

    return (win);
}

void init(void)
{
    wd = create_window(1920, 1080, "PaintWar");
}