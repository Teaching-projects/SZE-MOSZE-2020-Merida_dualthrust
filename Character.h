#ifndef CHARACTER_HEADER
#define CHARACTER_HEADER

#include <string>

class Character {

public:
    Character(const std::string, const int, const int);
    std::string getName();
    int getATK();
    int getHP();
    void sufferDamage(const int);
    void hit(Character*);
    void fight(Character*);
    bool isDead();
    void printStatus();

protected:
    const std::string name;
    const int ATK;
    int HP;
};

#endif // CHARACTER_HEADER