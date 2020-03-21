/*
** EPITECH PROJECT, 2019
** draw_game.cpp
** File description:
** drawing the game
*/

#include "SFML/Graphics.hpp"
#include "client/graphic/Game.hpp"

#define TILE_SIZE 24
extern sf::RenderWindow *wd;

sf::RectangleShape load_tile()
{
    sf::Vector2f size = {TILE_SIZE, TILE_SIZE};
    sf::RectangleShape rect(size);
    sf::Color fill = {125, 125, 125, 255};
    sf::Color outline = {130, 130, 130};
    rect.setPosition(0, 0);
    rect.setFillColor(fill);
    rect.setOutlineColor(outline);
    rect.setOutlineThickness(0.5);
    return (rect);
}

void draw_map(std::vector<std::string> *map)
{
    sf::Color grey = {125, 125, 125, 255};
    sf::Color blue = {0, 0, 255, 255};
    sf::Color red = {255, 0, 0, 255};
    sf::RectangleShape rect = load_tile();
    for(int i = 0; i < (int) map->size(); i++)
    {
        for (int j = 0; j < (int) (*map)[i].length(); j++)
        {
            if ((*map)[i][j] == 0)
                rect.setFillColor(grey);
            if ((*map)[i][j] == 1)
                rect.setFillColor(red);
            if ((*map)[i][j] == 2)
                rect.setFillColor(blue);
            rect.setPosition(j * TILE_SIZE , i*TILE_SIZE);
            wd->draw(rect);
        }
    }
}

void draw_players(std::vector<player_s> *players)
{
    sf::Color red = {255, 100, 100, 255};
    sf::Color blue = {100 , 100, 255, 255};
    sf::Vector2f size = {20, 20};
    sf::RectangleShape rect(size);
    for (uint i = 0; i < players->size(); i++)
    {
        rect.setPosition((*players)[i].pos.x * TILE_SIZE + 2, (*players)[i].pos.y * TILE_SIZE + 2);
        if ((*players)[i].team == BLUE)
            rect.setFillColor(blue);
        else
            rect.setFillColor(red);
        wd->draw(rect);
    }
}

void draw_texts(std::vector<str_s> *texts)
{

}

int draw_game(game_s game)
{
    wd->clear();
    draw_map(&game.map);
    draw_players(&game.players);
    draw_texts(&game.texts);
    wd->display();
    sf::Event evt;
    wd->pollEvent(evt);
    if (evt.type == sf::Event::KeyPressed)
        return (evt.key.code);
    return (0);
}