#include "client/graphic/Player.hpp"


Player::Player()
{
    _gun = new Gun;
}

void Player::setName(std::string name)
{
    _name = name;
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

std::string Player::getName() const
{
    return _name;
}

Direction Player::getDir() const
{
    return _dir;
}

void Player::shoot()
{
    _gun->fire(_dir);
    //send ("FIRE _dir")
}

vec_s Player::getPosition() const
{
    return _pos;
}

void Player::setPosition(vec_s pos)
{
    _pos = pos;
}

void Player::setClient(Client *client)
{
    _client = client;
}

void Player::move(Direction d)
{
    switch (d)
    {
    case Direction::DOWN:
        _pos.y++;
        break;
    case Direction::LEFT:
        _pos.x--;
        break;
    case Direction::RIGHT:
        _pos.x++;
        break;
    case Direction::UP:
        _pos.y--;
        break;
    default:
        break;
    }
    std::string data = "MOVE " + std::to_string(_pos.x) + std::to_string(_pos.y);
    std::cout << data << std::endl;
    _client->send(data);
}

std::string Player::getColor() const
{
    return _color;
}