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

int start(int argc, char **argv);

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

int start(int, char **);
int connexion_page(void);
int options(void);

#endif /* !START_HPP_ */
