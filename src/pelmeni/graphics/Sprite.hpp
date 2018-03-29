#pragma once

#include <memory>

#include "SFML/Graphics.hpp"

#include "AnimationState.hpp"
#include "SpritePackage.hpp"

namespace p2d { namespace graphics {
    class Sprite : public sf::Sprite {
    public:
        using id = std::string;
        using ptr = std::shared_ptr<Sprite>;

        void update();
        void useTexture(const Texture::ptr texture);
        void useAnimation(const FrameSequence::ptr fSequence);

        void useSpritePackage(const SpritePackage::ptr spritePackage);
    private:
        AnimationState animationState;
    }; // class Sprite
} // namespace graphics
} // namespace p2d