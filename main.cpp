#include <iostream>
#include <string>
#include <time.h>
#include <ctype.h>

#include "Utility.h"
#include "Character.h"
using namespace std;

Utility* Utility::instance = 0;


int main(int argc, char* argv[])
{

    Utility* util = util->getInstance();
    Character* player;
    Character* enemy;

    if (util->isNumber(argv[2]) && util->isNumber(argv[3]) && util->isNumber(argv[5]) && util->isNumber(argv[6]))
    {
        player = new Character(argv[1], std::stoi(argv[2]), std::stoi(argv[3]));
        enemy = new Character(argv[4], std::stoi(argv[5]), std::stoi(argv[6]));
        player->fight(enemy);
    }
    else {
        cout << "Incorrect input parameters. Please use the following pattern: Name1(string) HP1(int) ATK1(int) Name2(string) HP2(int) ATK2(int)" << endl;
    };

    return 0;
}