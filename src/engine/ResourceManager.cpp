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
 * @brief Transforms the given path to a platform specific path (swaping '/' to '\' in Windows).
 * @param path
 * @return
 */
std::string ResourceManager::FixPath(std::string path)
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
    return GetPath("Assets/");
}

std::string ResourceManager::GetImagesDir()
{
    return GetPath("Assets/Images/");
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
Assets2D::AnimatedSprite* ResourceManager::GetAnimatedSprite(std::string name)
{
    // Search the animated sprite in the already loaded assets
    std::map<std::string, Assets2D::AnimatedSprite*>::iterator found;

    found = this->animatedSprites.find(name);
    if (found != this->animatedSprites.end())
    {
        return found->second;
    }
    else
    {
        // Create new Animated Sprite and insert it into the mapper
        std::string pathToImage;

        pathToImage.append(GetImagesDir());
        pathToImage.append(FixPath(name));

        Assets2D::Sprite* sprite;

        sprite = new Assets2D::Sprite(name, pathToImage);

        std::pair<std::string, Assets2D::Sprite*> mappedSprite(name, sprite);
        this->sprites.insert(mappedSprite);

        Assets2D::AnimatedSprite* animatedSprite;

        animatedSprite = new Assets2D::AnimatedSprite(sprite);

        std::pair<std::string, Assets2D::AnimatedSprite*> mappedAnimatedSprite(name, animatedSprite);
        this->animatedSprites.insert(mappedAnimatedSprite);

        return animatedSprite;
    }
}

/**
 * @brief ResourceManager::GetSprite
 * @param name
 * @return
 */
Assets2D::Sprite* ResourceManager::GetSprite(std::string name)
{
    // Search the sprite in the already loaded assets
    std::map<std::string, Assets2D::Sprite*>::iterator found;

    found = this->sprites.find(name);
    if (found != this->sprites.end())
    {
        return found->second;
    }
    else
    {
        // Create new Sprite and insert it into the mapper
        std::string pathToImage;

        pathToImage.append(GetImagesDir());
        pathToImage.append(FixPath(name));

        Assets2D::Sprite* sprite;

        sprite = new Assets2D::Sprite(name, pathToImage);

        std::pair<std::string, Assets2D::Sprite*> mappedSprite(name, sprite);
        this->sprites.insert(mappedSprite);

        return sprite;
    }
}
