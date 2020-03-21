#include "client/network/Client.hpp"
#include "client/network/ClientError.hpp"
#include <thread>

int main(int ac, char **av)
{
    Client client;
    std::string str;
    game_t game;
    std::function<void (game_t)> func([&game](game_t _game){game = _game;});
    client.setCallback(func);
    try
    {
        client.connect("127.0.0.1", 53000, av[1], &game);
    }
    catch(const ClientError& e)
    {
        std::cerr << e.getComponent() << e.what() << '\n';
    }
    std::thread t(&Client::received, &client);
    t.detach();
    while (1)
    {
        std::this_thread::sleep_for(std::chrono::seconds(3));
    }
}