#include <iostream>
#include <string>
#include <time.h>
#include <ctype.h>

#include "Utility.h"
#include "Character.h"

using namespace std;


int main(int argc, char* argv[])
{

    Character* player1 = NULL;
    Character* player2 = NULL;

    //If we have enough arguments given, we create two units from the given input files
    if(argc > 2)
    {
        player1 = Character::parseUnit(argv[1]);
        player2 = Character::parseUnit(argv[2]);
    }

    if (player1 && player2) 
    {
        //The fight method is called, this is where all the logic happens
        player1->fight(player2);
        
        //After the fight, we delete the objects we've created
        delete player1;
        delete player2;
    }
    else 
    {
        //If the input parameters are not correct, we print a helper to the console
        cout << "Incorrect input parameters. Please check if the input file paths you entered were correct." << endl;
        return 1;
    };

    return 0;
}