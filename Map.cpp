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

        int64_t signed_longest_row_size = longest_row_size; //Fixes signed-unsigned errors
        uint64_t unsigned_longest_row_size = static_cast<uint64_t>(signed_longest_row_size);

        if(line.length() > unsigned_longest_row_size) 
        {
            longest_row_size=line.length();
        }
        map.push_back(map_row);
    }
    longest_column_size = map.size();
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
        if (i<0)
        {
            continue;
        }

        int64_t signed_i = i; //Fixes signed-unsigned errors
        uint64_t unsigned_i = static_cast<uint64_t>(signed_i);

        if(unsigned_i>=map.size()) 
        {
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
                if(unsigned_i < map.size()){ 

                    int64_t signed_j = j; //Fixes signed-unsigned errors
                    uint64_t unsigned_j = static_cast<uint64_t>(signed_j);

                    if(unsigned_j < map[i].size()){ 
                        std::cout <<tileString[get(i,j)];
                    }else if(unsigned_j < longest_row_size-1){
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