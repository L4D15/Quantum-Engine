#include "quantum/Game.h"
#include "quantum/Libraries.h"

// =====================================
// Static Variables
// =====================================

Window* Game::window = NULL;
systems2D::SceneManager Game::sceneManager;
ResourceManager Game::resourceManager;
float Game::deltaTime = 1.0f;

bool Game::run = false;
std::string Game::name;
Vector3 Game::gravity;
lua_State* Game::luaState = NULL;

// =====================================

/**
 * @brief Game::Game
 * @param name
 */
Game::Game(std::string name)
{
    Game::name = name;

    // Initialize SDL and TTF
    std::cout << "Initializing SDL2...";
    int error;
    error = SDL_Init(SDL_INIT_EVERYTHING);
    if (error == 0)
    {
        std::cout << "Ok" << std::endl;
    }
    else
    {
        std::cout << "Error - " << SDL_GetError() << std::endl;
    }

    std::cout << "Initializing SDL_TTF...";
    error = TTF_Init();
    if (error == 0)
    {
        std::cout << "Ok" << std::endl;
    }
    else
    {
        std::cout << "Error - " << TTF_GetError() << std::endl;
    }

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

    // Set Gravity Force
    gravity = Vector3(0.0f, 9.8f, 0.0f);

    // Initialize Lua
    std::cout << "Initializing lua...";
    luaState = luaL_newstate();
    luaL_openlibs(luaState);

    if (luaState != NULL)
    {
        std::cout << "Ok" << std::endl;
    }
    else
    {
        std::cout << "Error" << std::endl;
    }
}

/**
 * @brief Game::~Game
 */
Game::~Game()
{
    delete window;
    SDL_Quit();
    TTF_Quit();
    lua_close(luaState);
}

/**
 * @brief Game::start
 */
void Game::start()
{
    // Initial information
    std::cout << "Working dir : " << Game::resourceManager.getWorkingPath() << std::endl;
    std::cout << "Assets folder : " << Game::resourceManager.getAssetsDir() << std::endl;
    // ===================
    run = true;
    mainLoop();
}

/**
 * @brief Game::terminate
 */
void Game::terminate()
{
    run = false;
}

/**
 * @brief Game::mainLoop
 */
void Game::mainLoop()
{
    while (run)
    {
        Uint32 startTime = SDL_GetTicks();

        updateTime();

        handleEvents();
        update();
        render();

        manageFramesPerSecond();
        countFramesPerSecond();

        Uint32 endTime = SDL_GetTicks();
    }
}

/**
 * @brief Game::handleEvents
 */
void Game::handleEvents()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        sceneManager.onEvent(&event);
    }
}

/**
 * @brief Game::update
 */
void Game::update()
{
    sceneManager.onLoop();
}

/**
 * @brief Game::render
 */
void Game::render()
{
    this->window->clear();

    sceneManager.onRender();

    this->window->draw();

}

/**
 * @brief Game::updateDeltaTime
 */
void Game::updateTime()
{
    this->oldTime = this->currentTime;
    this->currentTime = SDL_GetTicks();
    deltaTime = (this->currentTime - this->oldTime) / 1000.0f;
}

/**
 * @brief Game::countFramesPerSecond
 */
void Game::countFramesPerSecond()
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
void Game::manageFramesPerSecond()
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
void Game::writeToConsole(std::string text)
{
    std::cout << text << std::endl;
}


void Game::runScript(std::string script)
{
    std::string scriptPath;

    scriptPath = Game::resourceManager.getScript(script);

    luaL_dofile(luaState, scriptPath.c_str());
}

