#ifndef CAMERA_H
#define CAMERA_H

#include "quantum/Libraries.h"
#include "quantum/components/Component.h"
#include "quantum/RenderizableAsset.h"
#include <list>

namespace components2D
{

// ==================================================== //
typedef struct {
    assets2D::RenderizableAsset*        asset;
    Vector2                            position;
    Vector2                            scale;
    float                               rotation;
    int                                 zIndex;
    int                                 distance;
}RenderPackage;
// ==================================================== //

class Camera : public components::Component
{
public:
    Camera(GameObject& owner);
    virtual ~Camera();

    void                setIndex(int index);
    inline int          getIndex() { return index; }

    void                queueForRender(RenderPackage package);
    void                renderScene();

private:
    int                 index;

    std::list
    <RenderPackage>     renderingQueue; // Contains the components to be renderized in rendering order
};

}

#endif // CAMERA_H
