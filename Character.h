#ifndef CHARACTER_HEADER
#define CHARACTER_HEADER

#include <string>

class Character {

    public:
        Character(const std::string, const int, const int);
        std::string getName();
        void sufferDamage(const int);
        void hit(Character*);
        void fight(Character*);
        bool isDead();
        void setATK(int);
        int getATK();
        void setHP(const int value);
        int getHP();
        void printStatus();
        void setName(std::string);

    protected:
        std::string name;
        int HP;
        int ATK;
};

#endif // CHARACTER_HEADER