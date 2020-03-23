/*
** EPITECH PROJECT, 2019
** Server.cpp
** File description:
** 
*/

#include "server/Server.hpp"

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
    this->spawn_blue.x = 1;
    this->spawn_blue.y = 22;
    this->spawn_red.x = 79;
    this->spawn_red.y = 22;
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
    send_all("START ");
    init();
    std::cout << "Starting game" << std::endl;
}

void Server::init()
{
    for (uint j = 0; j < players.size(); j++)
    {
        if (j % 2 == 0) 
        {
            players[j].team = Team::BLUE;
            players[j].pos.y = 22 + j;
            players[j].pos.x = 1;
        }
        else
        {
            players[j].team = Team::RED;
            players[j].pos.y = 22 + j;
            players[j].pos.x = 79;
        }
    }
    playerRegister newplayer;
    sf::Packet packet;
    for (uint j = 0; j < players.size(); j++)
    {
            char c;
            if (players[j].team == BLUE)
                newplayer.c = 'b';
            else
                newplayer.c = 'r';
            newplayer.x = players[j].pos.x;
            newplayer.y = players[j].pos.y;
            newplayer.stop = false;
            packet << newplayer; 
            sf::Socket::Status status;
            for (uint i = 0; i < this->clients.size(); i++) {
                status =(*clients[i]).send(packet);
                if (status == sf::Socket::Partial)
                    status = (*clients[i]).send(packet);
                if (status != sf::Socket::Done) 
                    throw ServerError("Error send_all", "ServerError");
                std::cout << "Sending to client " << i << " player " << j << std::endl;
            }
            packet.clear();
    }
    std::this_thread::sleep_for(std::chrono::seconds(1));
    newplayer.x = 0;
    newplayer.y = 0;
    newplayer.c = 0;
    newplayer.stop = true;
    packet << newplayer;
    send_all(packet);
    std::cout << "INITEND" << std::endl;
    send_id();
    process();
}

void Server::send_id()
{
    sf::Packet packet;
    for (uint i = 0; i < clients.size(); i++)
    {
        packet << i;
        if ( (*this->clients[i]).send(packet) != sf::Socket::Done)
            throw ServerError("Error in send_id()", "ServerError");
        packet.clear();
    }
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
                sf::Packet packet;
                Movement movement;
                if ((*clients[i]).receive(packet) != sf::Socket::Done)
                {
                    throw ServerError("Error while receiving msg", "ServerError");
                }
                packet >> movement;
                if (movement.type == "MOVE") {
                    std::cout << "PLAYER " << i << "MOVE to " << movement.x << " " << movement.y << std::endl;
                    movement.id = i;
                    players[i].pos.x = movement.x;
                    players[i].pos.y = movement.y;
                    packet.clear();
                    packet << movement;
                    send_all(packet);
                } else if (movement.type == "FIRE") {
                    handle_shoot(movement, i);
                }
            }
        }
        } else
        {
            std::cout << "[SERVER]: Nothing appends in the last 10 secondes" << std::endl;
        }
    
}

void Server::player_get_shot(int i)
{
    Movement movement;
    sf::Packet packet;
    std::cout << "PLAYER " << players[i].name << " GET SHOT\n";
    if (players[i].team == Team::BLUE) {
        players[i].pos = spawn_blue;
        movement.x = spawn_blue.x;
        movement.y = spawn_blue.y;
    } else {
        players[i].pos = spawn_red;
        movement.x = spawn_red.x;
        movement.y = spawn_red.y;
    }
    movement.type = "MOVE";
    movement.id = i;
    packet << movement;
    send_all(packet);
}

void Server::handle_shoot(Movement shot, int idx)
{
    Direction dir = (Direction) shot.id;
    Movement movement;
    sf::Packet packet;

    int inc = 0;
    if (dir == UP || dir == LEFT)
        inc = -1;
    if (dir == DOWN || dir == RIGHT)
        inc = 1;
    
    if (dir == UP)
        for (uint i = 0; i < players.size(); i++)
            if (i != idx && players[i].pos.x == players[idx].pos.x && players[idx].pos.y > players[i].pos.y && players[idx].team != players[i].team)
               player_get_shot(i);
    if (dir == DOWN)
        for (uint i = 0; i < players.size(); i++)
            if (i != idx && players[i].pos.x == players[idx].pos.x && players[idx].pos.y < players[i].pos.y && players[idx].team != players[i].team)
                player_get_shot(i);
    if (dir == RIGHT)
        for (uint i = 0; i < players.size(); i++)
            if (i != idx && players[i].pos.y == players[idx].pos.y && players[idx].pos.x < players[i].pos.x && players[idx].team != players[i].team)
                player_get_shot(i);
    if (dir == LEFT)
        for (uint i = 0; i < players.size(); i++)
            if (i != idx && players[i].pos.y == players[idx].pos.y && players[idx].pos.x > players[i].pos.x && players[idx].team != players[i].team)
                player_get_shot(i);
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

void Server::send_all(const std::string &msg)
{
    for (uint i = 0; i < this->clients.size(); i++)
        if ((*clients[i]).send(msg.c_str(), msg.length()) != sf::Socket::Done)
            throw ServerError("Error send_all", "ServerError");
}

void Server::send_all(sf::Packet packet)
{
    for (uint i = 0; i < this->clients.size(); i++) {
        sf::Packet p(packet);
        if ((*clients[i]).send(p) != sf::Socket::Done)
            throw ServerError("Error send_all", "ServerError");
    }
}