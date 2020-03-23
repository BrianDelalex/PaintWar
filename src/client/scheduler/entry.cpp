#include "client/network/Client.hpp"
#include "client/graphic/Player.hpp"
#include "client/network/ClientError.hpp"
#include "client/graphic/start.hpp"
#include <thread>
#include "client/graphic/graphic.hpp"
#include "client/scheduler/scheduler.hpp"

extern sf::RenderWindow *wd;

int main(int ac, char **av)
{
    if (error_management(ac, av) == 1)
        return (0);
    std::vector<std::string> map = load_map();
    game_t *game = new game_t;
    game->map = map;
    game->blue = 0;
    game->red = 0;
    Player *self = new Player;
    Client *client = connection(av[2], std::stoi(std::string(av[3])), av[1], *game);
    std::function<void (game_t)> func([&game](game_t _game){*game = _game;});
    client->setCallback(func);
    client->init();
    self->setClient(client);
    self->assign(client->get_id(), game->players);
    std::thread t(&Client::received, client);
    t.detach();
    init();
    int key = 0;
    while (wd->isOpen())
    {
        key = draw_game(*game);
        self->setPosition(game->players[game->me].pos);
        switch (key) {
        case sf::Keyboard::Up:
            self->move(Direction::UP);
            break;
        case sf::Keyboard::Down:
            self->move(Direction::DOWN);
            break;
        case sf::Keyboard::Left:
            self->move(Direction::LEFT);
            break;
        case sf::Keyboard::Right:
            self->move(Direction::RIGHT);
            break;
        case sf::Keyboard::Space:
            self->shoot();
        default:
            break;
        }
    }
    wd->close();
}