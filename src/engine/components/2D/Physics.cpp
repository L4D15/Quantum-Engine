#include "quantum/components/2D/Physics.h"
#include "quantum/Game.h"

using namespace Components2D;

Physics::Physics(GameObject &owner) :
    Component(owner)
{

}

Physics::~Physics()
{

}

void Physics::SetVelocity(float x, float y)
{
    this->velocity.SetX(x);
    this->velocity.SetY(y);
}

void Physics::SetVelocity(Vector2D &v)
{
    this->velocity = v;
}

void Physics::SetAceleration(float x, float y)
{
    this->aceleration.SetX(x);
    this->aceleration.SetY(y);
}

void Physics::SetAceleration(Vector2D &a)
{
    this->aceleration = a;
}

void Physics::AddVelocity(float x, float y)
{
    Vector2D v(x, y);

    this->velocity = this->velocity + v;
}

void Physics::AddVelocity(Vector2D &v)
{
    this->velocity = this->velocity + v;
}

void Physics::AddAceleration(float x, float y)
{
    Vector2D a(x, y);

    this->aceleration = this->aceleration + a;
}

void Physics::AddAceleration(Vector2D &a)
{
    this->aceleration = this->aceleration + a;
}

void Physics::Update()
{
    this->velocity = this->velocity + (this->aceleration * Game::deltaTime);
}
