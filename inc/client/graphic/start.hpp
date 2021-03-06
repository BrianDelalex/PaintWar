/*
** EPITECH PROJECT, 2020
** startmenujam
** File description:
** start
*/

#ifndef START_HPP_
#define START_HPP_

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <string>
#include <vector>
#include "Game.hpp"
#include "Player.hpp"

class Menu {
    public:
        Menu();
        ~Menu();
        sf::Sprite sprite;
        sf::Texture texture;
        sf::Mouse mouse;
        std::string _username;
        std::string _ip;
        int _port;

    private:
    protected:
};

class Connexion{
    public:
        Connexion();
        ~Connexion();
        int connexion_page();
        sf::Sprite sprite;
        sf::Texture texture;
        sf::String playerInput;
        sf::Text playerText;
        sf::Text text;
        sf::Text text_username;
        sf::Text text_ip;
        sf::Text text_port;
        sf::Font font;
        std::string _ip;
        unsigned short _port;
    private:
    protected:
};

class Options {
    public:
        Options();
        ~Options();
        sf::Sprite sprite;
        sf::Texture texture;
        sf::Text options;
        sf::Text volume;
        sf::Text back;
        sf::Text volume_25;
        sf::Text volume_50;
        sf::Text volume_75;
        sf::Text volume_100;
        sf::Font font;
    private:
    protected:
};

int start(void);
int connexion_page(void);
int options(void);
int error_management(int, char **);
int init_text(Options opt, sf::RenderWindow *window);
int init_button_back(Options opt, sf::RenderWindow *window);
int init_vol_25(Options opt, sf::RenderWindow *window);
int init_vol_50(Options opt, sf::RenderWindow *window);
int init_vol_75(Options opt, sf::RenderWindow *window);
int init_vol_100(Options opt, sf::RenderWindow *window);
#endif /* !START_HPP_ */
