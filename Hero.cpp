#include "Monster.h"
#include "Hero.h"
#include "JSON.h"
#include <iostream>
#include <string>
#include <cmath>

    Hero::Hero(const std::string& characterName, int characterHP, int characterATK, double characterACD, int XPperlevel, int HPperlevel, int DMGperlevel, float ACDperlevel) : Monster(characterName, characterHP, characterATK, characterACD), LVL(0), maxHP(characterHP), XP(0), experience_per_level(XPperlevel), health_point_bonus_per_level(HPperlevel), damage_bonus_per_level(DMGperlevel), cooldown_multiplier_per_level(ACDperlevel)
    {

    }

    int const & Hero::getMaxHealthPoints() const
    {
        return maxHP;
    }

    int const & Hero::getLevel() const
    {
        return LVL;
    }

    void Hero::lvlUp()
    {
        maxHP   +=  health_point_bonus_per_level;
        maxHP   =   round(maxHP);
        ATK     += damage_bonus_per_level;
        ACD     *= cooldown_multiplier_per_level;
        this->HP      =   maxHP;        
        LVL     +=  1;
    }
    
    Hero Hero::parse(const std::string& path)  //JSON parse method for creating a Monster object based on a given JSON input file
    {
        std::map<std::string, std::string> parsedMap = JSON::parseFromFile(path).content;
        std::string name = parsedMap["name"];
        int hp = std::stoi(parsedMap["base_health_points"]);
        int dmg = std::stoi(parsedMap["base_damage"]);
        float ACD = std::stof(parsedMap["base_attack_cooldown"]);

        int experience_per_level          = std::stoi(parsedMap["experience_per_level"]);
        int health_point_bonus_per_level  = std::stoi(parsedMap["health_point_bonus_per_level"]);
        int damage_bonus_per_level        = std::stoi(parsedMap["damage_bonus_per_level"]);
        float cooldown_multiplier_per_level = std::stof(parsedMap["cooldown_multiplier_per_level"]);

        return Hero(name, hp, dmg, ACD, experience_per_level, health_point_bonus_per_level, damage_bonus_per_level, cooldown_multiplier_per_level);
    }

    void Hero::deliverHit(Monster* enemy) 
    {
        int enemyHP     =   enemy->getHealthPoints();
        int XP_ToGain   =   0;

        if (enemyHP < ATK)
        {
            XP_ToGain   =   enemyHP;
        }
        else
        {
            XP_ToGain   =   ATK;
        }              

        enemy -> sufferDamage(this);

        XP  +=  XP_ToGain;
        
        if (XP>=experience_per_level)
        {
            int LVL_ToGain = XP / experience_per_level;
            for (int i = 0; i < LVL_ToGain; i++)
            {
                this->lvlUp();
            }
            XP  -=  LVL_ToGain * experience_per_level;            
        }
    }