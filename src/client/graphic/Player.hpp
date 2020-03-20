#ifndef _PLAYER_
#define _PLAYER_

#include "Gun.hpp"


class Player 
{
public:
    enum Direction {UP, DOWN, LEFT, RIGHT};
    Player(std::string color);
    ~Player();
    std::vector<int> getPosition() const;
    void move(Direction);

private:
    std::string _color;
    int _x;
    int _y;
    Gun *_gun;
    Direction _dir;
};


Player::Player(std::string color) :
    _color(color),
    _dir(color == "blue" ? Direction::LEFT : Direction::RIGHT)
{
    _gun = new Gun;
}

Player::~Player()
{
}


#endif