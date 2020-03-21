/*
** EPITECH PROJECT, 2019
** Client.cpp
** File description:
** 
*/

#include "client/network/Client.hpp"

Client::Client()
{
    this->nb_player = 0;
}

Client::~Client() {}

void Client::connect(const sf::IpAddress &adresse, unsigned short port, const std::string &name, game_t game)
{
    if (this->_socket.connect(adresse, port) != sf::Socket::Done)
    {
        throw ClientError(std::string("Unable to connect to" + adresse.toString()), "ClientError");
    }
    this->_is_connected = true;
    this->game = game;
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
        interpreter(msg);
        //cb(nb_player);
        //std::cout << msg << std::endl;
    }
}

void Client::init()
{
    std::size_t msgLength;
    std::string cmd;
    std::string args;
    while (1)
    {
        char msgC[100];
        if (this->_socket.receive(msgC, 100, msgLength) != sf::Socket::Done)
            throw ClientError("ERROR during init", "Client error");
        std::string msg(msgC);
        cmd = msg.substr(0, msg.find_first_of(" ", 0));
        args = msg.substr(msg.find_first_of(" ", 0) + 1, msg.length() - msg.find_first_of(" ", 0));
        std::cout << "cmd: " << cmd << std::endl;
        std::cout << "args: " << args << std::endl;
        if (cmd == "INITEND") {
            cb(game);
            std::cout << "HERE" << std::endl;
            return;
        }
        if (cmd == "PLAYER")
        {
            int first_space = args.find_first_of(" ", 0);
            int last_space = args.find_last_of(" ");
            player_t new_player;
            std::cout << args.substr(0, first_space) << std::endl;
            std::cout << args.substr(first_space + 1, args.length() - first_space - last_space) << std::endl;
            int x = std::stoi(args.substr(0, first_space));
            int y = std::stoi(args.substr(first_space + 1, args.length() - first_space - last_space));
            new_player.pos.x = x;
            new_player.pos.y = y;
            if (args[args.length() - 1] == 'b')
                new_player.team = BLUE;
            else
                new_player.team = RED;
            game.players.push_back(new_player);
        }
    }
}

void Client::interpreter(const std::string &msg)
{
    std::string cmd = msg.substr(0, msg.find_first_of(" ", 0));
    std::string args = msg.substr(msg.find_first_of(" ", 0) + 1, msg.length() - msg.find_first_of(" ", 0));

    if (cmd == "MOVE") {
        int first_space = args.find_first_of(" ", 0);
        int last_space = args.find_last_of(" ");
        uint id = std::stoi(args.substr(0, first_space));
        uint x = std::stoi(args.substr(first_space + 1, args.length() - first_space - last_space));
        uint y = std::stoi(args.substr(last_space, args.length() - last_space));
        std::cout << "MOVE: " << "id: " << id   << " x: " << x << " y: " << y << std::endl; 
    }
    if (cmd == "INFO")
    {
        std::cout << args << std::endl;
    }
}

void Client::setCallback(std::function<void(game_t)> func)
{
    this->cb = func;
}

bool Client::is_connected() { return (_is_connected); }

std::string Client::wait_start()
{
    char msg[100];
    std::size_t msgLength;
    if (this->_socket.receive(msg, 100, msgLength) != sf::Socket::Done)
        throw ClientError("Error while waiting game start", "ClientError");
    return (msg);
}