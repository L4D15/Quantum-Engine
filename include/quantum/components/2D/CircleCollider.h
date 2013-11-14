#ifndef QUANTUM_2D_CIRCLECOLLIDER_H
#define QUANTUM_2D_CIRCLECOLLIDER_H

#include "quantum/components/2D/Collisions.h"

namespace components2D
{

class CircleCollider : public Collisions
{
public:
    CircleCollider(GameObject& owner);

    inline void setRadius(const float r) { radius = r; }

    inline float getRadius() { return radius; }

protected:
    float radius;
};

}

#endif // QUANTUM_2D_CIRCLECOLLIDER_H
