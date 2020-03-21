/*
** EPITECH PROJECT, 2020
** startmenujam
** File description:
** start
*/

#include "start.hpp"
#include "connexion_page.cpp"

Menu::Menu()
{
    sf::IntRect rect (0, 0, 1920, 1080);
    this->texture.loadFromFile("Assets/menu.png");
    this->sprite.setTexture(this->texture);
    this->sprite.setTextureRect(rect);
}

Menu::~Menu()
{

}

int start(int argc, char **argv)
{
    Menu menu;

    argv[1] == menu._username;
    argv[2] == menu._ip;
    argv[3] += menu._port;
    printf("%s\n", argv[1]);
    printf("%s\n", argv[2]);
    // printf("%s\n", argv[3]);

    sf::RenderWindow window(sf::VideoMode(1920, 1080), "PaintWar");

    while (window.isOpen())
    {
        sf::Vector2i localPosition = sf::Mouse::getPosition(window);
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                printf("%d\n", localPosition.x);
                printf("%d\n",localPosition.y);
                if ((localPosition.x >= 24 && localPosition.x <= 718) && (localPosition.y >= 657 && localPosition.y <= 796))
                    printf("options");
                    // OPTIONS music extc
                if ((localPosition.y <= 720 && localPosition.y >= 644) && (localPosition.x <= 1145 && localPosition.x >= 818)) {
                    printf("play\n");
                    connexion_page();
                }
                    // PLAY jeu vidéo affichage map
                if ((localPosition.y <= 1299 && localPosition.y >= 643) && (localPosition.x <= 1708 && localPosition.x >= 801))
                    printf("EXIT\n");
                    window.close();
                    // EXIT
                }
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(menu.sprite);
        window.display();
    }
    return 0;
}
/*
    -> faire la page option avec musique sound extc
    faire peut etre page après  play pour le choix des caratères
    ensuite
    choisir la carte er c'est partis
*/