 #include <cstdio>

#include "SpritePackage.hpp"

namespace p2d { namespace graphics {
    SpritePackage::SpritePackage(
        const SpritePackage::id& spritePackageId,
        sf::Texture& texturePtr,
        const FrameSequenceMap& fSequenceMap)
    : _spritePackageId(spritePackageId), texture(texturePtr), frameSequenceMap(fSequenceMap) {
    }
} // namespace graphics
} // namespace p2d