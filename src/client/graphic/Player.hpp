#ifndef _PLAYER_
#define _PLAYER_

#include "Gun.hpp"

class Player
{
public:
    Player(std::string color);
    ~Player();
    std::vector<int> getPosition() const;
    void move(Direction);
    std::string getColor() const;
    void shoot();
    void reload();

private:
    std::string _color;
    int _x;
    int _y;
    Gun *_gun;
    Direction _dir;
};

#endif