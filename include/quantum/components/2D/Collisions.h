#ifndef COLLISIONS_H
#define COLLISIONS_H

#include "quantum/CollisionBox.h"
#include "quantum/components/Component.h"

namespace components2D
{

class Collisions : public components::Component
{
public:
    Collisions();
    ~Collisions();

private:
    CollisionBox box;

};

}

#endif // COLLISIONS_H
