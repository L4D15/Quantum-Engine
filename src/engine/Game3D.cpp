#include "quantum/Game3D.h"

#ifdef __APPLE__
#include <OpenGL/gl.h>
#else
#include "GL/gl.h"
#endif
Game3D::Game3D(std::string name) :
    Game(name)
{

}

Game3D::~Game3D()
{

}

/**
 * @brief Game3D::createWindow
 * @param width
 * @param height
 * @param fullscreen
 */
void Game3D::CreateWindow(int width, int height, bool fullscreen)
{
    if (fullscreen == true)
    {
        this->window = new Window(this->name, width, height, Fullscreen3D);
    }
    else
    {
        this->window = new Window(this->name, width, height, Windowed3D);
    }

    SetViewport(width, height);
}

/**
 * @brief Game3D::createWindow
 * @param fullscreen
 */
void Game3D::CreateWindow(bool fullscreen)
{
    if (fullscreen == true)
    {
        this->window = new Window(this->name, Fullscreen3D);
    }
    else
    {
        this->window = new Window(this->name, Windowed3D);
    }

    SetViewport(window->GetWidth(), window->GetHeight());
}

void Game3D::InitializeGL()
{
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);

    Color clearColor = this->window->GetBackgroundColor();

    glClearColor((float)clearColor.GetRed() / (float)255,
                 (float)clearColor.GetGreen() / (float)255,
                 (float)clearColor.GetBlue() / (float)255,
                 (float)clearColor.GetAlpha() / (float)255);
}

void Game3D::SetViewport(int width, int height)
{
    glViewport(0,0,width, height);
}
