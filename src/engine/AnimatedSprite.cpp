#include "quantum/AnimatedSprite.h"
#include "quantum/Game.h"

using namespace Assets2D;

AnimatedSprite::AnimatedSprite(SpriteSheet *sprite)
    : RenderizableAsset(sprite->GetName())
{
    this->sprite = sprite;
    this->currentAnimation = sprite->GetDefaultAnimation();
    this->currentAnimationFrame = 0;
    this->timeLastUpdate = Game::GetTime();
    this->frameIncrement = 1;
}

AnimatedSprite::~AnimatedSprite()
{
    // TODO: Inform the resource manager that we will no longer use the Sprite
}

void AnimatedSprite::ChangeAnimation(std::string animationName)
{
    this->currentAnimation = this->sprite->GetAnimation(animationName);
    this->currentAnimationFrame = 0;
    this->frameIncrement = 1;
    this->timeLastUpdate = Game::GetTime();
}

void AnimatedSprite::Render(SDL_Renderer *renderer, Vector2D position, Vector2D scale, float rotation)
{
    SDL_Rect spriteFrame = (* this->currentAnimation)[currentAnimationFrame];
    SDL_Rect renderFrame;

    renderFrame.x = position.GetX() - (this->currentAnimation->GetWidth() / 2);
    renderFrame.y = position.GetY() - (this->currentAnimation->GetHeight() / 2);
    renderFrame.w = this->currentAnimation->GetWidth() * scale.GetX();
    renderFrame.h = this->currentAnimation->GetHeight() * scale.GetY();

    SDL_Point centerPoint;
    centerPoint.x = renderFrame.x;
    centerPoint.y = renderFrame.y;

    SDL_RenderCopyEx(renderer, this->sprite->GetTexture(), &spriteFrame, &renderFrame, rotation, &centerPoint, SDL_FLIP_NONE);
}

void AnimatedSprite::Update()
{
    if (this->timeLastUpdate + this->currentAnimation->GetFrameRate() > SDL_GetTicks())
    {
        // We don't need to update
    }
    else
    {
        this->timeLastUpdate = Game::GetTime();
        this->currentAnimationFrame += this->frameIncrement;
        int numberOfFrames = this->currentAnimation->GetNumberOfFrames();

        if (this->currentAnimation->IsOscillating())
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
