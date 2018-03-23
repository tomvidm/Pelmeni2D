#pragma once

#include "SFML/Graphics.hpp"

#include "AnimationState.hpp"
#include "AnimationManager.hpp"
#include "TextureManager.hpp"

namespace p2d { namespace graphics {
    class Sprite : public sf::Sprite {
    public:
        void update();
        void setSpriteTexture(const ResourceId& id);
        //void setAnimation(const ResourceId& id);

        static AnimationManager animationManager;
        static TextureManager textureManager;
    private:
        AnimationState animationState;
    }; // class Sprite
} // namespace graphics
} // namespace p2d