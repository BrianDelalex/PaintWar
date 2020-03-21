#ifndef _GUN_
#define _GUN_

#include <string>
#include <vector>

enum Direction
    {
        UP,
        DOWN,
        LEFT,
        RIGHT
    };

class Gun
{
private:
    int _range;
    int _bullets;

public:
    Gun(int range = 5, int bullets = 2) : _range(range), _bullets(bullets) {}
    ~Gun() = default;
    int getAmmo() const;
    void setAmmo(int);
    void fire(Direction);
    void reload();
};

#endif