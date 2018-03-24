#include <iostream>

#include "Package.hpp"

namespace p2d { namespace graphics {
    Package::Package() {
        std::cout << "Package::Package() created at address " << this << "\n";
    }

    Package::Package(const TexturePtr texPtr)
    : texturePtr(texPtr) {
        std::cout << "Package::Package(TexturePtr at address " << texPtr.get() << ") created at address " << this << "\n";
    }
} // namespace graphics
} // namespace p2d