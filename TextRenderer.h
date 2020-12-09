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
    /**
     * @brief Type of the output stream
     * 
     */
    std::ostream &stream;

public:
    /**
     * @brief Constructor for Text Renderer object
     * 
     * @param stream (The output stream)
     */
    explicit TextRenderer(std::ostream &stream = std::cout) : stream(stream){};

    /**
     * @brief Function for drawing the Game& we want
     * 
     */
    virtual void render(const Game &) const = 0;

    /**
     * @brief Set the Output Stream object
     * 
     * @param stream (The output stream)
     */
    void setOutputStream(std::ostream &stream)
    {
        stream.copyfmt(this->stream); ///< Output stream setting method
    };
};

#endif // TEXTRENDERER_HEADER