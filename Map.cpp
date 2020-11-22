#include "Map.h"
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <fstream>

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
} // Betolt fajlbol egy terkepet