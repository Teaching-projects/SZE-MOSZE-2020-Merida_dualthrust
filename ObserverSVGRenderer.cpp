#include "ObserverSVGRenderer.h"

void ObserverSVGRenderer::render(const Game &game) const
{
    std::ofstream svgFile;
    svgFile.open(this->filename);
    svgFile << "<svg xmlns=\"http://www.w3.org/2000/svg\" >";

    Map map = *game.getMap();
    
    for (unsigned int i = 0; i < map.getMap().size(); i++)
    {
        for (unsigned int j = 0; j < map.getMap()[i].size(); j++)
        {
            std::string svg = "";
            
            if (map.get(i,j)==Map::type::Hero)
            {
                svg = readSVG(game.getHero()->getTexture());
            }
            else if (map.get(i,j)==Map::type::Monster)
            {
                svg = this->readSVG(game.getMonsterByPosition(i, j).getTexture());
            }
            else
            {
                svg = this->readSVG(map.svg[map.get(i,j)]);
            }
            svgFile << this->setCoords(svg, j * 10, i * 10);

        }

        for (unsigned int j = 0; j < map.longest_row_size - map.getMap()[i].size(); j++)
        {
            std::string textureFile = map.svg[1];
            std::string svgContent = readSVG(textureFile);
            svgFile << this->setCoords(svgContent, (j + map.getMap()[i].size()) * 10, i * 10);
        }
    }

    svgFile << "</svg>";
    svgFile.close();
}
