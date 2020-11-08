#include "Monster.h"
#include "Hero.h"
#include "JSON.h"
#include <iostream>
#include <string>
#include <cmath>

    Hero::Hero(const std::string& characterName, int characterHP, int characterATK, double characterACD, int XPperlevel, int HPperlevel, int DMGperlevel, float ACDperlevel) : Monster(characterName, characterHP, characterATK, characterACD), level(1), maximumHealthPoint(characterHP), experience(0), experiencePerLevel(XPperlevel), healthPointBonusPerLevel(HPperlevel), damageBonusPerLevel(DMGperlevel), cooldownMultiplierPerLevel(ACDperlevel)
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
        JSON data    =   JSON::parseFromFile(path);
        std::string name                                =   data.get<std::string>("name");
        int heatlhPoints                                =   data.get<int>("base_health_points");
        int damage                                      =   data.get<int>("base_damage");
        float cooldown                                  =   data.get<float>("base_attack_cooldown");
        int experiencePerLevel                          =   data.get<int>("experience_per_level");
        int healthPointBonusPerLevel                    =   data.get<int>("health_point_bonus_per_level");
        int damageBonusPerLevel                         =   data.get<int>("damage_bonus_per_level");
        float cooldownMultiplierPerLevel                =   data.get<float>("cooldown_multiplier_per_level");

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