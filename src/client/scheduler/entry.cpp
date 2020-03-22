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
    std::vector<std::string> map = load_map();
    game_t *game = new game_t;
    game->map = map;
    Player *self = new Player;
    Client *client = connection("127.0.0.1", std::stoi(std::string(av[2])), av[1], *game);
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
        switch (key) {
        case sf::Keyboard::Up:
            self->move(Direction::UP);
            std::cout << "UP" << std::endl;
            break;
        case sf::Keyboard::Down:
            self->move(Direction::DOWN);
            std::cout << "Down" << std::endl;
            break;
        case sf::Keyboard::Left:
            self->move(Direction::LEFT);
            std::cout << "Left" << std::endl;
            break;
        case sf::Keyboard::Right:
            self->move(Direction::RIGHT);
            std::cout << "Right" << std::endl;
            break;
        case sf::Keyboard::Space:
            self->shoot();
            std::cout << "Fire" << std::endl;
        default:
            break;
        }
    }
    wd->close();
    // Client client;
    // std::string str;
    // game_t game;
    // std::function<void (game_t)> func([&game](game_t _game){game = _game;});
    // client.setCallback(func);
    // try
    // {
    //     client.connect("127.0.0.1", 53000, av[1], &game);
    // }
    // catch(const ClientError& e)
    // {
    //     std::cerr << e.getComponent() << e.what() << '\n';
    // }
    // std::thread t(&Client::received, &client);
    // t.detach();
    // while (1)
    // {
    //     std::this_thread::sleep_for(std::chrono::seconds(3));
    // }
}