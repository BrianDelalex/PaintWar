#include "Player.hpp"
#include "Gun.hpp"

void Gun::fire(Direction d) {
    if (_bullets == 0)
        printf("can't fire");
    else {
        _bullets--;
        printf("fire");
    }
}

int Gun::getAmmo() const
{
    return _bullets;
}

void Gun::setAmmo(int nb)
{
    _bullets = nb;
}