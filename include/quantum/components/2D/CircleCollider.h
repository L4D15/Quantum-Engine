#ifndef QUANTUM_2D_CIRCLECOLLIDER_H
#define QUANTUM_2D_CIRCLECOLLIDER_H

#include "quantum/components/2D/Collisions.h"

namespace components2D
{

class CircleCollider : public components::Component
{
public:
    CircleCollider(GameObject& owner);

    inline void             setOffsetX(const float x) { offsetX = x; }
    inline void             setOffsetY(const float y) { offsetY = y; }
    inline float            getOffsetX() { return offsetX; }
    inline float            getOffsetY() { return offsetY; }
    inline void             setRadius(const float r) { radius = r; }

    inline float            getRadius() { return radius; }

protected:
    float                   offsetX;
    float                   offsetY;
    float                   radius;
};

}

#endif // QUANTUM_2D_CIRCLECOLLIDER_H
