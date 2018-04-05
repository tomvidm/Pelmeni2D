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

        void setSpriteTexture(const Texture& tex);
    private:
        AnimationState animationState;
        Texture::shared texture;
        SpritePack::shared spritePack;
    }; // class Sprite
} // namespace graphics
} // namespace p2d