#include "quantum/systems/2D/Collisions.h"
#include "quantum/Game.h"

using namespace systems2D;

Collisions::Collisions()
{
    addComponentType<components2D::Transform2D>();
    addComponentType<components2D::Collisions>();
}

Collisions::~Collisions()
{

}

void Collisions::initialize()
{
    transformMapper.init(* world);
    collisionsMapper.init(* world);
}

void Collisions::processEntity(artemis::Entity &e)
{
    // Check collision with others
    // Right now it checks with every object in the game, but we should implement a quadtree structure for this
    std::map<std::string, GameObject* >& objects = Game::sceneManager.getCurrentScene()->getObjects();

    std::map<std::string, GameObject* >::iterator currentObject;
    bool isColliding;
    for(currentObject = objects.begin(); currentObject != objects.end(); ++currentObject)
    {
        artemis::Entity& other = currentObject->second->getEntity();

        //********//
        long id;
        long otherId;

        id = e.getUniqueId();
        otherId = other.getUniqueId();
        //********//

        if (e.getUniqueId() != other.getUniqueId())
        {
            isColliding = collides(e, other);

            if (isColliding == true)
            {
                std::cout << "COLLISION!" << std::endl;
            }
            else
            {

            }
        }
    }
}

bool Collisions::collides(artemis::Entity &A, artemis::Entity &B)
{
    // Check for colliders
    components2D::BoxCollider* ABox;
    components2D::BoxCollider* BBox;
    components2D::CircleCollider* ACircle;
    components2D::CircleCollider* BCircle;

    ABox = (components2D::BoxCollider*) A.getComponent<components2D::BoxCollider>();
    BBox = (components2D::BoxCollider*) B.getComponent<components2D::BoxCollider>();

    // Boxes collision
    if (ABox != NULL && BBox != NULL)
    {
        Vector2 AOffset(ABox->getOffsetX() - ABox->getWidth() / 2.0f, ABox->getOffsetY());
        Vector2 BOffset(BBox->getOffsetX() - BBox->getWidth() / 2.0f, BBox->getOffsetY());

        Vector2 AUpperLeft = ABox->GetOwner().getRealPosition2D(AOffset);
        Vector2 BUpperLeft = BBox->GetOwner().getRealPosition2D(BOffset);

        SDL_Rect a;
        a.x = AUpperLeft.getX();
        a.y = AUpperLeft.getY();
        a.w = ABox->getWidth();
        a.h = ABox->getHeight();

        SDL_Rect b;
        b.x = BUpperLeft.getX();
        b.y = BUpperLeft.getY();
        b.w = BBox->getWidth();
        b.h = BBox->getHeight();

        if ((a.x + a.w) < (b.x) || a.x > (b.x + b.w))
        {
            return false;
        }

        if ((a.y + a.h) < (b.y) || a.y > (b.y + b.h))
        {
            return false;
        }

        return true;
    }

    ACircle = (components2D::CircleCollider*) A.getComponent<components2D::CircleCollider>();
    BCircle = (components2D::CircleCollider*) B.getComponent<components2D::CircleCollider>();

    // Circles collision
    if (ACircle != NULL && BCircle != NULL)
    {
        Vector2 centerA;
        Vector2 centerB;

        centerA = ACircle->GetOwner().getRealPosition2D(ACircle->getOffsetX(), ACircle->getOffsetY());
        centerB = BCircle->GetOwner().getRealPosition2D(BCircle->getOffsetX(), BCircle->getOffsetY());

        float distanceQuadratic;
        distanceQuadratic = centerA.distanceQuadratic(centerB);

        float dangerDistance;
        dangerDistance = ACircle->getRadius() * ACircle->getRadius() + BCircle->getRadius() * BCircle->getRadius();

        if (distanceQuadratic <= dangerDistance)
        {
            return true;
        }

        return false;
    }

    // Mixed collisions
    // Box vs Circle
    if (ABox != NULL && BCircle != NULL)
    {

    }

    // Circle vs Box
    if (ACircle != NULL && BBox != NULL)
    {

    }

    return false;
}
