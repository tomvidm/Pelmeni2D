#include "rapidjson/filereadstream.h"
#include "rapidjson/document.h"

#include "json/Helpers.hpp"

#include "SpritePackageManager.hpp"

namespace p2d { namespace graphics {
    void SpritePackageManager::initializePackageLookupTable() {
        printf("Initializing sprite package lookup table... ");
        rapidjson::Document doc = p2d::json::parseJsonFile("../resources/packages/package_lookup.json");

        for (auto& entry : doc["sprite_packages"].GetArray()) {
            const SpritePackage::id packageId = entry[0].GetString();
            const std::string packagePath = entry[1].GetString();
            packageLookupTable.insert(std::make_pair(packageId, packagePath));
        }
        printf("Finished\n");
    }

    void SpritePackageManager::loadSpritePackage(const SpritePackage::id& spritePackageId) {
        printf("Loading sprite package '%s'\n", spritePackageId.c_str());

        if (packageMap.contains(spritePackageId)) {
            return;
        }
        std::string spritePackagePath = packageLookupTable.get(spritePackageId);
        SpritePackage::ptr spritePackage = spritePackageLoader.createSpritePackage(spritePackageId, spritePackagePath);
        assert(spritePackage->getId() == spritePackageId);

        packageMap.insert(std::make_pair(spritePackageId, spritePackage));
    }

    SpritePackage::ptr SpritePackageManager::getSpritePackage(const SpritePackage::id& spritePackageId) {
        if (!packageMap.contains(spritePackageId)) {
            loadSpritePackage(spritePackageId);
        }

        return packageMap.get(spritePackageId);
    }
} // namespace graphics
} // namespace p2d