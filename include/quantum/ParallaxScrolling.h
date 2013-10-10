#ifndef PARALLAXLAYERS_H
#define PARALLAXLAYERS_H

#include "quantum/Vector2D.h"

namespace Systems2D {

class ParallaxScrolling {
public:
    ParallaxScrolling();
    virtual ~ParallaxScrolling();

    void                                SetBackgroundDistance(int distance);
    int                                 GetBackgroundDistance();

    Vector2D                            ApplyParallaxScrolling(Vector2D cameraPosition, Vector2D objectPosition, int objectDistanceFromCamera);

private:
    int                                 backgroundDistance; // Distance of the static background

};

}

#endif // PARALLAXLAYERS_H
