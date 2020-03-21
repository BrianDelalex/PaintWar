/*
** EPITECH PROJECT, 2019
** Server.cpp
** File description:
** 
*/

#include "server/Server.hpp"

Server::Server()
{
}

Server::~Server() {}

void Server::start(unsigned short port)
{
    if (listener.listen(port) != sf::Socket::Done)
    {
        throw ServerError("Error while opening port", "ServerError");
    }
    this->selector.add(listener);
    this->connectingPlayer = true;
    this->serverOn = false;
}

void Server::connecting_player()
{
    while (connectingPlayer)
    {
        if (selector.wait(sf::seconds(10)))
        {
            if (selector.isReady(listener))
            {
                sf::TcpSocket *client = new sf::TcpSocket;
                if (listener.accept(*client) != sf::Socket::Done)
                {
                    throw ServerError("Error while accepting client", "ServerError");
                }
                clients.push_back(client);
                Ply player;
                players.push_back(player);
                char msg[100];
                std::size_t msgLength;
                if (client->receive(msg, 100, msgLength) != sf::Socket::Done)
                    throw ServerError("Error while receiving connection infos", "ServerError");
                connection_info(msg);
            }
        } else
        {
            std::cout << "[SERVER]: Nothing appends in the last 10 secondes" << std::endl;
        }
    }
}

void Server::start_game()
{
    this->connectingPlayer = false;
    this->serverOn = true;
    this->selector.clear();
    for (uint i = 0; i < this->clients.size(); i++)
    {
        this->selector.add((*this->clients[i]));
    }
    std::cout << "Starting game" << std::endl;
}

void Server::process()
{
    while (this->serverOn)
        if (this->selector.wait(sf::seconds(10)))
        {
            for (int i = 0; i < (int) clients.size(); i++)
        {
            if (selector.isReady((*clients[i])))
            {
                char msg[100];
                size_t msgLength;
                if ((*clients[i]).receive(msg, 100, msgLength) != sf::Socket::Done)
                {
                    throw ServerError("Error while receiving msg", "ServerError");
                }
                if (i < (int) this->players.size())
                    std::cout << "[" << this->players[i].name << "]: " << msg << std::endl; 
                else
                    std::cout << "[CLIENT " << i << "]: " << msg << std::endl; 
                interpreter(std::string(msg), (uint) i);
            }
        }
        } else
        {
            std::cout << "[SERVER]: Nothing appends in the last 10 secondes" << std::endl;
        }
    
}

void Server::new_player(const std::string &name, uint idx)
{
    for (uint i = 0; i < this->clients.size(); i++)
    {
        if (i != idx)
            if ((*clients[i]).send(std::string("INFO " + name + " connected.").c_str(), 100) != sf::Socket::Done)
                throw ServerError("Error while sending new player", "ServerError");
    }
}

void Server::player_move(const std::string &args, uint idx)
{
    std::string toSend("MOVE " + std::to_string(idx) + " " + args);
    for (uint i = 0; i < clients.size(); i++)
        if (i != idx)
            if ((*clients[i]).send(toSend.c_str(), toSend.length()) != sf::Socket::Done)
                throw ServerError("Error while sending player movement", "ServerError");
}

void Server::interpreter(const std::string &msg, uint i)
{
    std::string cmd = msg.substr(0, msg.find_first_of(" ", 0));
    std::string args = msg.substr(msg.find_first_of(" ", 0) + 1, msg.length() - msg.find_first_of(" ", 0));
    if (cmd == "MOVE")
    {
        player_move(args, i);
    }
}

void Server::connection_info(const std::string &msg)
{
    std::string cmd = msg.substr(0, msg.find_first_of(" ", 0));
    std::string args = msg.substr(msg.find_first_of(" ", 0) + 1, msg.length() - msg.find_first_of(" ", 0));
    if (cmd == "NAME")
    {
        this->players.back().name = args;
        new_player(this->players.back().name, this->players.size() - 1);
        std::cout << "[SERVER]: " << args << " connected.\n";
    }
    
}