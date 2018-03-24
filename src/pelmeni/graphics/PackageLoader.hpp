#pragma once

#include "Package.hpp"
#include "Texture.hpp"
#include "TextureManager.hpp"
// #include "AnimationMap.hpp"

namespace p2d { namespace graphics {
    using PackageId = std::string;
    using PackagePtr = std::shared_ptr<Package>;

    class PackageLoader {
    public:
        std::pair<PackageId, PackagePtr> load(const PackageId& id);
    private:
        TextureManager textureManager;
    }; // class PackageLoader
} // namespace graphics
} // namespace p2d