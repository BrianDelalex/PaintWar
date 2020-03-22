/*
** EPITECH PROJECT, 2020
** startmenujam
** File description:
** start
*/

#include "../../../inc/client/graphic/start.hpp"

Menu::Menu()
{

    sf::IntRect rect (0, 0, 1920, 1080);
    this->texture.loadFromFile("src/client/graphic/picture/menu.png");
    this->sprite.setTexture(this->texture);
    this->sprite.setTextureRect(rect);
}

Menu::~Menu()
{

}

int error_management(int a, char **v)
{
    if (a > 1 && v[1][0] == '-') {
        std::cout << "Pour participer à ce jeu c'est très simple." << std::endl;
        std::cout << "Il vous suffit de mettre dans cette ordre:" << std::endl;
        std::cout << "Votre nom de joueur." << std::endl;
        std::cout << "Votre adresse Ip." << std::endl;
        std::cout << "Votre port" << std::endl;
        return (0);
    }
}

int start(int a, char **v)
{
    Menu menu;

    error_management(a, v);

    menu._username = v[1];
    menu._ip = v[2];
    menu._port = std::stoi(v[3]);
    std::cout << menu._username << "  " << menu._ip << " "<< menu._port << std::endl;

    sf::RenderWindow window(sf::VideoMode(1920, 1080), "PaintWar");

    while (window.isOpen())
    {
        sf::Vector2i localPosition = sf::Mouse::getPosition(window);
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                if ((localPosition.x >= 24 && localPosition.x <= 718) && (localPosition.y >= 657 && localPosition.y <= 796)) {
                    printf("options");
                    options();
                }
                    // OPTIONS music extc
                if ((localPosition.y <= 796 && localPosition.y >= 657) && (localPosition.x <= 1145 && localPosition.x >= 730)) {
                    printf("play\n");
                    window.close();
                    connexion_page();
                }
                    // PLAY jeu vidéo affichage map
                if ((localPosition.y <= 796 && localPosition.y >= 657) && (localPosition.x <= 1708 && localPosition.x >= 1300))
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