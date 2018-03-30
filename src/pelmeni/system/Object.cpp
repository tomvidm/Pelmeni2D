#include "Object.hpp"

namespace p2d { namespace system {
    Object::Object() {
        ;
    }

    Object::Object(graphics::SpritePackage::ptr spritePackageArg) {
        sprite.useSpritePackage(spritePackageArg);
        sprite.useAnimation("default");
    }

    void Object::update() {
        sprite.update();
    }
} // namespace system
} // namespace p2d