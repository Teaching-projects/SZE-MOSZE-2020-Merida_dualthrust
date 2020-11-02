/**
 * @file Hero.h
 * @author lapatkrisz
 * @brief Hero class
 * 
 * This class contains basic methods and data for leveling up our characters.
 * With each level-up, the maximum HP also increases, level-ups are calculated from the acquired XP.
 * 
 * @version 1.0
 * @date 2020-11-01 * 
 */

#ifndef HERO_HEADER
#define HERO_HEADER

#include <string>
#include "Monster.h"

class Hero : public Monster{
    protected:
        /**
         * @brief Tracking the units current level
         */
        int level;
        /**
         * @brief Tracking the units maximum Health Points
         * 
         * lvlUp() uses this to raise a units HP after a level up, and uses it to set the current up to max.
         */
        int maximumHealthPoint;
        /**
         * @brief Tracking the units current Experience Points.
         * 
         * When using the deliverHit() method XP is given to a unit based on its damage inflicted to the enemy.
         * The levelups are calculated from this.
         * 
         */
        int experience;
        /**
         * @brief Experience needed to level up.
         * 
         */
        const int experiencePerLevel;
        /**
         * @brief Extra health points per level.
         * 
         */
        const int healthPointBonusPerLevel;
        /**
         * @brief Extra attack damage per level.
         * 
         */
        const int damageBonusPerLevel;
        /**
         * @brief Changing the attack speed cooldown time per level.
         * 
         */
        const float cooldownMultiplierPerLevel;
        /**
         * @brief When a units XP is above or equal to 100, it is called.
         * 
         * If a unit has N times 100 XP it is called N times.
         * Sets a units maximumHP and ATK to 1.1 times the current value. Also it sets current HP to maximumHP.
         * lvlUp() method is used by in the deliverHit() method.
         * 
         */
        void levelUp();
          
    public:
        /**
         * @brief Constructor for our Hero class, uses the same inputs as a Monster class.
         */
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
        
        /**
         * @brief Provides data for our constructor.
         * 
         * Same as the Monster class's, only difference is that it returns a Hero object instead of a Monster.
         * 
         * @return Hero 
         */
        static Hero parse(const std::string&);
        /**
         * @brief Calls the enemy units sufferDamage() method, and handles the Hero units XP gain.
         * 
         * Also calls the lvlUp() method when sufficient XP is gained for a levelup.
         * 
         * @param enemy 
         */
        void deliverHit(Monster* enemy) override;
    };

#endif // HERO_HEADER