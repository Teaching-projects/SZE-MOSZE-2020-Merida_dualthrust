#include "Character.h"
#include "Adventurer.h"
#include "Utility.h"
#include <iostream>
#include <string>
#include <cmath>

    Adventurer::Adventurer(const std::string& characterName,const int characterHP, int characterATK, double characterACD) : Character(characterName, characterHP, characterATK, characterACD), LVL(0), maxHP(characterHP), XP(0)
    {

    }

    void Adventurer::lvlUp()
    {
        maxHP   *=  1.1;
        maxHP   =   round(maxHP);
        ATK     *=  1.1;
        this->HP      =   maxHP;        
        LVL     +=  1;
    }
    
    Adventurer* Adventurer::parseUnit(const std::string& path)  //JSON parse method for creating a Character object based on a given JSON input file
    {
        std::map<std::string, std::any> parsedMap = Utility::parseFile(path);
        if (parsedMap.size() > 0) {

            std::string name = std::any_cast<std::string>(parsedMap["name"]);
            try {
                int hp = (int)std::any_cast<float>(parsedMap["hp"]);
                int dmg = (int)std::any_cast<float>(parsedMap["dmg"]);
                float ACD = std::any_cast<float>(parsedMap["acd"]);
                return new Adventurer(name, hp, dmg, ACD);
            }
            catch (std::exception ex) {
                return nullptr;
            }
        }
        else {
            return nullptr;
        }
    }

    void Adventurer::deliverHit(Character* enemy) 
    {
        int enemyHP     =   enemy->getHP();
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