#ifndef QUANTUM_PHYSICS_SYSTEM_H
#define QUANTUM_PHYSICS_SYSTEM_H

#include "quantum/Libraries.h"
#include "quantum/components/2D/Transform2D.h"
#include "quantum/components/2D/Physics.h"

namespace Systems2D
{

class Physics : public artemis::EntityProcessingSystem
{
public:
    Physics();
    virtual ~Physics();

    void                initialize();
    void                processEntity(artemis::Entity& e);

private:
    artemis::ComponentMapper<Components2D::Physics>     physicsMapper;
    artemis::ComponentMapper<Components2D::Transform2D> transformMapper;
};

}

#endif // QUANTUM_PHYSICS_SYSTEM_H
