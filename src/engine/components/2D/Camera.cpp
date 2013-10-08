#include "quantum/components/2D/Camera.h"
#include "quantum/Game2D.h"

using namespace Components2D;

Camera::Camera(GameObject &owner) :
    Component(owner)
{
    this->index = 0;
}

Camera::~Camera()
{

}

/**
 * @brief Adds to the rendeing queue.
 *
 * Its position in the queue will depend on its zIndex.
 * The position on the screen will be affected by parallax effect relative to this camera.
 * @param package   Render Package to insert in the queue.
 */
void Camera::QueueForRender(RenderPackage package)
{
    // Apply parallax transformation
    package.position = Game2D::parallaxScrolling.ApplyParallaxScrolling(this->owner.GetPosition2D(), package.position, package.distance);

    // Insert into the queue
    if (this->renderingQueue.size() == 0)
    {
        this->renderingQueue.push_back(package);
    }
    else
    {
        std::list<RenderPackage>::iterator it;

        it = this->renderingQueue.begin();
        bool found = false;
        while (found == false && it != this->renderingQueue.end())
        {
            if ((*it).zIndex < package.zIndex)
            {
                ++it;
            }
            else
            {
                found = true;
            }
        }
        this->renderingQueue.insert(it, package);
    }
}

void Camera::RenderScene()
{
    std::list<RenderPackage>::iterator it;
    for (it = this->renderingQueue.begin(); it != this->renderingQueue.end(); ++it) {
        (*it).asset->Render(Game::window->GetRenderer(),
                            (*it).position,
                            (*it).scale,
                            (*it).rotation);
    }

    this->renderingQueue.clear();
}
