#include "quantum/AnimatedSprite.h"
#include "quantum/Game.h"

using namespace assets2D;

AnimatedSprite::AnimatedSprite(Sprite *sprite)
    : RenderizableAsset(sprite->getName())
{
    this->sprite = sprite;
    this->currentAnimation = sprite->getDefaultAnimation();
    this->currentAnimationFrame = 0;
    this->timeLastUpdate = Game::getTime();
    this->frameIncrement = 1;
}

AnimatedSprite::~AnimatedSprite()
{
    // TODO: Inform the resource manager that we will no longer use the Sprite
}

void AnimatedSprite::changeAnimation(std::string animationName)
{
    this->currentAnimation = this->sprite->getAnimation(animationName);
    this->currentAnimationFrame = 0;
    this->frameIncrement = 1;
    this->timeLastUpdate = Game::getTime();
}

void AnimatedSprite::render(SDL_Renderer *renderer, Vector2 position, Vector2 scale, float rotation)
{
    SDL_Rect spriteFrame = (* this->currentAnimation)[currentAnimationFrame];
    SDL_Rect renderFrame;

    renderFrame.x = position.getX() - ((this->currentAnimation->getWidth() * scale.getX()) / 2.0f);
    renderFrame.y = position.getY() - ((this->currentAnimation->getHeight() * scale.getY()) / 2.0f);
    renderFrame.w = this->currentAnimation->getWidth() * scale.getX();
    renderFrame.h = this->currentAnimation->getHeight() * scale.getY();

    SDL_Point centerPoint;
    centerPoint.x = renderFrame.x;
    centerPoint.y = renderFrame.y;

    SDL_RenderCopyEx(renderer, this->sprite->getTexture(), &spriteFrame, &renderFrame, rotation, &centerPoint, SDL_FLIP_NONE);
}

void AnimatedSprite::update()
{
    if (this->timeLastUpdate + this->currentAnimation->getFrameRate() > SDL_GetTicks())
    {
        // We don't need to update
    }
    else
    {
        this->timeLastUpdate = Game::getTime();
        this->currentAnimationFrame += this->frameIncrement;
        int numberOfFrames = this->currentAnimation->getNumberOfFrames();

        if (this->currentAnimation->isOscillating())
        {
            if (this->frameIncrement > 0)
            {
                if (this->currentAnimationFrame >= numberOfFrames - 1)
                {
                    this->frameIncrement = (-1) * this->frameIncrement;
                }
            }
            else
            {
                if (this->currentAnimationFrame <= 0)
                {
                    this->frameIncrement = (-1) * this->frameIncrement;
                }
            }
        }
        else
        {
            if (this->currentAnimationFrame >= numberOfFrames)
            {
                this->currentAnimationFrame = 0;
            }
        }
    }
}

int AnimatedSprite::getWidth()
{
    return this->currentAnimation->getWidth();
}

int AnimatedSprite::getHeight()
{
    return this->currentAnimation->getHeight();
}

/**
 * @brief Access to pixel matrix surface.
 *
 * If the animation indicated is "Current", the current animation will be used. If the frame is not indicated, the current frame will be used.
 * @param animation
 * @param frame
 * @return
 */
SDL_Surface* AnimatedSprite::getAssetSurface(std::string animation, unsigned int frame)
{
    if (animation == "Current")
    {
        return this->getAssetSurface(this->currentAnimation->getName(), this->currentAnimationFrame);
    }
    else
    {
        return this->getAssetSurface(animation, frame);
    }
}
