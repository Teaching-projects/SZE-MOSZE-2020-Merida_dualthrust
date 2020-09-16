#include <iostream>
#include <string>
#include <time.h>
#include <ctype.h>

#include "Utility.h"
#include "Character.h"
using namespace std;

//Utility class is singleton, so we initialize it's pointer (to zero), so it can be referenced the first time getInstance is called
Utility* Utility::instance = 0;

int main(int argc, char* argv[])
{
    //We initialize pointers to our objects
    Utility* util = util->getInstance();
    
    if (util->isNumber(argv[2]) && util->isNumber(argv[3]) && util->isNumber(argv[5]) && util->isNumber(argv[6]))
    {
        //If the input parameters are correct, we create two objects of the Character class based on the input data
        Character* player = new Character(argv[1], std::stoi(argv[2]), std::stoi(argv[3]));
        Character* enemy = new Character(argv[4], std::stoi(argv[5]), std::stoi(argv[6]));
        
        //The fight method is called, this is where all the logic happens
        player->fight(enemy);

        //After the fight, we delete the objects we've created
        delete util;
        delete player;
        delete enemy;
    }
    else {
        //If the input parameters are not correct, we print a helper to the console
        cout << "Incorrect input parameters. Please use the following pattern: Name1(string) HP1(int) ATK1(int) Name2(string) HP2(int) ATK2(int)" << endl;
    };


    return 0;
}