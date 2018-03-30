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
        void useAnimation(const FrameSequence::id& fid);
        void useSpritePackage(SpritePackage::ptr newSpritePackage);

        //void useSpritePackage(const SpritePackage::ptr spritePackage);
    private:
        AnimationState animationState;
        SpritePackage::ptr spritePackage;
    }; // class Sprite
} // namespace graphics
} // namespace p2d