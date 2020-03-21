/*
** EPITECH PROJECT, 2019
** Client.hpp
** File description:
** Object that manage connection to server
*/

#ifndef CLIENT_HPP_
#define CLIENT_HPP_

#include <SFML/Network.hpp>
#include "client/network/ClientError.hpp"
#include <functional>



class Client
{
public:
    Client();
    ~Client();
    void connect(const sf::IpAddress &adresse, unsigned short port, const std::string &name);
    void send(const std::string &msg);
    void received();
    void setCallback(std::function<void(int)> cb);
    bool is_connected();
private:
    sf::TcpSocket _socket;
    bool _is_connected;
    std::function<void(int)> cb;
    int nb_player;
};

#endif
