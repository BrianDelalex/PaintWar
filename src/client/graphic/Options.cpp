/*
** EPITECH PROJECT, 2020
** PaintWar
** File description:
** Options
*/

#include "../../../inc/client/graphic/start.hpp"

Options::Options()
{
    sf::IntRect rect (0, 0, 1920, 1080);
    this->texture.loadFromFile("src/client/graphic/picture/printop.jpg");
    this->sprite.setTexture(this->texture);
    this->sprite.setTextureRect(rect);
}

Options::~Options()
{
}

int options(void)
{
    Menu menu;
    Options opt;

    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Options Page");
    while (window.isOpen())
    {
        sf::Vector2i localPosition = sf::Mouse::getPosition(window);
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                if ((localPosition.x >= 5 && localPosition.x <= 915) && (localPosition.y >= 663 && localPosition.y <= 1059)) {
                    start();
                    window.close();
                }
            }
            if (event.type == sf::Event::Closed)
                window.close();
        }
    window.clear();
    window.draw(opt.sprite);
    init_text(opt, &window);
    init_button_back(opt, &window);
    init_vol_50(opt, &window);
    init_vol_75(opt, &window);
    init_vol_25(opt, &window);
    init_vol_100(opt, &window);
    window.display();
    }
    return (0);
}
