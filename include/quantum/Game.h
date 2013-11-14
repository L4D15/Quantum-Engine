#ifndef GAME_H
#define GAME_H

#include <string>
#include <SDL2/SDL.h>
#include "quantum/Window.h"
#include "quantum/SceneManager.h"
#include "quantum/ResourceManager.h"

#define QUANTUM_MAX_FPS 60

class Game
{
    // Methods
public:
    Game(std::string name);
    virtual ~Game();

    virtual void                        createWindow(int width, int height, bool fullscreen) = 0;
    virtual void                        createWindow(bool fullscreen) = 0;

    virtual void                        start();

protected:

private:
    void                                mainLoop();
    void                                update();
    void                                render();
    void                                handleEvents();

    void                                updateTime();
    void                                countFramesPerSecond();
    void                                manageFramesPerSecond();

    // Static Methods
public:
    static void                         writeToConsole(std::string text);
    static void                         terminate();
    static inline Uint32                getTime() { return SDL_GetTicks(); }
    static std::string                  getName() { return name; }
protected:

    // Attributes
public:

protected:
    static std::string                  name;

private:
    // Delta time
    Uint32                              currentTime;    // Measures the number of ticks since the start of SDL
    Uint32                              oldTime;        // Number of ticks on last update

    // Frames Per Second
    Uint32                              fpsCurrentTime;
    Uint32                              fpsOldTime;
    unsigned int                        fps;            // Number of frames rendered every second
    unsigned int                        fpsCounter;     // Current number of frames (inside this second)

    // Frame Skip
    Uint32                              frameSkipCurrentTime;
    Uint32                              frameSkipOldTime;
    unsigned int                        frameSkip;      // Frames to skip when the game is running slowly
    Uint32                              timePerFrame;

    // Static Attributes
public:
    static Window*                      window;

    static float                        deltaTime;      // Delta Time

    static Vector3D                     gravity;

    static systems2D::SceneManager      sceneManager;
    static ResourceManager              resourceManager;

protected:
    static bool                         run;
};

#endif // GAME_H
