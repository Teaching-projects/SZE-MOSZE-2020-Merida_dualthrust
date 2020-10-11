#ifndef PLAYER_HEADER
#define PLAYER_HEADER

#include <string>
#include "Character.h"

class Player : public Character{
    protected:
        int ATK;        ///<Redefined here, Character.cpp has it as a const, but the levelups change the value
        int LVL;        ///<Tracking the units current level
        int maxHP;      ///<Tracking the maximum HP, lvlUp() uses this to raise a units HP after a level up, and uses it to set the current up to max
        int XP;         ///<Tracking the units current XP. When using the deliverHit() method XP is given to a unit based on its damage inflicted to the enemy, from which levelups are calculated
        void lvlUp();   ///<lvlUp() method is used by in the deliverHit() method. When a units XP is above or equal to 100, it is called - how many times is dependant on XP, if it has N times 100 XP it is called N times. Sets a units maximumHP and ATK to 1.1 times the current value. Also it sets current HP to maximumHP.
    public:
        Player(const std::string, const int, const int);    ///<Constructor for our Player class. Uses the same inputs as a Character class.
        static Player* parseUnit(const std::string&);       ///<The parseUnit() method provides data for our constructor. Same as the Character class's, only difference is that it returns a Player object instead of a Character.
        void deliverHit(Character* enemy) ;                 ///<The deliverHit() method calls the enemy units sufferDamage() method, and handles the Player units XP gain. It also calls the lvlUp() method when sufficient XP is gained for a levelup.
    };

#endif // PLAYER_HEADER