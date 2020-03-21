/*
** EPITECH PROJECT, 2019
** Server.cpp
** File description:
** 
*/

#include "Server.hpp"

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
}

void Server::waiting()
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
            selector.add(*client);
        }
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
            if ((*clients[i]).send(std::string("INFO" + name + " connected.").c_str(), 100) != sf::Socket::Done)
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
    if (cmd == "NAME")
    {
        this->players[i].name = args;
        new_player(this->players[i].name, i);
    }
    if (cmd == "MOVE")
    {

    }
}