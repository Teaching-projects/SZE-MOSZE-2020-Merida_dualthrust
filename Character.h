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
    std::string getName() const;
    int getATK() const;
    int getHP() const;
    void sufferDamage(Character*);
    bool isDead() const;
    void fight(Character*);
    //'<<'operator overload
    friend std::ostream& operator<<(std::ostream& os, const Character& character);

protected:
    const std::string name;
    const int ATK;
    int HP;
};

#endif // CHARACTER_HEADER
