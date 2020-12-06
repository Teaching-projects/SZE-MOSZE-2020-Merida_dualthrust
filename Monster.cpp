#include "Monster.h"
#include "Hero.h"
#include "JSON.h"
#include <iostream>
#include <string>

    //Constructor
    Monster::Monster(const std::string& characterName, int characterHP, Damage damage, int characterDEF, const double characterACD):name(characterName), healthPoint(characterHP), damage(dmg), defense(characterDEF), cooldown(characterACD)
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

    int const & Monster::getPhysicalDamage() const
    {
        return damage.physical;
    }

    int const & Monster::getMagicalDamage() const
    {
        return damage.magical;
    }
    
    int const & Monster::getDefense() const
    {
        return defense;
    }

    float const & Monster::getAttackCoolDown() const
    {
        return cooldown;
    }

    //Setter for the unit's position on the map
    void Monster::setPosition(int x, int y){
        position=std::make_pair(x,y);
    }

    std::pair<int,int> Monster::getPosition(){
        return position;
    }


    //JSON parse method for creating a Monster object based on a given JSON input file
    Monster Monster::parse(const std::string& path)
    {
        JSON data           =   JSON::parseFromFile(path);
        Damage damage;
        std::string name    =   data.get<std::string>("name");
        int healthPoints    =   data.get<int>("health_points");
        damage.physical     =   std::stoi(data.get<std::string>("damage"));
        damage.magical      =   std::stoi(data.get<std::string>("magical-damage"));
        int def             =   std::stoi(data.get<std::string>("defense"));
        float cooldown      =   std::stof(data.get<std::string>("attack_cooldown"));

        return Monster(name, healthPoints, damage, def, cooldown);
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
        if (    (enemy-> getPhysicalDamage() - defense)  >   0)
        {
            healthPoint -= (enemy-> getPhysicalDamage() - defense) + getMagicalDamage();
        }
        
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
        os << character.getName() << ": [healthPoint: "  << character.getHealthPoints() << "] [DMG: " << character.getPhysicalDamage() << "] [MagicalDMG: " << character.getMagicalDamage() << "]";
        return os;
    }

    Monster* Monster::fightTilDeath(Monster& enemy) 
    {
        //We initialize the countdown variables - these keep track of the cooldown until a hit
        int attacker_hitCountdown=0;
        int enemy_hitCountdown=0;
        
        this->deliverHit(&enemy);   //Attacker hits the enemy first, then the other way around
        enemy.deliverHit(this);     //the enemy hits us
        
        //The fight keeps on going until somebody is dead
        while (enemy.isAlive() && this->isAlive()) 
        {
            if(attacker_hitCountdown >= getAttackCoolDown())
            {
                this->deliverHit(&enemy);
                attacker_hitCountdown = 0;
            }
            else
            {
                attacker_hitCountdown++;
            }
            
            if(enemy_hitCountdown >= enemy.getAttackCoolDown())
            {
                enemy.deliverHit(this);
                enemy_hitCountdown = 0;
            }
            else
            {
                enemy_hitCountdown++;
            }
        }
        //We announce the winner
        return isAlive() ? this : &enemy;
    }
