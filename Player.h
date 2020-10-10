#ifndef PLAYER_HEADER
#define PLAYER_HEADER

#include <string>
#include "Character.h"

    /* Minden 100 XP osszegyujtese utan szintet lep, aminek a kovetkezo hatasai vannak:

    max HP megno 10%-kal (egeszre kerekitve)
    DMG megno 10%-kal
    az aktualis HP felmegy max HP-ra */

class Player : public Character{
    protected:
        int ATK; // újradefiniálva, mert a character.cpp-ben const
        int LVL;
        int maxHP;
        int XP;
        void lvlUp();
    public:
    /*  Ezek a  character.h-ban szerepelnek már   
        Character(const std::string, const int, const int);
        static Character* parseUnit(const std::string&);
        std::string const & getName() const;
        int const & getATK() const;
        int const & getHP() const;
        void sufferDamage(Character*);
        bool isDead() const;
        void fight(Character*);
        //'<<'operator overload
        friend std::ostream& operator<<(std::ostream& os, const Character& character); */
        Player(const std::string, const int, const int);
        void deliverHit(Character* enemy) ;
};

#endif // PLAYER_HEADER