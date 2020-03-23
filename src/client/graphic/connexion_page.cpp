/*
** EPITECH PROJECT, 2020
** graphic
** File description:
** connexion_page
*/

#include "../../../inc/client/graphic/start.hpp"

Connexion::Connexion()
{
    sf::IntRect rect (0, 0, 1920, 1080);
    this->texture.loadFromFile("src/client/graphic/picture/connexion.jpg");
    this->sprite.setTexture(this->texture);
    this->sprite.setTextureRect(rect);
}

Connexion::~Connexion()
{
}

int connexion_page(void)
{
    Menu menu;
    Connexion connect;

    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Connexion Page");

    if (!connect.font.loadFromFile("src/client/graphic/picture/Graffiti.ttf")) {
        std::cout << "Not found" << std::endl;
        return (84);
    }
    connect.font.loadFromFile("src/client/graphic/picture/Graffiti.ttf");
    connect.playerText.setFont(connect.font);
    connect.playerText.setPosition(60,300);
    connect.text.setFont(connect.font);
    connect.text.setString("C'est parti pour la plus grand de toutes les batailles!!");
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::TextEntered)
            {
                if (event.text.unicode < 128) {
                connect.playerInput +=event.text.unicode;
                connect.playerText.setString(connect.playerInput);
                connect._ip += event.text.unicode;
                }
            }
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(connect.sprite);
        window.draw(connect.text);
        window.draw(connect.playerText);

        window.display();
    }
    return (0);
}
/*
    TODO-LIST:
        afficher les usernames extc
*/