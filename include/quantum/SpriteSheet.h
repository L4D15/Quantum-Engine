#ifndef SPRITESHEET_H
#define	SPRITESHEET_H

#include "quantum/Libraries.h"
#include <map>
#include <vector>
#include "Vector2D.h"
#include "quantum/Sprite.h"
#include "quantum/RenderizableAsset.h"

namespace Assets2D {

class SpriteSheet : public RenderizableAsset {
public:
    SpriteSheet(std::string name, std::string filePath);
    virtual ~SpriteSheet();

    Sprite *                            operator[](std::string animation);
    Sprite *                            GetDefaultAnimation();
    Sprite *                            GetAnimation(std::string animation);

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

    std::vector<Sprite *> *             animations;
    std::map<std::string, unsigned int> animationsMapper;
};

}

#endif	/* SPRITESHEET_H */

