#include "HeroSVGRenderer.h"

void HeroSVGRenderer::render(const Game &game) const
{
    std::ofstream svgFile;
    svgFile.open(this->filename);
    svgFile << "<svg xmlns=\"http://www.w3.org/2000/svg\" >";

    Hero* hero = game.getHero();
    Map map = *game.getMap();
    
    int hero_column = hero->getPosition().second;
    int hero_row = hero->getPosition().first;
    int viewrange = hero->getLightRadius();

    for (int i = hero_row-viewrange; i < hero_row+viewrange+1; i++)
    {
        for (int j = hero_column-viewrange; j < hero_column+viewrange+1; j++)
        {
            if (j<0||j>map.longest_row_size)
            {
                continue;
            }
            else
            {
                
                int64_t signed_i = i; //Fixes signed-unsigned errors
                uint64_t unsigned_i = static_cast<uint64_t>(signed_i);

                //Ha van ilyen mező a mapon, lekérjük a stringet amit kiírunk
                if(unsigned_i < map.getMap().size()){ 

                    int64_t signed_j = j; //Fixes signed-unsigned errors
                    uint64_t unsigned_j = static_cast<uint64_t>(signed_j);

                    if(unsigned_j < map.getMap()[i].size()){
                        svgFile << this->setCoords(readSVG(map.svg[map.get(i,j)]), j * 10, i * 10);
                    }else if(j < map.longest_row_size-1){
                        svgFile << this->setCoords(readSVG(map.svg[1]), j * 10, i * 10);
                    }

                    
                }
            }
 

        }
        
    }
    
    svgFile << "</svg>";
    svgFile.close();
}
