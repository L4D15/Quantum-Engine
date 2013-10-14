#ifndef QUANTUM_ANIMATEDSPRITE_H
#define QUANTUM_ANIMATEDSPRITE_H

#include "quantum/RenderizableAsset.h"
#include "quantum/Sprite.h"

namespace Assets2D
{

class AnimatedSprite : public RenderizableAsset
{
public:
    AnimatedSprite(Sprite* sprite);
    virtual ~AnimatedSprite();

    void                ChangeAnimation(std::string animationName);
    void                Update();

    int                 GetWidth();
    int                 GetHeight();

    void                Render(SDL_Renderer *renderer, Vector2D position, Vector2D scale, float rotation);

private:
    Sprite*        sprite;
    SpriteSheetAnimation*             currentAnimation;
    int                 currentAnimationFrame;

    int                 timeLastUpdate;
    int                 frameIncrement;
};

}

#endif // QUANTUM_ANIMATEDSPRITE_H
