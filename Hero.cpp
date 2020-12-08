#include "Hero.h"
#include "JSON.h"
#include <iostream>
#include <string>
#include <cmath>
/* 
        return Hero(name, heatlhPoints, damage, defense, lightradius, cooldown, experiencePerLevel, healthPointBonusPerLevel, damageBonusPerLevel, magicaldamageBonusPerLevel, defenseBonusPerLevel, lightradiusBonusPerLevel, cooldownMultiplierPerLevel);
 */
    Hero::Hero(const std::string& characterName, int characterHP, Damage dmg_struct, int characterDEF, int characterLIGHT, double characterACD, int XPperlevel, int HPperlevel, int DMGperlevel, int MDMGperlevel, int DEFperlevel, int LIGHTperlevel, float ACDperlevel, std::string texture) : Monster(characterName, characterHP, dmg_struct, characterDEF, characterACD, texture), level(1), maximumHealthPoint(characterHP), lightradius(characterLIGHT), experience(0), experiencePerLevel(XPperlevel), healthPointBonusPerLevel(HPperlevel), damageBonusPerLevel(DMGperlevel), magicaldamageBonusPerLevel(MDMGperlevel), defenseBonusPerLevel(DEFperlevel), lightradiusBonusPerLevel(LIGHTperlevel), cooldownMultiplierPerLevel(ACDperlevel)
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
    int const & Hero::getLightRadius() const
    {
        return lightradius;
    }

    void Hero::levelUp()
    {
        maximumHealthPoint  +=  healthPointBonusPerLevel;
        maximumHealthPoint  =   round(maximumHealthPoint);
        damage.physical     +=  damageBonusPerLevel;
        damage.magical      +=  magicaldamageBonusPerLevel;
        defense             +=  defenseBonusPerLevel;   
        lightradius         +=  lightradiusBonusPerLevel;
        cooldown            *=  cooldownMultiplierPerLevel;
        this->healthPoint   =   maximumHealthPoint;        
        level               +=  1;
    }
    
    Hero Hero::parse(const std::string& path)  //JSON parse method for creating a Monster object based on a given JSON input file
    {
        JSON data                           =   JSON::parseFromFile(path);
        std::string name                    =   data.get<std::string>("name");
        std::string texture                 =   data.get<std::string>("texture");
        int heatlhPoints                    =   data.get<int>("base_health_points");
        Damage damage                       = Damage(data.get<int>("base_damage"), data.get<int>("base_magical-damage"));
        int defense                         =   data.get<int>("base_defense");
        int lightradius                     =   data.get<int>("light_radius");
        float cooldown                      =   data.get<float>("base_attack_cooldown");
        int experiencePerLevel              =   data.get<int>("experience_per_level");
        int healthPointBonusPerLevel        =   data.get<int>("health_point_bonus_per_level");
        int damageBonusPerLevel             =   data.get<int>("damage_bonus_per_level");
        int magicaldamageBonusPerLevel      =   data.get<int>("magicaldamage_bonus_per_level");
        int defenseBonusPerLevel            =   data.get<int>("defense_bonus_per_level");
        int lightradiusBonusPerLevel=1;
        if (data.count("light_radius_bonus_per_level"))
        {
            lightradiusBonusPerLevel    =   data.get<int>("light_radius_bonus_per_level");
        }
        float cooldownMultiplierPerLevel    =   data.get<float>("cooldown_multiplier_per_level");

        return Hero(name, heatlhPoints, damage, defense, lightradius, cooldown, experiencePerLevel, healthPointBonusPerLevel, damageBonusPerLevel, magicaldamageBonusPerLevel, defenseBonusPerLevel, lightradiusBonusPerLevel, cooldownMultiplierPerLevel, texture);
    }

    void Hero::deliverHit(Monster* enemy) 
    {
        int enemyHealthPoint    =   enemy   ->  getHealthPoints();
        int physicalDamage      =   this    ->  getPhysicalDamage();
        int magicalDamage       =   this    ->  getMagicalDamage();
        int enemyDefense        =   enemy   ->  getDefense();
        int experienceToGain    =   0;
        
        if (enemyHealthPoint < (physicalDamage - enemyDefense) + magicalDamage)
        {
            experienceToGain   =   enemyHealthPoint;
        }
        else
        {
            experienceToGain   =   (physicalDamage - enemyDefense) + magicalDamage;
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