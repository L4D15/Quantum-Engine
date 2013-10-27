#ifndef GAME2D_H
#define GAME2D_H

#include "quantum/Game.h"
#include "quantum/ParallaxScrolling.h"

class Game2D : public Game
{
public:
    Game2D(std::string name);
    virtual ~Game2D();

    void                                createWindow(int width, int height, bool fullscreen);
    void                                createWindow(bool fullscreen);

public: // Systems
    static Systems2D::ParallaxScrolling parallaxScrolling;

private:

};

#endif // GAME2D_H
