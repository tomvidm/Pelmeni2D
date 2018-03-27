#include "Sprite.hpp"

namespace p2d { namespace graphics {
    void Sprite::update() {
        if (animationState.update()) {
            setTextureRect(animationState.getCurrentFrameRect());
        }
    } // update

    void Sprite::useSpritePackage(const SpritePackagePtr pkgPtr) {
        useTexture(pkgPtr->getTexturePtr());
    } // usePackage

    void Sprite::useTexture(const TexturePtr texPtr) {
        setTexture(*texPtr);
    } // useTexture

    void Sprite::useAnimation(const FrameSequencePtr fSequencePtr) {
        animationState.setFrameSequence(fSequencePtr);
    }
} // namespace graphics
} // namespace p2d