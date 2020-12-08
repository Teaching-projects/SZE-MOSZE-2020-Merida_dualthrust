
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
    virtual void render(const Game &) const override;
};

#endif // HeroTextRenderer