#include "Sprite.hpp"

namespace p2d { namespace graphics {
    PackageManager Sprite::packageManager;

    void Sprite::update() {
        if (animationState.update()) {
            setTextureRect(animationState.getCurrentFrameRect());
        }
    } // update

    void Sprite::usePackage(const PackageId& id) {
        
        packagePtr = packageManager.getPackage(id);
        if (packagePtr == nullptr) {
            std::cout << "Sprite::usePackage - Failed... pointer is empty.\n";
            return;
        } else {
            usePackageTexture();
        }
    } // usePackage

    void Sprite::usePackageTexture() {
        setTexture(*(packagePtr->getTexturePtr()));
    } // usePackageTextuer
} // namespace graphics
} // namespace p2d