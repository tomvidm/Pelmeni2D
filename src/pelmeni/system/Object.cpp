#include "Object.hpp"

 

namespace p2d { namespace system {
    Object::Object() {
         
    } // constructor

    void Object::setPackage(const PackagePtr pkgPtr) {
         
        packagePtr = pkgPtr;
        sprite.usePackage(packagePtr);
    }
} // namespace system
} // namespace p2d