#ifndef _PLAYER_
#define _PLAYER_

#include "Gun.hpp"
enum Team
{
    BLUE,
    RED
};

typedef struct vec_s
{
    int x;
    int y;
};

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

private:
    std::string _name;
    std::string _color;
    vec_s _pos;
    Gun *_gun;
    Direction _dir;
};

#endif