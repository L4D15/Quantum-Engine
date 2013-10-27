#include "quantum/components/2D/AssetRenderer.h"
#include "quantum/components/2D/Camera.h"
#include "quantum/Game.h"
#include <sstream>

using namespace Components2D;

/**
 * @brief AssetRenderer::AssetRenderer
 */
AssetRenderer::AssetRenderer(GameObject &owner, GameObject *camera) :
    Component(owner)
{
    this->zIndex = 0;
    this->distance = 0;
    this->asset = NULL;
    this->visible = true;
    this->camera = camera;
}

/**
 * @brief AssetRenderer::AssetRenderer
 * @param asset
 * @param zIndex
 * @param distance
 */
AssetRenderer::AssetRenderer(GameObject& owner, GameObject* camera, assets2D::RenderizableAsset *asset, int zIndex, int distance) :
    Component(owner)
{
    this->camera = camera;
    this->zIndex = zIndex;
    this->distance = distance;
    this->asset = asset;
    this->visible = true;
}

AssetRenderer::~AssetRenderer() {

}

/**
 * @brief Draws the asset into the camera at the given position.
 * @param camera        GameObject with a components::Camera attached.
 * @param position      Screen position where the asset will be rendered (center point, not the upper left corner).
 * @param angle         Rotation angle from the center point
 */
void AssetRenderer::Render(GameObject* camera, Vector2D position, Vector2D scale, float rotation) {
    Components2D::Camera* cameraComponent;

    cameraComponent = (Components2D::Camera*)camera->getComponent<Components2D::Camera>();

    if (cameraComponent != NULL && this->asset != NULL && this->visible == true) {
        RenderPackage package;

        package.asset = this->asset;
        package.position = position;
        package.scale = scale;
        package.rotation = rotation;
        package.distance = this->distance;
        package.zIndex = this->zIndex;

        // Add to the camera rendering queue
        cameraComponent->QueueForRender(package);
    } else {
        std::stringstream text;

        text << "Error - Trying to render to " << camera->getName() << " object with no camera component attached.";
        Game::writeToConsole(text.str());
    }
}
