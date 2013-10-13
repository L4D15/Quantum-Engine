#ifndef QUANTUM_RESOURCEMANAGER_H
#define QUANTUM_RESOURCEMANAGER_H

#include <string>

#ifdef __APPLE__
    #include <unistd.h>
    #define GetWorkingDir getcwd

#elif __linux
    #include <unistd.h>>
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

    std::string             GetWorkingPath();
    std::string             GetPath(std::string path);
    std::string             GetAssetsDir();
    std::string             GetImagesDir();
private:
    std::string             gameName;
};

#endif // QUANTUM_RESOURCEMANAGER_H
