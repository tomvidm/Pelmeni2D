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
    }
} // namespace graphics
} // namespace p2d