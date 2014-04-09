#include "quantum/ResourceManager.h"
#include <cstdlib>
#include "quantum/Game.h"
#include "sstream"
#include <boost/filesystem.hpp>
#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/path.hpp>

#ifdef __APPLE__
  #include <mach-o/dyld.h>
#endif

// Nickname the namespace
namespace fs = boost::filesystem;

ResourceManager::ResourceManager()
{

}

ResourceManager::~ResourceManager()
{
    std::map<std::string, assets2D::AnimatedSprite*>::iterator currentAS;

    for (currentAS = this->animatedSprites.begin(); currentAS != this->animatedSprites.end(); ++currentAS)
    {
        std::cout << "Deallocating resource [" << currentAS->first << " @ AnimatedSprite]" << std::endl;
        delete currentAS->second;
    }
    this->animatedSprites.clear();
    std::cout << "Deallocated all AnimatedSprites." << std::endl;

    std::map<std::string, assets2D::Sprite*>::iterator currentSprite;

    for (currentSprite = this->sprites.begin(); currentSprite != this->sprites.end(); ++currentSprite)
    {
        std::cout << "Unallocating resource [" << currentSprite->first << " @ Sprite]" << std::endl;
        delete currentSprite->second;
    }
    this->sprites.clear();
    std::cout << "Deallocated all Sprites." << std::endl;
}

std::string ResourceManager::getWorkingPath()
{
  return fs::current_path().string();
}

/**
 * @brief Transforms the given path to a platform specific path (swaping '/' to '\' in Windows).
 * @param path
 * @return
 */
std::string ResourceManager::fixPath(std::string path)
{
    std::string fixedPath(path);

#ifdef _WIN32
    for (int characterIndex = 0; characterIndex < fixedPath.length(); ++characterIndex)
    {
        if (fixedPath[characterIndex] == '/')
        {
            fixedPath.replace(characterIndex, 1, "\\");
        }
    }
#endif

    return fixedPath;
}

/**
 * @brief Get the absolute path of any resource inside the game.
 * The used separator is '/' even in Windows (this will be handled by the engine
 * for each platform). In the case of Mac OS X, it will append Contents/Resources to access
 * the contents inside the app bundle.
 * @param path  Relative path inside the application.
 * @return Absolute path to the given directory or file.
 */
std::string ResourceManager::getPath(std::string pathToFile)
{
    std::string absolutePath;

    fs::path currentPath;

    currentPath = fs::current_path();

    absolutePath.append(currentPath.string());
    absolutePath.append("/");

#ifdef __APPLE__
    char path[FILENAME_MAX];
    uint32_t size = sizeof(path);
    _NSGetExecutablePath(path, &size);

    absolutePath = path;

    // Take just the part we need
    absolutePath = absolutePath.substr(0, absolutePath.find("/MacOS/") + 1);
    absolutePath.append("/Resources/");

#elif __linux

#elif _WIN32

#elif _WIN64

#else
    STUBBED("ResourceManage::getPath - Missing code for this platform.");
#endif

    absolutePath.append(pathToFile);

    std::cout << absolutePath << std::endl;

    return absolutePath;
}

/**
 * @brief ResourceManager::getAssetsDir
 * @return
 */
std::string ResourceManager::getAssetsDir()
{
    return getPath("assets/");
}

/**
 * @brief ResourceManager::getImagesDir
 * @return
 */
std::string ResourceManager::getImagesDir()
{
    return getPath("assets/images/");
}

/**
 * @brief Access to an Animated Sprite.
 *
 * If the Animated Sprite is not already loaded it will be loaded from the resources folder.
 * All images must be placed in Assets/Images to be accessible by this function. Relative paths
 * can be used too, so an image in Assets/Images/ABC/image.png can be reference by this function
 * using name = ABC/image.png
 * @param name
 * @return
 */
assets2D::AnimatedSprite* ResourceManager::getAnimatedSprite(std::string name)
{
    // Search the animated sprite in the already loaded assets
    std::map<std::string, assets2D::AnimatedSprite*>::iterator found;

    found = this->animatedSprites.find(name);
    if (found != this->animatedSprites.end())
    {
        return found->second;
    }
    else
    {
        // Create new Animated Sprite and insert it into the mapper
        std::string pathToImage;

        pathToImage.append(getImagesDir());
        pathToImage.append(fixPath(name));

        assets2D::Sprite* sprite;

        sprite = new assets2D::Sprite(name, pathToImage);

        std::pair<std::string, assets2D::Sprite*> mappedSprite(name, sprite);
        this->sprites.insert(mappedSprite);

        assets2D::AnimatedSprite* animatedSprite;

        animatedSprite = new assets2D::AnimatedSprite(sprite);

        std::pair<std::string, assets2D::AnimatedSprite*> mappedAnimatedSprite(name, animatedSprite);
        this->animatedSprites.insert(mappedAnimatedSprite);

        return animatedSprite;
    }
}

/**
 * @brief ResourceManager::GetSprite
 * @param name
 * @return
 */
assets2D::Sprite* ResourceManager::getSprite(std::string name)
{
    // Search the sprite in the already loaded assets
    std::map<std::string, assets2D::Sprite*>::iterator found;

    found = this->sprites.find(name);
    if (found != this->sprites.end())
    {
        return found->second;
    }
    else
    {
        // Create new Sprite and insert it into the mapper
        std::string pathToImage;

        pathToImage.append(getImagesDir());
        pathToImage.append(fixPath(name));

        assets2D::Sprite* sprite;

        sprite = new assets2D::Sprite(name, pathToImage);

        std::pair<std::string, assets2D::Sprite*> mappedSprite(name, sprite);
        this->sprites.insert(mappedSprite);

        return sprite;
    }
}

/**
 * @brief Path to the script inside the assets folder.
 * @param name
 * @return
 */
std::string ResourceManager::getScript(std::string name)
{
    std::stringstream stream;

    stream << getPath("assets/scripts/") << name;

    return stream.str();
}
