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

int init_text(Options opt, sf::RenderWindow *window)
{
    if (!opt.font.loadFromFile("src/client/graphic/picture/JUICE.TTF")) {
        printf("stylesheet not found!!!");
        return (84);
    }
    opt.font.loadFromFile("src/client/graphic/picture/JUICE.TTF");
    opt.options.setFont(opt.font);
    opt.options.setPosition(30,50);
    opt.options.setCharacterSize(150);
    opt.options.setString("OPTIONS");
    window->draw(opt.options);
    return (0);
}

int init_button_back(Options opt, sf::RenderWindow *window)
{
    if (!opt.font.loadFromFile("src/client/graphic/picture/JUICE.TTF")) {
        printf("stylesheet not found!!!");
        return (84);
    }
    opt.font.loadFromFile("src/client/graphic/picture/JUICE.TTF");
    opt.back.setFont(opt.font);
    opt.back.setPosition(30, 850);
    opt.back.setCharacterSize(150);
    opt.back.setString("BACK");
    window->draw(opt.back);
    return (0);
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
    window.display();
    }
    return (0);
}
