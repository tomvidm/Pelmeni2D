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
        SpritePackage::ptr spritePackage = createSpritePackage(spritePackageId, spritePackagePath);
        assert(spritePackage->getId() == spritePackageId);

        packageMap.insert(std::make_pair(spritePackageId, spritePackage));
    }

    SpritePackage::ptr SpritePackageManager::getSpritePackage(const SpritePackage::id& spritePackageId) {
        if (!packageMap.contains(spritePackageId)) {
            loadSpritePackage(spritePackageId);
        }

        return packageMap.get(spritePackageId);
    }

    SpritePackage::ptr SpritePackageManager::createSpritePackage(const SpritePackage::id& spritePackageId, const std::string& spritePackagePath) {
        rapidjson::Document doc = json::parseJsonFile("../resources/packages/" + spritePackagePath);

        assert(spritePackageId == doc["package_id"].GetString());

        Texture::id textureId = doc["texture_id"].GetString();

        utility::Map<FrameSequence::id, FrameSequence::ptr> fSequenceMap;
        for (auto& entry : doc["animations"].GetArray()) {
            FrameSequence::id fSequenceId = entry["animation_key"].GetString();
            FrameSequence::ptr fSequence = frameSequenceLoader.generateFrameSequence(fSequenceId, entry);
            fSequenceMap.insert(std::make_pair(fSequenceId, fSequence));
        }

        textureManager.loadTexture(textureId);
        SpritePackage::ptr spritePackage = std::make_shared<SpritePackage>(
            spritePackageId,                        // SpritePackage::id
            textureManager.getTexture(textureId),   // Texture::ptr
            std::move(fSequenceMap)                            // utility::map<FrameSequence::id, FrameSequence::ptr>
        );

        return spritePackage;
    }
} // namespace graphics
} // namespace p2d