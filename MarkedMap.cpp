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
                monsterPositions.push_back(std::pair<int,int>(map.size()-1,i));
            }
            else if(line[i]=='H'){
                map_row.push_back(type(Free));
            }

        }
        
        int64_t signed_line_length = map_row.size(); //Fixes signed-unsigned errors
        
        if(signed_line_length > longest_row_size)
        {
            longest_row_size=map_row.size();
        }
        map.push_back(map_row);
    }
    longest_column_size = map.size();
}
