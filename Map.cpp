#include "Map.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

Map::type Map::get(unsigned int x, unsigned int y) const
{
    if(x >= map.size())
    {
        throw WrongIndexException();
    }
    else
    {
        if(y >= map[x].size())
        {
            throw WrongIndexException();
        }
        else
        {
            return type(map[x][y]);
        }
    }
}

Map::Map(){}

Map::Map(std::string path)
{
    std::string line;
    std::ifstream mapfile(path);
    longest_row_size = 0;
    
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
            //Nullpointereket tolunk bele, hogy fel legyen töltve hellyel
            
        }
        
        if(line.length() > longest_row_size)
        {
            longest_row_size=line.length();
        }

        map.push_back(map_row);
    }
}

void Map::drawMap() const
{

    std::cout << "╔";
    for (unsigned int number_of_chars = 0; number_of_chars < longest_row_size; number_of_chars++)
    {
        std::cout <<"══"; 
    }                           
    std::cout <<"╗"<< std::endl;


    for (unsigned int row = 0; row < map.size(); row++)
    {   

        int current_row_length = 0;
        std::cout <<"║";        
        for (unsigned int column = 0; column < map[row].size(); column++)
        {

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
            current_row_length=column;          
        }

        for(unsigned int i=current_row_length;i<longest_row_size-1;i++)
        {
            std::cout <<"  ";
        }
        std::cout <<"║"<<std::endl;

    }
    
    std::cout << "╚";
    for (unsigned int number_of_chars = 0; number_of_chars <  longest_row_size; number_of_chars++)
    {
        std::cout <<"══"; 
    }
    std::cout << "╝"<< std::endl;
    
}

void Map::setTile(int x, int y, int type_int){
    map[x][y] = type_int;
}