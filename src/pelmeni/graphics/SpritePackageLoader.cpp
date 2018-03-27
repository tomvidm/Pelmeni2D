#include <cstdio>
#include <cassert>
#include <string>

#include "rapidjson/filereadstream.h"
#include "rapidjson/document.h"

#include "json/Helpers.hpp"

#include "SpritePackageLoader.hpp"

namespace p2d { namespace graphics {
    SpritePackage::ptr SpritePackageLoader::createSpritePackage(const SpritePackage::id& spritePackageId, const std::string& spritePackagePath) {
        printf("SpritePackageLoader: Creating SpritePackage from data in ../resources/packages/%s\n", spritePackagePath.c_str());
        rapidjson::Document doc = json::parseJsonFile("../resources/packages/" + spritePackagePath);

        assert(spritePackageId == doc["package_id"].GetString());

        Texture::id textureId = doc["texture_id"].GetString();
       
        textureManager.loadTexture(textureId);
        SpritePackage::ptr spritePackage = std::make_shared<SpritePackage>(
            spritePackageId,                        // SpritePackage::id
            textureManager.getTexture(textureId)    // Texture::ptr
        );

        return spritePackage;
    }
} // namespace graphics
} // namespace p2d