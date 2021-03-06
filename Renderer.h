/**
 * \class Renderer
 * 
 * \brief Renderer class
 * 
 * \author LilikF
 * 
 * Created on: 2020/12/08
*/

#ifndef RENDERER_HEADER
#define RENDERER_HEADER

class Game;

class Renderer
{
public:
    /**
     * @brief Drawing function
     * 
     */
    virtual void render(const Game &) const = 0;
    /**
     * @brief Destructor for Renderer object
     * 
     */
    virtual ~Renderer(){};
};

#endif // RENDERER_HEADER