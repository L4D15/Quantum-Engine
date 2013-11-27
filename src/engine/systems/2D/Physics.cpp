#include "quantum/systems/2D/Physics.h"

using namespace systems2D;

Physics::Physics()
{
    addComponentType<components2D::Physics>();
    addComponentType<components2D::Transform2D>();
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
    physicsMapper.get(e)->update();

    // Add the velocity to the position
    transformMapper.get(e)->move(physicsMapper.get(e)->getVelocity() * world->getDelta());
}
