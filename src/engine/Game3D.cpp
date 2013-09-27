#include "quantum/Game3D.h"
#include "GL/gl.h"

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
void Game3D::createWindow(int width, int height, bool fullscreen)
{
    if (fullscreen == true)
    {
        this->window = new Window(this->name, width, height, Fullscreen3D);
    }
    else
    {
        this->window = new Window(this->name, width, height, Windowed3D);
    }

    setViewport(width, height);
}

/**
 * @brief Game3D::createWindow
 * @param fullscreen
 */
void Game3D::createWindow(bool fullscreen)
{
    if (fullscreen == true)
    {
        this->window = new Window(this->name, Fullscreen3D);
    }
    else
    {
        this->window = new Window(this->name, Windowed3D);
    }

    setViewport(window->getWidth(), window->getHeight());
}

void Game3D::initializeGL()
{
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);

    Color clearColor = this->window->getBackgroundColor();

    glClearColor((float)clearColor.red() / (float)255,
                 (float)clearColor.green() / (float)255,
                 (float)clearColor.blue() / (float)255,
                 (float)clearColor.alpha() / (float)255);
}

void Game3D::setViewport(int width, int height)
{
    glViewport(0,0,width, height);
}
