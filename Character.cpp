#include "Character.h"
#include "Utility.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

    //Constructor
    Character::Character(const std::string characterName,const int characterHP, const int characterATK, const double characterACD):name(characterName),HP(characterHP),ATK(characterATK),ACD(characterACD){}


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
            int DMG = std::stoi(Utility::split(Utility::split(fileContents, ',')[2], ':')[1]); //We get the DMG value from the file - we split the string between the third ',' character and ':' character, and parse it into an integer
            double ACD = std::stoi(Utility::split(Utility::split(fileContents, ':')[4], '}')[0]); //We get the ACD value from the file - we split the string between the fourth ':' character and '}' character, and parse it into an integer

            return new Character(name, HP, DMG, ACD);
        }
        else 
        {
            //If the input file doesn't exist, we return null
            return NULL;
        }

        //Character* player = new Character("Maple",10,1);
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
        //We initialize the countdown variables - these keep track of the cooldown until a hit
        int attacker_hitCountdown=0;
        int enemy_hitCountdown=0;


        //Attacker hits the enemy first, then the other way around
        enemy->sufferDamage(this);
        this->sufferDamage(enemy); //the enemy hits us
        
        
        //The fight keeps on going until somebody is dead
        while (!enemy->isDead() && !this->isDead()) 
        {

            if(attacker_hitCountdown >= getACD()){
                enemy->sufferDamage(this);
                attacker_hitCountdown = 0;
            }else{
                attacker_hitCountdown++;
            }

            if(enemy_hitCountdown >= enemy->getACD()){
                this->sufferDamage(enemy);
                enemy_hitCountdown = 0;
            }else{
                enemy_hitCountdown++;
            }

        }

        //We announce the winner
        std::cout << (!isDead() ? getName() + " wins. Remaining HP: " + std::to_string(getHP()) :  enemy->getName() + " wins. Remaining HP: " + std::to_string(enemy->getHP()) ) << std::endl;
    }