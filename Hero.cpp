#include "Monster.h"
#include "Hero.h"
#include "JSON.h"
#include <iostream>
#include <string>
#include <cmath>

    Hero::Hero(const std::string& characterName, int characterHP, int characterATK, double characterACD) : Monster(characterName, characterHP, characterATK, characterACD), LVL(0), maxHP(characterHP), XP(0)
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
        maxHP   *=  1.1;
        maxHP   =   round(maxHP);
        ATK     *=  1.1;
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
        return Hero(name, hp, dmg, ACD);
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
        
        if (XP>=100)
        {
            int LVL_ToGain = XP / 100;
            for (int i = 0; i < LVL_ToGain; i++)
            {
                this->lvlUp();
            }
            XP  -=  LVL_ToGain * 100;            
        }
    }