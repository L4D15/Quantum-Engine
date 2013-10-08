#ifndef RENDERIZABLEASSET_H
#define RENDERIZABLEASSET_H

#include <string>
#include "quantum/Window.h"
#include "quantum/Vector2D.h"

namespace Assets2D {

class RenderizableAsset {
public:
    RenderizableAsset(std::string name);

    virtual void                        Update();
    virtual void                        Render(SDL_Renderer* renderer, Vector2D position, Vector2D scale, float rotation) = 0;

    inline std::string                  GetName() { return name; }
    inline void                         SetName(std::string name) { this->name = name; }

protected:
    std::string                         name;
};

}

#endif // RENDERIZABLEASSET_H
