#include "quantum/systems/2D/AssetRendering.h"

using namespace systems2D;

AssetRendering::AssetRendering()
{
    addComponentType<components2D::Transform2D>();
    addComponentType<components2D::AssetRenderer>();
}

AssetRendering::~AssetRendering()
{

}

void AssetRendering::initialize()
{
    transformMapper.init(* world);
    rendererMapper.init(* world);
}

void AssetRendering::processEntity(artemis::Entity &e)
{
    // Queue the asset for render
    components2D::Transform2D* transform;
    components2D::AssetRenderer* renderer;

    transform = transformMapper.get(e);
    renderer = rendererMapper.get(e);

    renderer->render(renderer->getCamera(), transform->GetOwner().getPosition2D(), transform->getScale(), transform->getRotation());
    renderer->update();
}
