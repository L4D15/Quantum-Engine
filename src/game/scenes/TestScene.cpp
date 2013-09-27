#include "TestScene.h"
#include "quantum/Game.h"

TestScene::TestScene() :
    Scene("Test Scene")
{

}

TestScene::~TestScene()
{

}

void TestScene::onActivate()
{

}

void TestScene::onDeactivate()
{

}

void TestScene::onLoop()
{

}

void TestScene::onRender()
{

}


void TestScene::onKeyDown(SDL_Keycode key, Uint16 mod)
{
    switch (key)
    {
    case SDLK_ESCAPE:
        Game::terminate();
        break;
    }
}
