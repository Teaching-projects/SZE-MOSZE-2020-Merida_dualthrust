#include "Character.h"
#include "Adventurer.h"
#include "Utility.h"
#include <iostream>
#include <string>
#include <cmath>

    Adventurer::Adventurer(const std::string& characterName,const int characterHP, int characterATK) : Character(characterName, characterHP, characterATK), XP(0), LVL(0), maxHP(characterHP)
    {

    }

    void Adventurer::lvlUp()
    {
        maxHP   *=  1.1;
        maxHP   =   round(maxHP);
        ATK     *=  1.1;
        this->HP      =   maxHP;        
        LVL     +=  1;
        std::cout << "Max HP: " << maxHP << " HP: " << HP << std::endl;
    }
    
    Adventurer* Adventurer::parseUnit(const std::string& path)  //JSON parse method for creating a Character object based on a given JSON input file
    {
        std::vector<std::string> unit_data = Utility::getJsonData(path);

        if (unit_data.size() == 3) 
        {
            return new Adventurer(unit_data[0], std::stoi(unit_data[1]), std::stoi(unit_data[2]));
        }
        else
        {
            //If the input file doesn't exist, we return null
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