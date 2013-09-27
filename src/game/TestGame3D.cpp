#include "TestGame3D.h"
#include "scenes/TestScene3D.h"

TestGame3D::TestGame3D() :
    Game3D("Test Game 3D")
{

}

TestGame3D::~TestGame3D()
{

}

void TestGame3D::start()
{
    createWindow(false);
    initializeGL();

    this->sceneManager.addScene(new TestScene3D());
    this->sceneManager.changeToScene("Test Scene 3D");
    Game3D::start();
}
