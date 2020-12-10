  
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
    /**
     * @brief Name of the output file
     * 
     */
    std::string filename;

public:
    /**
     * @brief Constructor for Svg Renderer object
     * 
     * @param filename of the output we want to use
     */
    SvgRenderer(const std::string& filename) : filename(filename){};

    /**
     * @brief Render method responsible for creating SVG output based on a Game state.
     *
     */
    virtual void render(const Game &) const override = 0;
    /**
     * @brief Reading the SVG file we want to use
     * 
     * @param path 
     * @return std::string 
     */
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

    /**
     * @brief Sets the coordinates for a given tile in the rendered SVG output.
     * 
     */
    std::string setCoords(std::string svg_raw, int x, int y) const
    {
        return svg_raw.replace(svg_raw.find("\"Ł\""),3, "\""+std::to_string(x)).replace(svg_raw.find("\"ß\""),3, "\""+std::to_string(y));
    }

};

#endif // SVGRENDERER_HEADER
