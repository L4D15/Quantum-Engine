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

    void setBoxGeometry(const int x, const int y, const int w, const int h);

private:
    CollisionBox box;

    // Trigger collisions
    bool trigger;
    std::string pathToScript;
};

}

#endif // COLLISIONS_H
