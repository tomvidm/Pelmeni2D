#pragma once

#include "SFML/Graphics.hpp"

#include "Package.hpp"
#include "Frame.hpp"
#include "FrameSequence.hpp"
#include "Texture.hpp"
#include "TextureManager.hpp"
// #include "AnimationMap.hpp"

namespace p2d { namespace graphics {
    using PackageId = std::string;
    using PackagePtr = std::shared_ptr<Package>;
    using FrameSequencePtr = std::shared_ptr<FrameSequence>;

    class PackageLoader {
    public:
        std::pair<PackageId, PackagePtr> load(const PackageId& id);
    private:
        TextureManager textureManager;
    }; // class PackageLoader
} // namespace graphics
} // namespace p2d