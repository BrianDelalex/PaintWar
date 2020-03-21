/*
** EPITECH PROJECT, 2019
** Server.hpp
** File description:
** 
*/

#ifndef SERVER_HPP_
#define SERVER_HPP_

#include <SFML/Network.hpp>
#include "server/ServerError.hpp"
#include "server/ServerPlayer.hpp"

class Server
{
public:
    Server();
    ~Server();
    void start(unsigned short port);
    void connecting_player();
    void process();
    void interpreter(const std::string &msg, uint i);
    void connection_info(const std::string &msg);
    void start_game();
    void new_player(const std::string &name, uint idx);
    void player_move(const std::string &args, uint idx);
private:
    sf::TcpListener listener;
    std::vector<sf::TcpSocket *> clients;
    std::vector<Ply> players;
    sf::SocketSelector selector;
    bool connectingPlayer;
    bool serverOn;
};

#endif
