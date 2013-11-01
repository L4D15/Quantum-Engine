#include "quantum/components/2D/Collisions.h"
#include "quantum/components/ComponentsList.h"
#include "quantum/Math.h"
#include "quantum/Game.h"

using namespace components2D;

Collisions::Collisions(GameObject &owner):
    Component(owner)
{
    // Set geometry of the collision box equal to the dimensions of the asociated sprite (if any)
    AssetRenderer* renderer;
    Transform2D* transform;

    transform = (Transform2D*) this->owner.getComponent<Transform2D>();
    renderer = (AssetRenderer*) this->owner.getComponent<AssetRenderer>();

    if (renderer != NULL)
    {
        box.width = renderer->getRenderizableAsset()->getWidth();
        box.height = renderer->getRenderizableAsset()->getHeight();
    }
}

void Collisions::setBoxGeometry(const int x, const int y, const int w, const int h)
{
    box.position = Vector2D(x,y);
    box.width = w;
    box.height = h;
}

bool Collisions::collides(GameObject &other)
{
    Transform2D* transform;
    Transform2D* otherTransform;
    Collisions* otherCollisionsComp;
    bool boxesCollides;

    transform = (Transform2D*) this->owner.getComponent<Transform2D>();
    otherTransform = (Transform2D*) this->owner.getComponent<Transform2D>();
    otherCollisionsComp = (Collisions*) this->owner.getComponent<Collisions>();

    // If the other object does not have a Collisions component, they won't collide
    if (otherCollisionsComp == NULL)
    {
        return false;
    }

    boxesCollides = box.collides(transform->getPosition(), otherCollisionsComp->box, otherTransform->getPosition());

    if (boxesCollides == false)
    {
        return false;
    } else if (usePixelLevelCollision == true)
    {
        return pixelLevelCollision(other);
    } else {
        return true;
    }
}

bool Collisions::pixelLevelCollision(GameObject &other)
{
    // Check that both have an asset renderer component
    AssetRenderer* assetRenderer;
    AssetRenderer* otherAssetRenderer;

    assetRenderer = (AssetRenderer*) owner.getComponent<AssetRenderer>();
    otherAssetRenderer = (AssetRenderer*) other.getComponent<AssetRenderer>();

    if (assetRenderer != NULL && otherAssetRenderer != NULL)
    {
        SDL_Surface* A;
        SDL_Surface* B;

        A = assetRenderer->getRenderizableAsset()->getAssetSurface();
        B = otherAssetRenderer->getRenderizableAsset()->getAssetSurface();

        Transform2D* position;
        Transform2D* otherPosition;

        position = (Transform2D*) owner.getComponent<Transform2D>();
        otherPosition = (Transform2D*) other.getComponent<Transform2D>();

        // We calculate the position of the upper left corners of the images
        // We need this to perform the pixel collision testing (the central point is not very useful, tho)
        Vector2D upperLeftA;
        Vector2D upperLeftB;
        int widthA;
        int widthB;
        int heightA;
        int heightB;

        widthA = assetRenderer->getRenderizableAsset()->getWidth();
        heightA = assetRenderer->getRenderizableAsset()->getHeight();
        widthB = otherAssetRenderer->getRenderizableAsset()->getWidth();
        heightB = otherAssetRenderer->getRenderizableAsset()->getHeight();

        upperLeftA = position->getPosition() - Vector2D(widthA / 2.0f, heightA / 2.0f);
        upperLeftB = otherPosition->getPosition() - Vector2D(widthB / 2.0f, heightB / 2.0f);

        // We calculate the overlapping area of the two images since we don't need to test areas we know aren't closer to each other
        SDL_Rect overlappingArea;

        overlappingArea.x = math::max(upperLeftA.getX(), upperLeftB.getX());
        overlappingArea.w = math::min(upperLeftA.getX()+ widthA, upperLeftB.getX() + widthB);
        overlappingArea.y = math::max(upperLeftA.getY(), upperLeftB.getY());
        overlappingArea.h = math::min(upperLeftA.getY()+ heightA, upperLeftB.getY() + heightB);

        Uint32 pixelA;
        Uint32 pixelB;

        Vector2D positionA;
        Vector2D positionB;

        positionA = position->getPosition();
        positionB = otherPosition->getPosition();

        for (int x = overlappingArea.x; x < (overlappingArea.x + overlappingArea.w); x++)
        {
            for (int y = overlappingArea.y; y < (overlappingArea.y + overlappingArea.h); y++)
            {
                pixelA = pixelAt(A, localPixelCoordinates(A, positionA, x, y));
                pixelB = pixelAt(B, localPixelCoordinates(B, positionB, x, y));

                if (pixelA != 0 && pixelB != 0)
                {
                    return true;
                }
            }
        }
        return false;

    }
    else
    {
        return false;
    }
}

/**
 * @brief Access to a color value inside the image.
 * @param image     Image from which extract the value.
 * @param x         Horizontal coordinate inside the pixel matrix.
 * @param y         Vertical coordinate inside the pixel matrix.
 * @return          Color value of the pixel.
 */
Uint32 Collisions::pixelAt(SDL_Surface *image, int x, int y)
{
    return ((Uint32*)image->pixels)[ y * image->w + x ];
}

/**
 * @brief Access to a color value inside the image.
 * @param image     Image from which extract the value.
 * @param position  Position inside the pixel matrix (not the object position in the game).
 * @return          Color value of the pixel.
 */
Uint32 Collisions::pixelAt(SDL_Surface *image, Vector2D position)
{
    return ((Uint32*)image->pixels)[(int)position.getY() * image->w + (int)position.getX()];
}

/**
 * @brief Makes the collision box a trigger that will trigger a certain script when it collides.
 * @param isTrigger     True to make the collision box a trigger, false otherwise.
 * @param script        Name of the script that will be triggered when the object collides.
 */
void Collisions::setTrigger(bool isTrigger, std::string script)
{
    this->trigger = isTrigger;

    if (isTrigger == true)
    {
        this->script = Game::resourceManager.getScript(script);
    }
}
