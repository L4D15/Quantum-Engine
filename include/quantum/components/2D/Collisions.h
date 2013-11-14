#ifndef QUANTUM_2D_COLLISIONS_H
#define QUANTUM_2D_COLLISIONS_H

#include "quantum/components/Component.h"
#include "quantum/Vector2D.h"

namespace components2D
{

class Collisions : public components::Component
{
public:
    Collisions(GameObject& owner) : Component(owner) { offsetX = 0.0f; offsetY = 0.0f; }

    inline float getOffsetX() { return offsetX; }
    inline float getOffsetY() { return offsetY; }
    inline bool isTrigger() { return trigger; }
    inline std::string getScriptToTrigger() { return script; }

    inline void setOffsetX(const float x) { offsetX = x; }
    inline void setOffsetY(const float y) { offsetY = y; }
    inline void setIsTrigger(const bool t) { trigger = t; }
    inline void setScriptToTrigger(const std::string s) { script = s; }

protected:
    float offsetX;
    float offsetY;
    bool trigger;
    std::string script;
};

}

#endif // QUANTUM_2D_COLLISIONS_H
