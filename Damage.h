#ifndef DAMAGE_H
#define DAMAGE_H
#include <ostream>
struct Damage {

    int physical;
    int magical;

    Damage operator+(const Damage& other){
        Damage dmgToReturn;
        dmgToReturn.physical = this->physical + other.physical;
        dmgToReturn.magical = this->magical + other.magical;
        return dmgToReturn;
    }

    Damage& operator+=(const Damage& other){
        this->physical += other.physical;
        this->magical += other.magical;
        return *this;
    }

    Damage& operator*=(const Damage& other){
        this->physical *= other.physical;
        this->magical *= other.magical;
        return *this;
    
    }
    friend std::ostream& operator<<(std::ostream& out, const Damage& dmg){
    out<<"DMG: "<<dmg.physical<<", MagicalDMG: "<<dmg.magical;
    return out;
    }
};
#endif