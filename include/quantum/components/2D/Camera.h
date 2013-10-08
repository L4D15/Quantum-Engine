#ifndef CAMERA_H
#define CAMERA_H

#include "quantum/Libraries.h"
#include "quantum/components/Component.h"
#include "quantum/RenderizableAsset.h"
#include <list>

namespace Components2D
{

// ==================================================== //
typedef struct {
    Assets2D::RenderizableAsset*        asset;
    Vector2D                            position;
    Vector2D                            scale;
    float                               rotation;
    int                                 zIndex;
    int                                 distance;
}RenderPackage;
// ==================================================== //

class Camera : public Components::Component
{
public:
    Camera(GameObject& owner);
    virtual ~Camera();

    void                SetIndex(int index);
    inline int          GetIndex() { return index; }

    void                QueueForRender(RenderPackage package);
    void                RenderScene();

private:
    int                 index;

    std::list
    <RenderPackage>     renderingQueue; // Contains the components to be renderized in rendering order
};

}

#endif // CAMERA_H
