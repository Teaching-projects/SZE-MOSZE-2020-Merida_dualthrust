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

    std::cout << "╔";
    for (int number_of_chars = 0; number_of_chars < map[0].length(); number_of_chars++)
    {
        std::cout <<"═"; 
    }                           
    std::cout <<"╗"<< std::endl;


    for (int row = 0; row < map.size(); row++)
    {   
        
        for (int column = 0; column < map[row].length(); column++)
        {
            if (column==0 || column==map[row].length())
            {
                std::cout <<"║";
            }

            if (Map::get(row,column)==Free)   
            {
                std::cout <<"░░";
            }
            else if (Map::get(row,column)==Wall)
            {
                std::cout <<"██";
            }
            else if (Map::get(row,column)==Hero)
            {
                std::cout <<"┣┫";
            }
            else if (Map::get(row,column)==Monster)
            {
                std::cout <<"M░";
            }
            else if (Map::get(row,column)==Monsters)
            {
                std::cout <<"MM";
            }
                        
        }
    }
    
    std::cout << "╚";
    for (int number_of_chars = 0; number_of_chars < map[map.size()].length(); number_of_chars++)
    {
        std::cout <<"═"; 
    }
    std::cout << "╝"<< std::endl;
    
}