#include "Object.hpp"

namespace p2d { namespace system {
    Object::Object() {
        ;
    }

    Object::Object(const graphics::SpritePackage::ptr spritePackagePtr)
    : spritePackage(spritePackagePtr) {
        ;
    }
} // namespace system
} // namespace p2d