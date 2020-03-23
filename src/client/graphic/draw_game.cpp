/*
** EPITECH PROJECT, 2019
** draw_game.cpp
** File description:
** drawing the game
*/

#include "SFML/Graphics.hpp"
#include "client/graphic/Game.hpp"
#include <iostream>

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
            if ((*map)[i][j] == '0')
                rect.setFillColor(grey);
            if ((*map)[i][j] == '1')
                rect.setFillColor(red);
            if ((*map)[i][j] == '2')
                rect.setFillColor(blue);
            rect.setPosition(j * TILE_SIZE , i*TILE_SIZE);
            wd->draw(rect);
        }
    }
}

void draw_players(std::vector<player_s> *players, uint me)
{
    sf::Color red = {255, 100, 100, 255};
    sf::Color blue = {100 , 100, 255, 255};
    sf::Color yellow = {255, 255, 0, 255};
    sf::Vector2f size = {20, 20};
    sf::CircleShape circle(10, 30);
    circle.setOutlineThickness(1.5);
    for (uint i = 0; i < players->size(); i++)
    {
        circle.setPosition((*players)[i].pos.x * TILE_SIZE + 2, (*players)[i].pos.y * TILE_SIZE + 2);
        if ((*players)[i].team == BLUE) {
            circle.setFillColor(blue);
            circle.setOutlineColor(blue);
        }
        else {
            circle.setFillColor(red);
            circle.setOutlineColor(red);
        }
        if (i == me)
            circle.setOutlineColor(yellow);
        wd->draw(circle);
    }
}

void draw_texts(std::vector<str_s> *texts)
{

}

void draw_score(int blue, int  red)
{
    std::string f_path = PROJECT_PATH;
    f_path.append("/ressources/FiraCode-Bold.ttf");
    sf::Font f;
    if (!f.loadFromFile(f_path)) {
        std::cerr << "Error while loading font" << std::endl;
        return;
    }
    sf::Text blue_t(std::to_string(blue), f, 32);
    blue_t.setFillColor(sf::Color::Blue);
    blue_t.setPosition(860 - blue_t.getGlobalBounds().width * 2, 5);
    wd->draw(blue_t);
    sf::Text txt(":", f, 32);
    blue_t.setFillColor(sf::Color::Black);
    txt.setPosition(blue_t.getPosition().x + blue_t.getGlobalBounds().width + 3, 5);
    wd->draw(txt);
    sf::Text red_t(std::to_string(red), f, 32);
    red_t.setOutlineColor(sf::Color::Red);
    red_t.setPosition(txt.getPosition().x + txt.getGlobalBounds().width + 3, 5);
    wd->draw(red_t);
}

int draw_game(game_s game)
{
    wd->clear();
    draw_map(&game.map);
    draw_players(&game.players, game.me);
    draw_texts(&game.texts);
    wd->display();
    sf::Event evt;
    wd->pollEvent(evt);
    if (evt.type == sf::Event::KeyPressed)
        return (evt.key.code);
    return (0);
}