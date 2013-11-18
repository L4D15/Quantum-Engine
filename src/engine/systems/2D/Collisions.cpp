#include "quantum/systems/2D/Collisions.h"
#include "quantum/Game.h"
#include "quantum/Math.h"

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

        long id;
        long otherId;

        id = e.getUniqueId();
        otherId = other.getUniqueId();

        if (e.getUniqueId() != other.getUniqueId())
        {
            isColliding = collides(e, other);

            if (isColliding == true)
            {
                components2D::Collisions* collisionsComp;
                collisionsComp = (components2D::Collisions*) e.getComponent<components2D::Collisions>();

                if (collisionsComp != NULL)
                {
                    if (collisionsComp->isTrigger() == true)
                    {
                        Game::runScript(collisionsComp->getScriptToTrigger());
                    }

                    // If both systems have a Physics component, they will physically collide
                    components2D::Physics* physicsComp;
                    components2D::Physics* otherPhysicsComp;

                    physicsComp = (components2D::Physics*) e.getComponent<components2D::Physics>();
                    otherPhysicsComp = (components2D::Physics*) e.getComponent<components2D::Physics>();

                    if (physicsComp != NULL && otherPhysicsComp != NULL)
                    {
                        makeCollide(physicsComp, otherPhysicsComp);
                    }
                }
                else
                {
                    std::cout << "ERROR - Collisions detected but no Collisions component attached." << std::endl;
                }
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
    components2D::Transform2D* ATransform;
    components2D::Transform2D* BTransform;

    ABox = (components2D::BoxCollider*) A.getComponent<components2D::BoxCollider>();
    BBox = (components2D::BoxCollider*) B.getComponent<components2D::BoxCollider>();
    ATransform = (components2D::Transform2D*) A.getComponent<components2D::Transform2D>();
    BTransform = (components2D::Transform2D*) B.getComponent<components2D::Transform2D>();

    // Boxes collision
    if (ABox != NULL && BBox != NULL)
    {
        Vector2 AOffset(ABox->getOffsetX(), ABox->getOffsetY());
        Vector2 BOffset(BBox->getOffsetX(), BBox->getOffsetY());

        Vector2 AUpperLeft = ABox->GetOwner().getRealPosition2D(AOffset);
        Vector2 BUpperLeft = BBox->GetOwner().getRealPosition2D(BOffset);

        AUpperLeft = AUpperLeft - Vector2((ABox->getWidth() * ATransform->getScale().getX()) / 2.0f,
                                          (ABox->getHeight() * ATransform->getScale().getY()) / 2.0f);

        BUpperLeft = BUpperLeft - Vector2((BBox->getWidth() * BTransform->getScale().getX()) / 2.0f,
                                          (BBox->getHeight() * BTransform->getScale().getY()) / 2.0f);

        SDL_Rect a;
        a.x = AUpperLeft.getX();
        a.y = AUpperLeft.getY();
        a.w = ABox->getWidth() * ATransform->getScale().getX();
        a.h = ABox->getHeight() * ATransform->getScale().getY();

        SDL_Rect b;
        b.x = BUpperLeft.getX();
        b.y = BUpperLeft.getY();
        b.w = BBox->getWidth() * BTransform->getScale().getX();
        b.h = BBox->getHeight() * BTransform->getScale().getY();

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
        float ARadius;
        float BRadius;

        ARadius = ACircle->getRadius() * math::max(ATransform->getScale().getX(), ATransform->getScale().getY());
        BRadius = BCircle->getRadius() * math::max(BTransform->getScale().getX(), BTransform->getScale().getY());

        dangerDistance = ARadius * ARadius + BRadius * BRadius;

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

void Collisions::makeCollide(components2D::Physics *APhysics, components2D::Physics *BPhysics)
{

}
