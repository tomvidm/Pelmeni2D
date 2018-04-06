#pragma once

#include <memory>

#include "SFML/Graphics.hpp"

#include "AnimationState.hpp"

#include "graphics/SpritePack.hpp"
#include "graphics/FrameSequence.hpp"
#include "graphics/Texture.hpp"

namespace p2d { namespace graphics {
    class Sprite : public sf::Sprite {
    public:
        using id = std::string;
        using shared = std::shared_ptr<Sprite>;
        Sprite() {
            ;
        }

        Sprite(const Sprite& other)
        : animationState(other.animationState),
          spritePack(other.spritePack) {
              ;
          }

        void setSpritePack(SpritePack::shared spritePackArg);
    private:
        AnimationState animationState;
        SpritePack::shared spritePack;
    }; // class Sprite
} // namespace graphics
} // namespace p2d