/*
** EPITECH PROJECT, 2020
** graphic
** File description:
** connexion_page
*/

#include "client/graphic/start.hpp"

Connexion::Connexion()
{
    sf::IntRect rect (0, 0, 1920, 1080);
    this->texture.loadFromFile("Assets/connexion.jpg");
    this->sprite.setTexture(this->texture);
    this->sprite.setTextureRect(rect);
}

Connexion::~Connexion()
{
}

int load_text()
{
    Connexion connect;
    printf("%s\n", "putain");
    if (!connect.font.loadFromFile("Graffiti.ttf")) {
        printf("pas marché l'écriture");
        return (84);
    }
    connect.font.loadFromFile("Graffiti.ttf");
    connect.playerText.setFont(connect.font);
    connect.playerText.setPosition(60,300);
    connect.text.setFont(connect.font);
    connect.text.setString("C'est parti pour la plus grand de toutes les batailles de peinture !!");
    printf("%s\n", "censé avoir");
    return (0);
}

// void print_cpu(Connect connect, sf::RenderWindow *window)
// {

// }
int Connexion::connexion_page(void)
{
    /*Case a tapper port et IP*/
    Connexion connect;

    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Connexion Page");

    if (!connect.font.loadFromFile("Graffiti.ttf")) {
        printf("pas marché l'écriture");
        return (84);
    }

    connect.font.loadFromFile("Graffiti.ttf");
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
                printf("%s\n", connect._ip);
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
        1- Récupérer et stocker les valeurs du port et ip
        2- Belle affichage avec input avec case pour écrire pour le port et l'input extc
*/