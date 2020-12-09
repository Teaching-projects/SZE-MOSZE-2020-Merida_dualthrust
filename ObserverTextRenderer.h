
/**
 * \class ObserverTextRenderer
 * 
 * \brief ObserverTextRenderer class
 * 
 * \author LilikF
 * 
 * Created on: 2020/12/08
*/

#ifndef OBSERVERTEXTRENDERER_HEADER
#define OBSERVERTEXTRENDERER_HEADER

#include "TextRenderer.h"
#include "Game.h"
#include "Map.h"

class ObserverTextRenderer : public TextRenderer
{
public:
    using TextRenderer::TextRenderer;
    /**
     * @brief Render method responsible for creating text output based on a Game state. Draws the whole map.
     * 
     */
    virtual void render(const Game &) const override;
};

#endif // OBSERVERTEXTRENDERER_HEADER