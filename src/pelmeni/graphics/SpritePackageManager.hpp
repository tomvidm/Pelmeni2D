#pragma once

#include <string>
#include <memory>

#include "utility/Map.hpp"
#include "graphics/SpritePackage.hpp"
#include "graphics/TextureManager.hpp"
#include "graphics/FrameSequence.hpp"
#include "graphics/FrameSequenceLoader.hpp"

namespace p2d { namespace graphics {
    class SpritePackageManager {
        using PackageMap = utility::Map<SpritePackage::id, SpritePackage::ptr>;
        using PackageLookupTable = utility::Map<SpritePackage::id, std::string>;
    public:
        SpritePackageManager() {
            initializePackageLookupTable();
        }

        SpritePackage::ptr getSpritePackage(const SpritePackage::id& spritePackageId);
        void loadSpritePackage(const SpritePackage::id& spritePackageId);
    private:
        SpritePackage::ptr createSpritePackage(const SpritePackage::id& spritePackageId, const std::string& spritePackagePath);
        void initializePackageLookupTable();

        PackageMap packageMap;
        PackageLookupTable packageLookupTable;

        FrameSequenceLoader frameSequenceLoader;

        TextureManager textureManager;
        
    }; // class PackageManager
} // namespace graphics
} // namespace p2d