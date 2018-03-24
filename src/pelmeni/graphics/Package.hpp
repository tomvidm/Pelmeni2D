#pragma once

#include <memory>
#include <string>

#include "FrameSequence.hpp"
#include "Texture.hpp"

namespace p2d { namespace graphics {
    using FrameSequencePtr = std::shared_ptr<FrameSequence>;
    using ResourceId = std::string;

    class Package {
    public:
        Package();
        Package(const TexturePtr texPtr);
        inline TexturePtr getTexturePtr() const { return texturePtr; }
        // FrameSequencePtr& getFrameSequencePtr(const ResourceId& animId) const;
    private:
        TexturePtr texturePtr;
    }; // class Package

    using PackagePtr = std::shared_ptr<Package>;
} // namespace graphics
} // namespace p2d