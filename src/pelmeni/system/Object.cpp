#include "Object.hpp"

 

namespace p2d { namespace system {
    Object::Object() {
         
    } // constructor

    void Object::setSpritePackage(const SpritePackagePtr pkgPtr) {
         
        spritePackagePtr = pkgPtr;
        sprite.useSpritePackage(spritePackagePtr);
    }
    void Object::update() {
        sprite.update();
    }

    void Object::setAnimation(const AnimationId& id) {
        sprite.useAnimation(spritePackagePtr->getAnimation(id));
    }
} // namespace system
} // namespace p2d