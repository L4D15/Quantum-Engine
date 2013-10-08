#ifndef QUANTUM_PHYSICS_COMPONENT_H
#define QUANTUM_PHYSICS_COMPONENT_H

#include "quantum/components/Component.h"
#include "quantum/Vector2D.h"

namespace Components2D
{

class Physics : public Components::Component
{
public:
    Physics(GameObject& owner);
    ~Physics();

    void                    SetVelocity(float x, float y);
    void                    SetVelocity(Vector2D& v);
    void                    SetAceleration(float x, float y);
    void                    SetAceleration(Vector2D& a);

    inline Vector2D         GetVelocity() { return velocity; }
    inline Vector2D         GetAceleration() { return aceleration; }

    void                    AddVelocity(float x, float y);
    void                    AddVelocity(Vector2D& v);
    void                    AddAceleration(float x, float y);
    void                    AddAceleration(Vector2D& a);

    void                    Update();

private:
    Vector2D                velocity;
    Vector2D                aceleration;
};

}


#endif // QUANTUM_PHYSICS_COMPONENT_H
