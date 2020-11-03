#include "Monster.h"
#include "Hero.h"
#include "JSON.h"
#include <iostream>
#include <string>

    //Constructor
    Monster::Monster(const std::string& characterName, int characterHP, int characterATK, const double characterACD):name(characterName),healthPoint(characterHP),damage(characterATK),cooldown(characterACD)
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
        return healthPoint;
    }

    int const & Monster::getDamage() const
    {
        return damage;
    }

    float const & Monster::getAttackCoolDown() const
    {
        return cooldown;
    }



    //JSON parse method for creating a Monster object based on a given JSON input file
    Monster Monster::parse(const std::string& path)
    {
        JSON data = JSON::parseFromFile(path);
        std::string name = data.get<std::string>("name");
        int healthPoints = data.get<int>("health_points");
        int dmg = std::stoi(data.get<std::string>("damage"));
        float cooldown = std::stof(data.get<std::string>("attack_cooldown"));
        return Monster(name, healthPoints, dmg, cooldown);
    }

    //Convenience method for simple checking
    bool Monster::isAlive() const 
    {
        return getHealthPoints() > 0;
    }

    //Instead of using an healthPoint setter from outside of the class, we declare a 'sufferDamage' method
    //The Monster object's healthPoint gets lowered based on the output 
    void Monster::sufferDamage(Monster* enemy) 
    {
        //std::cout << enemy->getName() << " -> " << this->getName() << std::endl;
        healthPoint = (getHealthPoints() - enemy->getDamage());
        if (healthPoint < 0)
        {
            healthPoint = 0; 
        }
    }

    void Monster::deliverHit(Monster* enemy) 
    {
        enemy -> sufferDamage(this);
    }

    //Printing a characters status
    std::ostream& operator<<(std::ostream& os, const Monster& character)
    {
        os << character.getName() << ": [healthPoint: "  << character.getHealthPoints() << "] [DMG:" << character.getDamage() << "]";
        return os;
    }

Monster* Monster::fightTilDeath(Monster& enemy) 
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