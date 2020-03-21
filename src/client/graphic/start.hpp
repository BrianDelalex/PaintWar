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
        int main();
        sf::Sprite sprite;
        sf::Texture texture;
        sf::Mouse mouse;

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
        sf::Font font;
        std::string _ip;
    private:
    protected:
};
#endif /* !START_HPP_ */
