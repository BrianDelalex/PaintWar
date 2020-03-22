#ifndef _PLAYER_
#define _PLAYER_

#include "Gun.hpp"
#include "client/network/Client.hpp"



class Player
{
public:
    Player();
    ~Player();
    vec_s getPosition() const;
    void setPosition(vec_s);
    void setName(std::string);
    std::string getName(void) const;
    void move(Direction);
    std::string getColor() const;
    void shoot();
    void reload();
    Direction getDir() const;
    void setClient(Client *client);
    void assign(uint id, std::vector<player_s>);

private:
    Client *_client;
    std::string _name;
    std::string _color;
    vec_s _pos;
    Gun *_gun;
    Direction _dir;
};

#endif