/*
** EPITECH PROJECT, 2019
** Client.cpp
** File description:
** 
*/

#include "client/network/Client.hpp"

sf::Packet& operator<<(sf::Packet& packet, const playerRegister& m)
{
    return packet << m.x << m.y << m.c << m.stop;
}

sf::Packet& operator>>(sf::Packet& packet, playerRegister& m)
{
    return packet >> m.x >> m.y >> m.c >> m.stop;
}

sf::Packet& operator<<(sf::Packet &packet, const Movement&m)
{
    return packet << m.type << m.x << m.y << m.id;
}

sf::Packet& operator>>(sf::Packet &packet, Movement &m)
{
    return packet >> m.type >> m.x >> m.y >> m.id;
}

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
        Movement movement;
        sf::Packet packet;
        if (this->_socket.receive(packet) != sf::Socket::Done)
        {
            throw ClientError("Unable to receive message", "ClientError");
        }
        packet >> movement;
        if (movement.type == "MOVE")
        {
            game.players[movement.id].pos.x = movement.x;
            game.players[movement.id].pos.y = movement.y;
            if (game.players[movement.id].team == BLUE)
                game.map[movement.y][movement.x] = '2';
            else
                game.map[movement.y][movement.x] = '1';
        }
        cb(game);
        packet.clear();
        //std::cout << msg << std::endl;
    }
}

uint Client::get_id()
{
    sf::Packet packet;
    uint id;
    if (this->_socket.receive(packet) != sf::Socket::Done)
        throw ClientError("Error in get_id()", "ClientError");
    packet >> id;
    game.me = id;
    cb(game);
    return id;
}

void Client::init()
{
    sf::Packet packet;
    playerRegister playerReg;
    while (1)
    {
        if (this->_socket.receive(packet) != sf::Socket::Done)
            throw ClientError("Error during init", "ClientError");
        packet >> playerReg;
        packet.clear();
        if (playerReg.stop == true) {
            for (uint i = 0; i < game.players.size(); i++)
            {
                if (game.players[i].team == BLUE)
                    game.map[game.players[i].pos.y][game.players[i].pos.x] = '2';
                else
                    game.map[game.players[i].pos.y][game.players[i].pos.x] = '1';
            }
            cb(game);
            return;
        }
        if (playerReg.stop == false)
        {
            player_t new_player;
            new_player.pos.x = playerReg.x;
            new_player.pos.y = playerReg.y;
            if (playerReg.c == 'b')
                new_player.team = BLUE;
            else
                new_player.team = RED;
            game.players.push_back(new_player);
        }
    }
}

void Client::move(uint x, uint y)
{
    Movement move;
    sf::Packet packet;
    move.type = std::string("MOVE");
    move.x = x;
    move.y = y;
    move.id = -1;
    packet << move;
    if (this->_socket.send(packet) != sf::Socket::Done)
        throw ClientError("Error went sending movement", "ClientError");
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