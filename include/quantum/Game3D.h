#ifndef GAME3D_H
#define GAME3D_H

#include "quantum/Game.h"

class Game3D : public Game
{
public:
    Game3D(std::string name);
    virtual ~Game3D();

    void                                createWindow(int width, int height, bool fullscreen);
    void                                createWindow(bool fullscreen);

    virtual void                        initializeGL();
    virtual void                        setViewport(int width, int height);

private:

};

#endif // GAME3D_H
