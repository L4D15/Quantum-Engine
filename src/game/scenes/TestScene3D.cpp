#include "TestScene3D.h"
#include "quantum/Game.h"
#include <GL/gl.h>

TestScene3D::TestScene3D() :
    Scene("Test Scene 3D")
{

}

TestScene3D::~TestScene3D()
{

}

void TestScene3D::onActivate()
{

}

void TestScene3D::onDeactivate()
{

}

void TestScene3D::onLoop()
{

}

void TestScene3D::onRender()
{
    glClear(GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();

    glBegin(GL_TRIANGLES);
      glVertex3f( 0.0f,  0.8f, 0.0f);
      glVertex3f(-0.8f, -0.8f, 0.0f);
      glVertex3f(0.8f, -0.8f, 0.0f);
    glEnd();
}

void TestScene3D::onKeyDown(SDL_Keycode key, Uint16 mod)
{
    switch(key)
    {
    case SDLK_ESCAPE:
        Game::terminate();
        break;
    }
}
