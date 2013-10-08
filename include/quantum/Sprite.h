#ifndef QUANTUM_SPRITE_H
#define QUANTUM_SPRITE_H

#include <string>
#include <vector>
#include "quantum/Libraries.h"
#include "Vector2D.h"

class Sprite {
public:
    Sprite();
    Sprite(
            std::string name,
            unsigned int animationIndex,
            unsigned int widthPerFrame,
            unsigned int heightPerFrame,
            unsigned int numberOfFrames,
            unsigned int frameRate = 200,
            bool oscillate = false);
    virtual ~Sprite();
    
    SDL_Rect                    operator[](const unsigned int frameIndex);
    
    std::string                 ToString();
    
    inline std::string          GetName() { return name; }
    inline int                  GetFrameRate() { return frameRate; }
    inline int                  IsOscillating() { return oscillate; }
    inline int                  GetNumberOfFrames() { return frames->size(); }
    inline int                  GetWidth() { return frameWidth; }
    inline int                  GetHeight() { return frameHeight; }
    
private:
    std::string                 name;
    
    unsigned int                frameWidth;
    unsigned int                frameHeight;
    
    std::vector<Vector2D> *     frames;
    
    unsigned int                frameRate;
    bool                        oscillate;
};

#endif // QUANTUM_SPRITE_H
