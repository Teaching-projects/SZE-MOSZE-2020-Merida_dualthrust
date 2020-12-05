/**
 * @file Monster.h
 * @author lapatkrisz
 * @brief Monster class
 * 
 * This class contains basic methods and data members of the Monster class.
 * Monster objects in the game can have different healthpoint/damage values and fight each other.
 * 
 * @version 1.0
 * @date 2020-10-13
 * 
 */

#ifndef MONSTER_HEADER
#define MONSTER_HEADER

#include <string>

class Monster {

public:
    /**
     * @brief Destructor for Monster class
     * 
     */
    virtual ~Monster();
    /**
     * @brief Construct a new Monster object
     * In case of no inputs the Monster object gets default values
     * 
     */
    Monster(const std::string&, int, int, int, const double);
    
    //Copy constructor
    Monster(const Monster &m2): name(m2.name),healthPoint(m2.healthPoint),damage(m2.damage),defense(m2.defense),cooldown(m2.cooldown){}
    /**
     * @brief Setter for the unit's position for the map. Evaluation logic of the move's validity happens inside the Game class.
     * 
     */
    void setPosition(int x, int y);

    /**
     * @brief Getter for the unit's current position on the map.
     * 
     */
    std::pair<int,int> getPosition(/**There's no input parameter here.*/);
    
    /**
     * @brief JSON parse method for creating a Monster object based on a given JSON input file
     * @return Monster type unit
     * 
     */
    static Monster parse(const std::string&);
    /**
     * @brief Getter for the name of the character
     * @return std::string const&
     * 
     */
    std::string const & getName(/**There's no input parameter here.*/) const;
    /**
     * @brief Getter for character attack damage
     * @return int const& 
     * 
     */
    int const & getDamage(/**There's no input parameter here.*/) const;
    /**
     * @brief Getter for character defense
     * @return int const& 
     * 
     */
    int const & getDefense(/**There's no input parameter here.*/) const;
    /**
     * @brief Getter for character healthpoint
     * @return int const& 
     * 
     */
    int const & getHealthPoints(/**There's no input parameter here.*/) const;
    /**
     * @brief Getter for attack speed cooldown of character
     * @return  float const&
     * 
     */
    float const & getAttackCoolDown(/**There's no input parameter here.*/) const;
    /**
     * @brief Function for depleting HealthPoints during fight
     * Basic subtraction operation. If the HealthPoint drops below 0 we set it to 0
     * @param[in] Monster type object
     * 
     */
    void sufferDamage(Monster*);
    /**
     * @brief The monster object whose sufferDamage method is called will lose healthpoints based on the attacker's damage points. The attacker object is the one whose reference is passed in the argument list.
     * @param enemy Monster or Hero type object that represents the attacker
     * 
     */
    virtual void deliverHit(Monster* enemy);
    /**
     * @brief Bool function to examine if the Monster is dead or alive
     * @return false, if the Characters' HealthPoint 0 or below 0
     * @return true, if the Characters' HealthPoint is more than 0
     * 
     */
    bool isAlive(/**There's no input parameter here.*/) const;
    /**
     * @brief Fight function, performs the whole fight
     * Winner gets announced. Puts out the results to both file and command line
     * @param[in] Monster type object
     * 
     */
    Monster* fightTilDeath(Monster&);
    /**
     * @brief Operator overload
     * Printing a characters' status
     * @param[in] output stream 
     * @param[in] character (name, HealthPoint, damage)
     * @return std::ostream& (containing Characters' status)
     * 
     */
    friend std::ostream& operator<<(std::ostream& os, const Monster& character);

protected:
    /**
     * @brief Name of the unit
     * 
     */
    const std::string name;
    /**
     * @brief HealthPoint of the unit
     * 
     */
    int healthPoint;
    /**
     * @brief Attack damage of the unit
     * 
     */
    int damage;
    /**
     * @brief Defense of the unit
     * 
     */
    int defense;
    /**
     * @brief Attack cooldown of the unit
     * 
     */
    float cooldown;
    /**
     * @brief Represents the unit's current coordinates on the game map
     * 
     */
    std::pair<int,int> position;
};

#endif // MONSTER_HEADER
