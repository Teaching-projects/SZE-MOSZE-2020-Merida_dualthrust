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
        if(y >= map[x].size() || y < 0)
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
        for(int i=0;i<line.length();i++){
            if(line[i]=='#'){
                map_row.push_back(type(Wall));
            }else if(line[i]=' '){
                map_row.push_back(type(Free));
            }
        }
        
        if(line.length() > longest_row_size){
            longest_row_size=line.length();
        }

        map.push_back(map_row);
    }
}

void Map::drawMap() const
{

    std::cout << "╔";
    for (int number_of_chars = 0; number_of_chars < longest_row_size; number_of_chars++)
    {
        std::cout <<"══"; 
    }                           
    std::cout <<"╗"<< std::endl;


    for (int row = 0; row < map.size(); row++)
    {   

        int current_row_length = 0;
        std::cout <<"║";        
        for (int column = 0; column < map[row].size(); column++)
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

        for(int i=current_row_length;i<longest_row_size-1;i++)
        {
            std::cout <<"  ";
        }
        std::cout <<"║"<<std::endl;

    }
    
    std::cout << "╚";
    for (int number_of_chars = 0; number_of_chars <  longest_row_size; number_of_chars++)
    {
        std::cout <<"══"; 
    }
    std::cout << "╝"<< std::endl;
    
}