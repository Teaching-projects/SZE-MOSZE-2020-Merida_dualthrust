/**
 * \class TextRenderer
 * 
 * \brief TextRenderer class
 * 
 * \author LilikF
 * 
 * Created on: 2020/12/08
*/

#ifndef TEXTRENDERER_HEADER
#define TEXTRENDERER_HEADER

#include <iostream>
#include <map>

#include "Renderer.h"

class TextRenderer : public Renderer
{
protected:
    std::ostream &stream;

public:
    explicit TextRenderer(std::ostream &stream = std::cout) : stream(stream){};

    virtual void render(const Game &) const = 0;

    void setOutputStream(std::ostream &stream)
    {
        stream.copyfmt(this->stream);
    };
};

#endif // TEXTRENDERER_HEADER