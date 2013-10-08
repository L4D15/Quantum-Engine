#ifndef CAMERA_H
#define CAMERA_H

#include "quantum/Libraries.h"
#include "quantum/components/Component.h"

namespace Components2D
{

class Camera : public Components::Component
{
public:
    Camera(GameObject& owner);
    virtual ~Camera();

private:

};

}

#endif // CAMERA_H
