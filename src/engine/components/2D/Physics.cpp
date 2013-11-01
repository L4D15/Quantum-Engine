#include "quantum/components/2D/Physics.h"
#include "quantum/Game.h"

using namespace components2D;

Physics::Physics(GameObject &owner) :
    Component(owner)
{

}

Physics::~Physics()
{

}

void Physics::setVelocity(float x, float y)
{
    this->velocity.setX(x);
    this->velocity.setY(y);
}

void Physics::setVelocity(Vector2D &v)
{
    this->velocity = v;
}

void Physics::setAceleration(float x, float y)
{
    this->aceleration.setX(x);
    this->aceleration.setY(y);
}

void Physics::setAceleration(Vector2D &a)
{
    this->aceleration = a;
}

void Physics::addVelocity(float x, float y)
{
    Vector2D v(x, y);

    this->velocity = this->velocity + v;
}

void Physics::addVelocity(Vector2D &v)
{
    this->velocity = this->velocity + v;
}

void Physics::addAceleration(float x, float y)
{
    Vector2D a(x, y);

    this->aceleration = this->aceleration + a;
}

void Physics::addAceleration(Vector2D &a)
{
    this->aceleration = this->aceleration + a;
}

void Physics::update()
{
    this->velocity = this->velocity + (this->aceleration * Game::deltaTime);
}
