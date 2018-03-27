#pragma once

#include <string>
#include <memory>

#include "utility/Map.hpp"
#include "graphics/SpritePackage.hpp"
#include "graphics/SpritePackageLoader.hpp"

namespace p2d { namespace graphics {
    class SpritePackageManager {
        using PackageMap = utility::Map<SpritePackage::id, SpritePackage::ptr>;
        using PackageLookupTable = utility::Map<SpritePackage::id, std::string>;
    public:
        SpritePackageManager() {
            initializePackageLookupTable();
        }

        void loadSpritePackage(const SpritePackage::id spritePackageId);
    private:
        void initializePackageLookupTable();
        PackageMap packageMap;
        PackageLookupTable packageLookupTable;
        SpritePackageLoader spritePackageLoader;
    }; // class PackageManager
} // namespace graphics
} // namespace p2d