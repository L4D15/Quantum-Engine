#ifndef RENDERER_H
#define RENDERER_H

#include "quantum/RenderizableAsset.h"
#include "quantum/GameObject.h"
#include "quantum/components/Component.h"
#include "quantum/GameObject.h"

namespace Components2D {

/**
 * @brief Component used to render any asset capable of being rendered into the scene
 */
class AssetRenderer : public Components::Component {
public:
    AssetRenderer(GameObject& owner, GameObject* camera);
    AssetRenderer(GameObject& owner, GameObject* camera, assets2D::RenderizableAsset* asset, int zIndex = 0, int distance = 0);
    virtual ~AssetRenderer();

    void                                Render(GameObject* camera, Vector2D position, Vector2D scale, float rotation);

    inline void                         SetVisible(bool visible) { this->visible = visible; }
    inline bool                         IsVisible() { return this->visible; }

    inline GameObject*                  GetCamera() { return camera; }
    inline void                         SetCamera(GameObject* camera) { this->camera = camera; }

    inline void                         Update() { asset->update(); }
private:
    int                                 zIndex;
    int                                 distance;
    assets2D::RenderizableAsset*        asset;
    bool                                visible;
    GameObject*                         camera;     // Camera where the rendering will be done

};

}

#endif // RENDERER_H
