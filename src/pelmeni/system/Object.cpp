#include "Object.hpp"

namespace p2d { namespace system {
    Object::Object() {
        ;
    }

    Object::Object(const graphics::SpritePackage::ptr spritePackage)
    : spritePackage(spritePackage) {
        sprite->useSpritePackage(spritePackage);
    }
} // namespace system
} // namespace p2d