#include "quantum/components/2D/BoxCollider.h"
#include "quantum/components/2D/AssetRenderer.h"
#include "quantum/Game.h"
#include <sstream>

using namespace components2D;

BoxCollider::BoxCollider(GameObject& owner) :
    Collisions(owner)
{
    // Check if there is an asset renderer attached to automatically set width and height
    AssetRenderer* rendererComp;

    rendererComp = (AssetRenderer*) owner.getComponent<AssetRenderer>();

    if (rendererComp != NULL)
    {
        this->width = rendererComp->getRenderizableAsset()->getWidth();
        this->height = rendererComp->getRenderizableAsset()->getHeight();
    }
    else
    {
        // If no asset attached, make the box 1x1
        this->width = 1.0f;
        this->height = 1.0f;
    }

    // Check owner has a Collisions component. If not, add it
    Collisions* collisionsComp;

    collisionsComp = (Collisions*) owner.getComponent<Collisions>();

    if (collisionsComp == NULL)
    {
        owner.addComponent(new Collisions(owner));
    }
}

std::string BoxCollider::toString()
{
    std::stringstream stream;
    Vector2D globalPosition;

    globalPosition = this->owner.getRealPosition2D(offsetX, offsetY);

    stream << "Box Collider [x=" << globalPosition.getX() << " y=" << globalPosition.getY() << " // w=" << width << " h=" << height << "]" << std::endl;

    return stream.str();
}

/**
 * @brief BoxCollider::render
 * @param color
 */
void BoxCollider::render(Color color)
{
    Vector2D realPosition = this->owner.getRealPosition2D(offsetX, offsetY);

    SDL_Rect box;

    box.x = realPosition.getX();
    box.y = realPosition.getY();
    box.w = width;
    box.h = height;

    Uint8 r, g, b, a;
    SDL_GetRenderDrawColor(Game::window->getRenderer(), &r, &g, &b, &a);

    SDL_SetRenderDrawColor(Game::window->getRenderer(), color.getRed(), color.getGreen(), color.getBlue(), color.getAlpha());
    SDL_RenderDrawRect(Game::window->getRenderer(), &box);
    SDL_SetRenderDrawColor(Game::window->getRenderer(), r, g, b, a);
}
