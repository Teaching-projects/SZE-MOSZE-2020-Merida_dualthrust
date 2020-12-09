
/**
 * \class HeroTextRenderer
 * 
 * \brief HeroTextRenderer class
 * 
 * \author LilikF
 * 
 * Created on: 2020/12/08
*/

#ifndef HEROTEXTRENDERER_HEADER
#define HEROTEXTRENDERER_HEADER

#include "TextRenderer.h"
#include "Game.h"
#include "Map.h"

class HeroTextRenderer : public TextRenderer
{
public:
    using TextRenderer::TextRenderer;
    /**
     * @brief Render method responsible for creating text output based on a Game state, centered on the Hero and using it's light radius.
     * 
     */
    virtual void render(const Game &) const override;
};

#endif // HeroTextRenderer