#include "Sprite.hpp"

namespace p2d { namespace graphics {
    void Sprite::update() {
        if (animationState.update()) {
            setTextureRect(animationState.getCurrentFrameRect());
        }
    } // update

    void Sprite::useAnimation(const FrameSequence::id& fid) {
        animationState.setFrameSequence(spritePackage->getFrameSequence(fid));
    }

    void Sprite::useSpritePackage(SpritePackage::ptr newSpritePackage) {
        spritePackage = newSpritePackage;
        setTexture(spritePackage->getTexture());
    }
} // namespace graphics
} // namespace p2d