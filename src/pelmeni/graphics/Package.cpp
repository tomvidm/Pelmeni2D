 

#include "Package.hpp"

namespace p2d { namespace graphics {
    Package::Package() {
         ;
    }

    Package::Package(const TexturePtr texPtr)
    : texturePtr(texPtr) {
         
    }
} // namespace graphics
} // namespace p2d