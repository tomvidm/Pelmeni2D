#pragma once

#include <memory>
#include <string>

#include "utility/Map.hpp"

#include "graphics/Texture.hpp"

namespace p2d { namespace graphics {
    class SpritePackage {
    public:
        using id = std::string;
        using ptr = std::shared_ptr<SpritePackage>;

        SpritePackage(const SpritePackage::id& spritePackageId,
                      Texture::ptr texturePtr);

        inline SpritePackage::id getId() const { return _spritePackageId; }
    private:
        SpritePackage::id _spritePackageId;
        
        Texture::ptr texture;
    }; // class Package
} // namespace graphics
} // namespace p2d