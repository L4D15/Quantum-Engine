#ifndef GAME2D_H
#define GAME2D_H

#include "quantum/Game.h"

class Game2D : public Game
{
public:
    Game2D(std::string name);
    virtual ~Game2D();

    void                                CreateWindow(int width, int height, bool fullscreen);
    void                                CreateWindow(bool fullscreen);

private:

};

#endif // GAME2D_H