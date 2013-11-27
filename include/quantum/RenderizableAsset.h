#ifndef RENDERIZABLEASSET_H
#define RENDERIZABLEASSET_H

#include <string>
#include "quantum/Window.h"
#include "quantum/Vector2.h"

namespace assets2D {

class RenderizableAsset {
public:
    RenderizableAsset(std::string name);

    virtual void                        update();
    virtual void                        render(SDL_Renderer* renderer, Vector2 position, Vector2 scale, float rotation) = 0;

    virtual int                         getWidth() = 0;
    virtual int                         getHeight() = 0;

    virtual SDL_Surface*                getAssetSurface(std::string animation = "None", unsigned int frame = 0) = 0;

    inline std::string                  getName() { return name; }
    inline void                         setName(std::string name) { this->name = name; }

protected:
    std::string                         name;
};

}

#endif // RENDERIZABLEASSET_H
