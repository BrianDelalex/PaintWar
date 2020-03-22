/*
** EPITECH PROJECT, 2019
** connection.cpp
** File description:
** connect client and wait the game start
*/

#include "SFML/Network.hpp"
#include "client/network/Client.hpp"
#include "client/network/ClientError.hpp"

Client *connection(std::string ip, unsigned short port, std::string name, game_t game)
{
    Client *client = new Client;
    std::string str;
    std::function<void (game_t)> func([&game](game_t _game){game = _game;});
    client->setCallback(func);
    try
    {
        client->connect(ip, port, name, game);
    }
     catch(const ClientError& e)
    {
        std::cerr << e.getComponent() << ": " << e.what() << '\n';
    }

    std::string msg;
    std::string cmd;
    std::string args;
    while (1)
    {
        try
        {
            msg = client->wait_start();
        }
        catch(const ClientError& e)
        {
            std::cerr << e.getComponent() << ": " << e.what() << '\n';
        }
        cmd = msg.substr(0, msg.find_first_of(" ", 0));
        args = msg.substr(msg.find_first_of(" ", 0) + 1, msg.length() - msg.find_first_of(" ", 0));
        if (cmd == "START")
        {
            std::cout << "RECEIVED START FROM SERVER" << std::endl;
            return (client);
        }
        if (cmd == "INFO")
            std::cout << args << std::endl;
    }
}