#include "Character.h"
#include "Adventurer.h"
#include "Utility.h"
#include <iostream>
#include <string>

    //Constructor
    Character::Character(const std::string& characterName,const int characterHP, int characterATK, const double characterACD):name(characterName),HP(characterHP),ATK(characterATK),ACD(characterACD)
    {

    }

    Character::~Character()
    {

    }

    //Getters
    std::string const & Character::getName() const
    {
        return name;
    }

    int const & Character::getHP() const
    {
        return HP;
    }

    int const & Character::getATK() const
    {
        return ATK;
    }

    double const & Character::getACD() const
    {
        return ACD;
    }



    //JSON parse method for creating a Character object based on a given JSON input file
    Character* Character::parseUnit(const std::string& path)
    {
        std::vector<std::string> unit_data = Utility::getJsonData(path);

        if (unit_data.size() == 4)
        {
            return new Character(unit_data[0], std::stoi(unit_data[1]), std::stoi(unit_data[2]), std::stoi(unit_data[3]));
        }
        else 
        {
            //If the input file doesn't exist, we return null
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

    void Character::deliverHit(Character* enemy) 
    {
        enemy -> sufferDamage(this);
    }

    //Printing a characters status
    std::ostream& operator<<(std::ostream& os, const Character& character)
    {
        os << character.getName() << ": [HP: "  << character.getHP() << "] [DMG:" << character.getATK() << "]";
        return os;
    }

Character* Character::fight(Character* enemy) 
    {
        //We initialize the countdown variables - these keep track of the cooldown until a hit
        int attacker_hitCountdown=0;
        int enemy_hitCountdown=0;

        //Attacker hits the enemy first, then the other way around
        this->deliverHit(enemy);
        enemy->deliverHit(this); //the enemy hits us

        
        //The fight keeps on going until somebody is dead
        while (!enemy->isDead() && !this->isDead()) 
        {
            if(attacker_hitCountdown >= getACD()){
                this->deliverHit(enemy);
                attacker_hitCountdown = 0;
            }else{
                attacker_hitCountdown++;
            }
            if(enemy_hitCountdown >= enemy->getACD()){
                enemy->deliverHit(this);
                enemy_hitCountdown = 0;
            }else{
                enemy_hitCountdown++;
            }
        }
        //We announce the winner
        return !isDead() ? this : enemy;
    }
