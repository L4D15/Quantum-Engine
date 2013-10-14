#ifndef QUANTUM_SPRITE_H
#define	QUANTUM_SPRITE_H

#include "quantum/Libraries.h"
#include <map>
#include <vector>
#include "Vector2D.h"
#include "quantum/SpriteSheetAnimation.h"
#include "quantum/RenderizableAsset.h"

namespace Assets2D {

class Sprite : public RenderizableAsset {
public:
    Sprite(std::string name, std::string filePath);
    virtual ~Sprite();

    SpriteSheetAnimation *                            operator[](std::string animation);
    SpriteSheetAnimation *                            GetDefaultAnimation();
    SpriteSheetAnimation *                            GetAnimation(std::string animation);

    inline int                          GetWidth() { return totalWidth; }
    inline int                          GetHeight() { return totalHeight; }
    inline int                          GetIndividualFrameWidth() { return frameWidth; }
    inline int                          GetIndividualFrameHeight() { return frameHeight; }

    inline SDL_Texture *                GetTexture() { return spriteSheet; }

    void                                Render(SDL_Renderer* renderer, Vector2D position, Vector2D scale, float rotation);

    std::string                         ToString();
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

