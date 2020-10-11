#include "Character.h"
#include "Player.h"
#include "Utility.h"
#include <iostream>
#include <string>

    /* Egy levelup branchen keszuljon egy olyan Kalandor/Player osztaly, mely a korabbi harcoshoz hasonlit, azonban minden utes utan kap annyi XP-t, 
    amennyi sebzest bevitt. Minden 100 XP osszegyujtese utan szintet lep, aminek a kovetkezo hatasai vannak:

    max HP megno 10%-kal (egeszre kerekitve)
    DMG megno 10%-kal
    az aktualis HP felmegy max HP-ra

    Figyelem: az XP novelo logika fusson le akkor is, ha a playert tamadjak meg, nem csak akkor, ha O tamad! Illetve szintlepes csata kozben is tortenhet.
    Az uj funkcio tesztelesere keszuljenek egyszeru in-out tesztek, ahol 1-2 szintlepes megtortenik.
    Ezen a branchen keruljon be statikus kodanalizis, valamint a teszt futtatasok mar ugy tortenjenek, hogy a memoriaszemeteles is ellenorizve legyen. 
    A GHA workflow hasaljon el, ha barmilyen memoriaszemet keletkezik, vagy a statikus kodellenorzo barmilyen errort / warningot talal. 
    A stilus/teljesitmeny uzeneteket csak tegye bele egy fajlba, es artifactolja el.
    */

    Player::Player(const std::string characterName,const int characterHP, int characterATK) : Character(characterName, characterHP, characterATK) 
    { 
        maxHP=characterHP;
    }   

    void Player::lvlUp(){
        maxHP *= 1.1;
        this ->ATK*=1.1;
        HP = maxHP;
        LVL+=1;
        
    }

    //JSON parse method for creating a Character object based on a given JSON input file
    Player* Player::parseUnit(const std::string& path)
    {
        std::vector<std::string> unit_data = Utility::getJsonData(path);

        if (unit_data.size() > 0) {
            return new Player(unit_data[0], std::stoi(unit_data[1]), std::stoi(unit_data[2]));
        }
        else
        {
            //If the input file doesn't exist, we return null
            return NULL;
        }
    }

    void Player::deliverHit(Character* enemy) 
    {
        int enemyHP = enemy->getHP();
        int XP_ToGain = 0;

        if (enemyHP < ATK)
        {
            XP_ToGain = enemyHP;
        }
        else
        {
            XP_ToGain = ATK;
        }              

        enemy -> sufferDamage(this);

        XP+=XP_ToGain;
        
        if (XP>=100)
        {
            int LVL_ToGain = XP / 100;
            for (int i = 0; i < LVL_ToGain; i++)
            {
                lvlUp();
            }
            XP -= LVL_ToGain * 100;            
        }
        std::cout<< this->getName() 
                    + " jumped to level: " 
                    + std::to_string(this->LVL) 
                    + ". \tWith this, it's HP is increased to "
                    + std::to_string(maxHP)
                    + ", and it's ATK is increased to "
                    + std::to_string(getATK())+"."/* 
                    + " \tCurrent HP is "+std::to_string(getHP()) */
                    + "\n";
        
    }