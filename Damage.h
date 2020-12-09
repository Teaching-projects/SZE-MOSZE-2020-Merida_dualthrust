/**
 * @file Damage.h
 * @author lapatkrisz
 * @brief 
 * @version 1.0
 * @date 2020-12-09
 * 
 */

#ifndef DAMAGE_H
#define DAMAGE_H
#include <ostream>
struct Damage {

    int physical;
    int magical;

    /**
     * @brief Constructor for Damage object
     * 
     * @param phis 
     * @param magi 
     */
    Damage(const int phis, const int magi){
        physical=phis;
        magical = magi;
    }

    /**
     * @brief Operator that sums two damages
     * 
     * @param other 
     * @return Damage 
     */
    Damage operator+(const Damage& other){

        this->physical += other.physical;
        this->magical += other.magical;
        return *this;
    }

    /**
     * @brief Operator that sums one damage to another damage
     * 
     * @param other 
     * @return Damage& 
     */
    Damage& operator+=(const Damage& other){
        this->physical += other.physical;
        this->magical += other.magical;
        return *this;
    }
    
    /**
     * @brief Operator that multiplies a damage with another damage
     * 
     * @param other 
     * @return Damage& 
     */
    Damage& operator*=(const Damage& other){
        this->physical *= other.physical;
        this->magical *= other.magical;
        return *this;
    
    }

    /**
     * @brief Operator for writing out the damage
     * 
     * @param out 
     * @param dmg 
     * @return std::ostream& 
     */
    friend std::ostream& operator<<(std::ostream& out, const Damage& dmg){
    out<<"DMG: "<<dmg.physical<<", MagicalDMG: "<<dmg.magical;
    return out;
    }
};
#endif