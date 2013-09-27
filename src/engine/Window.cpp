#include "quantum/Window.h"
#include "quantum/Game.h"
#include <sstream>
#include <GL/gl.h>

/**
 * @brief Initializes the Window and creates the appropiate renderer.
 *
 * This will create a window with half the size of the display current resolution in windowed mode.
 * Also the default background color is light blue.
 */
Window::Window(std::string title, WindowMode mode) {
    this->title = title;

    // Search the desktop resolution
    SDL_DisplayMode dMode;

    SDL_GetCurrentDisplayMode(0, &dMode);

    showDisplayModeInfo(dMode);

    this->width = dMode.w / 2;
    this->height = dMode.h / 2;

    this->mode = mode;

    this->bgColor = presetcolors::LightBlue;

    int windowFlags;
    if (mode == Windowed2D) {
        windowFlags = SDL_WINDOW_SHOWN;
    } else if (mode == Fullscreen2D) {
        windowFlags = SDL_WINDOW_FULLSCREEN;
    } else if (mode == Windowed3D) {
        windowFlags = SDL_WINDOW_OPENGL;
    } else if (mode == Fullscreen3D) {
        windowFlags = SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL;
    }

    this->window = SDL_CreateWindow(this->title.c_str(),
                                    SDL_WINDOWPOS_CENTERED,
                                    SDL_WINDOWPOS_CENTERED,
                                    this->width,
                                    this->height,
                                    windowFlags);

    this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);

    // Set up the blend mode
    SDL_SetRenderDrawBlendMode(this->renderer, SDL_BLENDMODE_BLEND);

    // Set up the background color
    SDL_SetRenderDrawColor(this->renderer,
                           this->bgColor.red(),
                           this->bgColor.green(),
                           this->bgColor.blue(),
                           this->bgColor.alpha());
}

/**
 * @brief Creates a window capable of 2D or 3D rendering.
 * @param title     Title to show in the window.
 * @param w         Resolution width.
 * @param h         Resolution height.
 * @param mode      Use Windowed to create a windowed Window or Fullscreen to cover the whole display.
 * @param bg        Specifies the background color of the window. By default it is light blue.
 */
Window::Window(std::string title, Uint16 w, Uint16 h, WindowMode mode, Color bg) {
    this->title = title;
    this->width = w;
    this->height = h;
    this->mode = mode;
    this->bgColor = bg;

    int windowFlags;
    if (mode == Windowed2D) {
        windowFlags = SDL_WINDOW_SHOWN;
    } else if (mode == Fullscreen2D) {
        windowFlags = SDL_WINDOW_FULLSCREEN;
    } else if (mode == Windowed3D) {
        windowFlags = SDL_WINDOW_OPENGL;
    } else if (mode == Fullscreen3D) {
        windowFlags = SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL;
    }

    this->window = SDL_CreateWindow(title.c_str(),
                                    SDL_WINDOWPOS_CENTERED,
                                    SDL_WINDOWPOS_CENTERED,
                                    this->width,
                                    this->height,
                                    windowFlags);

    this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);

    // Set up the blend mode
    SDL_SetRenderDrawBlendMode(this->renderer, SDL_BLENDMODE_BLEND);

    // Set up the background color
    SDL_SetRenderDrawColor(this->renderer,
                           this->bgColor.red(),
                           this->bgColor.green(),
                           this->bgColor.blue(),
                           this->bgColor.alpha());
}

/**
 * @brief Window::~Window
 */
Window::~Window() {
    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->window);
}

/**
 * @brief Window::showDisplayModeInfo
 * @param mode
 */
void Window::showDisplayModeInfo(SDL_DisplayMode& mode) {
    std::stringstream text;

    text << "Display mode: [ Resolution: { " << mode.w << "x" << mode.h <<  " } @ " << mode.refresh_rate << " Hz ];";

    Game::writeToConsole(text.str());
}

/**
 * @brief Clear the color buffer of the window.
 *
 * In windows for 3D rendering it calls glClear(GL_COLOR_BUFFER_BIT). For windows
 * for 2D rendering SDL_RenderClear(...) is called.
 */
void Window::clear()
{
    if (this->mode == Fullscreen2D || this->mode == Windowed2D)
    {
        SDL_RenderClear(this->renderer);
    }
    else
    {
        glClear(GL_COLOR_BUFFER_BIT);
    }
}
