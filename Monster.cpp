#include "Monster.h"
#include "Hero.h"
#include "JSON.h"
#include <iostream>
#include <string>

    //Constructor
    Monster::Monster(const std::string& characterName, int characterHP, int characterATK, const double characterACD):name(characterName),HP(characterHP),ATK(characterATK),ACD(characterACD)
    {

    }

    Monster::~Monster()
    {

    }

    //Getters
    std::string const & Monster::getName() const
    {
        return name;
    }

    int const & Monster::getHealthPoints() const
    {
        return HP;
    }

    int const & Monster::getDamage() const
    {
        return ATK;
    }

    double const & Monster::getAttackCoolDown() const
    {
        return ACD;
    }



    //JSON parse method for creating a Monster object based on a given JSON input file
    Monster Monster::parse(const std::string& path)
    {
        std::map<std::string, std::string> parsedMap = JSON::parseFromFile(path).content;
        std::string name = parsedMap["name"];
        int hp = std::stoi(parsedMap["health_points"]);
        int dmg = std::stoi(parsedMap["damage"]);
        float ACD = std::stof(parsedMap["attack_cooldown"]);
        return Monster(name, hp, dmg, ACD);
    }

    //Convenience method for simple checking
    bool Monster::isAlive() const 
    {
        return getHealthPoints() >= 0;
    }

    //Instead of using an HP setter from outside of the class, we declare a 'sufferDamage' method
    //The Monster object's HP gets lowered based on the output 
    void Monster::sufferDamage(Monster* enemy) 
    {
        //std::cout << enemy->getName() << " -> " << this->getName() << std::endl;
        HP = (getHealthPoints() - enemy->getDamage());
        if (HP < 0)
        {
            HP = 0; 
        }
    }

    void Monster::deliverHit(Monster* enemy) 
    {
        enemy -> sufferDamage(this);
    }

    //Printing a characters status
    std::ostream& operator<<(std::ostream& os, const Monster& character)
    {
        os << character.getName() << ": [HP: "  << character.getHealthPoints() << "] [DMG:" << character.getDamage() << "]";
        return os;
    }

Monster* Monster::fightTilDeath(Monster enemy) 
    {
        //We initialize the countdown variables - these keep track of the cooldown until a hit
        int attacker_hitCountdown=0;
        int enemy_hitCountdown=0;

        //Attacker hits the enemy first, then the other way around
        this->deliverHit(&enemy);
        enemy.deliverHit(this); //the enemy hits us

        
        //The fight keeps on going until somebody is dead
        while (enemy.isAlive() && this->isAlive()) 
        {
            if(attacker_hitCountdown >= getAttackCoolDown()){
                this->deliverHit(&enemy);
                attacker_hitCountdown = 0;
            }else{
                attacker_hitCountdown++;
            }
            if(enemy_hitCountdown >= enemy.getAttackCoolDown()){
                enemy.deliverHit(this);
                enemy_hitCountdown = 0;
            }else{
                enemy_hitCountdown++;
            }
        }
        //We announce the winner
        return isAlive() ? this : &enemy;
    }
