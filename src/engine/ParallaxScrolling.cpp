#include "quantum/ParallaxScrolling.h"
#include <cmath>
#include "quantum/Game.h"

using namespace systems2D;

ParallaxScrolling::ParallaxScrolling() {
    this->backgroundDistance = 1000;
}

ParallaxScrolling::~ParallaxScrolling() {

}

/**
 * @brief Sets the distance of the background layer, where the image is static and won't move with the camera.
 *
 * This distance is used to calculate the parallax effect applied to other objects, so changing this value
 * will change the behavior of the effect in other objects.
 * @param distance      Distance the static background layer is from the camera.
 */
void ParallaxScrolling::setBackgroundDistance(int distance) {
    this->backgroundDistance = distance;
}

/**
 * @brief Distance from the camera of the static background layer.
 * @return  Distance from the camera.
 */
int ParallaxScrolling::getBackgroundDistance() {
    return this->backgroundDistance;
}

/**
 * @brief Calculates the in-screen position after applying the parallax scrolling effect.
 * @param cameraPosition                Position of the camera the object will be rendered.
 * @param objectPosition                Position of the object without any perspective transformation applied (the "real" position).
 * @param objectDistanceFromCamera      Distance of the object from the camera.
 * @return Perspective position of the object after applying the parallax scrolling effect.
 */
Vector2 ParallaxScrolling::applyParallaxScrolling(Vector2 cameraPosition, Vector2 objectPosition, int objectDistanceFromCamera) {

    int distance;

    distance = objectDistanceFromCamera - this->backgroundDistance;

    // Calculate the offset if the object were in the reference layer (the one at backgroundDistance distance)
    float alphaX;   // Angle between the center axis (the camera) and the object in the reference layer
    float alphaY;
    alphaX = atan((cameraPosition.getX() - objectPosition.getX()) / backgroundDistance);
    alphaY = atan((cameraPosition.getY() - objectPosition.getY()) / backgroundDistance);

    // Now we interpolate the value to a layer that has a different distance to the background
    float offsetX = distance * tan(alphaX);
    float offsetY = distance * tan(alphaY);

    // We have the offset of the displaced position, so we add it to the objects position
    return objectPosition + Vector2(offsetX, offsetY) + Vector2(Game::window->getWidth() / 2.0f, Game::window->getHeight() / 2.0f);
}

