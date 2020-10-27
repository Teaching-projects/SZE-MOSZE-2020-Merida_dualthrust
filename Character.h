/**
 * @file Character.h
 * @author lapatkrisz
 * @brief Character class
 * 
 * This class contains basic methods and data members of the Character class. Character objects in the game can have different HP/ATK values and fight each other.
 * 
 * @version 1.0
 * @date 2020-10-13
 */

#ifndef CHARACTER_HEADER
#define CHARACTER_HEADER

#include <string>

class Character {

public:
    virtual ~Character();
    /**
     * @brief Construct a new Character object
     * In case of no inputs the Character object gets default values
     */
    Character(const std::string&, const int, int, const double);
    /**
     * @brief JSON parse method for creating a Character object based on a given JSON input file
     * @return Character type unit
     */
    static Character* parseUnit(const std::string&);
    /**
     * @brief Getter for the name of the character
     * @return std::string const&
     */
    std::string const & getName(/**There's no input parameter here.*/) const;
    /**
     * @brief Getter for character name
     * @return int const& 
     */
    int const & getATK(/**There's no input parameter here.*/) const;
    /**
     * @brief Getter for character HP
     * @return int const& 
     */
    int const & getHP(/**There's no input parameter here.*/) const;
    /**
     * @brief Getter for attack speed cooldown of character
     * @return  double const&
     */
    double const & getACD(/**There's no input parameter here.*/) const;
    /**
     * @brief Function for depleting HP-s during fight
     * Basic subtraction operation. If the HP drops below 0 we set it to 0
     * @param[in] Character type object
     */
    void sufferDamage(Character*);
    virtual void deliverHit(Character* enemy);
    //'<<'operator overload
    /**
     * @brief Bool function to examine if the Character is dead or alive
     * @return true, if the Characters' HP 0 or below 0
     * @return false, if the Characters' HP is more than 0
     */
    bool isDead(/**There's no input parameter here.*/) const;
    /**
     * @brief Fight function, performs the whole fight
     * Winner gets announced. Puts out the results to both file and command line
     * @param[in] Character type object
     */
    Character* fight(Character*);
    /**
     * @brief Operator overload
     * Printing a characters' status
     * @param[in] output stream 
     * @param[in] character (name, HP, damage)
     * @return std::ostream& (containing Characters' status)
     */
    friend std::ostream& operator<<(std::ostream& os, const Character& character);

protected:
    const std::string name; 
    int HP;
    int ATK;
    const double ACD;
};

#endif
