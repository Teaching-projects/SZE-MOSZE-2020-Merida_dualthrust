#include <iostream>
#include "Utility.h"
#include "Monster.h"
#include "Hero.h"

using namespace std;

int main(int argc, char* argv[])
{

    Monster* player1 = NULL;
    Monster* player2 = NULL;

    //If we have enough arguments given, we create two units from the given input files
    if(argc > 2)
    {
        player1 = Hero::parseUnit(argv[1]);
        player2 = Monster::parseUnit(argv[2]);
    }

    if (player1 && player2) 
    {
        //The fight method is called, this is where all the logic happens
        Monster* winner = player1->fight(player2);
        std::cout << winner->getName() + " wins. Remaining HP: " + std::to_string(winner->getHealthPoints()) << std::endl;
        Utility::deleteCharacters({ player1,player2 });
    }
    else 
    {
        //If the input parameters are not correct, we print a helper to the console
        cout << "Incorrect input parameters. Please check if the input file paths you entered were correct." << endl;
        //We delete existing objects
        Utility::deleteCharacters({ player1,player2 });
        return 1;
    };

    return 0;
}