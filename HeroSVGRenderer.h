/**
 * \class CharacterSVGRenderer
 * 
 * \brief CharacterSVGRenderer class
 * 
 * \author Lilikf
 * Created on: 2020/12/08
*/

#ifndef HEROSVGRENDERER_HEADER
#define HEROSVGRENDERER_HEADER

#include "SVGRenderer.h"

class HeroSVGRenderer : public SvgRenderer
{
public:
    using SvgRenderer::SvgRenderer;
    /**
     * @brief Render method responsible for creating SVG output based on a Game state, centered on the Hero and using it's light radius.
     * 
     */
    virtual void render(const Game &) const override;
};

#endif // HEROSVGRENDERER_HEADER