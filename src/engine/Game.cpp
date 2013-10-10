#include "quantum/Game.h"
//#include <SDL2/SDL_ttf.h>

// =====================================
// Static Variables
// =====================================

Window* Game::window = NULL;
Systems2D::SceneManager Game::sceneManager;
float Game::deltaTime = 1.0f;

bool Game::run = false;

// =====================================

/**
 * @brief Game::Game
 * @param name
 */
Game::Game(std::string name)
{
    this->name = name;

    // Initialize SDL and TTF
    SDL_Init(SDL_INIT_EVERYTHING);
    //TTF_Init();

    this->currentTime = SDL_GetTicks();
    this->oldTime = 0;

    this->fpsCurrentTime = SDL_GetTicks();
    this->fpsOldTime = 0;
    this->fps = 0;
    this->fpsCounter = 0;

    this->frameSkip = 0;
    this->frameSkipCurrentTime = SDL_GetTicks();
    this->frameSkipOldTime = 0;
    this->timePerFrame = (Uint32) ((1000.0 / (double)QUANTUM_MAX_FPS));
}

/**
 * @brief Game::~Game
 */
Game::~Game()
{
    delete window;
    SDL_Quit();
    //TTF_Quit();
}

/**
 * @brief Game::start
 */
void Game::Start()
{
    run = true;
    MainLoop();
}

/**
 * @brief Game::terminate
 */
void Game::Terminate()
{
    run = false;
}

/**
 * @brief Game::mainLoop
 */
void Game::MainLoop()
{
    while (run)
    {
        Uint32 startTime = SDL_GetTicks();

        UpdateTime();

        HandleEvents();
        Update();
        Render();

        ManageFramesPerSecond();
        CountFramesPerSecond();

        Uint32 endTime = SDL_GetTicks();
    }
}

/**
 * @brief Game::handleEvents
 */
void Game::HandleEvents()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        sceneManager.OnEvent(&event);
    }
}

/**
 * @brief Game::update
 */
void Game::Update()
{
    sceneManager.OnLoop();
}

/**
 * @brief Game::render
 */
void Game::Render()
{
    this->window->Clear();

    sceneManager.OnRender();

    this->window->Draw();

}

/**
 * @brief Game::updateDeltaTime
 */
void Game::UpdateTime()
{
    this->oldTime = this->currentTime;
    this->currentTime = SDL_GetTicks();
    deltaTime = (this->currentTime - this->oldTime) / 1000.0f;
}

/**
 * @brief Game::countFramesPerSecond
 */
void Game::CountFramesPerSecond()
{
    this->fpsCurrentTime = SDL_GetTicks();
    Uint32 timeElapsed = this->fpsCurrentTime - this->fpsOldTime;

    if (timeElapsed >= 1000)
    {
        // Reset FPS counting
        this->fpsOldTime = this->fpsCurrentTime;
        this->fps = this->fpsCounter;
        this->fpsCounter = 0;
        std::cout << "Running @" << this->fps << " fps. Delta Time = " << this->deltaTime << std::endl;
    }
    else
    {
        this->fpsCounter++;
    }
}

/**
 * @brief Game::manageFramesPerSecond
 */
void Game::ManageFramesPerSecond()
{
    this->frameSkipOldTime = this->frameSkipCurrentTime;
    this->frameSkipCurrentTime = SDL_GetTicks();    // Total time since the start of the game

    int timeElapsed = (int)this->frameSkipCurrentTime - (int)this->frameSkipOldTime; // Time elapsed since the last frame

    // We are running too fast so we need to make the game wait a bit
    int timeToWait = (int)this->timePerFrame - (int)timeElapsed;
    if (timeToWait > 0)
    {
        SDL_Delay(timeToWait);
    }
    this->frameSkipCurrentTime = SDL_GetTicks();
}

/**
 * @brief Game::writeToConsole
 * @param text
 */
void Game::WriteToConsole(std::string text)
{
    std::cout << text << std::endl;
}

