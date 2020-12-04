#include "MarkedMap.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

MarkedMap::MarkedMap(std::string path)
{
    std::string line;
    std::ifstream mapfile(path);
    longest_row_size=0;
    
    while (std::getline(mapfile, line))
    {
        std::vector<int> map_row;
        
        for(unsigned int i=0;i<line.length();i++)
        {
            if(line[i]=='#')
            {
                map_row.push_back(type(Wall));
            }
            else if(line[i]==' ')
            {
                map_row.push_back(type(Free));
            }
            else if(line[i]=='1' || line[i]=='2' || line[i] == '3'){
                map_row.push_back(type(Monster));
            }

            //Nullpointereket tolunk bele, hogy fel legyen töltve hellyel
            
        }
        
        if(line.length() > longest_row_size)
        {
            longest_row_size=line.length();
        }
        map.push_back(map_row);
    }
}

MarkedMap::~MarkedMap()
{
}

const std::pair<int,int> MarkedMap::getHeroPosition()
{
    return std::pair<int,int>(1,1);
}

const std::vector<std::pair<int,int>> MarkedMap::getMonsterPositions(char)
{
    std::vector<std::pair<int,int>> positions = {};
    return positions;
}