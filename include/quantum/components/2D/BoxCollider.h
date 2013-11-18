#ifndef QUANTUM_2D_BOXCOLLIDER_H
#define QUANTUM_2D_BOXCOLLIDER_H

#include "quantum/components/2D/Collisions.h"
#include "quantum/components/2D/Camera.h"
#include "quantum/Color.h"

namespace components2D
{

class BoxCollider : public components::Component
{
public:
    BoxCollider(GameObject& owner);

    inline void             setOffsetX(const float x) { offsetX = x; }
    inline void             setOffsetY(const float y) { offsetY = y; }
    inline float            getOffsetX() { return offsetX; }
    inline float            getOffsetY() { return offsetY; }
    inline float            getWidth() { return width; }
    inline float            getHeight() { return height; }

    inline void             setWidth(const float w) { width = w; }
    inline void             setHeight(const float h) { height = h; }

    std::string             toString();

    void                    render(Color color);

protected:
    float                   offsetX;
    float                   offsetY;
    float                   width;
    float                   height;
};

}

#endif // QUANTUM_2D_BOXCOLLIDER_H
