/*
** EPITECH PROJECT, 2020
** PaintWar
** File description:
** Init_text
*/

#include "../../../inc/client/graphic/start.hpp"

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

int init_vol_25(Options opt, sf::RenderWindow *window)
{
    if (!opt.font.loadFromFile("src/client/graphic/picture/JUICE.TTF")) {
        printf("stylesheet not found!!!");
        return (84);
    }
    opt.font.loadFromFile("src/client/graphic/picture/JUICE.TTF");
    opt.volume_25.setFont(opt.font);
    opt.volume_25.setPosition(100, 200);
    opt.volume_25.setCharacterSize(100);
    opt.volume_25.setString("Objectif: Gagnez la partie !!");
    window->draw(opt.volume_25);
    return (0);
}

int init_vol_50(Options opt, sf::RenderWindow *window)
{
    if (!opt.font.loadFromFile("src/client/graphic/picture/JUICE.TTF")) {
        printf("stylesheet not found!!!");
        return (84);
    }
    opt.font.loadFromFile("src/client/graphic/picture/JUICE.TTF");
    opt.volume_50.setFont(opt.font);
    opt.volume_50.setPosition(100, 350);
    opt.volume_50.setCharacterSize(80);
    opt.volume_50.setString("Recouvrir la map de votre peinture !!");
    window->draw(opt.volume_50);
    return (0);
}

int init_vol_75(Options opt, sf::RenderWindow *window)
{
    if (!opt.font.loadFromFile("src/client/graphic/picture/JUICE.TTF")) {
        printf("stylesheet not found!!!");
        return (84);
    }
    opt.font.loadFromFile("src/client/graphic/picture/JUICE.TTF");
    opt.volume_75.setFont(opt.font);
    opt.volume_75.setPosition(100, 500);
    opt.volume_75.setCharacterSize(80);
    opt.volume_75.setString("Tuer les combattans ennemis !!");
    window->draw(opt.volume_75);
    return (0);
}

int init_vol_100(Options opt, sf::RenderWindow *window)
{
    if (!opt.font.loadFromFile("src/client/graphic/picture/JUICE.TTF")) {
        printf("stylesheet not found!!!");
        return (84);
    }
    opt.font.loadFromFile("src/client/graphic/picture/JUICE.TTF");
    opt.volume_100.setFont(opt.font);
    opt.volume_100.setPosition(100, 650);
    opt.volume_100.setCharacterSize(80);
    opt.volume_100.setString("Bonne chance !!");
    window->draw(opt.volume_100);
    return (0);
}