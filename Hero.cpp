#include "Monster.h"
#include "Hero.h"
#include "JSON.h"
#include <iostream>
#include <string>
#include <cmath>

    Hero::Hero(const std::string& characterName, int characterHP, Damage dmg, int characterDEF, double characterACD, int XPperlevel, int HPperlevel, int DMGperlevel, int MDMGperlevel, int DEFperlevel, float ACDperlevel) : Monster(characterName, characterHP, dmg, characterDEF, characterACD), level(1), maximumHealthPoint(characterHP), experience(0), experiencePerLevel(XPperlevel), healthPointBonusPerLevel(HPperlevel), damageBonusPerLevel(DMGperlevel), magicaldamageBonusPerLevel(MDMGperlevel), defenseBonusPerLevel(DEFperlevel), cooldownMultiplierPerLevel(ACDperlevel)
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
        damage.physical     +=  damageBonusPerLevel;
        damage.magical      +=  magicaldamageBonusPerLevel;
        defense             +=  defenseBonusPerLevel;   
        cooldown            *=  cooldownMultiplierPerLevel;
        this->healthPoint   =   maximumHealthPoint;        
        level               +=  1;
    }
    
    Hero Hero::parse(const std::string& path)  //JSON parse method for creating a Monster object based on a given JSON input file
    {
        JSON data                           =   JSON::parseFromFile(path);
        Damage damage;
        std::string name                    =   data.get<std::string>("name");
        int heatlhPoints                    =   data.get<int>("base_health_points");
        damage.physical                     =   data.get<int>("base_damage");
        damage.magical                      =   data.get<int>("base_magical-damage");
        int defense                         =   data.get<int>("base_defense");
        float cooldown                      =   data.get<float>("base_attack_cooldown");
        int experiencePerLevel              =   data.get<int>("experience_per_level");
        int healthPointBonusPerLevel        =   data.get<int>("health_point_bonus_per_level");
        int damageBonusPerLevel             =   data.get<int>("damage_bonus_per_level");
        int magicaldamageBonusPerLevel      =   data.get<int>("magical_damage_bonus_per_level");
        int defenseBonusPerLevel            =   data.get<int>("defense_bonus_per_level");
        float cooldownMultiplierPerLevel    =   data.get<float>("cooldown_multiplier_per_level");

        return Hero(name, heatlhPoints, damage, defense, cooldown, experiencePerLevel, healthPointBonusPerLevel, damageBonusPerLevel, magicaldamageBonusPerLevel, defenseBonusPerLevel, cooldownMultiplierPerLevel);
    }

    void Hero::deliverHit(Monster* enemy) 
    {
        int enemyHealthPoint    =   enemy   ->  getHealthPoints();
        int enemyDefense        =   enemy   ->  getDefense();
        int experienceToGain    =   0;
        
        if (enemyHealthPoint < damage.physical - enemyDefense + damage.magical)
        {
            experienceToGain   =   enemyHealthPoint;
        }
        else
        {
            experienceToGain   =   damage.physical - enemyDefense + damage.magical;
            if (experienceToGain    <   0)
            {
                experienceToGain    =   0;
            }
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