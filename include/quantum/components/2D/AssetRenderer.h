#ifndef RENDERER_H
#define RENDERER_H

#include "quantum/RenderizableAsset.h"
#include "quantum/GameObject.h"
#include "quantum/components/Component.h"
#include "quantum/GameObject.h"

namespace components2D {

/**
 * @brief Component used to render any asset capable of being rendered into the scene
 */
class AssetRenderer : public components::Component {
public:
    AssetRenderer(GameObject& owner, GameObject* camera);
    AssetRenderer(GameObject& owner, GameObject* camera, assets2D::RenderizableAsset* asset, int zIndex = 0, int distance = 0);
    virtual ~AssetRenderer();

    void                                render(GameObject* camera, Vector2 position, Vector2 scale, float rotation);

    inline void                         setVisible(bool visible) { this->visible = visible; }
    inline bool                         isVisible() { return this->visible; }

    inline GameObject*                  getCamera() { return camera; }
    inline void                         setCamera(GameObject* camera) { this->camera = camera; }
    inline assets2D::RenderizableAsset* getRenderizableAsset() { return this->asset; }

    inline int                          getDistance() { return distance; }

    inline void                         update() { asset->update(); }
private:
    int                                 zIndex;
    int                                 distance;
    assets2D::RenderizableAsset*        asset;
    bool                                visible;
    GameObject*                         camera;     // Camera where the rendering will be done

};

}

#endif // RENDERER_H
