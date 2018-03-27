#pragma once

#include "SFML/Graphics.hpp"

#include "graphics/SpritePackage.hpp"
#include "graphics/TextureManager.hpp"

namespace p2d { namespace graphics {
    using id = std::string;

    class SpritePackageLoader {
    public:
        SpritePackage::ptr createSpritePackage(const SpritePackage::id& spritePackageId, const std::string& spritePackagePath);

        TextureManager textureManager;
    }; // class PackageLoader
} // namespace graphics
} // namespace p2d