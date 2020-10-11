#include "Character.h"
#include "Adventurer.h"
#include "Utility.h"
#include <iostream>
#include <string>

    Adventurer::Adventurer(const std::string characterName,const int characterHP, int characterATK) : Character(characterName, characterHP, characterATK) 
    { 
        maxHP   =   characterHP;
    }   

    void Adventurer::lvlUp(){
        maxHP   *=  1.1;
        ATK     *=  1.1;
        HP      =   maxHP;
        LVL     +=  1;
        
    }
    
    Adventurer* Adventurer::parseUnit(const std::string& path)  //JSON parse method for creating a Character object based on a given JSON input file
    {
        std::vector<std::string> unit_data = Utility::getJsonData(path);

        if (unit_data.size() > 0) 
        {
            return new Adventurer(unit_data[0], std::stoi(unit_data[1]), std::stoi(unit_data[2]));
        }
        else
        {
            //If the input file doesn't exist, we return null
            return NULL;
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
                lvlUp();
            }
            XP  -=  LVL_ToGain * 100;            
        }
        std::cout<< this->getName() 
                    + " jumped to level: " 
                    + std::to_string(this->LVL) 
                    + ". \tWith this, it's HP is increased to "
                    + std::to_string(maxHP)
                    + ", and it's ATK is increased to "
                    + std::to_string(getATK())+".\n";
        
    }