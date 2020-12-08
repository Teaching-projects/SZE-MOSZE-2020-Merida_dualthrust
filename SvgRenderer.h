  
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
    SvgRenderer(std::string filename) : filename(filename){};

    virtual void render(const Game &) const = 0;
};

#endif // SVGRENDERER_HEADER