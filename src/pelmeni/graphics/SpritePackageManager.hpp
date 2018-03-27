#pragma once

#include <string>
#include <memory>

#include "SpritePackage.hpp"
#include "SpritePackageLoader.hpp"
#include "../utility/Map.hpp"

namespace p2d { namespace graphics {
    class SpritePackageManager {
        using SpritePackageId = std::string;
        using SpritePackagePtrMap = utility::Map<ResourceId, SpritePackagePtr>;
    
    public:
        SpritePackagePtr getSpritePackage(const SpritePackageId& id);
        SpritePackagePtr loadSpritePackage(const SpritePackageId& id);
    private:
        SpritePackagePtrMap spritePackagePtrMap;
        SpritePackageLoader spritePackageLoader;
    }; // class PackageManager
} // namespace graphics
} // namespace p2d