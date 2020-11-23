#include "Map.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

Map::type Map::get(int x, int y) const
{
    if(x >= map.size() || x < 0 )
    {
        throw WrongIndexException();
    }
    else
    {
        if(y >= map[x].length() || y < 0)
        {
            throw WrongIndexException();
        }
        else
        {
            std::string types = " #";
            return type(types.find(map[x][y]));
        }
    }
}

Map::Map(std::string path)
{
    std::string line;
    std::ifstream mapfile(path);
    while (std::getline(mapfile, line))
    {
        map.push_back(line);
    }
}

void Map::drawMap() const
{

    for (int i = 0; i < map.size(); i++)
    {   
        for (int j = 0; j < map[i].length(); j++)
        {
            if (i==0)
            {
                std::cout << "╔";
            }
            else if (/* condition */)
            {
                std::cout <<"╗"<< std::endl;
            }
            


            /* code */
        }
        
    }
    
    
    /* ║ oldala, ═ alja és teteje*/
    std::cout << "╚"<<"╝"<< std::endl;
    
}
/* 
Miden loop elejen kiirodik a jatek olyan formaban, hogy a falak ██-vel, a szabad teruletek ░░-vel jelenjenek meg. 
Ahol a Hero all, ott ┣┫ legyen, ahol Monsterek, ott pedig MM, M░ attol fuggoen, hogy egy vagy tobb van ott. 
Az egesz palya korul U+255x karakterekkel (azok kozul a mindenhol duplavonalasakkal) legyen egy keret.
 */