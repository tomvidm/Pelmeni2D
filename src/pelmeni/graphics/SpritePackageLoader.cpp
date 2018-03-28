#include <cstdio>
#include <cassert>
#include <string>

#include "rapidjson/filereadstream.h"
#include "rapidjson/document.h"

#include "json/Helpers.hpp"

#include "SpritePackageLoader.hpp"

namespace p2d { namespace graphics {
    SpritePackage::ptr SpritePackageLoader::createSpritePackage(const SpritePackage::id& spritePackageId, const std::string& spritePackagePath) {
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
            fSequenceMap                            // utility::map<FrameSequence::id, FrameSequence::ptr>
        );

        return spritePackage;
    }
} // namespace graphics
} // namespace p2d