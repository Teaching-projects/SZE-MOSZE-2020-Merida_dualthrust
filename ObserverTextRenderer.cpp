#include "ObserverTextRenderer.h"

void ObserverTextRenderer::render(const Game &game) const
{
   Map map = *game.getMap();
   this->stream << "╔";


    for (int j = 0; j < map.longest_row_size-1; j++)
    {
         if (j<0)
            {
                continue;
            }
            else
            {
                    this->stream <<"══"; 
            }
    }


    this->stream <<"╗"<< std::endl;

    for (int i = 0; i < map.longest_column_size; i++)
    {
        if (i<0)
        {
            continue;
        }

        int64_t signed_i = i; //Fixes signed-unsigned errors
        uint64_t unsigned_i = static_cast<uint64_t>(signed_i);

        this->stream <<"║";    
        
        for (int j = 0; j < map.longest_row_size; j++)
        {
                //Ha van ilyen mező a mapon, lekérjük a stringet amit kiírunk
                if(unsigned_i < map.longest_column_size){ 

                    int64_t signed_j = j; //Fixes signed-unsigned errors
                    uint64_t unsigned_j = static_cast<uint64_t>(signed_j);

                    if(unsigned_j < map.getMap()[i].size()){ 
                        this->stream <<map.tileString[map.get(i,j)];
                    }else if(j < map.longest_row_size-1){
                        this->stream <<"  ";
                    }

                }
        }
        
        this->stream <<"║"<<std::endl;      
    }
    
    this->stream << "╚";

    for (int j = 0; j < map.longest_row_size-1; j++)
    {
         if (j<0)
            {
                continue;
            }
            else
            {
                    this->stream <<"══"; 
            }
    }

    this->stream <<"╝"<< std::endl;
}