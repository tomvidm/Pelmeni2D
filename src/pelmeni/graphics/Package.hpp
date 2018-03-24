#pragma once

#include <memory>
#include <string>

#include "FrameSequence.hpp"
#include "Texture.hpp"

namespace p2d { namespace graphics {
    using FrameSequencePtr = std::shared_ptr<FrameSequence>;
    using ResourceId = std::string;
    using AnimationId = std::string;
    using AnimationMap = utility::Map<AnimationId, FrameSequence>;

    class Package {
    public:
        Package();
        Package(const TexturePtr texPtr);
        inline TexturePtr getTexturePtr() const { return texturePtr; }
        // FrameSequencePtr& getFrameSequencePtr(const ResourceId& animId) const;
        void addAnimation(const std::pair<AnimationId, FrameSequence>);
    private:
        TexturePtr texturePtr;
        AnimationMap animationMap;
    }; // class Package

    using PackagePtr = std::shared_ptr<Package>;
} // namespace graphics
} // namespace p2d