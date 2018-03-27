 #include <cstdio>

#include "SpritePackage.hpp"

namespace p2d { namespace graphics {
    SpritePackage::SpritePackage(
        const SpritePackage::id& spritePackageId,
        Texture::ptr texturePtr)
    : _spritePackageId(spritePackageId), texture(texturePtr) {
        printf("SpritePackage: %s created\n", getId().c_str());
    }
} // namespace graphics
} // namespace p2d