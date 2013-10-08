#include "quantum/Scene.h"
#include "quantum/Game.h"
#include "quantum/components/ComponentsList.h"

Scene::Scene(std::string name):
    name(name)
{
    // Setup Artemis systems
    world = new artemis::World();

    // Create the main camera
    mainCamera = CreateGameObject("Main Camera");
    mainCamera->AddComponent(new Components2D::Camera(*mainCamera));
}

Scene::~Scene()
{
    // Empty the objects mapper
    std::map<std::string, GameObject* >::iterator mappedObject;

    for (mappedObject = this->objectsMapping.begin(); mappedObject != this->objectsMapping.end(); ++mappedObject)
    {
        delete (*mappedObject).second;
    }

    this->objectsMapping.clear();

    DestroyGameObject(mainCamera);
    delete this->world;
}

void Scene::OnActivate()
{

}

void Scene::OnDeactivate()
{

}

void Scene::OnLoop()
{
    world->loopStart();
    world->setDelta(Game::deltaTime);
}

void Scene::OnRender()
{
    RenderScene();
}

void Scene::RenderScene()
{
    // TODO: Support multiple cameras
    Components2D::Camera* cameraComp;

    cameraComp = (Components2D::Camera*) mainCamera->GetComponent<Components2D::Camera>();

    cameraComp->RenderScene();
}

/**
 * @brief Scene::createGameObject
 * @param name
 * @return
 */
GameObject* Scene::CreateGameObject(std::string name)
{
    GameObject* object;

    artemis::Entity& objectEntity = world->createEntity();
    object = new GameObject(name, objectEntity);

    // Add the transform component (every object will have at least that)
    object->AddComponent(new Components2D::Transform2D(*object));

    std::pair<std::string, GameObject* > objectMapped(name, object);
    this->objectsMapping.insert(objectMapped);

    return object;
}

/**
 * @brief Scene::destroyGameObject
 * @param object
 */
void Scene::DestroyGameObject(GameObject*& object)
{
    world->deleteEntity(object->entity);
    delete &object;
    object = NULL;
}

/**
 * @brief Scene::destroyGameObject
 * @param name
 */
void Scene::DestroyGameObject(std::string name)
{
    std::map<std::string, GameObject* >::iterator object;

    object = this->objectsMapping.find(name);

    if (object != this->objectsMapping.end())
    {
        this->objectsMapping.erase(object);
    }
}

/**
 * @brief Scene::AddSystem
 * @param system
 * @return
 */
artemis::EntitySystem* Scene::AddSystem(artemis::EntitySystem *system)
{
    artemis::EntitySystem* sys;
    sys = this->world->getSystemManager()->setSystem(system);
    system->initialize();

    return sys;
}
