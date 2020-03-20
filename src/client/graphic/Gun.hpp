#ifndef _GUN_
#define _GUN_

#include <string>
#include <vector>

class Gun
{
private:
    int _range;
    int _bullets;
public:
    Gun(int range = 5, int bullets = 2) : _range(range), _bullets(bullets);
    ~Gun();
    void fire();
};

void Gun::fire() {
    printf("fire");
}


#endif