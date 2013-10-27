#ifndef RENDERIZABLEASSET_H
#define RENDERIZABLEASSET_H

#include <string>
#include "quantum/Window.h"
#include "quantum/Vector2D.h"

namespace assets2D {

class RenderizableAsset {
public:
    RenderizableAsset(std::string name);

    virtual void                        update();
    virtual void                        render(SDL_Renderer* renderer, Vector2D position, Vector2D scale, float rotation) = 0;

    inline std::string                  getName() { return name; }
    inline void                         setName(std::string name) { this->name = name; }

protected:
    std::string                         name;
};

}

#endif // RENDERIZABLEASSET_H
