#ifndef QUANTUM_ANIMATEDSPRITE_H
#define QUANTUM_ANIMATEDSPRITE_H

#include "quantum/RenderizableAsset.h"
#include "quantum/Sprite.h"

namespace assets2D
{

class AnimatedSprite : public RenderizableAsset
{
public:
    AnimatedSprite(Sprite* sprite);
    virtual ~AnimatedSprite();

    void                changeAnimation(std::string animationName);
    void                update();

    int                 getWidth();
    int                 getHeight();

    void                render(SDL_Renderer *renderer, Vector2D position, Vector2D scale, float rotation);

private:
    Sprite*             sprite;
    SpriteSheetAnimation*             currentAnimation;
    int                 currentAnimationFrame;

    int                 timeLastUpdate;
    int                 frameIncrement;
};

}

#endif // QUANTUM_ANIMATEDSPRITE_H
