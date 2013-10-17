#ifndef QUANTUM_RESOURCEMANAGER_H
#define QUANTUM_RESOURCEMANAGER_H

#include <string>
#include "quantum/AnimatedSprite.h"
#include "quantum/Sprite.h"
#include <map>

#ifdef __APPLE__
    #include <unistd.h>
    #define GetWorkingDir getcwd

#elif __linux
    #include <unistd.h>
    #define GetWorkingDir getcwd

#elif _WIN32
    #include <dirent.h>
    #define GetWorkingDir _getcwd

#elif _WIN64
    #include <unistd.h>
    #define GetWorkingDir __getcwd
#endif

class ResourceManager
{
public:
    ResourceManager();
    virtual ~ResourceManager();

    // Resource management
    Assets2D::AnimatedSprite*       GetAnimatedSprite(std::string name);
    Assets2D::Sprite*               GetSprite(std::string name);

    // Path management
    std::string                     GetWorkingPath();
    std::string                     GetPath(std::string path);
    std::string                     GetAssetsDir();
    std::string                     GetImagesDir();
    std::string                     FixPath(std::string path);

private:
    void                            SetUsed(std::string assetName);
    void                            SetUnused(std::string assetName);

private:
    std::string                     gameName;

    // Resources
    std::map<
        std::string,
        Assets2D::AnimatedSprite*>  animatedSprites;
    std::map<
        std::string,
        Assets2D::Sprite*>          sprites;
};

#endif // QUANTUM_RESOURCEMANAGER_H
