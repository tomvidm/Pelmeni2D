#include "Object.hpp"

 

namespace p2d { namespace system {
    Object::Object() {
         
    } // constructor

    void Object::setPackage(const PackagePtr pkgPtr) {
         
        packagePtr = pkgPtr;
        sprite.usePackage(packagePtr);
    }
    void Object::update() {
        sprite.update();
    }

    void Object::setAnimation(const AnimationId& id) {
        sprite.useAnimation(packagePtr->getAnimation(id));
    }
} // namespace system
} // namespace p2d