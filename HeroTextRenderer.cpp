#include "HeroTextRenderer.h"
#include "map.h"

void HeroTextRenderer::render(const Game &game) const
{
    Map map = *game.getMap();
    
    Hero* hero = game.getHero();
    int hero_column = hero->getPosition().second;
    int hero_row = hero->getPosition().first;
    int viewrange = hero->getLightRadius();


    this->stream << "╔";


    for (int j = hero_column-viewrange; j < hero_column+viewrange+1; j++)
    {
         if (j<0)
            {
                continue;
            }
            else
            {
                if(j<map.longest_row_size-1){
                    this->stream <<"══"; 
                }
            }
    }


    this->stream <<"╗"<< std::endl;

    for (int i = hero_row-viewrange; i < hero_row+viewrange+1; i++)
    {
        if (i<0)
        {
            continue;
        }

        int64_t signed_i = i; //Fixes signed-unsigned errors
        uint64_t unsigned_i = static_cast<uint64_t>(signed_i);

        if(unsigned_i>=map.getMap().size()) 
        {
            break;
        }else{
            this->stream <<"║";    
        }
        
        
        for (int j = hero_column-viewrange; j < hero_column+viewrange+1; j++)
        {
            if (j<0||j>map.longest_row_size)
            {
                continue;
            }
            else
            {
                //Ha van ilyen mező a mapon, lekérjük a stringet amit kiírunk
                if(unsigned_i < map.getMap().size()){ 

                    int64_t signed_j = j; //Fixes signed-unsigned errors
                    uint64_t unsigned_j = static_cast<uint64_t>(signed_j);

                    if(unsigned_j < map.getMap()[i].size()){ 
                        this->stream << map.tileString[map.get(i,j)];
                    }else if(j < map.longest_row_size-1){
                        this->stream <<"  ";
                    }
                }
            }
 

        }
        
        this->stream <<"║"<<std::endl;      
    }
    
    this->stream << "╚";

    for (int j = hero_column-viewrange; j < hero_column+viewrange+1; j++)
    {
         if (j<0)
            {
                continue;
            }
            else
            {
                if(j<map.longest_row_size-1){
                    this->stream <<"══"; 
                }
            }
    }

    this->stream <<"╝"<< std::endl;
}