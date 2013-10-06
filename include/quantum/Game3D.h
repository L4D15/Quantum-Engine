#ifndef GAME3D_H
#define GAME3D_H

#include "quantum/Game.h"

class Game3D : public Game
{
public:
    Game3D(std::string name);
    virtual ~Game3D();

    void                                CreateWindow(int width, int height, bool fullscreen);
    void                                CreateWindow(bool fullscreen);

    virtual void                        InitializeGL();
    virtual void                        SetViewport(int width, int height);

private:

};

#endif // GAME3D_H
