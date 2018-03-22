#pragma once

#include "SFML/Graphics.hpp"

#include "AnimationState.hpp"
#include "AnimationManager.hpp"
#include "TextureManager.hpp"

namespace p2d { namespace graphics {
    class Sprite : public sf::Sprite {
    public:
        
    private:
        AnimationState animationState;
    }; // class Sprite
} // namespace graphics
} // namespace p2d