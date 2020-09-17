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

    //Simple method for printing one's status
    void Character::printStatus() const {
        std::cout << this->getName()
            + ": [HP: " << std::to_string(this->getHP())
            + "] [DMG:" << std::to_string(this->getATK())
            + "]" << std::endl;
    }

    //Instead of using an HP setter from outside of the class, we declare a 'sufferDamage' method
    //The Character object's hp gets lowered based on the output 
    void Character::sufferDamage(int atk) {
        this->HP = (this->getHP() - atk);
    }

    //Code piece responsible for handling a hit 
    void Character::hit(Character* enemy) {
        std::cout << this->getName() << " -> " << enemy->getName() << std::endl;
        enemy->sufferDamage(this->getATK());
    }

    //Fight function - the enemy's reference is passed as an argument
    void Character::fight(Character* enemy) {

        //Variable to keep track of who's turn it is currently - 'my' in this case refers to the Character object that called the 'fight' method
        bool myTurn = true;

        while (!enemy->isDead() && !this->isDead()) {

            switch (myTurn)
            {
            case 0: this->hit(enemy); //we hit the enemy
                break;
            case 1: enemy->hit(this); //the enemy hits us
                break;
            }

            //We swap the state of 'myTurn'
            myTurn = !myTurn;

            //We print the status of each fighter, just to know what's up after every round
            this->printStatus();
            enemy->printStatus();

            //Simple visual line break, makes it easier to follow the fight in the console
            std::cout << "======================================================" << std::endl;
        }
        //We announce the winner
        if (enemy->isDead()) {
            std::cout << enemy->getName() << " died. " << this->getName() << " wins." << std::endl;
        }
        else {
            std::cout << this->getName() << " died. " << enemy->getName() << " wins." << std::endl;
        }
    }
