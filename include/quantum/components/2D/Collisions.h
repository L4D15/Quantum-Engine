#ifndef COLLISIONS_H
#define COLLISIONS_H

#include "quantum/CollisionBox.h"
#include "quantum/components/Component.h"
#include "quantum/GameObject.h"

namespace components2D
{

class Collisions : public components::Component
{
public:
    Collisions(GameObject& owner);
    ~Collisions();

    void                setBoxGeometry(const int x, const int y, const int w, const int h);
    inline void         setPixelLevelCollision(bool use) { usePixelLevelCollision = use; }

    bool                collides(GameObject& other);

    void                setTrigger(bool isTrigger, std::string script = "");

private:
    bool                pixelLevelCollision(GameObject& other);
    Uint32              pixelAt(SDL_Surface* image, int x, int y);
    Uint32              pixelAt(SDL_Surface *image, Vector2D position);
    Vector2D            localPixelCoordinates(SDL_Surface* image, Vector2D& imageGlobalPosition ,int x, int y);

private:
    CollisionBox        box;
    bool                usePixelLevelCollision;

    // Trigger collisions
    bool                trigger;
    std::string         script;
};

}

#endif // COLLISIONS_H
