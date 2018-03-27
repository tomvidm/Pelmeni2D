#pragma once

#include <memory>

#include "SFML/Graphics.hpp"

#include "AnimationState.hpp"
#include "SpritePackage.hpp"

namespace p2d { namespace graphics {
    class Sprite : public sf::Sprite {
    public:
        void update();
        //void setSpriteTexture(const ResourceId& id);
        //void setAnimation(const ResourceId& id);

        void useSpritePackage(const SpritePackagePtr pkgPtr);
        void useTexture(const TexturePtr texPtr);
        void useAnimation(const FrameSequencePtr fSequencePtr);
    private:
        AnimationState animationState;
    }; // class Sprite
} // namespace graphics
} // namespace p2d