#ifndef CHARACTER_HEADER
#define CHARACTER_HEADER

#include <string>

/* Character class
   This class contains basic methods and data members of the Character class.
   Character objects in the game can have different HP/ATK values and fight each other.
*/

class Character {

public:
    Character(const std::string, const float, const float);
    static Character* parseUnit(const std::string&);
    std::string const & getName() const;
    float const & getATK() const;
    float const & getHP() const;
    void sufferDamage(Character*);
    bool isDead() const;
    void fight(Character*);
    //'<<'operator overload
    friend std::ostream& operator<<(std::ostream& os, const Character& character);

protected:
    const std::string name;
    const float ATK;
    float HP;
};

#endif // CHARACTER_HEADER
