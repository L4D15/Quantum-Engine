#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>
#include <string>
#include "quantum/Color.h"

typedef enum {
    Fullscreen2D,
    Windowed2D,
    Fullscreen3D,
    Windowed3D
} WindowMode;

class Window {
public:
    Window(std::string title, WindowMode mode);
    Window(std::string title, Uint16 w, Uint16 h, WindowMode mode, Color bg = presetcolors::LightBlue);
    virtual ~Window();

    void                                SetTitle(std::string title);
    void                                ChangeResolution(Uint16 w, Uint16 h);
    void                                ChangeMode(WindowMode mode);

    inline Uint16                       GetWidth() { return width; }
    inline Uint16                       GetHeight() { return height; }
    inline WindowMode                   GetMode() { return mode; }
    inline Color                        GetBackgroundColor() { return bgColor; }

    inline SDL_Renderer*                GetRenderer() { return renderer; }

    void                                Clear();
    inline void                         Draw() { SDL_RenderPresent(this->renderer); }

private:
    void                                ShowDisplayModeInfo(SDL_DisplayMode &mode);

private:
    std::string                         title;      // Title the window will show
    Uint16                              width;      // Resolution width
    Uint16                              height;     // Resolution height
    WindowMode                          mode;       // View mode of the window

    Color                               bgColor;    // Color the window will use to clean the renderer

    SDL_Window*                         window;     // Window

    SDL_Renderer*                       renderer;   // Renderer that will draw into the window
};

#endif // WINDOW_H
