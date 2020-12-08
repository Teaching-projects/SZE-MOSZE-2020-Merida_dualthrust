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

#include "SvgRenderer.h"

class ObserverSVGRenderer : public SvgRenderer
{
public:
    using SvgRenderer::SvgRenderer;
    virtual void render(const Game &) const override;
};

#endif // OBSERVERSVGRENDERER_HEADER