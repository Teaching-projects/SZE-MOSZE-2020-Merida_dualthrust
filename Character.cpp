#include "Character.h"
#include "Utility.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

    //Constructor
    Character::Character(const std::string characterName,const float characterHP, const float characterATK):name(characterName),HP(characterHP),ATK(characterATK){}


    //Getters
    std::string const & Character::getName() const
    {
        return name;
    }

    float const & Character::getHP() const
    {
        return HP;
    }

    float const & Character::getATK() const
    {
        return ATK;
    }

    //JSON parse method for creating a Character object based on a given JSON input file
    Character* Character::parseUnit(const std::string& path) 
    {
        std::map<std::string, std::any> parsedMap = Utility::parseFile(path);
        if (parsedMap.size() > 0) {

            std::string name = std::any_cast<std::string>(parsedMap["name"]);
            float hp = std::any_cast<float>(parsedMap["hp"]);
            float dmg = std::any_cast<float>(parsedMap["dmg"]);

            return new Character(name, hp, dmg);
        }
        else {
            return NULL;
        }
    }

    //Convenience method for simple checking
    bool Character::isDead() const 
    {
        return getHP() <= 0;
    }

    //Instead of using an HP setter from outside of the class, we declare a 'sufferDamage' method
    //The Character object's HP gets lowered based on the output 
    void Character::sufferDamage(Character* enemy) 
    {
        //std::cout << enemy->getName() << " -> " << this->getName() << std::endl;
        HP = (getHP() - enemy->getATK());
        if (HP < 0)
        {
            HP = 0; 
        }
    }


    //Printing a characters status
    std::ostream& operator<<(std::ostream& os, const Character& character)
    {
        os << character.getName() << ": [HP: "  << character.getHP() << "] [DMG:" << character.getATK() << "]";
        return os;
    }

    //Fight function - a pointer to the enemy is passed as an argument
    void Character::fight(Character* enemy) 
    {
        //Variable to keep track of who's turn it is currently - 'my' in this case refers to the Character object that called the 'fight' method
        bool myTurn = true;

        while (!enemy->isDead() && !this->isDead()) 
        {
            switch (myTurn)
            {
            case true: enemy->sufferDamage(this); //we hit the enemy
                break;
            case false: this->sufferDamage(enemy); //the enemy hits us
                break;
            }

            //We swap the state of 'myTurn'
            myTurn = !myTurn;

        }

        //We announce the winner
        std::cout << (!isDead() ? getName() + " wins. Remaining HP: " + std::to_string(getHP()) :  enemy->getName() + " wins. Remaining HP: " + std::to_string(enemy->getHP()) ) << std::endl;
    }
