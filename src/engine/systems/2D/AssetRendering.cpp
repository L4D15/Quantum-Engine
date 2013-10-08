#include "quantum/systems/2D/AssetRendering.h"

using namespace Systems2D;

AssetRendering::AssetRendering()
{
    addComponentType<Components2D::Transform2D>();
    addComponentType<Components2D::AssetRenderer>();
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
    Components2D::Transform2D* transform;
    Components2D::AssetRenderer* renderer;

    transform = transformMapper.get(e);
    renderer = rendererMapper.get(e);

    renderer->Render(renderer->GetCamera(), transform->GetOwner().GetPosition2D(), transform->GetScale(), transform->GetRotation());
    renderer->Update();
}
