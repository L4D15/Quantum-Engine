#include "quantum/systems/2D/Collisions.h"

using namespace systems2D;

Collisions::Collisions()
{
    addComponentType<components2D::Transform2D>();
    //addComponentType<components2D::Collisions>();
}

Collisions::~Collisions()
{

}

void Collisions::initialize()
{
    transformMapper.init(* world);
    //collisionsMapper.init(* world);
}

void Collisions::processEntity(artemis::Entity &e)
{
    // Check collision with others
    // Right now it checks with every object in the game, but we should implement a quadtree structure for this

}
