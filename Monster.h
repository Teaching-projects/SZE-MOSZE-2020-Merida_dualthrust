/**
 * @file Monster.h
 * @author lapatkrisz
 * @brief Monster class
 * 
 * This class contains basic methods and data members of the Monster class. Monster objects in the game can have different HP/ATK values and fight each other.
 * 
 * @version 1.0
 * @date 2020-10-13
 */

#ifndef MONSTER_HEADER
#define MONSTER_HEADER

#include <string>

class Monster {

public:
    virtual ~Monster();
    /**
     * @brief Construct a new Monster object
     * In case of no inputs the Monster object gets default values
     */
    Monster(const std::string&, int, int, const double);
    /**
     * @brief JSON parse method for creating a Monster object based on a given JSON input file
     * @return Monster type unit
     */
    static Monster parse(const std::string&);
    /**
     * @brief Getter for the name of the character
     * @return std::string const&
     */
    std::string const & getName(/**There's no input parameter here.*/) const;
    /**
     * @brief Getter for character name
     * @return int const& 
     */
    int const & getDamage(/**There's no input parameter here.*/) const;
    /**
     * @brief Getter for character HP
     * @return int const& 
     */
    int const & getHealthPoints(/**There's no input parameter here.*/) const;
    /**
     * @brief Getter for attack speed cooldown of character
     * @return  double const&
     */
    float const & getAttackCoolDown(/**There's no input parameter here.*/) const;
    /**
     * @brief Function for depleting HP-s during fight
     * Basic subtraction operation. If the HP drops below 0 we set it to 0
     * @param[in] Monster type object
     */
    void sufferDamage(Monster*);
    virtual void deliverHit(Monster* enemy);
    //'<<'operator overload
    /**
     * @brief Bool function to examine if the Monster is dead or alive
     * @return false, if the Characters' HP 0 or below 0
     * @return true, if the Characters' HP is more than 0
     */
    bool isAlive(/**There's no input parameter here.*/) const;
    /**
     * @brief Fight function, performs the whole fight
     * Winner gets announced. Puts out the results to both file and command line
     * @param[in] Monster type object
     */
    Monster* fightTilDeath(Monster&);
    /**
     * @brief Operator overload
     * Printing a characters' status
     * @param[in] output stream 
     * @param[in] character (name, HP, damage)
     * @return std::ostream& (containing Characters' status)
     */
    friend std::ostream& operator<<(std::ostream& os, const Monster& character);

protected:
    const std::string name; 
    int HP;
    int ATK;
    float ACD;
};

#endif // MONSTER_HEADER
