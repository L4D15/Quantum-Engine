#ifndef QUANTUM_2D_BOXCOLLIDER_H
#define QUANTUM_2D_BOXCOLLIDER_H

#include "quantum/components/2D/Collisions.h"
#include "quantum/components/2D/Camera.h"
#include "quantum/Color.h"

namespace components2D
{

class BoxCollider : public Collisions
{
public:
    BoxCollider(GameObject& owner);

    inline void setWidth(const float w) { width = w; }
    inline void setHeight(const float h) { height = h; }

    inline float getWidth() { return width; }
    inline float getHeight() { return height; }

    std::string toString();

    void render(Color color);

protected:
    float width;
    float height;
};

}

#endif // QUANTUM_2D_BOXCOLLIDER_H
