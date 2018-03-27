#include <cstdio>

#include "rapidjson/filereadstream.h"
#include "rapidjson/document.h"

#include "json/Helpers.hpp"

#include "TextureManager.hpp"

namespace p2d { namespace graphics {
    Texture::ptr TextureManager::getTexture(const Texture::id& id) {
        return textureMap.get(id);
    }

    void TextureManager::loadTexture(const Texture::id& id) {
        const std::string textureFullPath = "../resources/textures/" + textureLookupTable.get(id);
        printf("TextureManager: Loading texture from %s\n", textureFullPath.c_str());
        Texture::ptr texture = std::make_shared<Texture>(id, textureFullPath);
        textureMap.insert(std::make_pair(id, texture)); 
    }

    void TextureManager::initializeLookupTable() {
        printf("TextureManager: Loading and parsing texture lookup table\n");
        rapidjson::Document doc = p2d::json::parseJsonFile("../resources/textures/texture_lookup.json");

        for (auto& entry : doc.GetArray()) {
            const Texture::id textureId = entry[0].GetString();
            const std::string texturePath = entry[1].GetString();
            textureLookupTable.insert(std::make_pair(textureId, texturePath));
            printf("-- %s: %s\n", textureId.c_str(), texturePath.c_str());
        }
        printf("TextureManager: Finished loading texture lookup table\n");
    }
} // namespace graphics
} // namespace p2d