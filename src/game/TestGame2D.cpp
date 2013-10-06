#include "TestGame2D.h"
#include "scenes/TestScene.h"

TestGame2D::TestGame2D() :
    Game2D("Test Game 2D")
{

}

TestGame2D::~TestGame2D()
{

}

void TestGame2D::Start()
{
    CreateWindow(false);
    this->sceneManager.AddScene(new TestScene());
    this->sceneManager.ChangeToScene("Test Scene");
    Game2D::Start();
}
