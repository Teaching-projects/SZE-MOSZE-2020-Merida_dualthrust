/**
 * @file Hero.h
 * @author lapatkrisz
 * @brief Hero class
 * 
 * This class contains basic methods and data for leveling up our characters.
 * With each level-up, the maximum HP also increases, level-ups are calculated from the acquired XP.
 * 
 * @version 1.0
 * @date 2020-11-01
 * 
 */

#ifndef HERO_HEADER
#define HERO_HEADER

#include <string>
#include "Monster.h"
#include "Damage.h"

class Hero : public Monster{
    protected:
        /**
         * @brief Tracking the units current level.
         * 
         */
        int level;

        /**
         * @brief Tracking the units maximum HealthPoints.
         * 
         * lvlUp() uses this to raise a units HP after a level up, and uses it to set the current up to max.
         * 
         */
        int maximumHealthPoint;

        /**
         * @brief Shows how far our hero can see the map.
         * 
         */
        int lightradius;

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
        const int magicaldamageBonusPerLevel;

        /**
         * @brief Extra defense per level.
         * 
         */
        const int defenseBonusPerLevel;

        /**
         * @brief Extra lightradius - viewrange - per level. 
         * 
         */
        const float lightradiusBonusPerLevel;

        /**
         * @brief Member variable responsible for the rate of change in a given Hero's cooldown after leveling up. 
         * 
         */
        const float cooldownMultiplierPerLevel;

        /**
         * @brief Handles the leveling of a unit.
         * 
         When the unit's XP hits the needed amount described in the JSON file of the unit.
         After leveling up, the unit's stats change based on the levelup rate also described in the JSON file
         * 
         */
        void levelUp();
          
    public:
    
        /**
         * @brief Constructor for our Hero class.
         * 
         * @param name
         * @param heatlhPoints
         * @param damage
         * @param defense
         * @param lightradius
         * @param cooldown
         * @param experiencePerLevel
         * @param healthPointBonusPerLevel
         * @param damageBonusPerLevel
         * @param defenseBonusPerLevel
         * @param lightradiusBonusPerLevel
         * @param cooldownMultiplierPerLevel
         * 
         * @return Hero
         */
        Hero(const std::string&, int, Damage, int, int, double, const int, const int, const int, const int, const int, const int, const float);
        /**
         * @brief Getter for maximum health points of our Hero.
         * 
         * @return int const&
         * 
         */
        int const & getMaxHealthPoints(/**There's no input parameter here.*/) const;

        /**
         * @brief Getter for level of our Hero.
         * 
         * @return  int const&
         * 
         */
        int const & getLevel(/**There's no input parameter here.*/) const;   
        /**
         * @brief Getter for the lightrange - viewrange - of our Hero.
         * 
         * @return  int const&
         * 
         */
        int const & getLightRadius(/**There's no input parameter here.*/) const;    

        /**
         * @brief Provides data for our constructor.
         * 
         * Same as the Monster class's, only difference is that it returns a Hero object instead of a Monster.
         * 
         * @param Path to our JSON file.
         * 
         * @return Hero 
         * 
         */
        static Hero parse(const std::string&);

        /**
         * @brief Calls the enemy units sufferDamage() method, and handles the Hero units XP gain.
         * 
         * Also calls the lvlUp() method when sufficient XP is gained for a levelup.
         * 
         * @param enemy Pointer to a Monster object.
         * 
         */
        void deliverHit(Monster* enemy) override;
    };

#endif // HERO_HEADER