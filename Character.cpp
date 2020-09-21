#include "Character.h"
#include <iostream>
#include <string>

    //Constructor
    Character::Character(const std::string characterName,const int characterHP, const int characterATK):name(characterName),HP(characterHP),ATK(characterATK){}


    //Getters
    std::string Character::getName() const
    {
        return this->name;
    }

    int Character::getHP() const
    {
        return this->HP;
    }

    int Character::getATK() const
    {
        return this->ATK;
    }


    //Convenience method for simple checking
    bool Character::isDead() const {
        return this->getHP() <= 0;
    }

    //Instead of using an HP setter from outside of the class, we declare a 'sufferDamage' method
    //The Character object's HP gets lowered based on the output 
    void Character::sufferDamage(Character* enemy) {
        std::cout << enemy->getName() << " -> " << this->getName() << std::endl;
        this->HP = (this->getHP() - enemy->getATK());
        if (this->HP < 0) { this->HP = 0; }
    }


    //Printing a characters status
    std::ostream& operator<<(std::ostream& os, const Character& character){
    os << character.getName() << ": [HP: "  << character.getHP() << "] [DMG:" << character.getATK() << "]";
    return os;
    }

    //Fight function - a pointer to the enemy is passed as an argument
    void Character::fight(Character* enemy) {

        //Character stats of the two fighters are printed out before starting the loop with an overloaded << operator
        std::cout << *this << std::endl;
        std::cout << *enemy << "\n"<< std::endl;

        //Variable to keep track of who's turn it is currently - 'my' in this case refers to the Character object that called the 'fight' method
        bool myTurn = true;

        while (!enemy->isDead() && !this->isDead()) {

            switch (myTurn)
            {
            case true: enemy->sufferDamage(this); //we hit the enemy
                break;
            case false: this->sufferDamage(enemy); //the enemy hits us
                break;
            }

            //We swap the state of 'myTurn'
            myTurn = !myTurn;

            //We print the status of each fighter, just to know what's up after every round
            std::cout << *this << std::endl;
            std::cout << *enemy<< std::endl;

            //Simple visual line break, makes it easier to follow the fight in the console
            std::cout << "======================================================" << std::endl;
        }
        //We announce the winner
        std::cout << (!this->isDead() ? enemy->getName() + " died. " + this->getName() + " wins." : this->getName() + " died. " + enemy->getName() + " wins.");
    }
