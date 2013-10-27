#ifndef QUANTUM_SPRITE_H
#define	QUANTUM_SPRITE_H

#include "quantum/Libraries.h"
#include <map>
#include <vector>
#include "Vector2D.h"
#include "quantum/SpriteSheetAnimation.h"
#include "quantum/RenderizableAsset.h"

namespace assets2D {

class Sprite : public RenderizableAsset {
public:
    Sprite(std::string name, std::string filePath);
    virtual ~Sprite();

    SpriteSheetAnimation *              operator[](std::string animation);
    SpriteSheetAnimation *              getDefaultAnimation();
    SpriteSheetAnimation *              getAnimation(std::string animation);

    inline int                          getWidth() { return totalWidth; }
    inline int                          getHeight() { return totalHeight; }
    inline int                          getIndividualFrameWidth() { return frameWidth; }
    inline int                          getIndividualFrameHeight() { return frameHeight; }

    inline SDL_Texture *                getTexture() { return spriteSheet; }

    void                                render(SDL_Renderer* renderer, Vector2D position, Vector2D scale, float rotation);

    std::string                         toString();
private:
    SDL_Texture *                       spriteSheet;

    int                                 totalWidth;
    int                                 totalHeight;
    int                                 frameWidth;
    int                                 frameHeight;

    std::vector<SpriteSheetAnimation *> *             animations;
    std::map<std::string, unsigned int> animationsMapper;
};

}

#endif	/* QUANTUM_SPRITE_H */

