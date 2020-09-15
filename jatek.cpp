#include <iostream>
#include <string>
#include <time.h>

using namespace std;

class Character
{
private:
    string CharacterName;
    int CharacterHP;
    int CharacterATK;

public:
    /*Constructor*/
    //We use optional parameters for safety, although a badly constructed 'Character' object should never occur in the code  
    Character(string CharacterName = "Dummy", int CharacterHP = 10000, int CharacterATK = 0) {
        setName(CharacterName);
        setHP(CharacterHP);
        setATK(CharacterATK);
    };

    /*Getter and setter for CharacterName*/
    void setName(string value)
    {
        CharacterName = value;
    }
    string getName()
    {
        return CharacterName;
    }

    /*Getter and setter for CharacterHP*/
    void setHP(int value)
    {
        CharacterHP = value;
    }
    int getHP()
    {
        return CharacterHP;
    }

    /*Getter and setter for CharacterATK*/
    void setATK(int value)
    {
        CharacterATK = value;
    }
    int getATK()
    {
        return CharacterATK;
    }

    //Convenience method for simple checking
    bool isDead() {
        return getHP() <= 0;
    }

    //Simple method for printing one's status
    void printStatus() {
        cout << getName()
            +": [HP: " << to_string(getHP())
            +"] [DMG:" << to_string(getATK()) 
        +"]" << endl;
    }

    //Code piece responsible for handling a hit - we use a pointer to be able to do something like this:
    // enemy.hit(this) - the class references itself in this case, which means that a pointer is passed as the argument ('this' keyword returns a pointer)
    //We later use this in the 'Fight' function, this is why we use pointers in this method, although we don't do that anywhere else in the class (yet)
    void hit(Character* enemy) {
        cout << getName() << " -> " << enemy->getName() << endl;
        enemy->setHP(enemy->getHP() - getATK());
    }

    //Fight function - the enemy's reference is passed as an argument
    void Fight(Character enemy) {

        //We initialize a new seed for the random generator
        srand(time(NULL));

        while (!enemy.isDead() && !isDead()) {

            //Random hit chance - it's 50/50 right now, can be adjusted later if hit chances get introduced to the game
            switch (rand() % 2)
            {
            case 0: hit(&enemy); //we create a pointer to reference the enemy and hit it
                break;
            case 1: enemy.hit(this); //the enemy hits us - 'this' gives us a pointer to this specific object of the Character class
                break;
            }

            //We print the status of each fighter, just to know what's up after every round
            printStatus();
            enemy.printStatus();

            //Simple visual line break, makes it easier to follow the fight in the console
            cout << "======================================================" << endl;
        }
        //We announce the winner
        if (enemy.isDead()) {
            cout << enemy.getName() << " died. " << getName() << " wins." << endl;
        }
        else {
            cout << getName() << " died. " << enemy.getName() << " wins." << endl;
        }
    };

};

class Utilities
{
public:
    static Utilities *instance;
    /*Constructor*/
    Utilities() {
    
    };


public:
    static Utilities *getInstance() {
        if (!instance)
            instance = new Utilities;
        return instance;
    }


    bool isNumber(string Input) {
        if (Input.size() == 0) return false;
        for (int i = 0; i < Input.size(); i++) {
            if ((Input[i] >= '0' && Input[i] <= '9') == false) {
                return false;
            }
        }
        return true;
    }
};

Utilities *Utilities::instance = 0;


int main(int argc, char* argv[])
{

    Utilities *util = util->getInstance();

    
    if (util->isNumber(argv[2])&&util->isNumber(argv[3])&&util->isNumber(argv[5])&&util->isNumber(argv[6]))
    {
        Character player(argv[1], std::stoi(argv[2]), std::stoi(argv[3]));
        Character enemy(argv[4], std::stoi(argv[5]), std::stoi(argv[6]));
        player.Fight(enemy);
    };

    return 0;
}