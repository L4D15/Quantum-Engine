#ifndef QUANTUM_2D_COLLISIONS_H
#define QUANTUM_2D_COLLISIONS_H

#include "quantum/components/Component.h"
#include "quantum/Vector2.h"

namespace components2D
{

class Collisions : public components::Component
{
public:
    Collisions(GameObject& owner) : Component(owner) { trigger = false; }


    inline bool         isTrigger() { return trigger; }
    inline std::string  getScriptToTrigger() { return script; }

    inline void         setIsTrigger(const bool t) { trigger = t; }
    inline void         setScriptToTrigger(const std::string s){ this->script = s; }

    virtual std::string toString()
    {
        std::stringstream str;

        str << "trigger: ";
        if (trigger)
        {
            str << "yes";
        }
        else
        {
            str << "no";
        }
        str << std::endl;

        str << "script: " << script;

        return str.str();
    }

protected:
    bool                trigger;
    std::string         script;
};

}

#endif // QUANTUM_2D_COLLISIONS_H
