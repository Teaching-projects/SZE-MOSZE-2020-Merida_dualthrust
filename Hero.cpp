#include "Monster.h"
#include "Hero.h"
#include "JSON.h"
#include <iostream>
#include <string>
#include <cmath>

    Hero::Hero(const std::string& characterName, int characterHP, int characterATK, double characterACD, int XPperlevel, int HPperlevel, int DMGperlevel, float ACDperlevel) : Monster(characterName, characterHP, characterATK, characterACD), level(0), maximumHealthPoint(characterHP), experience(0), experiencePerLevel(XPperlevel), healthPointBonusPerLevel(HPperlevel), damageBonusPerLevel(DMGperlevel), cooldownMultiplierPerLevel(ACDperlevel)
    {

    }

    int const & Hero::getMaxHealthPoints() const
    {
        return maximumHealthPoint;
    }

    int const & Hero::getLevel() const
    {
        return level;
    }

    void Hero::levelUp()
    {
        maximumHealthPoint  +=  healthPointBonusPerLevel;
        maximumHealthPoint  =   round(maximumHealthPoint);
        damage              +=  damageBonusPerLevel;
        cooldown            *=  cooldownMultiplierPerLevel;
        this->healthPoint   =   maximumHealthPoint;        
        level               +=  1;
    }
    
    Hero Hero::parse(const std::string& path)  //JSON parse method for creating a Monster object based on a given JSON input file
    {
        std::map<std::string, std::string> parsedMap    =   JSON::parseFromFile(path).content;
        std::string name                                =   parsedMap["name"];
        int heatlhPoints                                =   std::stoi(parsedMap["base_health_points"]);
        int damage                                      =   std::stoi(parsedMap["base_damage"]);
        float cooldown                                  =   std::stof(parsedMap["base_attack_cooldown"]);
        int experiencePerLevel                          =   std::stoi(parsedMap["experience_per_level"]);
        int healthPointBonusPerLevel                    =   std::stoi(parsedMap["health_point_bonus_per_level"]);
        int damageBonusPerLevel                         =   std::stoi(parsedMap["damage_bonus_per_level"]);
        float cooldownMultiplierPerLevel                =   std::stof(parsedMap["cooldown_multiplier_per_level"]);

        return Hero(name, heatlhPoints, damage, cooldown, experiencePerLevel, healthPointBonusPerLevel, damageBonusPerLevel, cooldownMultiplierPerLevel);
    }

    void Hero::deliverHit(Monster* enemy) 
    {
        int enemyHealthPoint    =   enemy   ->  getHealthPoints();
        int experienceToGain    =   0;

        if (enemyHealthPoint < damage)
        {
            experienceToGain   =   enemyHealthPoint;
        }
        else
        {
            experienceToGain   =   damage;
        }              

        enemy       ->  sufferDamage(this);

        experience  +=  experienceToGain;
        
        if (experience  >=  experiencePerLevel)
        {
            int LVL_ToGain  =   (experience / experiencePerLevel);

            for (int i = 0; i < LVL_ToGain; i++)
            {
                this    ->  levelUp();
            }

            experience  -=  (LVL_ToGain * experiencePerLevel);            
        }
    }