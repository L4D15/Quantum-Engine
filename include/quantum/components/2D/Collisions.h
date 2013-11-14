#ifndef QUANTUM_2D_COLLISIONS_H
#define QUANTUM_2D_COLLISIONS_H

#include "quantum/components/Component.h"
#include "quantum/Vector2D.h"

namespace Components2D
{

class Collisions : public components::Component
{
public:
    Collisions(GameObject& owner) : owner(owner) { }

    inline float getOffsetX() { return offsetX; }
    inline float getOffsetY() { return offsetY; }

    inline void setOffsetX(const float x) { offsetX = x; }
    inline void setOffsetY(const float y) { offsetY = y; }

private:
    float offsetX;
    float offsetY;
};

}

#endif // QUANTUM_2D_COLLISIONS_H
