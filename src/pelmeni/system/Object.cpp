#include "Object.hpp"

#include <iostream>

namespace p2d { namespace system {
    Object::Object() {
        std::cout << "Object::Object() created at address " << this << "\n";
    } // constructor

    void Object::setPackage(const PackagePtr pkgPtr) {
        std::cout << "Object::setPackage(PackagePtr pointing to " << pkgPtr.get() << ")\n";
        packagePtr = pkgPtr;
        spritePtr->usePackage(packagePtr);
    }
} // namespace system
} // namespace p2d