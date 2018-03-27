#pragma once

#include "SFML/Graphics.hpp"

#include "SpritePackage.hpp"
#include "Frame.hpp"
#include "FrameSequence.hpp"
#include "Texture.hpp"
#include "TextureManager.hpp"
// #include "AnimationMap.hpp"

namespace p2d { namespace graphics {
    using SpritePackageId = std::string;
    using SpritePackagePtr = std::shared_ptr<SpritePackage>;
    using FrameSequencePtr = std::shared_ptr<FrameSequence>;

    class SpritePackageLoader {
    public:
        std::pair<SpritePackageId, SpritePackagePtr> load(const SpritePackageId& id);
    private:
        TextureManager textureManager;
    }; // class PackageLoader
} // namespace graphics
} // namespace p2d