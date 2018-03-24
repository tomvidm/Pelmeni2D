#include "Sprite.hpp"

namespace p2d { namespace graphics {
    void Sprite::update() {
        if (animationState.update()) {
            setTextureRect(animationState.getCurrentFrameRect());
        }
    } // update

    void Sprite::usePackage(const PackagePtr pkgPtr) {
        std::cout << "Sprite::usePackage(PackagePtr pointing to " << pkgPtr.get() << "\n";
        useTexture(pkgPtr->getTexturePtr());
    } // usePackage

    void Sprite::useTexture(const TexturePtr texPtr) {
        std::cout << "Sprite::useTexture(TexturePtr pointing to " << texPtr.get() << "\n";
        setTexture(*texPtr);
    } // useTexture
} // namespace graphics
} // namespace p2d