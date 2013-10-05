#include "TestScene3D.h"
#include "quantum/Game.h"
#ifdef __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif

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

    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_TRIANGLES);
      glVertex3f( 0.0f,  0.8f, 0.0f);
      glVertex3f(-0.8f, -0.8f, 0.0f);
      glVertex3f(0.8f, -0.8f, 0.0f);
    glEnd();

    Uint8 red, green, blue, alpha;

    SDL_GetRenderDrawColor(Game::window->getRenderer(), &red, &green, &blue, &alpha);

    SDL_Rect rect;

    rect.x = -1;
    rect.y = -1;
    rect.w = 2;
    rect.h = 2;

    SDL_SetRenderDrawColor(Game::window->getRenderer(), 255, 0, 0, 255);
    SDL_RenderDrawRect(Game::window->getRenderer(), &rect);
    SDL_SetRenderDrawColor(Game::window->getRenderer(), red, green, blue, alpha);
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
