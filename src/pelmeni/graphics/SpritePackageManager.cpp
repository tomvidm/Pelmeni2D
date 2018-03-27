#include "rapidjson/filereadstream.h"
#include "rapidjson/document.h"

#include "json/Helpers.hpp"

#include "SpritePackageManager.hpp"

namespace p2d { namespace graphics {
    void SpritePackageManager::initializePackageLookupTable() {
        printf("SpritePackageManager: Loading and parsing sprite package lookup table\n");
        rapidjson::Document doc = p2d::json::parseJsonFile("../resources/packages/package_lookup.json");

        for (auto& entry : doc["sprite_packages"].GetArray()) {
            const SpritePackage::id packageId = entry[0].GetString();
            const std::string packagePath = entry[1].GetString();
            packageLookupTable.insert(std::make_pair(packageId, packagePath));
            printf("-- %s: %s\n", packageId.c_str(), packagePath.c_str());
        }
        printf("SpritePackageManager: Finished loading sprite package lookup table\n");
    }

    void SpritePackageManager::loadSpritePackage(const SpritePackage::id spritePackageId) {
        printf("SpritePackageManager: Loading sprite package %s\n", spritePackageId.c_str());

        if (packageMap.contains(spritePackageId)) {
            printf("SpritePackageManager: Sprite package %s already loaded\n", spritePackageId.c_str());
            return;
        }

        SpritePackage::ptr spritePackage = spritePackageLoader.createSpritePackage(spritePackageId, packageLookupTable.get(spritePackageId));
        assert(spritePackage->getId() == spritePackageId);

        packageMap.insert(std::make_pair(spritePackageId, spritePackage));
    }
} // namespace graphics
} // namespace p2d