#ifndef HERO_HEADER
#define HERO_HEADER

#include <string>
#include "Monster.h"

class Hero : public Monster{
    protected:
        int level;        ///<Tracking the units current level
        int maximumHealthPoint;      ///<Tracking the maximum healthPoint, levelUp() uses this to raise a units healthPoint after a level up, and uses it to set the current up to max
        int experience;         ///<Tracking the units current experience. When using the deliverHit() method experience is given to a unit based on its damage inflicted to the enemy, from which levelups are calculated
        const int experiencePerLevel;
        const int healthPointBonusPerLevel;
        const int damageBonusPerLevel;
        const float cooldownMultiplierPerLevel;
        void levelUp();   ///<levelUp() method is used by in the deliverHit() method. When a units experience is above or equal to 100, it is called - how many times is dependant on experience, if it has N times 100 experience it is called N times. Sets a units maximumHP and damage to 1.1 times the current value. Also it sets current healthPoint to maximumHP.
          
    public:
        Hero(const std::string&, int, int, double, const int, const int, const int, const float);    ///<Constructor for our Hero class. Uses the same inputs as a Monster class.
        /**
         * @brief Getter for maximum health points of our Hero
         * @return  double const&
         */
        int const & getMaxHealthPoints(/**There's no input parameter here.*/) const;
        /**
         * @brief Getter for level of our Hero
         * @return  double const&
         */
        int const & getLevel(/**There's no input parameter here.*/) const;
        
        static Hero parse(const std::string&);       ///<The parseUnit() method provides data for our constructor. Same as the Monster class's, only difference is that it returns an Hero object instead of a Monster.
        void deliverHit(Monster* enemy) override;                 ///<The deliverHit() method calls the enemy units sufferDamage() method, and handles the Hero units experience gain. It also calls the levelUp() method when sufficient experience is gained for a levelup.
    };

#endif // HERO_HEADER