#include "client/graphic/Player.hpp"
#include "client/graphic/Gun.hpp"
#include "def/keyword.h"

void Gun::fire(Direction d __unused)
{
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