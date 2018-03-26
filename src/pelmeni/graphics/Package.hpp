#pragma once

#include <memory>
#include <string>

#include "FrameSequence.hpp"
#include "Texture.hpp"
#include "../utility/Map.hpp"

namespace p2d { namespace graphics {
    using FrameSequencePtr = std::shared_ptr<FrameSequence>;
    using ResourceId = std::string;
    using AnimationId = std::string;
    using AnimationPtrMap = utility::Map<AnimationId, FrameSequencePtr>;

    class Package {
    public:
        Package();
        Package(const TexturePtr texPtr, const AnimationPtrMap& animPtrMap);
        inline TexturePtr getTexturePtr() const { return texturePtr; }
        // FrameSequencePtr& getFrameSequencePtr(const ResourceId& animId) const;
        FrameSequencePtr getAnimation(const AnimationId& id);
    private:
        TexturePtr texturePtr;
        AnimationPtrMap animationPtrMap;
    }; // class Package

    using PackagePtr = std::shared_ptr<Package>;
} // namespace graphics
} // namespace p2d