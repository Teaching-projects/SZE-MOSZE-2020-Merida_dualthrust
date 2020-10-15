#include "Character.h"
#include "Utility.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

    //Constructor
    Character::Character(const std::string characterName,const int characterHP, const int characterATK):name(characterName),HP(characterHP),ATK(characterATK){}


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
        std::ifstream f(path);
        //We check if the file given as input exists
        if (f.good()) 
        {
            //We read the whole file into a string variable using ifstream and stringstream
            //We do this because since we'll use the split method anyway, a counter variable holding which row we're currently reading is not needed
            //This saves us a few addition and divide operations here
            std::stringstream s;
            s << f.rdbuf();
            std::string fileContents = s.str();
            f.close();

            //We save the values we need - this could be inlined into the Character constructor call, but the code is clearer this way
            std::string name = Utility::split(fileContents,'"')[3]; //We get the name from the file
            int HP = std::stoi(Utility::split(Utility::split(fileContents, ',')[1],':')[1]); //We get the HP value from the file - we split the string between the second ',' character and ':' character, and parse it into an integer
            int DMG = std::stoi(Utility::split(Utility::split(fileContents, ':')[3], '}')[0]); //We get the DMG value from the file - we split the string between the third ':' character and '}' character, and parse it into an integer

            return new Character(name, HP, DMG);
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
