#include "Player.hpp"


Player::Player(std::string color) : _color(color),
                                    _dir(color == "blue" ? Direction::LEFT : Direction::RIGHT)
{
    _gun = new Gun;
}

Player::~Player()
{
    if (_gun)
        delete _gun;
}


void Player::reload()
{
    if (_gun->getAmmo() >= 5)
        _gun->setAmmo(10);
    else
        _gun->setAmmo(_gun->getAmmo() + 5);
}

void Player::shoot()
{
    _gun->fire(_dir);
}

std::vector<int> Player::getPosition() const
{
    return std::vector<int>(_x, _y);
}

void Player::move(Direction d)
{
    switch (d)
    {
    case Direction::DOWN:
        _y++;
        break;
    case Direction::LEFT:
        _x--;
        break;
    case Direction::RIGHT:
        _x++;
        break;
    case Direction::UP:
        _y--;
        break;
    default:
        break;
    }
}

std::string Player::getColor() const
{
    return _color;
}