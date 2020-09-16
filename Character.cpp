#include "Character.h"
#include <iostream>
#include <string>

    Character::Character(const std::string characterName, int characterHP, const int characterATK){
        this->setName(characterName);
        this->setHP(characterHP);
        this->setATK(characterATK);
    }

    /*Getter and setter for CharacterName*/
    void Character::setName(std::string value)
    {
        this->name = value;
    }

    std::string Character::getName()
    {
        return this->name;
    }

    /*Getter and setter for CharacterHP*/
    void Character::setHP(int value)
    {
        this->HP = value;
    }
    int Character::getHP()
    {
        return this->HP;
    }

    /*Getter and setter for CharacterATK*/
    void Character::setATK(const int value)
    {
        this->ATK = value;
    }
    int Character::getATK()
    {
        return this->ATK;
    }

    //Convenience method for simple checking
    bool Character::isDead() {
        return this->getHP() <= 0;
    }

    //Simple method for printing one's status
    void Character::printStatus() {
        std::cout << this->getName()
            + ": [HP: " << std::to_string(this->getHP())
            + "] [DMG:" << std::to_string(this->getATK())
            + "]" << std::endl;
    }

    void Character::sufferDamage(int atk) {
        this->setHP(this->getHP() - atk);
    }

    //Code piece responsible for handling a hit - we use a pointer to be able to do something like this:
    // enemy.hit(this) - the class references itself in this case, which means that a pointer is passed as the argument ('this' keyword returns a pointer)
    //We later use this in the 'Fight' function, this is why we use pointers in this method, although we don't do that anywhere else in the class (yet)
    void Character::hit(Character* enemy) {
        std::cout << this->getName() << " -> " << enemy->getName() << std::endl;
        enemy->sufferDamage(this->getATK());
    }

    //Fight function - the enemy's reference is passed as an argument
    void Character::fight(Character* enemy) {

        bool myTurn = true;

        while (!enemy->isDead() && !this->isDead()) {

            switch (myTurn)
            {
            case 0: this->hit(enemy); //we create a pointer to reference the enemy and hit it
                break;
            case 1: enemy->hit(this); //the enemy hits us - 'this' gives us a pointer to this specific object of the Character class
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
