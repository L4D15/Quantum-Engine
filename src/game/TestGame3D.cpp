#include "TestGame3D.h"
#include "scenes/TestScene3D.h"

TestGame3D::TestGame3D() :
    Game3D("Test Game 3D")
{

}

TestGame3D::~TestGame3D()
{

}

void TestGame3D::Start()
{
    CreateWindow(false);
    InitializeGL();

    this->sceneManager.AddScene(new TestScene3D());
    this->sceneManager.ChangeToScene("Test Scene 3D");
    Game3D::Start();
}
