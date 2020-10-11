#ifndef CHARACTER_HEADER
#define CHARACTER_HEADER

#include <string>

/* Character class
   This class contains basic methods and data members of the Character class.
   Character objects in the game can have different HP/ATK values and fight each other.
*/

class Character {

public:
    Character(const std::string, const int, const int);
    static Character* parseUnit(const std::string&);
    std::string const & getName() const;
    int const & getATK() const;
    int const & getHP() const;
    void sufferDamage(Character*);
    virtual void deliverHit(Character* enemy);
    bool isDead() const;
    void fight(Character*);
    //'<<'operator overload
    friend std::ostream& operator<<(std::ostream& os, const Character& character);

protected:
    const std::string name;
    int ATK;
    int HP;
};

#endif // CHARACTER_HEADER
