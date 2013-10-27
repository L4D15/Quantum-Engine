#ifndef ASSETRENDERING_H
#define ASSETRENDERING_H

#include "quantum/Libraries.h"
#include "quantum/components/ComponentsList.h"

namespace systems2D
{

class AssetRendering : public artemis::EntityProcessingSystem
{
public:
    AssetRendering();
    virtual ~AssetRendering();

    void                initialize();
    void                processEntity(artemis::Entity &e);

private:
    artemis::ComponentMapper<components2D::Transform2D> transformMapper;
    artemis::ComponentMapper<components2D::AssetRenderer> rendererMapper;
};

}

#endif // ASSETRENDERING_H
