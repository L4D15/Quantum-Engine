#include "quantum/Libraries.h"
#include <fstream>
#include <sstream>
#include "quantum/Sprite.h"
#include "quantum/Game.h"

using namespace assets2D;

/**
 *
 * @param filePath
 */
Sprite::Sprite(std::string name, std::string filePath) :
    RenderizableAsset(name)
{
    // Open Image file
    this->spriteSheet = IMG_LoadTexture(Game::window->getRenderer(), filePath.c_str());

    if (this->spriteSheet == NULL) {
        std::stringstream stream;

        stream << "Image " << filePath << " couldn't be loaded." << std::endl << SDL_GetError();

        SDL_ShowSimpleMessageBox(
                SDL_MESSAGEBOX_ERROR,
                "ERROR - Sprite Sheet",
                stream.str().c_str(),
                NULL);
    }

    SDL_QueryTexture(this->spriteSheet, NULL, NULL, & this->totalWidth, & this->totalHeight);

    // Open JSON file
    Json::Value root;
    Json::Reader reader;

    // Find the JSON file (it will have the same name but with the .json extension)
    std::string jsonFilePath(filePath);
    unsigned int lastDotPosition = jsonFilePath.find_last_of(".");
    jsonFilePath = jsonFilePath.substr(0, lastDotPosition);
    jsonFilePath.append(".json");

    bool parsingSuccessful;
    std::ifstream jsonStream(jsonFilePath.c_str(), std::ifstream::binary);

    parsingSuccessful = reader.parse(jsonStream, root, false);

    if (parsingSuccessful == false) {
        std::stringstream stream;

        stream << "Missing file or parsing error for JSON " << jsonFilePath;

        SDL_ShowSimpleMessageBox(
                SDL_MESSAGEBOX_ERROR,
                "ERROR - Sprite Sheet",
                stream.str().c_str(),
                NULL);
    }

    Json::Value animations = root["animations"];
    unsigned int numberOfAnimations = animations.size();

    // Reserve memory for all the animations
    this->animations = new std::vector<SpriteSheetAnimation *>(numberOfAnimations);

    unsigned int maxNumberOfFrames = 0; // We will need it later
    unsigned int currentNumberOfFrames;
    for (unsigned int currentAnimation = 0; currentAnimation < numberOfAnimations; ++currentAnimation) {
        currentNumberOfFrames = animations[currentAnimation]["frames"].asUInt();

        if (currentNumberOfFrames > maxNumberOfFrames) {
            maxNumberOfFrames = currentNumberOfFrames;
        }
    }

    // Now we can calculate the width and height of each animation frame
    this->frameWidth = this->totalWidth / maxNumberOfFrames;
    this->frameHeight = this->totalHeight / numberOfAnimations;

    // Iterate over the animation information creating SpriteAnimation data
    Json::Value currentAnimation;
    for (unsigned int currentAnimationIndex = 0; currentAnimationIndex < numberOfAnimations; ++currentAnimationIndex) {
        currentAnimation = animations[currentAnimationIndex];

        std::string name = currentAnimation["name"].asString();
        int frames = currentAnimation["frames"].asInt();
        bool oscillate = currentAnimation["oscillate"].asBool();
        int frameRate = currentAnimation["frame-rate"].asInt();

        this->animations->at(currentAnimationIndex)
                =
                new SpriteSheetAnimation(
                name,
                currentAnimationIndex,
                this->frameWidth,
                this->frameHeight,
                frames,
                frameRate,
                oscillate);

        this->animationsMapper.insert(
                std::pair<std::string, unsigned int>(
                        currentAnimation["name"].asString(),
                        currentAnimationIndex));
    }
}

/**
 *
 */
Sprite::~Sprite() {
    for (unsigned int animationIndex = 0; animationIndex < this->animations->size(); ++animationIndex) {
        delete this->animations->at(animationIndex);
    }

    this->animations->clear();

    delete this->animations;

    SDL_DestroyTexture(this->spriteSheet);
}

/**
 * Access to an specific animation of the sprite.
 *
 * It is usually used for sprite[animation][frame].
 * @param animation     Name of the animation.
 * @return              Reference to the animation.
 */
SpriteSheetAnimation * Sprite::operator [](std::string animation) {
    return (this->animations->at(this->animationsMapper.find(animation)->second));
}

/**
 *
 * @return
 */
SpriteSheetAnimation * Sprite::getDefaultAnimation() {
    return (this->animations->at(0));
}

/**
 * Access to an specific animation of the sprite.
 * @param animation     Name of the animation.
 * @return              Reference to the animation.
 */
SpriteSheetAnimation * Sprite::getAnimation(std::string animation) {
   std::map<std::string, unsigned int>::iterator animationFound;

   if (this->animationsMapper.count(animation) == 0) {
       std::stringstream stream;

       stream << "Animation " << animation << " name not found in animations mapper.";
       SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "ERROR - SpriteSheet", stream.str().c_str(), NULL);
   }

   animationFound = this->animationsMapper.find(animation);

   if (animationFound == this->animationsMapper.end()) {
    std::stringstream stream;

    stream << "Animation " << animation << " name is not correct.";
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "ERROR - SpriteSheet", stream.str().c_str(), NULL);
   }

   return (this->animations->at(animationFound->second));
}

/**
 * @brief SpriteSheet::render
 * @param renderer
 * @param position
 * @param scale
 * @param rotation
 */
void Sprite::render(SDL_Renderer *renderer, Vector2D position, Vector2D scale, float rotation) {
    // TODO: Implement

    SDL_Rect geometry;

    geometry.x = position.getX() - this->getWidth() / 2.0f;
    geometry.y = position.getY() - this->getHeight() / 2.0f;
    geometry.w = this->getWidth() * scale.getX();
    geometry.h = this->getHeight() * scale.getY();

    SDL_Point centerPoint;

    centerPoint.x = position.getX();
    centerPoint.y = position.getY();

    SDL_RenderCopyEx(renderer, this->spriteSheet, NULL, &geometry, rotation, &centerPoint, SDL_FLIP_NONE);
}

SDL_Surface* Sprite::getAssetSurface(std::string animation, unsigned int frame)
{
    SDL_Surface* surface = SDL_CreateRGBSurface(SDL_PIXELFORMAT_ARGB8888,
                             this->getIndividualFrameWidth(),
                             this->getIndividualFrameHeight(),
                             32,
                             0x00ff0000,
                             0x0000ff00,
                             0x000000ff,
                             0xff000000);

    SDL_Renderer* softwareRenderer = SDL_CreateSoftwareRenderer(surface);

    SpriteSheetAnimation* currentAnimation;
    currentAnimation = this->getAnimation(animation);

    SDL_Rect spriteFrame;
    spriteFrame = currentAnimation->getFrameRect(frame);

    SDL_RenderCopy(softwareRenderer, this->spriteSheet, & spriteFrame, NULL);

    SDL_DestroyRenderer(softwareRenderer);

    return surface;
}


/**
 *
 * @return
 */
std::string Sprite::toString() {
    std::stringstream stream;

    stream << "[========================]" << std::endl;
    stream << "-->ANIMATIONS<---" << std::endl;
    for (unsigned int i = 0; i < this->animations->size(); ++i) {
        stream << "Animations[" << i << "] = " << this->animations->at(i)->getName() << std::endl;
    }

    stream << std::endl;

    stream << "-->BINDINGS<--" << std::endl;
    for (std::map<std::string, unsigned int>::iterator currentAnimation = this->animationsMapper.begin(); currentAnimation != this->animationsMapper.end(); ++currentAnimation) {
        stream << "Animation: " << currentAnimation->first << "    Position: " << currentAnimation->second << std::endl;
    }

    stream << "[========================]" << std::endl;

    return stream.str();
}

