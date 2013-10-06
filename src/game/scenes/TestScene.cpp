#include "TestScene.h"
#include "quantum/Game.h"

TestScene::TestScene() :
    Scene("Test Scene")
{

}

TestScene::~TestScene()
{

}

void TestScene::OnActivate()
{

}

void TestScene::OnDeactivate()
{

}

void TestScene::OnLoop()
{

}

void TestScene::OnRender()
{

}


void TestScene::OnKeyDown(SDL_Keycode key, Uint16 mod)
{
    switch (key)
    {
    case SDLK_ESCAPE:
        Game::Terminate();
        break;
    }
}
