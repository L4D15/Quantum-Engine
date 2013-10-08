#include "TestScene.h"
#include "quantum/Game.h"
#include "quantum/Math.h"
#include "quantum/components/ComponentsList.h"

TestScene::TestScene() :
    Scene("Test Scene")
{
    // This Scene will have a Physics and rendering system
    this->physicsSystem = (Systems2D::Physics*) AddSystem(new Systems2D::Physics());
    this->renderingSystem = (Systems2D::AssetRendering*) AddSystem(new Systems2D::AssetRendering());

    // Resources
    image = new Assets2D::SpriteSheet("Zero", "assets/images/zero.png");
    sprite = new Assets2D::AnimatedSprite(image);

    bgImage = new Assets2D::SpriteSheet("Background", "assets/images/bg.png");

    // Objects
    object = CreateGameObject("Object");
    object->SetPosition(0, 0);
    object->AddComponent(new Components2D::Physics(*object));
    object->AddComponent(new Components2D::AssetRenderer(*object, mainCamera, sprite));

    background = CreateGameObject("Background");
    background->AddComponent(new Components2D::AssetRenderer(*background, mainCamera, bgImage, -1, 1000));

    mainCamera->AddComponent(new Components2D::Physics(*mainCamera));
}

TestScene::~TestScene()
{

}

void TestScene::OnActivate()
{
    keyDown = false;
}

void TestScene::OnDeactivate()
{

}

void TestScene::OnLoop()
{
    Scene::OnLoop();

    // Process systems
    physicsSystem->process();

    // If there is no directional key pressed, smoot the stop of the camera
    Components2D::Physics* p;
    p = (Components2D::Physics*) mainCamera->GetComponent<Components2D::Physics>();
    if (keyDown == false && p->GetVelocity() != Vector2D(0,0))
    {
        // Camera Smoothing
        Vector2D velocity;

        velocity = Math::Interpolate(Math::Interpolation::EasyIn, p->GetVelocity(), Vector2D(0,0), Math::Normalize(timeKeyUp, timeKeyUp + 1000, Game::GetTime()));
        p->SetVelocity(velocity);
    }
}

void TestScene::OnRender()
{
    this->renderingSystem->process();
    Scene::OnRender();
}


void TestScene::OnKeyDown(SDL_Keycode key, Uint16 mod)
{
    Components2D::Physics* p;
    switch (key)
    {
    case SDLK_ESCAPE:
        Game::Terminate();
        break;

    case SDLK_RIGHT:
        p = (Components2D::Physics*) mainCamera->GetComponent<Components2D::Physics>();
        p->AddVelocity(5.0f, 0.0f);
        break;

    case SDLK_LEFT:
        p = (Components2D::Physics*) mainCamera->GetComponent<Components2D::Physics>();
        p->AddVelocity(-5.0f, 0.0f);
        break;

    case SDLK_UP:
        p = (Components2D::Physics*) mainCamera->GetComponent<Components2D::Physics>();
        p->AddVelocity(0.0f, -5.0f);
        break;

    case SDLK_DOWN:
        p = (Components2D::Physics*) mainCamera->GetComponent<Components2D::Physics>();
        p->AddVelocity(0.0f, 5.0f);
        break;
    }
    this->keyDown = true;
}

void TestScene::OnKeyUp(SDL_Keycode key, Uint16 mod)
{
    // If we transition between pressed and unpressed
    if (keyDown == true)
    {
        timeKeyUp = Game::GetTime();
    }

    keyDown = false;
}
