#include "TestGame2D.h"
#include "scenes/TestScene.h"

TestGame2D::TestGame2D() :
    Game2D("Test Game 2D")
{

}

TestGame2D::~TestGame2D()
{

}

void TestGame2D::start()
{
    createWindow(false);
    this->sceneManager.addScene(new TestScene());
    this->sceneManager.changeToScene("Test Scene");
    Game2D::start();
}
