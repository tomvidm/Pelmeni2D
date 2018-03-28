#include <cstdio>

#include "rapidjson/filereadstream.h"
#include "rapidjson/document.h"

#include "json/Helpers.hpp"

#include "TextureManager.hpp"

namespace p2d { namespace graphics {
    Texture::ptr TextureManager::getTexture(const Texture::id& id) {
        return textureMap.get(id);
    }

    void TextureManager::loadTexture(const Texture::id& textureId) {
        const std::string textureFullPath = "../resources/textures/" + textureLookupTable.get(textureId);
        printf("Loading texture '%s' from %s\n", textureId.c_str(), textureFullPath.c_str());
        Texture::ptr texture = textureLoader.createTexture(textureId, textureFullPath);
        textureMap.insert(std::make_pair(textureId, texture)); 
    }

    void TextureManager::initializeLookupTable() {
        printf("Initializing texture lookup table... ");
        rapidjson::Document doc = p2d::json::parseJsonFile("../resources/textures/texture_lookup.json");

        for (auto& entry : doc.GetArray()) {
            const Texture::id textureId = entry[0].GetString();
            const std::string texturePath = entry[1].GetString();
            textureLookupTable.insert(std::make_pair(textureId, texturePath));
        }
        printf("Finished\n");
    }
} // namespace graphics
} // namespace p2d