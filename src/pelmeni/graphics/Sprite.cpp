#include "Sprite.hpp"

namespace p2d { namespace graphics {
    void Sprite::update() {
        if (animationState.update()) {
            setTextureRect(animationState.getCurrentFrameRect());
        }
    } // update

    void Sprite::useSpritePackage(const SpritePackage::ptr spritePackage) {
        printf("using sprite package!\n");
        useTexture(spritePackage->getTexture());
    } // usePackage

    void Sprite::useTexture(const Texture::ptr texture) {
        printf("using texture!\n");
        setTexture(texture->getTexture());
    }

    void Sprite::useAnimation(const FrameSequence::ptr fSequence) {
        animationState.setFrameSequence(fSequence);
    }
} // namespace graphics
} // namespace p2d