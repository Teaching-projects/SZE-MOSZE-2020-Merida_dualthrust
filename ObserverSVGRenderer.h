/**
 * \class ObserverSVGRenderer
 * 
 * \brief ObserverSVGRenderer class
 * 
 * \author Lilikf
 * Created on: 2020/12/08
*/

#ifndef OBSERVERSVGRENDERER_HEADER
#define OBSERVERSVGRENDERER_HEADER

#include "SVGRenderer.h"

class ObserverSVGRenderer : public SvgRenderer
{
public:
    using SvgRenderer::SvgRenderer;
    /**
     * @brief Render method responsible for creating SVG output based on a Game state. Draws the whole map.
     * 
     */
    virtual void render(const Game &) const override;
};

#endif // OBSERVERSVGRENDERER_HEADER
