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
                      sf::Texture& texturePtr,
                      const FrameSequenceMap& fSequenceMap);
                    
        SpritePackage(const SpritePackage& rhs)
        : _spritePackageId(rhs._spritePackageId),
        texture(rhs.texture),
        frameSequenceMap(rhs.frameSequenceMap) {}

        inline SpritePackage::id getId() const { return _spritePackageId; }
        inline sf::Texture& getTexture() const { return texture; }
        inline FrameSequence::ptr getFrameSequence(const FrameSequence::id& fid) { return frameSequenceMap.get(fid); }
    protected:
        SpritePackage::id _spritePackageId;
        sf::Texture& texture;
        FrameSequenceMap frameSequenceMap;
    }; // class Package
} // namespace graphics
} // namespace p2d