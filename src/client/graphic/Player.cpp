#include "client/graphic/Player.hpp"


Player::Player()
{
    _gun = new Gun;
}

Player::~Player()
{
    if (_gun)
        delete _gun;
}

void Player::assign(uint id, std::vector<player_s> arr)
{
    player_s self = arr.at(id);
    _dir = self.team == Team::BLUE ? Direction::RIGHT : Direction::LEFT;
    _pos.x = self.pos.x;
    _pos.y = self.pos.y;
}

void Player::setName(std::string name)
{
    _name = name;
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
    std::string data("FIRE " + std::to_string(_dir));    
    _client->send(data);
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
        if (_pos.y + 1 < 43)
            _pos.y++;
        break;
    case Direction::LEFT:
        if (_pos.x - 1 >= 0)
            _pos.x--;
        break;
    case Direction::RIGHT:
        if (_pos.x + 1 < 80)
            _pos.x++;
        break;
    case Direction::UP:
        if (_pos.y - 1 >= 0)
            _pos.y--;
        break;
    default:
        break;
    }
    _dir = d;
    _client->move(_pos.x, _pos.y);
}

std::string Player::getColor() const
{
    return _color;
}