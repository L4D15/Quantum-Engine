#ifndef QUANTUM_SPRITESHEET_ANIMATION_H
#define QUANTUM_SPRITESHEET_ANIMATION_H

#include <string>
#include <vector>
#include "quantum/Libraries.h"
#include "Vector2D.h"

class SpriteSheetAnimation {
public:
    SpriteSheetAnimation();
    SpriteSheetAnimation(
            std::string name,
            unsigned int animationIndex,
            unsigned int widthPerFrame,
            unsigned int heightPerFrame,
            unsigned int numberOfFrames,
            unsigned int frameRate = 200,
            bool oscillate = false);
    virtual ~SpriteSheetAnimation();
    
    SDL_Rect                    operator[](const unsigned int frameIndex);
    
    std::string                 toString();
    
    inline std::string          getName() { return name; }
    inline int                  getFrameRate() { return frameRate; }
    inline int                  isOscillating() { return oscillate; }
    inline int                  getNumberOfFrames() { return frames->size(); }
    inline int                  getWidth() { return frameWidth; }
    inline int                  getHeight() { return frameHeight; }
    
private:
    std::string                 name;
    
    unsigned int                frameWidth;
    unsigned int                frameHeight;
    
    std::vector<Vector2D> *     frames;
    
    unsigned int                frameRate;
    bool                        oscillate;
};

#endif // QUANTUM_SPRITESHEET_ANIMATION_H
