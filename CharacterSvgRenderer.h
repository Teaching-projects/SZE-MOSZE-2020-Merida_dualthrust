/**
 * \class CharacterSVGRenderer
 * 
 * \brief CharacterSVGRenderer class
 * 
 * \author Lilikf
 * Created on: 2020/12/08
*/

#ifndef CHARACTERSVGRENDERER_HEADER
#define CHARACTERSVGRENDERER_HEADER

#include "SvgRenderer.h"

class CharacterSVGRenderer : public SvgRenderer
{
public:
    using SvgRenderer::SvgRenderer;
    virtual void render(const Game &) const override;
};

#endif // CHARACTERSVGRENDERER_HEADER