#include "quantum/CollisionBox.h"
#include "quantum/Game.h"

/**
 * @brief CollisionBox::CollisionBox
 */
CollisionBox::CollisionBox()
{
    this->width = 0;
    this->height = 0;
}

/**
 * @brief CollisionBox::CollisionBox
 * @param x
 * @param y
 * @param w
 * @param h
 */
CollisionBox::CollisionBox(const float x, const float y, const float w, const float h) :
    position(x, y)
{
    this->width = w;
    this->height = h;
}

/**
 * @brief CollisionBox::collides
 * @param globalPosition
 * @param other
 * @param otherGlobalPosition
 * @return
 */
bool CollisionBox::collides(Vector2D objectPosition, CollisionBox &other, Vector2D otherGlobalPosition)
{
    Vector2D boxUpperLeftPosition;
    Vector2D otherUpperLeftPosition;

    boxUpperLeftPosition = objectPosition + this->position - Vector2D(this->width / 2, this->height / 2);
    otherUpperLeftPosition = otherGlobalPosition + other.position - Vector2D(other.width / 2, other.height / 2);

    SDL_Rect A;
    SDL_Rect B;

    A.x = boxUpperLeftPosition.getX();
    A.y = boxUpperLeftPosition.getY();
    A.w = this->width;
    A.h = this->height;

    B.x = otherUpperLeftPosition.getX();
    B.y = otherUpperLeftPosition.getY();
    B.w = other.width;
    B.h = other.height;

    // If the right side is not beyond the others left side, they aren't colliding
    if (A.x + A.w < B.x)
    {
        return false;
    }

    // If the left side is not before the other box right side, they aren't colliding
    if (A.x > B.x + B.w)
    {
        return false;
    }

    // If the bottom side os not less than the other upper side, they aren't colliding
    if (A.y > B.y + B.h)
    {
        return false;
    }

    // If the upper side is not less than the other bottom side, they aren't colliding
    if (A.y + A.h < B.y)
    {
        return false;
    }

    // If none of these cases are met, they are colliding
    return true;
}

/**
 * @brief CollisionBox::render
 * @param cameraToRender
 * @param position
 * @param color
 */
void CollisionBox::render(components2D::Camera *cameraToRender, Vector2D position, Color color)
{
    SDL_Renderer* renderer;
    Vector2D globalPosition;
    Vector2D upperLeftPosition;

    renderer = Game::window->getRenderer();

    globalPosition = position + this->position;
    upperLeftPosition = globalPosition - Vector2D(this->width / 2, this->height / 2);

    SDL_Rect box;

    box.x = upperLeftPosition.getX();
    box.y = upperLeftPosition.getY();
    box.w = this->width;
    box.h = this->height;

    Uint8 oldRed;
    Uint8 oldGreen;
    Uint8 oldBlue;
    Uint8 oldAlpha;

    SDL_GetRenderDrawColor(renderer, &oldRed, &oldGreen, &oldBlue, &oldAlpha);
    SDL_SetRenderDrawColor(renderer, color.getRed(), color.getGreen(), color.getBlue(), color.getAlpha());

    SDL_RenderDrawRect(renderer, &box);
    SDL_RenderDrawPoint(renderer, globalPosition.getX(), globalPosition.getY());

    SDL_SetRenderDrawColor(renderer, oldRed, oldGreen, oldBlue, oldAlpha);
}
