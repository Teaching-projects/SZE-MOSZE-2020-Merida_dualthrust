#include "Character.h"
#include "Adventurer.h"
#include "Utility.h"
#include <iostream>
#include <string>

    //Constructor
    Character::Character(const std::string& characterName,const int characterHP, const int characterATK):name(characterName),HP(characterHP),ATK(characterATK){}

    Character::~Character(){};

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

    //JSON parse method for creating a Character object based on a given JSON input file
    Character* Character::parseUnit(const std::string& path)
    {
        std::vector<std::string> unit_data = Utility::getJsonData(path);

        if (unit_data.size() == 3){
            return new Character(unit_data[0], std::stoi(unit_data[1]), std::stoi(unit_data[2]));
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

    //Fight function - a pointer to the enemy is passed as an argument
    void Character::fight(Character* enemy) 
    {
        //Variable to keep track of who's turn it is currently - 'my' in this case refers to the Character object that called the 'fight' method
        bool myTurn = true;

        while (!enemy->isDead() && !this->isDead()) 
        {
            if (myTurn)
            {
                this->deliverHit(enemy); //we hit the enemy
            }
            else
            {
                enemy->deliverHit(this); //the enemy hits us
            }           
            //We swap the state of 'myTurn'
            myTurn = !myTurn;
            std::cout<<*this;
            std::cout<<"\n";
            std::cout<<*enemy;
            std::cout<<"\n";
            
        }

        //We announce the winner
        std::cout << (!isDead() ? "\n\n" + getName() + " wins. Remaining HP: " + std::to_string(getHP()) :  "\n\n" + enemy->getName() + " wins. Remaining HP: " + std::to_string(enemy->getHP()) ) << std::endl;
    }    
