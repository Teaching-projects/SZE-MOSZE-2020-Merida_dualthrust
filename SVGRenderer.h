  
/**
 * \class SvgRenderer
 * 
 * \brief SvgRenderer class
 * 
 * \author LilikF
 * 
 * Created on: 2020/12/08
*/

#ifndef SVGRENDERER_HEADER
#define SVGRENDERER_HEADER

#include <iostream>
#include <map>
#include <string>
#include <regex>
#include <fstream>

#include "Renderer.h"
#include "Game.h"

class SvgRenderer : public Renderer
{
protected:
    std::string filename;

public:
    SvgRenderer(const std::string& filename) : filename(filename){};

    virtual void render(const Game &) const = 0;

    std::string readSVG(const std::string& path) const
    {
        std::ifstream svg_file(path);
        if (!svg_file.good())
        {
            svg_file.close();
            return "<svg width=\"10\" height=\"10\" viewBox=\"0 0 1 1\"><rect width=\"10\" height=\"10\"/></svg>";
        }
        std::string content((std::istreambuf_iterator<char>(svg_file)), std::istreambuf_iterator<char>());
        svg_file.close();

        return content;
    }

    std::string setCoords(std::string svg_raw, int x, int y) const
    {
        return svg_raw.replace(svg_raw.find("\"Ł\""),3, "\""+std::to_string(x)).replace(svg_raw.find("\"ß\""),3, "\""+std::to_string(y));
    }

};

#endif // SVGRENDERER_HEADER
