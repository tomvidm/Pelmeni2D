#include "Sprite.hpp"

namespace p2d { namespace graphics {
    void Sprite::update() {
        if (animationState.update()) {
            setTextureRect(animationState.getCurrentFrameRect());
        }
    } // update
} // namespace graphics
} // namespace p2d