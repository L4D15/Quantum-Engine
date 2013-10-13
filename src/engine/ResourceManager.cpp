#include "quantum/ResourceManager.h"
#include <cstdlib>
#include "quantum/Game.h"

ResourceManager::ResourceManager()
{

}

ResourceManager::~ResourceManager()
{

}

std::string ResourceManager::GetWorkingPath()
{
    char currentPath[FILENAME_MAX];
    GetWorkingDir(currentPath, sizeof(currentPath));

    return std::string(currentPath);
}

/**
 * @brief Fix the relative path in a platform independent way.
 * The used separator is '/' even in Windows (this will be handled by the engine
 * for each platform). In the case of Mac OS X, it will append Contents/Resources to access
 * the contents inside the app bundle.
 * @param path  Relative path inside the application.
 * @return Absolute path to the given directory or file.
 */
std::string ResourceManager::GetPath(std::string path)
{
    std::string absolutePath;
#ifdef _WIN32
    absolutePath = path;
    for (int characterIndex = 0; characterIndex < abosolutePath.length(); ++characterIndex)
    {
        if (absolutePath[characterIndex] == '/')
        {
            absolutePath.replace(characterIndex, 1, "\\");
        }
    }
    absolutePath.insert(0, "\");
#endif

#ifdef __APPLE__
    absolutePath = path;
    absolutePath.insert(0, ".app/Contents/Resources/");
    absolutePath.insert(0, Game::GetName());
    absolutePath.insert(0, "/");
#endif

#ifdef _linux
    absolutePath = path;
    absolutePath.insert(0, "/");
#endif

    char currentPath[FILENAME_MAX];
    GetWorkingDir(currentPath, sizeof(currentPath));

    absolutePath.insert(0, currentPath);

    return absolutePath;
}

std::string ResourceManager::GetAssetsDir()
{
    return GetPath("Assets");
}
