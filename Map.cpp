#include "Map.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

Map::type Map::get(unsigned int row, unsigned int column) const
{
    if(row >= map.size())
    {
        throw WrongIndexException();
    }
    else
    {
        if(column >= map[row].size())
        {
            throw WrongIndexException();
        }
        else
        {
            return type(map[row][column]);
        }
    }
}

Map::Map(){}

Map::Map(std::string path)
{
    std::string line;
    std::ifstream mapfile(path);
    longest_row_size = 0;
    longest_column_size = 0;
    
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

void Map::drawMap(const int viewrange, int hero_row, int hero_column) const
{
/*     std::cout << "viewrange: "<< viewrange <<", hero_row: "<< hero_row <<", hero_column: "<< hero_column <<std::endl;
 */

    //Draw the upper border of the map
    std::cout << "╔";


    for (int j = hero_column-viewrange; j < hero_column+viewrange+1; j++)
    {
         if (j<0)
            {
                continue;
            }
            else
            {
                if(j<longest_row_size-1){
                    std::cout <<"══"; 
                }
            }
    }


    std::cout <<"╗"<< std::endl;

    for (int i = hero_row-viewrange; i < hero_row+viewrange+1; i++)
    {
        int current_row_length = 0;
 
        if (i<0)
        {
            continue;
        }

        if(i>=map.size()){
            break;
        }else{
            std::cout <<"║";    
        }
        
        
        for (int j = hero_column-viewrange; j < hero_column+viewrange+1; j++)
        {
            if (j<0||j>longest_row_size)
            {
                continue;
            }
            else
            {
                //Ha van ilyen mező a mapon, lekérjük a stringet amit kiírunk
                if(i < map.size()){
                    if(j < map[i].size()){
                        std::cout <<tileString[get(i,j)];
                        current_row_length=j;
                    }else if(j < longest_row_size-1){
                        std::cout <<"  ";
                    }
                }
            }
 

        }
        
        std::cout <<"║"<<std::endl;      
    }
    
    std::cout << "╚";

    for (int j = hero_column-viewrange; j < hero_column+viewrange+1; j++)
    {
         if (j<0)
            {
                continue;
            }
            else
            {
                if(j<longest_row_size-1){
                    std::cout <<"══"; 
                }
            }
    }

    std::cout <<"╝"<< std::endl;
    
}

void Map::setTile(int row, int column, int type_int){
    map[row][column] = type_int;
}