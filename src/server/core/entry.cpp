#include "server/Server.hpp"
#include "server/ServerError.hpp"
#include <thread>

int main(int ac, char **av)
{
    Server server;
    int port = 53000;
    if (ac < 2)
    {
        std::cerr << "No port assign taking default 53000" << std::endl;
    } else
    {
        port = std::stoi(av[1]);
    }
    

    try
    {
        server.start((unsigned short) port);
        std::thread t(&Server::connecting_player, &server);
        t.detach();
        std::string str;
        while (std::getline(std::cin, str, '\n'))
        {
            if (str == "start")
                server.start_game();
        }
    }
    catch(const ServerError& e)
    {
        std::cerr << e.getComponent() << ": " << e.what() << '\n';
    }
    
}