#include "Sprite.hpp"

namespace p2d { namespace graphics {
    AnimationManager Sprite::animationManager;
    TextureManager Sprite::textureManager;

    void Sprite::update() {
        if (animationState.update()) {
            setTextureRect(animationState.getCurrentFrameRect());
        }
    } // update

    void Sprite::setSpriteTexture(const ResourceId& id) {
        setTexture(textureManager.get(id));
    }

/*     
    void Sprite::setAnimation(const ResourceId& id) {
        animationState.setFrameSequence(animationManager.get(id));
    } 
*/
} // namespace graphics
} // namespace p2d