#include "quantum/systems/2D/Physics.h"

using namespace Systems2D;

Physics::Physics()
{
    addComponentType<Components2D::Physics>();
    addComponentType<Components2D::Transform2D>();
}

Physics::~Physics()
{

}

void Physics::initialize()
{
    physicsMapper.init(* world);
    transformMapper.init(* world);
}

void Physics::processEntity(artemis::Entity& e)
{
    // Update the physics component (adding the aceleration to the velocity)
    physicsMapper.get(e)->Update();

    // Add the velocity to the position
    transformMapper.get(e)->Move(physicsMapper.get(e)->GetVelocity() * world->getDelta());
}
