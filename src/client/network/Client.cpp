/*
** EPITECH PROJECT, 2019
** Client.cpp
** File description:
** 
*/

#include "Client.hpp"

Client::Client()
{
    this->nb_player = 0;
}

Client::~Client() {}

void Client::connect(const sf::IpAddress &adresse, unsigned short port, const std::string &name)
{
    if (this->_socket.connect(adresse, port) != sf::Socket::Done)
    {
        throw ClientError(std::string("Unable to connect to" + adresse.toString()), "ClientError");
    }
    this->_is_connected = true;
    if (this->_socket.send(std::string("NAME " + name).c_str(), 100) != sf::Socket::Done)
        throw ClientError("Error While sending name", "ClientError");
}

void Client::send(const std::string &msg)
{
    if (this->_socket.send(msg.c_str(), msg.length()) != sf::Socket::Done)
    {
        throw ClientError("Unable to send message", "ClientError");
    }
}

void Client::received()
{
    while (_is_connected)
    {
        char msg[100];
        std::size_t msgLength;
        if (this->_socket.receive(msg, 100, msgLength) != sf::Socket::Done)
        {
            throw ClientError("Unable to receive message", "ClientError");
        }
        this->nb_player++;
        cb(nb_player);
        std::cout << msg << std::endl;
    }
}

void Client::setCallback(std::function<void(int)> func)
{
    this->cb = func;
}

bool Client::is_connected() { return (_is_connected); }