#ifndef ASSETRENDERING_H
#define ASSETRENDERING_H

#include "quantum/Libraries.h"
#include "quantum/components/ComponentsList.h"

namespace Systems2D
{

class AssetRendering : public artemis::EntityProcessingSystem
{
public:
    AssetRendering();
    virtual ~AssetRendering();

    void                initialize();
    void                processEntity(artemis::Entity &e);

private:
    artemis::ComponentMapper<Components2D::Transform2D> transformMapper;
    artemis::ComponentMapper<Components2D::AssetRenderer> rendererMapper;
};

}

#endif // ASSETRENDERING_H
