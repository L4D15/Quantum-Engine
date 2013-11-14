#ifndef QUANTUM_SYSTEMS_COLLISIONS_H
#define QUANTUM_SYSTEMS_COLLISIONS_H

#include "quantum/Libraries.h"
#include "quantum/components/ComponentsList.h"

namespace systems2D
{

class Collisions : artemis::EntityProcessingSystem
{
public:
    Collisions();
    virtual ~Collisions();

    void                initialize();
    void                processEntity(artemis::Entity &e);

private:
    artemis::ComponentMapper<components2D::Transform2D> transformMapper;
    //artemis::ComponentMapper<components2D::Collisions>  collisionsMapper;
};

}

#endif // QUANTUM_SYSTEMS_COLLISIONS_H
