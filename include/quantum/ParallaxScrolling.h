#ifndef PARALLAXLAYERS_H
#define PARALLAXLAYERS_H

#include "quantum/Vector2.h"

namespace systems2D {

class ParallaxScrolling {
public:
    ParallaxScrolling();
    virtual ~ParallaxScrolling();

    void                                setBackgroundDistance(int distance);
    int                                 getBackgroundDistance();

    Vector2                             applyParallaxScrolling(Vector2 cameraPosition, Vector2 objectPosition, int objectDistanceFromCamera);

private:
    int                                 backgroundDistance; // Distance of the static background

};

}

#endif // PARALLAXLAYERS_H
