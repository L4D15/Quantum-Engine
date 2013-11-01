#ifndef QUANTUM_PHYSICS_COMPONENT_H
#define QUANTUM_PHYSICS_COMPONENT_H

#include "quantum/components/Component.h"
#include "quantum/Vector2D.h"

namespace components2D
{

class Physics : public components::Component
{
public:
    Physics(GameObject& owner);
    ~Physics();

    void                    setVelocity(float x, float y);
    void                    setVelocity(Vector2D& v);
    void                    setAceleration(float x, float y);
    void                    setAceleration(Vector2D& a);

    inline Vector2D         getVelocity() { return velocity; }
    inline Vector2D         getAceleration() { return aceleration; }

    void                    addVelocity(float x, float y);
    void                    addVelocity(Vector2D& v);
    void                    addAceleration(float x, float y);
    void                    addAceleration(Vector2D& a);

    void                    update();

private:
    Vector2D                velocity;
    Vector2D                aceleration;
};

}


#endif // QUANTUM_PHYSICS_COMPONENT_H
