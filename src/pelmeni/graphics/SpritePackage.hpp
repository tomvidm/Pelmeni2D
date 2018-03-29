#pragma once

#include <memory>
#include <string>

#include "utility/Map.hpp"

#include "graphics/Texture.hpp"
#include "graphics/FrameSequence.hpp"

namespace p2d { namespace graphics {
    using FrameSequenceMap = utility::Map<FrameSequence::id, FrameSequence::ptr>;
    class SpritePackage {
    public:
        using id = std::string;
        using ptr = std::shared_ptr<SpritePackage>;

        SpritePackage(const SpritePackage::id& spritePackageId,
                      const Texture::ptr texturePtr,
                      const FrameSequenceMap& fSequenceMap);

        inline SpritePackage::id getId() const { return _spritePackageId; }
        inline Texture::ptr getTexture() const { return texture; }
    private:
        SpritePackage::id _spritePackageId;
        Texture::ptr texture;
        FrameSequenceMap frameSequenceMap;
    }; // class Package
} // namespace graphics
} // namespace p2d